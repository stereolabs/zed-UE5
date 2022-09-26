#include "ZEDPointCloudRenderer.h"

// Sets default values
AZEDPointCloudRenderer::AZEDPointCloudRenderer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


}

// Just the destructor:
AZEDPointCloudRenderer::~AZEDPointCloudRenderer()
{
	if (Vertices) sl_mat_free(Vertices, SL_MEM_CPU);
	if (Colors) sl_mat_free(Colors, SL_MEM_GPU);
	if (SignedColors) sl_mat_free(SignedColors, SL_MEM_GPU);
}

// Called when the game starts or when spawned
void AZEDPointCloudRenderer::BeginPlay()
{
	Super::BeginPlay();

	GSlCameraProxy->OnCameraOpened.AddDynamic(this, &AZEDPointCloudRenderer::Init);
	GSlCameraProxy->AddToGrabDelegate([this](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp)
	{
		UpdateTextures(ErrorCode, Timestamp);
	});
}

/**
 * Just a helper method to set a texture for a user variable because the UNiagaraComponent 
 * has no direct way to edit a texture variable compared to float, vectors, ...
 */

void SetNiagaraVariableTexture(class UNiagaraComponent* niagara, FString variableName, UTexture* texture)
{
	if (!niagara || !texture)
		return;

	FNiagaraUserRedirectionParameterStore& overrideParameters = niagara->GetOverrideParameters();
	FNiagaraVariable niagaraVariable = FNiagaraVariable(FNiagaraTypeDefinition(UNiagaraDataInterfaceTexture::StaticClass()), *variableName);

	UNiagaraDataInterfaceTexture* dataInterface = (UNiagaraDataInterfaceTexture*)overrideParameters.GetDataInterface(niagaraVariable);
	dataInterface->SetTexture(texture);
}

void AZEDPointCloudRenderer::Init() 
{
	Resolution = FIntPoint(1280, 704);
	PointCount = Resolution.X * Resolution.Y;

	// Initialize data arrays:
	Vertices = (float*)sl_mat_create_new(Resolution.X, Resolution.Y, SL_MAT_TYPE_F32_C4, SL_MEM_CPU);
	Colors = (unsigned char *)sl_mat_create_new(Resolution.X, Resolution.Y, SL_MAT_TYPE_U8_C4, SL_MEM_GPU);
	SignedColors = (unsigned char*)sl_mat_create_new(Resolution.X, Resolution.Y, SL_MAT_TYPE_S8_C4, SL_MEM_GPU);

	Region = FUpdateTextureRegion2D(0, 0, 0, 0, Resolution.X, Resolution.Y);

		// Initialize the Niagara System:
	RendererInstance = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			this,
			PointCloudRenderer,
			FVector(0, 0, 0),
			FRotator(0),
			FVector(1),
			true,
			true,
			ENCPoolMethod::AutoRelease,
			true
		);
	RendererInstance->SetCastShadow(false);

	VerticeTexture = UTexture2D::CreateTransient(Resolution.X, Resolution.Y, PF_A32B32G32R32F, "PositionData");
	VerticeTexture->Filter = TF_Bilinear;
	

	// Create dynamic texture for color:
	ColorTexture = UTexture2D::CreateTransient(Resolution.X, Resolution.Y, PF_R8G8B8A8_SNORM, "ColorTexture");
	ColorTexture->Filter = TF_Bilinear;
	ColorTexture->bNoTiling = true;
	ColorTexture->SRGB = true;
	ColorTexture->AddressX = TextureAddress::TA_Clamp;
	ColorTexture->AddressY = TextureAddress::TA_Clamp;
	ColorTexture->LODGroup = TextureGroup::TEXTUREGROUP_RenderTarget;

	VerticeTexture->UpdateResource();
	ColorTexture->UpdateResource();
	// Set the niagara system user variables:
	SetNiagaraVariableTexture(RendererInstance, "User.PositionTexture", VerticeTexture);
	SetNiagaraVariableTexture(RendererInstance, "User.ColorTexture", ColorTexture);

	RendererInstance->SetVariableInt("User.TextureWidth", Resolution.X);
	RendererInstance->SetVariableInt("User.TextureHeight", Resolution.Y);
	RendererInstance->SetVariableInt("User.PointCount", PointCount);

	Runtime = 0;
}


void AZEDPointCloudRenderer::UpdateTextures(ESlErrorCode ErrorCode, FSlTimestamp Timestamp) 
{
	if (sl_mat_is_init(Vertices)) sl_retrieve_measure(GSlCameraProxy->GetCameraID(), Vertices, SL_MEASURE_XYZ, SL_MEM_CPU, Resolution.X, Resolution.Y);
	else UE_LOG(LogTemp, Warning, TEXT("Positions is not init"));

	if (sl_mat_is_init(Colors)) sl_retrieve_image(GSlCameraProxy->GetCameraID(), Colors, SL_VIEW_LEFT, SL_MEM_GPU, Resolution.X, Resolution.Y);
	else UE_LOG(LogTemp, Warning, TEXT("Colors is not init"));

	sl_convert_image(Colors, SignedColors, 0);
	sl_mat_update_cpu_from_gpu(SignedColors);
	if (Runtime < 0) {
		UE_LOG(LogTemp, Warning, TEXT("Not initialized"));
		return;
	}

	AsyncTask(ENamedThreads::GameThread, [=]() {
		VerticeTexture->UpdateTextureRegions(0, 1, &Region, sl_mat_get_step_bytes(Vertices, SL_MEM_CPU), sl_mat_get_pixel_bytes(Vertices), (uint8*)sl_mat_get_ptr(Vertices, SL_MEM_CPU));
		ColorTexture->UpdateTextureRegions(0, 1, &Region, sl_mat_get_step_bytes(SignedColors, SL_MEM_CPU), sl_mat_get_pixel_bytes(SignedColors), (uint8*)sl_mat_get_ptr(SignedColors, SL_MEM_CPU));
	});
}

// Called every frame
void AZEDPointCloudRenderer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (Runtime < 0) return;
	Runtime += DeltaTime;
}

