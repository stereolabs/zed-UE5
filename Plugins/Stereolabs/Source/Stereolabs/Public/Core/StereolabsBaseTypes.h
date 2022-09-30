//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Windows/AllowWindowsPlatformTypes.h"
#include <sl/Camera.hpp>
#include "Windows/HideWindowsPlatformTypes.h"

#include "Engine/Texture2D.h"
#include "Misc/ConfigCacheIni.h"

THIRD_PARTY_INCLUDES_START
#include "../../../ThirdParty/sl_zed_c/include/sl/c_api/zed_interface.h"
THIRD_PARTY_INCLUDES_END

#include "StereolabsBaseTypes.generated.h"


/**
 * Convert the value of an enum to a string.
 *
 * @param EnumValue
 *	The enumerated type value to convert to a string.
 *
 * @return
 *	The key/name that corresponds to the value in the enumerated type.
 */
template<typename T>
FString EnumToString(const T EnumValue)
{
	FString Name = StaticEnum<T>()->GetNameStringByValue(static_cast<__underlying_type(T)>(EnumValue));

	check(Name.Len() != 0);

	return Name;
}

/************************************************************************/
/*								 Enums									*/
/************************************************************************/

/*
 * List of possible camera state
 * see sl::CAMERA_STATE
 */
enum class ESlCameraState : uint8
{
	CS_Available			UMETA(DisplayName = "Available"),
	CS_NotAvailable			UMETA(DisplayName = "Not available")
};

/*
 * Formats supported by USlTexture
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlTextureFormat : uint8
{
	TF_R32_FLOAT			UMETA(DisplayName = "R32 Float (depth/disparity)"),
	TF_R8G8B8A8_SNORM		UMETA(DisplayName = "RGBA8 SNORM (Color)"),
	TF_R8G8B8A8_UINT		UMETA(DisplayName = "RGBA8 UINT (Point Cloud)"),
	TF_A32B32G32R32F		UMETA(DisplayName = "ABGR32 Float (normals)"),
	TF_R8_UNORM				UMETA(DisplayName = "R8 UNORM (Color grayscale)"),
	TF_Unkown				UMETA(Hidden, DisplayName = "Unknown")
};

/*
 * Texture quality presets for depth and normals
 * Low    = 192p
 * Medium = 480p
 * High   = 720p
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlTextureQuality : uint8
{
	TQ_Low					UMETA(DisplayName = "Low"),
	TQ_Medium				UMETA(DisplayName = "Medium"),
	TQ_High					UMETA(DisplayName = "High")
};

/*
 * Resolution presets for spatial mapping
 * See sl::SpatialMappingParameters::RESOLUTION
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlSpatialMappingResolution : uint8
{
	SMR_Low					UMETA(DisplayName = "Low resolution"),
	SMR_Medium				UMETA(DisplayName = "Medium resolution"),
	SMR_High				UMETA(DisplayName = "High resolution")
};

/*
 * Range presets for spatial mapping
 * See sl::SpatialMappingParameters::RANGE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlSpatialMappingRange : uint8
{
	SMR_Short				UMETA(DisplayName = "Short"),
	SMR_Medium				UMETA(DisplayName = "Medium"),
	SMR_Long				UMETA(DisplayName = "Long"),
	SMR_Auto				UMETA(DisplayName = "Auto")
};

/*
 * Mesh filtering presets for spatial mapping
 * See sl::MeshFilterParameters::FILTER
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlFilterIntensity : uint8
{
	FI_Low					UMETA(DisplayName = "Low"),
	FI_Medium				UMETA(DisplayName = "Medium"),
	FI_High					UMETA(DisplayName = "High")
};

/*
 * IDs of each "eye"
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlEye : uint8
{
	E_Left					UMETA(DisplayName = "Left"),
	E_Right					UMETA(DisplayName = "Right")
};

/*
 * Threading mode selected to perform grab
 * MultiThreaded  = Grab called asynchronously at max rate
 * SingleThreaded = Grab called in game thread at game FPS rate
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlThreadingMode : uint8
{
	TM_MultiThreaded		 UMETA(DisplayName = "MultiThreaded"),
	TM_SingleThreaded		 UMETA(DisplayName = "SingleThreaded"),
	TM_None					 UMETA(Hidden, DisplayName = "Unselected")
};

/*
 * SDK Memory types
 * see sl::MEM
 */
UENUM(BlueprintType, Meta = (Bitflags), Category = "Stereolabs|Enum")
enum class ESlMemoryType : uint8
{
	MT_CPU			UMETA(DisplayName = "CPU"),
	MT_GPU			UMETA(DisplayName = "GPU"),
};
ENUM_CLASS_FLAGS(ESlMemoryType)

/*
 * SDK Video resolutions
 * see sl::RESOLUTION
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlResolution : uint8
{
	R_HD2K			   		 UMETA(DisplayName = "HD 2K"),
	R_HD1080		   		 UMETA(DisplayName = "HD 1080p"),
	R_HD720		   			 UMETA(DisplayName = "HD 720p"),
	R_VGA			   		 UMETA(DisplayName = "VGA")
};

/*
 * SDK Depth modes
 * see sl::DEPTH_MODE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlDepthMode : uint8
{
	DM_None				     UMETA(DisplayName = "None"),
	DM_Performance			 UMETA(DisplayName = "Performance"),
	DM_Quality				 UMETA(DisplayName = "Quality"),
	DM_Ultra				 UMETA(DisplayName = "Ultra"),
	DM_Neural				 UMETA(DisplayName = "Neural")
};

/*
 * SDK Sensing modes
 * see sl::SENSING_MODE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlSensingMode : uint8
{
	SM_Standard				 UMETA(DisplayName = "Standard"),
	SM_Fill					 UMETA(DisplayName = "Fill")
};

/*
 * Units used for measures.
 * For performance concern, only centimeter natively used by UE is available
 * see sl::UNIT
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlUnit : uint8
{
	DU_Centimeter            UMETA(DisplayName = "Centimeter")
};

/*
 * Coordinate systems used for measures.
 * For performance concern, only Cartesian natively used by UE is available
 * See sl::COORDINATE_SYSTEM
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlCoordinateSystem : uint8
{
	CS_Cartesian   			 UMETA(DisplayName = "Cartesian left-handed")
};

/*
 * Input type
 * See sl::INPUT_TYPE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlInputType : uint8
{
	IT_USB   			 UMETA(DisplayName = "USB input mode"),
	IT_SVO   			 UMETA(DisplayName = "SVO input mode"),
	IT_STREAM   		 UMETA(DisplayName = "Stream input mode"),
};

/*
 * Camera flip mode
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlFlipMode : uint8
{
	FP_OFF   			 UMETA(DisplayName = "Default behaviour"),
	FP_ON   			 UMETA(DisplayName = "Images and camera sensors data are flipped"),
	FP_AUTO   			 UMETA(DisplayName = "Detect automatically")
};

/*
 * SDK Tracking states 
 * See sl::TRACKING_STATE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlTrackingState : uint8
{
	TS_TrackingSearch	     UMETA(DisplayName = "Searching a match"),
	TS_TrackingOk            UMETA(DisplayName = "Operates normally"),
	TS_TrackingOff           UMETA(DisplayName = "Disabled"),
	TS_FpsTooLow			 UMETA(DisplayName = "FPS too low"),
	TS_SeachingFloorPlane    UMETA(DisplayName = "Searching floor plane")
};

/*
 * Rendering modes available in the plugin
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlRenderingMode : uint8
{
	RM_Mono				     UMETA(DisplayName = "Mono"),
	RM_Stereo			     UMETA(DisplayName = "Stereo"),
	RM_None					 UMETA(Hidden, DisplayName = "Unselected")
};

/*
 * SDK View types
 * See sl::VIEW
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlView : uint8
{
	V_Left					 UMETA(DisplayName = "Left"),
	V_Right					 UMETA(DisplayName = "Right"),
	//Not supported for the moment"
	//V_LeftGray				 UMETA(DisplayName = "Left gray"),
	//V_RightGray				 UMETA(DisplayName = "Right gray"),
	V_LeftUnrectified		 UMETA(DisplayName = "Left unrectified"),
	V_RightUnrectified		 UMETA(DisplayName = "Right unrectified"),
	//Not supported for the moment"
	//V_LeftUnrectifiedGray	 UMETA(DisplayName = "Left unrectified gray"),
	//V_RightUnrectifiedGray	 UMETA(DisplayName = "Right unrectified gray"),
	V_SideBySide			 UMETA(DisplayName = "Side by side"),
	V_Depth					 UMETA(DisplayName = "Depth"),
	V_Confidence			 UMETA(DisplayName = "Confidence"),
	V_Normals				 UMETA(DisplayName = "Normals"),
	V_DepthRight			 UMETA(DisplayName = "Depth right"),
	V_NormalsRight		     UMETA(DisplayName = "Normals right")
};

UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlViewFormat : uint8
{
	VF_Signed					 UMETA(DisplayName = "Signed"), //  Each pixel contains 4 signed char 
	VF_Unsigned					 UMETA(DisplayName = "Unsigned"), //  Each pixel contains 4 unsigned char 
};

/*
 * SDK Measure types
 * See sl::MEASURE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlMeasure : uint8
{
	M_Disparity				 UMETA(DisplayName = "Disparity"),
	M_Depth					 UMETA(DisplayName = "Depth"),
	M_Confidence			 UMETA(DisplayName = "Confidence"),
	M_XYZ					 UMETA(DisplayName = "Point Cloud"),
	M_XYZ_RGBA				 UMETA(DisplayName = "Point Cloud RGBA"),
	M_XYZ_BGRA				 UMETA(DisplayName = "Point Cloud BGRA"),
	M_XYZ_ARGB				 UMETA(DisplayName = "Point Cloud ARGB"),
	M_XYZ_ABGR				 UMETA(DisplayName = "Point Cloud ABGR"),
	M_Normals				 UMETA(DisplayName = "Normals"),
	M_DisparityRight		 UMETA(DisplayName = "Disparity right"),
	M_DepthRight			 UMETA(DisplayName = "Depth right"),
	M_XYZ_Right				 UMETA(DisplayName = "Point Cloud right"),
	M_XYZ_RGBA_Right		 UMETA(DisplayName = "Point Cloud RGBA right"),
	M_XYZ_BGRA_Right		 UMETA(DisplayName = "Point Cloud BGRA right"),
	M_XYZ_ARGB_Right		 UMETA(DisplayName = "Point Cloud ARGB right"),
	M_XYZ_ABGR_Right		 UMETA(DisplayName = "Point Cloud ABGR right"),
	M_NormalsRight			 UMETA(DisplayName = "Normals right"),
	M_DEPTH_U16_MM		     UMETA(DisplayName = "Depth in millimeter"),
	M_DEPTH_U16_MM_RIGHT     UMETA(DisplayName = "Depth right in millimeter")
};

/*
 * Plugin texture types
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlTextureType : uint8
{
	TT_View					 UMETA(DisplayName = "View"),
	TT_Measure				 UMETA(DisplayName = "Measure")
};

/*
 * Retrieve valid or not
 * RR_DepthNotValid does not exist because depth values are clamped between min and max
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlRetrieveResult : uint8
{
	/** The location is valid and the retrieve returned a valid value */
	RR_RetrieveValid        UMETA(DisplayName = "Retrieve valid"), 
	/** The location is not valid and no retrieve */
	RR_LocationNotValid		UMETA(DisplayName = "Retrieve location not valid"), 
	/** The location is valid and the normal retrieved is not valid */
	RR_NormalNotValid		UMETA(DisplayName = "Normal not valid") 
};

/* 
 * SDK Error codes
 * see sl::ERROR_CODE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlErrorCode : uint8
{
 	EC_Success					     UMETA(DisplayName = "Success"),
	EC_Failure					     UMETA(DisplayName = "Failure"),
	EC_NoGpuCompatible			     UMETA(DisplayName = "No GPU compatible"),
	EC_NotEnoughGPUMemory		     UMETA(DisplayName = "Not enough GPU memory"),
	EC_CameraNotDetected		     UMETA(DisplayName = "Camera not detected"),
	EC_SensorNotInitialized		     UMETA(DisplayName = "Sensors not initialized"),
	EC_SensorNotAvailable		     UMETA(DisplayName = "Sensors not available"),
	EC_InvalidResolution		     UMETA(DisplayName = "Invalid resolution"),
	EC_LowUSBBandwidth			     UMETA(DisplayName = "Low USB bandwidth"),
	EC_CalibrationFileNotAvailable   UMETA(DisplayName = "Calibration file not available"),
	EC_InvalidCalibrationFile	     UMETA(DisplayName = "Invalid calibration file"),
	EC_InvalidSVOFile			     UMETA(DisplayName = "Invalid SVO file"),
	EC_SVORecordingError		     UMETA(DisplayName = "SVO recording error"),
	EC_SVOUnsupportedCompression     UMETA(DisplayName = "SVO unsupported compression"),
	EC_SVOEndOfSVOFile               UMETA(DisplayName = "End of SVO file reached"),
	EC_InvalidCoordinateSystem	     UMETA(DisplayName = "Invalid coordinate system"),
	EC_InvalidFirmware			     UMETA(DisplayName = "Invalid firmware"),
	EC_InvalidFunctionParameters     UMETA(DisplayName = "Invalid function parameters"),
	EC_CUDAError				     UMETA(DisplayName = "CUDA error"),
	EC_CameraNotInitialized		     UMETA(DisplayName = "Camera not initialized"),
	EC_NVIDIADriverOutOfDate	     UMETA(DisplayName = "NVIDIA driver out of date"),
	EC_InvalidFunctionCall		     UMETA(DisplayName = "Invalid function call"),
	EC_CorruptedSDKInstallation	     UMETA(DisplayName = "Corrupted SDK installation"),
	EC_IncompatibleSDKVersion        UMETA(DisplayName = "Incompatible SDK version"),
	EC_InvalidAreaFile			     UMETA(DisplayName = "Invalid area file"),
	EC_IncompatibleAreaFile		     UMETA(DisplayName = "Incompatible area file"),
	EC_CameraFailedToSetup		     UMETA(DisplayName = "Camera failed to setup"),
	EC_CameraDetectionIssue		     UMETA(DisplayName = "Camera detection issue"),
	EC_CameraStreamFailedToStart     UMETA(DisplayName = "Camera failed to start stream"),
	EC_NoGpuDetected			     UMETA(DisplayName = "No GPU detected"),
	EC_NoplaneFound				     UMETA(DisplayName = "No plane(s) found"),
	EC_ModuleNotCompatibleWithCamera UMETA(DisplayName = "Module not compatible with camera"),
	EC_MotionSensorsRequired         UMETA(DisplayName = "Motion sensors required"),
	EC_ModuleNotCompatibleWithCuda   UMETA(DisplayName = "Module not compatible with cuda version"),
	// ERROR_CODE_LAST
	EC_None					  	   UMETA(DisplayName = "No error") 
};

/* 
 * SDK SVO compression modes
 * see sl::SVO_COMPRESSION_MODE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlSVOCompressionMode : uint8
{
	SCM_Lossless			UMETA(DisplayName = "Lossless"),
	SCM_H264				UMETA(DisplayName = "H264"),
	SCM_H265				UMETA(DisplayName = "H265"),
    SCM_H264_Lossless	    UMETA(DisplayName = "H264_Lossless"),
	SCM_H265_Lossless	    UMETA(DisplayName = "H265_Lossless")
};

/* 
 * SDK spatial memory export state
 * see sl::AREA_EXPORT_STATE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlSpatialMemoryExportingState : uint8
{
	SMES_Success			   UMETA(DisplayName = "Success"),
	SMES_Running			   UMETA(DisplayName = "Running"),
	SMES_NotStarted			   UMETA(DisplayName = "NotStarted"),
	SMES_FileEmpty			   UMETA(DisplayName = "FileEmpty"),
	SMES_FileError			   UMETA(DisplayName = "FileError"),
	SMES_SpatialMemoryDisabled UMETA(DisplayName = "SpatialMemoryDisabled")
};

/* 
 * SDK mesh file format
 * see sl::MESH_FILE_FORMAT
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlMeshFileFormat : uint8
{
	MFF_PLY					UMETA(DisplayName = "Ply (.ply)"),
	MFF_PLY_BIN				UMETA(DisplayName = "Ply binary (.ply)"),
	MFF_OBJ					UMETA(DisplayName = "Obj (.obj)")
};

/* 
 * SDK mesh texture format
 * see sl::MESH_TEXTURE_FORMAT
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlMeshTextureFormat : uint8
{
	MTF_RGB					UMETA(DisplayName = "RGB"),
	MTF_RGBA				UMETA(DisplayName = "RGBA")
};

/* 
 * SDK camera type
 * see sl::MODEL
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlModel : uint8
{
	M_Zed					UMETA(DisplayName = "ZED"),
	M_ZedM					UMETA(DisplayName = "ZED Mini"),
	M_Zed2					UMETA(DisplayName = "ZED 2"),
	M_Zed2i          		UMETA(DisplayName = "ZED 2i"),
	M_Unknown				UMETA(DisplayName = "Unknown")
};

/*
 * SDK reference frame
 * see sl::REFERENCE_FRAME
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlReferenceFrame : uint8
{
	/** The transform of FSlPose will contains the motion with reference to the world frame */
	RF_World				UMETA(DisplayName = "World"),
	/** The transform of FSlPose will contains the motion with reference to the previous camera frame */
	RF_Camera				UMETA(DisplayName = "Camera")
};

/*
 * Defines the world type that the SDK can use to initialize the Positionnal Tracking module
 * see sl::SENSOR_WORLD
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlSensorWorld : uint8
{
	/** The SDK takes the user initial pose without any modification as the world position of the Positional Tracking module.*/
	SW_Off	    			UMETA(DisplayName = "Off"),
	/** Align the positional tracking world to imu gravity measurement. keep the yaw from the user initial pose.*/
	SW_ImuGravity			UMETA(DisplayName = "IMU gravity")
};

/*
 * SDK time reference
 * see sl::TIME_REFERENCE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlTimeReference : uint8
{
	TR_Image				UMETA(DisplayName = "Image"),
	TR_Current				UMETA(DisplayName = "Current")
};

/*
 * SDK mat type
 * see sl::MAT_TYPE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlMatType : uint8
{
	MT_32F_C1				UMETA(DisplayName = "Float 1 channel"),
	MT_32F_C2				UMETA(DisplayName = "Float 2 channels"),
	MT_32F_C3				UMETA(DisplayName = "Float 3 channels"),
	MT_32F_C4				UMETA(DisplayName = "Float 4 channels"),
	MT_8U_C1				UMETA(DisplayName = "Uint 1 channel"),
	MT_8U_C2				UMETA(DisplayName = "Uint 2 channels"),
	MT_8U_C3				UMETA(DisplayName = "Uint 3 channels"),
	MT_8U_C4				UMETA(DisplayName = "Uint 4 channels"),
	MT_16U_C1				UMETA(DisplayName = "Ushort 1 channels"),
	MT_8S_C4				UMETA(DisplayName = "Signed char 4 channels")
};

/*
 * SDK mat copy type
 * see sl::COPY_TYPE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlCopyType : uint8
{
	CT_CPUToCPU				UMETA(DisplayName = "CPU to CPU"),
	CT_CPUToGPU				UMETA(DisplayName = "CPU to GPU"),
	CT_GPUToGPU				UMETA(DisplayName = "GPU to GPU"),
	CT_GPUToCPU				UMETA(DisplayName = "GPU to CPU")
};

/*
 * SDK self calibration state
 * see sl::SELF_CALIBRATION_STATE
 */
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlSelfCalibrationState : uint8
{
	SCS_NotStarted			UMETA(DisplayName = "Not started"),
	SCS_Running				UMETA(DisplayName = "Running"),
	SCS_Failed				UMETA(DisplayName = "Failed"),
	SCS_Success				UMETA(DisplayName = "Success"),
};

/*
* Tracking type selection
* Allow to chose which tracking is selected for the pawn.
* ZED : Zed tracking only
* HMD : Hmd tracking only
* Mixte : Zed Imu rotations and Hmd translations
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ETrackingType : uint8
{
	TrT_ZED			UMETA(DisplayName = "Zed"),
	TrT_HMD			UMETA(DisplayName = "Hmd"),
	TrT_Mixte		UMETA(DisplayName = "Mixte"),
};

/*
* Lists available object tracking state.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlObjectTrackingState : uint8
{
	OTS_Off				UMETA(DisplayName = "Off"),
	OTS_Ok				UMETA(DisplayName = "Ok"),
	OTS_Searching		UMETA(DisplayName = "Searching"),
	OTS_Terminate		UMETA(DisplayName = "Terminate"),
};

/*
* Lists available object action state.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlObjectActionState : uint8
{
	OAS_Idle		UMETA(DisplayName = "Idle"),
	OAS_Moving		UMETA(DisplayName = "Moving"),
};

/*
* List of available models for detection.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlDetectionModel : uint8
{
	DM_MultiClassBox			UMETA(DisplayName = "Multi class box"),
	DM_MultiClassBoxAccurate	UMETA(DisplayName = "Multi class box accurate"),
	DM_HumanBodyFast			UMETA(DisplayName = "Human body fast"),
	DM_HumanBodyAccurate		UMETA(DisplayName = "Human body accurate"),
	DM_MultiClassBoxMedium		UMETA(DisplayName = "Multi class box medium"),
	DM_HumanBodyMedium			UMETA(DisplayName = "Human body medium"),
	DM_PersonHeadBox			UMETA(DisplayName = "Person head box"),
	DM_PersonHeadAccurateBox	UMETA(DisplayName = "Person head accurate box"),
	DM_CustomBoxObjects			UMETA(DisplayName = "Custom box objects")
};

UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlAIModels : uint8
{
	AIM_MultiClassDetection			    UMETA(DisplayName = "Multi class Detection"),
	AIM_MultiClassMediumDetection		UMETA(DisplayName = "Multi class medium Detection"),
	AIM_MultiClassAccurateDetection		UMETA(DisplayName = "Multi class accurate Detection"),
	AIM_HumanBodyFastDetection			UMETA(DisplayName = "Human body fast Detection"),
	AIM_HumanBodyMediumDetection		UMETA(DisplayName = "Human body medium Detection"),
	AIM_HumanBodyAccurateDetection		UMETA(DisplayName = "Human body accurate Detection"),
	AIM_PersonHeadDetection				UMETA(DisplayName = "Person head Detection"),
	AIM_PersonHeadAccurateDetection		UMETA(DisplayName = "Person head accurate Detection"),
	AIM_REIDAssociation					UMETA(DisplayName = "REID Associaiton"),
	AIM_NeuralDepth						UMETA(DisplayName = "Neural Depth"),
};

/*
* List of supported skeleton body model.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBodyFormat : uint8
{
	BF_POSE_18    UMETA(DisplayName = "Pose 18"),
	BF_POSE_34		  UMETA(DisplayName = "Pose 34")
};

/*
* Lists of supported bounding box preprocessing.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlObjectFilteringMode : uint8
{
	OFM_NONE				UMETA(DisplayName = "None"),
	OFM_NMS3D				UMETA(DisplayName = "Nms3d"),
	OFM_NMS3D_PER_CLASS		UMETA(DisplayName = "Nms3d per class")

};

/*
* Lists available object class.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlObjectClass : uint8
{
	OC_PERSON = 0			UMETA(DisplayName = "Person"),
	OC_VEHICLE = 1			UMETA(DisplayName = "Vehicle"),
	OC_BAG = 2				UMETA(DisplayName = "Bag"),
	OC_ANIMAL= 3			UMETA(DisplayName = "Animal"),
	OC_ELECTRONICS = 4		UMETA(DisplayName = "Electronics"),
	OC_FRUIT_VEGETABLE = 5	UMETA(DisplayName = "Fruit and Vegetables"),
	OC_SPORT = 6			UMETA(DisplayName = "Sport"),
};

/*
* Lists available object subclass.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlObjectSubClass : uint8
{
	OSC_PERSON = 0			UMETA(DisplayName = "Person"),
	OSC_PERSON_HEAD = 22	UMETA(DisplayName = "Person head"),
	OSC_BICYCLE = 1			UMETA(DisplayName = "Bicyle"),
	OSC_CAR = 2				UMETA(DisplayName = "Car"),
	OSC_MOTORBIKE = 3		UMETA(DisplayName = "Motorbike"),
	OSC_BUS = 4				UMETA(DisplayName = "Bus"),
	OSC_TRUCK = 5			UMETA(DisplayName = "Truck"),
	OSC_BOAT = 6			UMETA(DisplayName = "Boat"),
	OSC_BACKPACK = 7		UMETA(DisplayName = "Backpack"),
	OSC_HANDBAG = 8			UMETA(DisplayName = "Handbag"),
	OSC_SUITCASE = 9		UMETA(DisplayName = "Suitcase"),
	OSC_BIRD = 10			UMETA(DisplayName = "Bird"),
	OSC_CAT = 11			UMETA(DisplayName = "Cat"),
	OSC_DOG = 12			UMETA(DisplayName = "Dog"),
	OSC_HORSE = 13			UMETA(DisplayName = "Horse"),
	OSC_SHEEP = 14			UMETA(DisplayName = "Sheep"),
	OSC_COW = 15			UMETA(DisplayName = "Cow"),
	OSC_CELLPHONE = 16		UMETA(DisplayName = "Cellphone"),
	OSC_LAPTOP = 17			UMETA(DisplayName = "Laptop"),
	OSC_BANANA = 18			UMETA(DisplayName = "Banana"),
	OSC_APPLE = 19			UMETA(DisplayName = "Apple"),
	OSC_ORANGE = 20			UMETA(DisplayName = "Orange"),
	OSC_CARROT = 21			UMETA(DisplayName = "Carrot"),
	OSC_SPORTBALL = 23		UMETA(DisplayName = "Sportball"),
};

/*
* List of human body parts and order of SlObjectData::keypoint for BODY_FORMAT::POSE_18.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBodyParts : uint8 {
	NOSE = 0,
	NECK = 1,
	RIGHT_SHOULDER = 2,
	RIGHT_ELBOW = 3,
	RIGHT_WRIST = 4,
	LEFT_SHOULDER = 5,
	LEFT_ELBOW = 6,
	LEFT_WRIST = 7,
	RIGHT_HIP = 8,
	RIGHT_KNEE = 9,
	RIGHT_ANKLE = 10,
	LEFT_HIP = 11,
	LEFT_KNEE = 12,
	LEFT_ANKLE = 13,
	RIGHT_EYE = 14,
	LEFT_EYE = 15,
	RIGHT_EAR = 16,
	LEFT_EAR = 17
};



/*
* List of human body parts and order of SlObjectData::keypoint for BODY_FORMAT::POSE_34.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBodyPartsPose34 : uint8 {
	PELVIS = 0,
	NAVAL_SPINE = 1,
	CHEST_SPINE = 2,
	NECK = 3,
	LEFT_CLAVICLE = 4,
	LEFT_SHOULDER = 5,
	LEFT_ELBOW = 6,
	LEFT_WRIST = 7,
	LEFT_HAND = 8,
	LEFT_HANDTIP = 9,
	LEFT_THUMB = 10,
	RIGHT_CLAVICLE = 11,
	RIGHT_SHOULDER = 12,
	RIGHT_ELBOW = 13,
	RIGHT_WRIST = 14,
	RIGHT_HAND = 15,
	RIGHT_HANDTIP = 16,
	RIGHT_THUMB = 17,
	LEFT_HIP = 18,
	LEFT_KNEE = 19,
	LEFT_ANKLE = 20,
	LEFT_FOOT = 21,
	RIGHT_HIP = 22,
	RIGHT_KNEE = 23,
	RIGHT_ANKLE = 24,
	RIGHT_FOOT = 25,
	HEAD = 26,
	NOSE = 27,
	LEFT_EYE = 28,
	LEFT_EAR = 29,
	RIGHT_EYE = 30,
	RIGHT_EAR = 31,
	LEFT_HEEL = 32,
	RIGHT_HEEL = 33
};
/************************************************************************/
/*							    Structs				    				*/
/************************************************************************/

/*
 * Bone descriptor, pair of ESlBodyParts
 * To be used in the correspondance array in ZEDPlayerController
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBone18 
{
	GENERATED_BODY()

	FSlBone18()
	{}

	FSlBone18(ESlBodyParts first, ESlBodyParts second)
	{
		FirstEnd = first;
		SecondEnd = second;
	}

	/** First end of the bone */
	UPROPERTY(BlueprintReadOnly)
	ESlBodyParts FirstEnd;

	/** Second end of the bone */
	UPROPERTY(BlueprintReadOnly)
	ESlBodyParts SecondEnd;
};

/*
 * Bone descriptor, pair of ESlBodyPartsPose34
 * To be used in the correspondance array in ZEDPlayerController
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBone34
{
	GENERATED_BODY()

	FSlBone34() 
	{}

	FSlBone34(ESlBodyPartsPose34 first, ESlBodyPartsPose34 second)
	{
		FirstEnd = first;
		SecondEnd = second;
	}

	/** First end of the bone */
	UPROPERTY(BlueprintReadOnly)
	ESlBodyPartsPose34 FirstEnd;

	/** Second end of the bone */
	UPROPERTY(BlueprintReadOnly)
	ESlBodyPartsPose34 SecondEnd;
};

/*
 * SDK device properties
 * see sl::DeviceProperties
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlDeviceProperties
{
	GENERATED_BODY()

	FSlDeviceProperties()
		:
		Path(""),
		ID(0),
		SerialNumber(0),
		CameraState(ESlCameraState::CS_NotAvailable),
		CameraModel(ESlModel::M_Unknown)
	{
	}

	/** The camera system path */
	FString Path;

	/** The camera ID (Notice that only the camera with ID '0' can be used on Windows) */
	int32 ID;

	/** he camera serial number */
	int32 SerialNumber;

	/** The camera state */
	ESlCameraState CameraState;

	/** The camera model */
	ESlModel CameraModel;
};

/*
 * SDK camera parameters
 * see sl::CameraParameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlCameraParameters
{
	GENERATED_BODY()

	FSlCameraParameters()
		:
		Resolution(FIntPoint::ZeroValue),
		HFOV(0.0f),
		VFOV(0.0f),
		HFocal(0.0f),
		VFocal(0.0f),
		OpticalCenterX(0.0f),
		OpticalCenterY(0.0f)
	{
	}

	/** Distortion factor : [ k1, k2, p1, p2, k3 ]. Radial (k1,k2,k3) and Tangential (p1,p2) distortion. */
	UPROPERTY(BlueprintReadOnly)
	TArray<float> Disto;

	/** Resolution of images */
	UPROPERTY(BlueprintReadOnly)
	FIntPoint Resolution;

	/** Horizontal field of view */
	UPROPERTY(BlueprintReadOnly)
	float HFOV;

	/** Vertical field of view */
	UPROPERTY(BlueprintReadOnly)
	float VFOV;

	/** Horizontal focal */
	UPROPERTY(BlueprintReadOnly)
	float HFocal;

	/** Vertical focal */
	UPROPERTY(BlueprintReadOnly)
	float VFocal;

	/** Horizontal position of the optical center in pixels */
	UPROPERTY(BlueprintReadOnly)
	float OpticalCenterX;

	/** Vertical position of the optical center in pixels */
	UPROPERTY(BlueprintReadOnly)
	float OpticalCenterY;
};

/*
 * SDK calibration parameters
 * see Sl::CalibrationParameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlCalibrationParameters
{
	GENERATED_BODY()

	FSlCalibrationParameters()
		:
		Rotation(FVector::ZeroVector),
		Translation(FVector::ZeroVector)
	{
	}

    /** Intrinsic parameters of the left camera */
	UPROPERTY(BlueprintReadOnly)
	FSlCameraParameters LeftCameraParameters;

	/** Intrinsic parameters of the left camera */
	UPROPERTY(BlueprintReadOnly)
	FSlCameraParameters RightCameraParameters;

	/** Rotation (using Rodrigues' transformation) between the two sensors. Defined as 'tilt', 'convergence' and 'roll' */
	UPROPERTY(BlueprintReadOnly)
	FVector Rotation;

	/** Translation between the two sensors. T.x is the distance between the two cameras (baseline) in the sl::UNIT */
	UPROPERTY(BlueprintReadOnly)
	FVector Translation;
};

/*
 * SDK camera information
 * see Sl::CameraInformation
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlCameraInformation
{
	GENERATED_BODY()

	FSlCameraInformation()
		:
		HalfBaseline(0.0f),
		SerialNumber(0),
		CameraFirmwareVersion(0),
		SensorsFirmwareVersion(0),
		CameraModel(ESlModel::M_Unknown)
	{
	}

	/** Intrinsic and Extrinsic stereo parameters for rectified images (default) */
	UPROPERTY(BlueprintReadOnly)
	FSlCalibrationParameters CalibrationParameters; 

	/** Intrinsic and Extrinsic stereo parameters for original images (unrectified) */
	UPROPERTY(BlueprintReadOnly)
	FSlCalibrationParameters CalibrationParametersRaw;
	
	/** Half baseline in selected unit */
	UPROPERTY(BlueprintReadOnly)
	float HalfBaseline;

	/** camera dependent serial number */
	UPROPERTY(BlueprintReadOnly)
	int32 SerialNumber;

	/** current firmware version of the camera */
	UPROPERTY(BlueprintReadOnly)
	int32 CameraFirmwareVersion;

	/** current firmware version of the camera */
	UPROPERTY(BlueprintReadOnly)
	int32 SensorsFirmwareVersion;

	/** camera model (ZED or ZED-M) */
	UPROPERTY(BlueprintReadOnly)
	ESlModel CameraModel; 

	/* Resolution of the camera */
	UPROPERTY(BlueprintReadOnly)
	FIntPoint Resolution;
};

/*
 * SDK mat
 * Only holding the mat
 * see sl::Mat
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlMat
{
	GENERATED_BODY()

	FSlMat()
	{
	}

	FSlMat(void* NewMat)
		:
		Mat(NewMat)
	{
	}

	FSlMat& operator=(void* NewMat)
	{
		Mat = NewMat;
		return *this;
	}


	/** The underlying sl::Mat */
	void* Mat;
};

/*
 * Spatial mapping data of a mesh
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlMeshData
{
	GENERATED_BODY()

	FSlMeshData()
		:
		Texture(nullptr)
	{
		Clear();
	}

	/*
	 * Clear all the data
	 */
	void Clear()
	{
		Vertices.Empty(0);
		Indices.Empty(0);
		Normals.Empty(0);
		UV0.Empty(0);

		if (Texture && Texture->IsValidLowLevel())
		{
			Texture->ConditionalBeginDestroy();
			Texture = nullptr;
		}
	}

	/** Vertices of the mesh */
	UPROPERTY(BlueprintReadOnly)
	TArray<FVector> Vertices;

	/** Indices of the mesh */
	UPROPERTY(BlueprintReadOnly)
	TArray<int32> Indices;

	/** UV0 of the mesh */
	UPROPERTY(BlueprintReadOnly)
	TArray<FVector2D> UV0;

	/** Texture of the mesh */
	UPROPERTY(BlueprintReadOnly)
	UTexture2D* Texture;

	/** Normals of the mesh */
	UPROPERTY(BlueprintReadOnly)
	TArray<FVector> Normals;
};

/*
 * SDK mesh filter parameters
 * see sl::MeshFilterParameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlMeshFilterParameters
{
	GENERATED_BODY()

	FSlMeshFilterParameters(ESlFilterIntensity FilterIntensity)
		:
		FilterIntensity(FilterIntensity)
	{
	}

	FSlMeshFilterParameters()
		:
		FilterIntensity(ESlFilterIntensity::FI_Low)
	{
	}

	/** Intensity of the mesh filtering */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlFilterIntensity FilterIntensity;
};


/*
 * SDK spatial mapping parameters
 * see sl::SpatialMappingParameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Types")
struct STEREOLABS_API FSlSpatialMappingParameters
{
	GENERATED_BODY()

	FSlSpatialMappingParameters();

	/*
	 * Set the resolution
	 * @param NewPresetResolution The new preset
	 */
	void SetResolution(ESlSpatialMappingResolution NewPresetResolution);

	/*
	 * Set the resolution
	 * @param NewResolution The new resolution
	 */
	FORCEINLINE void SetResolution(float NewResolution)
	{
		sl::SpatialMappingParameters Dummy;

		Resolution = FMath::Clamp(NewResolution, Dummy.allowed_resolution.first, Dummy.allowed_resolution.second);
	}

	/*
	 * Set the range
	 * @param NewPresetRange The new preset
	 */
	void SetMaxRange(ESlSpatialMappingRange NewPresetRange);

	/*
	 * Set the max range
	 * @param NewRange The new range
	 */
	FORCEINLINE void SetMaxRange(float NewRange)
	{
		sl::SpatialMappingParameters Dummy;

		MaxRange = FMath::Clamp(NewRange, Dummy.allowed_range.first, Dummy.allowed_range.second);
	}

	/** Depth integration max range. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "2.0", ClampMax = "20.0"))
	float MaxRange;

	/** Spatial mapping resolution. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0.01", ClampMax = "0.2"))
	float Resolution;

	/** The maximum CPU memory (in mega bytes) allocated for the meshing process (will fit your configuration in any case). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxMemoryUsage;

	/** Resolution preset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlSpatialMappingResolution PresetResolution;

	/** Range preset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlSpatialMappingRange PresetRange;

	/*
	 * Set to true if you want be able to apply texture to your mesh after its creation.
	 * This option will take more memory.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSaveTexture;

	/** remove this function when chunks supported */
	bool GetUseChunksOnly() const
	{
		return bUseChunkOnly;
	}

private:
	/*  Set to false if you want keep consistency between the mesh and its inner chunks data.
	 *	Updating the Mesh is time consuming, consider using only Chunks data for better performance.
	 *  Chunks are not supported, forced to false.
	 */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bUseChunkOnly = false;
};

/*
 * SDK recording state
 * see sl::RecordingState
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Types")
struct STEREOLABS_API FSlRecordingState
{
	GENERATED_BODY()

	FSlRecordingState()
		:
		CurrentCompressionTime(0.0f),
		CurrentCompressionRatio(0.0f),
		AverageCompressionTime(0.0f),
		AverageCompressionRatio(0.0f),
		Status(false)
	{
	}

	/** Compression time for the current frame in ms. */
	UPROPERTY(BlueprintReadOnly)
	float CurrentCompressionTime;

	/** Compression ratio (% of raw size) for the current frame. */
	UPROPERTY(BlueprintReadOnly)
	float CurrentCompressionRatio;

	/** Average compression time in ms since beginning of recording. */
	UPROPERTY(BlueprintReadOnly)
	float AverageCompressionTime; 

	/** Compression ratio (% of raw size) since beginning of recording. */
	UPROPERTY(BlueprintReadOnly)
	float AverageCompressionRatio;

	/** Status of current frame. May be true for success or false if frame could not be written in the SVO file. */
	UPROPERTY(BlueprintReadOnly)
	uint8 Status:1;
};

/*
 * SDK camera settings
 * see sl::CameraSettings
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlVideoSettings
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("Camera");

	FSlVideoSettings()
		:
		Brightness(4),
		Contrast(4),
		Hue(0),
		Saturation(4),
		Sharpness(3),
		Gamma(1),
		WhiteBalance(4700),
		Gain(56),
		Exposure(100),
		bAutoWhiteBalance(true),
		bAutoGainAndExposure(true),
		bDefault(false)
	{
	}

	FORCEINLINE void Load(const FString& Path)
	{
		GConfig->GetInt(
			Section,
			TEXT("Brightness"),
			Brightness,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("Contrast"),
			Contrast,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("Hue"),
			Hue,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("Saturation"),
			Saturation,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("Sharpness"),
			Sharpness,
			*Path
		);

		GConfig->GetInt(
			Section,
			TEXT("WhiteBalance"),
			WhiteBalance,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("Gain"),
			Gain,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("Gamma"),
			Gamma,
			*Path
		);

		GConfig->GetInt(
			Section,
			TEXT("Exposure"),
			Exposure,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bAutoWhiteBalance"),
			bAutoWhiteBalance,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bAutoGainAndExposure"),
			bAutoGainAndExposure,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bDefault"),
			bDefault,
			*Path
			);
	}

	FORCEINLINE void Save(const FString& Path) const
	{

		GConfig->SetInt(
			Section,
			TEXT("Brightness"),
			Brightness,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("Contrast"),
			Contrast,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("Hue"),
			Hue,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("Saturation"),
			Saturation,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("Sharpness"),
			Sharpness,
			*Path
		);

		GConfig->SetInt(
			Section,
			TEXT("Gamma"),
			Gamma,
			*Path
		);

		GConfig->SetInt(
			Section,
			TEXT("WhiteBalance"),
			WhiteBalance,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("Gain"),
			Gain,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("Exposure"),
			Exposure,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bAutoWhiteBalance"),
			bAutoWhiteBalance,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bAutoGainAndExposure"),
			bAutoGainAndExposure,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bDefault"),
			bDefault,
			*Path
			);
	}

	/** Brightness, default = 4 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "8"))
	int32 Brightness;

	/** Contrast, default = 4 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "8"))
	int32 Contrast;

	/** Hue, default = 0 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "11"))
	int32 Hue;

	/** Saturation, default = 4 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "8"))
	int32 Saturation;

	/** Saturation, default = 3 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "8"))
	int32 Sharpness;

	/** Gamma, default = 3 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1", ClampMax = "9"))
	int32 Gamma;
	
	/** WhiteBalance */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "2800", ClampMax = "6500"))
	int32 WhiteBalance;

	/** Gain */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "100"))
	int32 Gain;

	/** Exposure */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "100"))
	int32 Exposure;

	/** Automatic white balance, default = true */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAutoWhiteBalance;

	/** Automatic gain and exposure, default = true */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAutoGainAndExposure;

	/** True to reset to default */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDefault;
};

/*
 * SDK runtime parameters
 * see sl::RuntimeParameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlRuntimeParameters
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("Runtime");

	FSlRuntimeParameters()
		:
		SensingMode(ESlSensingMode::SM_Fill),
		bEnableDepth(true),
		ConfidenceThreshold(100),
		TextureConfidenceThreshold(100),
		ReferenceFrame(ESlReferenceFrame::RF_World),
		bRemoveSaturatedAreas(true)
	{
	}

	FORCEINLINE void Load(const FString& Path)
	{
		int32 ConfigSensingMode;
		GConfig->GetInt(
			Section,
			TEXT("SensingMode"),
			ConfigSensingMode,
			*Path
			);
		SensingMode = (ESlSensingMode)ConfigSensingMode;

		GConfig->GetBool(
			Section,
			TEXT("bEnableDepth"),
			bEnableDepth,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("ConfidenceThreshold"),
			ConfidenceThreshold,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("TextureConfidenceThreshold"),
			TextureConfidenceThreshold,
			*Path
		);

		int32 ConfigReferenceFrame;
		GConfig->GetInt(
			Section,
			TEXT("ReferenceFrame"),
			ConfigReferenceFrame,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bRemoveSaturatedAreas"),
			bRemoveSaturatedAreas,
			*Path
		);
		ReferenceFrame = (ESlReferenceFrame)ConfigReferenceFrame;
	}

	FORCEINLINE void Save(const FString& Path) const
	{
		GConfig->SetInt(
			Section,
			TEXT("SensingMode"),
			static_cast<int32>(SensingMode),
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bEnableDepth"),
			bEnableDepth,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("ConfidenceThreshold"),
			ConfidenceThreshold,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("TextureConfidenceThreshold"),
			TextureConfidenceThreshold,
			*Path
		);

		GConfig->SetInt(
			Section,
			TEXT("ReferenceFrame"),
			static_cast<int32>(ReferenceFrame),
			*Path
		);

		GConfig->SetBool(
			Section,
			TEXT("bRemoveSaturatedAreas"),
			bRemoveSaturatedAreas,
			*Path
		);
	}

	/** Sensing mode */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlSensingMode SensingMode;

	/** Enable depth (need to be true if tracking enabled) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableDepth;

	/** Threshold to reject depth values based on their confidence. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConfidenceThreshold;

	/**Threshold to reject depth values based on their texture confidence.. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TextureConfidenceThreshold;

	/** Reference frame */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlReferenceFrame ReferenceFrame;

	/** Remove saturated areas */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRemoveSaturatedAreas;
};

/*
 * SDK timestamp
 * Only holding the timestamp
 * see sl::timeStamp
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlTimestamp
{
	GENERATED_BODY()

	FSlTimestamp()
		:
		timestamp((sl::Timestamp)0)
	{
	}

	FSlTimestamp(sl::Timestamp tstamp)
		:
		timestamp(tstamp)
	{
	}

	FSlTimestamp& operator=(sl::Timestamp NewTimestamp)
	{
		timestamp = NewTimestamp;
		return *this;
	}

	FString ToString() const
	{
		return FString::Printf(TEXT("%llu"), timestamp.data_ns);
	}

	/** Underlying timestamp */
	sl::Timestamp timestamp;
};

/*
 * SDK recording parameters
 * see sl::RecordingParameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlRecordingParameters
{
	GENERATED_BODY()

	FSlRecordingParameters():
		VideoFilename(""),
		CompressionMode(ESlSVOCompressionMode::SCM_H264),
		TargetFramerate(0),
		Bitrate(0),
		bTranscodeStreamingInput(false)
	{}

	FORCEINLINE void Load(const FString& Path)
	{
		int32 ConfigCompressionMode;
		GConfig->GetInt(
			Section,
			TEXT("CompressionMode"),
			ConfigCompressionMode,
			*Path
		);
		CompressionMode = (ESlSVOCompressionMode)ConfigCompressionMode;

		GConfig->GetString(
			Section,
			TEXT("VideoFilename"),
			VideoFilename,
			*Path
		);

		GConfig->GetInt(
			Section,
			TEXT("TargetFramerate"),
			TargetFramerate,
			*Path
		);

		GConfig->GetInt(
			Section,
			TEXT("Bitrate"),
			Bitrate,
			*Path
		);

		GConfig->GetBool(
			Section,
			TEXT("bTranscodeStreamingInput"),
			bTranscodeStreamingInput,
			*Path
		);
	}

	FORCEINLINE void Save(const FString& Path) const
	{
		GConfig->SetInt(
			Section,
			TEXT("CompressionMode"),
			static_cast<int32>(CompressionMode),
			*Path
		);

		GConfig->SetString(
			Section,
			TEXT("VideoFilename"),
			*VideoFilename,
			*Path
		);

		GConfig->SetInt(
			Section,
			TEXT("TargetFramerate"),
			TargetFramerate,
			*Path
		);

		GConfig->SetInt(
			Section,
			TEXT("Bitrate"),
			Bitrate,
			*Path
		);

		GConfig->SetBool(
			Section,
			TEXT("bTranscodeStreamingInput"),
			bTranscodeStreamingInput,
			*Path
		);

	}

	const TCHAR* Section = TEXT("Recording");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VideoFilename;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlSVOCompressionMode CompressionMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TargetFramerate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Bitrate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTranscodeStreamingInput;

	/** True to loop when SVO playback enabled */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 bLoop : 1;
};

/*
 * SDK tracking parameters
 * see sl::TrackingParameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlPositionalTrackingParameters
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("Tracking");

	FSlPositionalTrackingParameters()
		:
		Location(FVector::ZeroVector),
		Rotation(FRotator::ZeroRotator),
		bEnableTracking(true),
		bEnableAreaMemory(false),
		bEnablePoseSmoothing(true),
		bSetFloorAsOrigin(true),
		AreaFilePath(""),
		bEnableImuFusion(true),
		bSetAsStatic(false),
		DepthMinRange(-1),
		SensorsWorld(ESlSensorWorld::SW_ImuGravity),
		TrackingType(ETrackingType::TrT_ZED)
	{
	}

	FORCEINLINE void Load(const FString& Path)
	{
		GConfig->GetString(
			Section,
			TEXT("AreaFilePath"),
			AreaFilePath,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bEnableTracking"),
			bEnableTracking,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bEnableAreaMemory"),
			bEnableAreaMemory,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bEnablePoseSmoothing"),
			bEnablePoseSmoothing,
			*Path
		);

		GConfig->GetFloat(
			Section,
			TEXT("DepthMinRange"),
			DepthMinRange,
			*Path
		);

		GConfig->GetVector(
			Section,
			TEXT("Location"),
			Location,
			*Path
			);

		GConfig->GetRotator(
			Section,
			TEXT("Rotation"),
			Rotation,
			*Path
			);

		int32 ConfigTrackingType;
		GConfig->GetInt(
			Section,
			TEXT("TrackingType"),
			ConfigTrackingType,
			*Path
		);
		TrackingType = (ETrackingType)ConfigTrackingType;
	}

	FORCEINLINE void Save(const FString& Path) const
	{
		GConfig->SetString(
			Section,
			TEXT("AreaFilePath"),
			*AreaFilePath,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bEnableTracking"),
			bEnableTracking,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bEnableAreaMemory"),
			bEnableAreaMemory,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bEnablePoseSmoothing"),
			bEnablePoseSmoothing,
			*Path
		);

		GConfig->SetFloat(
			Section,
			TEXT("DepthMinRange"),
			DepthMinRange,
			*Path
		);

		GConfig->SetVector(
			Section,
			TEXT("Location"),
			Location,
			*Path
			);

		GConfig->SetRotator(
			Section,
			TEXT("Rotation"),
			Rotation,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("TrackingType"),
			static_cast<int32>(TrackingType),
			*Path
		);
	}

	/*
	 * Initial position. 
	 * If using HMD tracking origin, this is the HMD location.
	 * If not using HMD tracking origin, this is an offset from origin added to the tracking.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Location;

	/*
	 * Initial rotation.
	 * If using HMD tracking origin, this is the HMD rotation.
	 * If not using HMD tracking origin, this is an offset from origin added to the tracking.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Rotation;

	/** Enable positional tracking */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Tracking"))
	bool bEnableTracking;

	/** Enable area localization */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Area Memory"))
	bool bEnableAreaMemory;

	/** Enable smooth pose */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Pose smoothing"))
	bool bEnablePoseSmoothing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSetFloorAsOrigin;

	/** Path to the area file */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AreaFilePath;

	/* This setting allows you to enable or disable IMU fusion. When set to false, only the optical odometry will be used. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableImuFusion;

	/* This setting allows you define the camera as static.If true, it will not move in the environment. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSetAsStatic;

	/* This setting allows you to change the minimum depth used by the SDK for Positional Tracking. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DepthMinRange;
	/**
	 *This setting allows you to set the odometry world using sensors data. For example, if IMU world is chosen, the initial_world_transform
	 * will be aligned with IMU gravity by keeping user's yaw.
	 * default : IMU_GRAVITY
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlSensorWorld SensorsWorld;

	/** Tracking type 
	* Allow to chose which tracking is selected for the pawn.
	* ZED : Zed tracking only
	* HMD : Hmd tracking only
	* Mixte : Zed Imu rotations and Hmd translations
	*/
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETrackingType TrackingType;
};

/*
 * SDK pose
 * see Sl::Pose
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlPose
{
	GENERATED_BODY()

	FSlPose()
		:
		Transform(FTransform::Identity),
		Timestamp((sl::Timestamp)0),
		Confidence(0),
		bValid(false)
	{
	}

	/** Translation and rotation */
	FTransform Transform;

	/** Timestamp of the pose. This timestamp should be compared with the camera timestamp for synchronization. */
	FSlTimestamp Timestamp;

	/** 
	 * Confidence/Quality of the pose estimation for the target frame.
	 * A confidence metric of the tracking [0-100], 0 means that the tracking is lost, 100 means that the tracking can be fully trusted.
	 */
	int Confidence;

	/** Indicates if tracking is activated or not. You should check that first if something wrong. */
	bool bValid;
};

/*
 * SDK IMU data
 * see Sl::IMUData
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlIMUData : public FSlPose
{
	GENERATED_BODY()

	FSlIMUData()
		:
		FSlPose(),
		OrientationCovariance(FMatrix::Identity),
		AngularVelocity(FVector::ZeroVector),
		LinearAcceleration(FVector::ZeroVector),
		AngularVelocityConvariance(FMatrix::Identity),
		LinearAccelerationConvariance(FMatrix::Identity)
	{
	}
	/** Covariance matrix for orientation (x,y,z axes) */
	FMatrix OrientationCovariance;

	/** Vector for angular velocity of the IMU, given in deg/s */
	FVector AngularVelocity;

	/** Vector for linear acceleration of the IMU, given in m/s^2 */
	FVector LinearAcceleration;

	/** Covariance matrix for the angular velocity */
	FMatrix AngularVelocityConvariance;

	/** Covariance matrix for the linear acceleration */
	FMatrix LinearAccelerationConvariance;
};

/*
 * SDK init parameters
 * see sl::InitParameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlInitParameters
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("Init");

	FSlInitParameters()
		:
		Resolution(ESlResolution::R_HD1080),
		FPS(30),
		VerticalFlipImage(ESlFlipMode::FP_AUTO),
		bDisableSelfCalibration(false),
		bEnableRightSideMeasure(false),
		bRealTime(false),
		DepthMode(ESlDepthMode::DM_Ultra),
		DepthMinimumDistance(10.0f),
		DepthMaximumDistance(4000.0f),
		Unit(ESlUnit::DU_Centimeter),
		CoordinateSystem(ESlCoordinateSystem::CS_Cartesian),
		GPUID(-1.0f),
		bVerbose(false),
		VerboseFilePath(""),
		InputType(ESlInputType::IT_USB),
		SvoPath(""),
		StreamIP(""),
		StreamPort(30000),
		DepthStabilization(1),
		OptionalSettingPath(""),
		OptionalOpencvCalibrationFile(""),
		bSensorsRequired(false),
		bEnableImageEnhancement(true),
		OpenTimeoutSec(5.0f),
		bLoop(false)
	{
	}

	FORCEINLINE void Load(const FString& Path)
	{
		int32 ConfigDepthMode;
		GConfig->GetInt(
			Section,
			TEXT("DepthMode"),
			ConfigDepthMode,
			*Path
			);
		DepthMode = (ESlDepthMode)ConfigDepthMode;

		int32 ConfigUnit;
		GConfig->GetInt(
			Section,
			TEXT("Unit"),
			ConfigUnit,
			*Path
			);
		Unit = (ESlUnit)ConfigUnit;

		int32 ConfigCoordinateSystem;
		GConfig->GetInt(
			Section,
			TEXT("CoordinateSystem"),
			ConfigCoordinateSystem,
			*Path
			);
		CoordinateSystem = (ESlCoordinateSystem)ConfigCoordinateSystem;

		GConfig->GetFloat(
			Section,
			TEXT("GPUID"),
			GPUID,
			*Path
			);

		int32 inputType;
		GConfig->GetInt(
			Section,
			TEXT("InputType"),
			inputType,
			*Path
		);
		InputType = (ESlInputType)inputType;

		GConfig->GetFloat(
			Section,
			TEXT("DepthMinimumDistance"),
			DepthMinimumDistance,
			*Path
			);

		GConfig->GetFloat(
			Section,
			TEXT("DepthMaximumDistance"),
			DepthMaximumDistance,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bRealTime"),
			bRealTime,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bVerbose"),
			bVerbose,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bDisableSelfCalibration"),
			bDisableSelfCalibration,
			*Path
			);

		int32 FlipMode;
		GConfig->GetInt(
			Section,
			TEXT("VerticalFlipImage"),
			FlipMode,
			*Path
		);
		VerticalFlipImage = (ESlFlipMode)FlipMode;

		int32 ConfigResolution;
		GConfig->GetInt(
			Section,
			TEXT("Resolution"),
			ConfigResolution,
			*Path
			);
		Resolution = (ESlResolution)ConfigResolution;

		GConfig->GetInt(
			Section,
			TEXT("FPS"),
			FPS,
			*Path
			);

		GConfig->GetString(
			Section,
			TEXT("SvoPath"),
			SvoPath,
			*Path
			);

		GConfig->GetString(
			Section,
			TEXT("StreamIP"),
			StreamIP,
			*Path
		);

		GConfig->GetInt(
			Section,
			TEXT("StreamPort"),
			StreamPort,
			*Path
		);

		GConfig->GetString(
			Section,
			TEXT("VerboseFilePath"),
			VerboseFilePath,
			*Path
			);

		GConfig->GetInt(
			Section,
			TEXT("DepthStabilization"),
			DepthStabilization,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("bEnableRightSideMeasure"),
			bEnableRightSideMeasure,
			*Path
		);

		bool bConfigLoop;
		GConfig->GetBool(
			Section,
			TEXT("bLoop"),
			bConfigLoop,
			*Path
		);
		bLoop = bConfigLoop;
	}

	FORCEINLINE void Save(const FString& Path) const
	{
		GConfig->SetInt(
			Section,
			TEXT("Resolution"),
			static_cast<int32>(Resolution),
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("FPS"),
			FPS,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("InputType"),
			static_cast<int32>(InputType),
			*Path
		);

		GConfig->SetBool(
			Section,
			TEXT("bRealTime"),
			bRealTime,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("DepthMode"),
			static_cast<int32>(DepthMode),
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("Unit"),
			static_cast<int32>(Unit),
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("CoordinateSystem"),
			static_cast<int32>(CoordinateSystem),
			*Path
			);

		GConfig->SetFloat(
			Section,
			TEXT("GPUID"),
			GPUID,
			*Path
			);

		GConfig->SetFloat(
			Section,
			TEXT("DepthMinimumDistance"),
			DepthMinimumDistance,
			*Path
			);

		GConfig->SetFloat(
			Section,
			TEXT("DepthMaximumDistance"),
			DepthMaximumDistance,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bVerbose"),
			bVerbose,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bDisableSelfCalibration"),
			bDisableSelfCalibration,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("VerticalFlipImage"),
			static_cast<int32>(VerticalFlipImage),
			*Path
		);

		GConfig->SetString(
			Section,
			TEXT("StreamIP"),
			*StreamIP,
			*Path
		);

		GConfig->SetInt(
			Section,
			TEXT("StreamPort"),
			StreamPort,
			*Path
		);

		GConfig->SetString(
			Section,
			TEXT("SvoPath"),
			*SvoPath,
			*Path
			);

		GConfig->SetString(
			Section,
			TEXT("VerboseFilePath"),
			*VerboseFilePath,
			*Path
			);

		GConfig->SetInt(
			Section,
			TEXT("DepthStabilization"),
			DepthStabilization,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("bEnableRightSideMeasure"),
			bEnableRightSideMeasure,
			*Path
		);

		GConfig->SetBool(
			Section,
			TEXT("bLoop"),
			bLoop,
			*Path
		);
	}

	/** Input type used in the ZED SDK */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlInputType InputType;

	/** Path to a SVO file if inputType is set to SVO */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SvoPath;

	/** True to loop when SVO playback enabled */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 bLoop : 1;

	/** IP of the sender camera if inputType is set to Stream */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StreamIP;

	/** Port of the sender camera if inputType is set to Stream */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StreamPort;

	/** Resolution of the camera (720p if used with HMD) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlResolution Resolution;

	/** Capture fps of the camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FPS;

	/** Disparity */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlDepthMode DepthMode;

	/** Verbose file path */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VerboseFilePath;

	/** Minimum distance for depth */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DepthMinimumDistance;

	/** Maximum distance for depth */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DepthMaximumDistance;

	/** Device selected */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GPUID;

	/** Unit */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlUnit Unit;

	/** Coordinate system */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlCoordinateSystem CoordinateSystem;

	/** If true, skip some SVO frame if computation time is too long */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRealTime;

	/** Verbose ZED */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bVerbose;

	/** Disable self calibration */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDisableSelfCalibration;

	/** Vertical flip */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlFlipMode VerticalFlipImage;

	/** Enable right side measure */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableRightSideMeasure;

	/**Regions of the generated depth map can oscillate from one frame to another.These oscillations result from a lack of texture(too homogeneous) on an objectand by image noise.
		\n This parameter control a stabilization filter that reduces these oscillations.In the range[0 - 100], 0 is disable(raw depth), smoothness is linear from 1 to 100.
		\n default: 1
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DepthStabilization;

	/* Set the optional path where the SDK has to search for the settings file (SN<XXXX>.conf file). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OptionalSettingPath;

	/* Set an optional file path where the SDK can find a file containing the calibration information of the camera computed by OpenCV. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OptionalOpencvCalibrationFile;

	/* Force the motion sensors opening of the ZED 2 / ZED-M to open the camera. default : false.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSensorsRequired;

	/* Enable or Disable the Enhanced Contrast Technology, to improve image quality. default : true. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableImageEnhancement;

	/* Define a timeout in seconds after which an error is reported if the open() command fails. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OpenTimeoutSec;
};

/*
* Batch parameters
*/
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBatchParameters
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("Batch");

	/* Defines if the Batch option in the object detection module is enabled.  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnable;

	/* Max retention time in seconds of a detected object. After this time, the same object will mostly have a different ID.  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float IdRetentionTime;

	/* Trajectories will be output in batch with the desired latency in seconds. During this waiting time, re-identification of objects is done in the background. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Latency;

	FSlBatchParameters() :
		bEnable(false),
		IdRetentionTime(240),
		Latency(2.0f)
	{}
};

/*
* Object Detection parameters
*/
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlObjectDetectionParameters
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("ObjectDetection");

	/* Defines if the object detection is synchronized to the image or runs in a separate thread.	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bImageSync;

	/* Defines if the object detection will track objects across images flow.	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableTracking;

	/* Defines if the mask object will be computed. 	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableMaskOutput;

	/* Enable human pose estimation with skeleton keypoints output. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlDetectionModel DetectionModel;

	/* Defines if the body fitting will be applied.  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableBodyFitting;

	/* Defines the body format outputed by the sdk when retrieveObjects is called. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlBodyFormat BodyFormat;
	
	/* Defines a upper depth range for detections. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxRange;

	/* Batching system parameters. Batching system (introduced in 3.5) performs short-term re-identification with deep learning and trajectories filtering. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlBatchParameters BatchParameters;
	 /* Defines the filtering mode that should be applied to raw detections. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectFilteringMode FilteringMode;

	/*When an object is not detected anymore, the SDK will predict its positions during a short period of time before switching its state to SEARCHING.
	/* Defines the duration of this prediction.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PredictionTimeout_s;

	FSlObjectDetectionParameters() :
		bImageSync(true),
		bEnableTracking(true),
		bEnableMaskOutput(false),
		DetectionModel(ESlDetectionModel::DM_MultiClassBox),
		bEnableBodyFitting(true),
		BodyFormat(ESlBodyFormat::BF_POSE_34),
		MaxRange(-1.0f),
		BatchParameters(FSlBatchParameters()),
		FilteringMode(ESlObjectFilteringMode::OFM_NMS3D),
		PredictionTimeout_s(0.2f)
	{}
};

/*
* Object Detection parameters
*/
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlObjectDetectionRuntimeParameters
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("ObjectDetectionRuntime");

	/* Defines the confidence threshold: interval between 1 and 99. A confidence of 1 meaning a low threshold, more uncertain objects and 99 very few but very precise objects.  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DetectionConfidenceThreshold;

	/* Select which object types to detect and track. By default all classes are tracked. Fewer object types can slightly speed up the process, since every objects are tracked. Only the selected classes in the vector will be output.  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int>	ObjectClassFilter;

	/* Defines a detection threshold for each classes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, float> ObjectClassDetectionConfidenceThreshold;

	/**
	\brief Defines the minimum keypoints threshold.
	 * the SDK will outputs skeletons with more keypoints than this threshold
	 * it is useful for example to remove unstable fitting results when a skeleton is partially occluded
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinimumKeypointsThreshold;

	FSlObjectDetectionRuntimeParameters() :
		DetectionConfidenceThreshold(60.0f),
		MinimumKeypointsThreshold(5)
	{
		ObjectClassFilter = TArray<int>();
		ObjectClassFilter.Init(0, (int)SL_OBJECT_CLASS_LAST);

		ObjectClassDetectionConfidenceThreshold = TMap<int, float>();

		for (int i = 0; i < (int)SL_OBJECT_CLASS_LAST; i++) {
			ObjectClassDetectionConfidenceThreshold.Add(i, 60.0f);
		}
	}
};

USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlObjectData
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("ObjectData");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UniqueObjectId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RawLabel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectClass Label;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectSubClass Sublabel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectTrackingState TrackingState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectActionState ActionState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> PositionCovariance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> BoundingBox2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlMat Mask;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Confidence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> BoundingBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Dimensions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> Keypoint2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Keypoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> HeadBoundingBox2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> HeadBoundingBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HeadPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> KeypointConfidence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> LocalPositionPerJoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuat> LocalOrientationPerJoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FQuat GlobalRootOrientation;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<TPair<FVector, FVector>> BodyBones; TODO : Implement and fill with the positions of the end of the bones.
};

USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlObjects
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("Objects");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlTimestamp Timestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSlObjectData> ObjectsList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsNew;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsTracked;
};


/*
 * Anti drift parameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlAntiDriftParameters
{
	GENERATED_BODY()
		
	const TCHAR* Section = TEXT("HMD");

	FSlAntiDriftParameters()
		:
		CalibrationTransform(FTransform(FQuat::Identity, FVector(13.5, -3.15, 0)))
	{
	}

	FORCEINLINE void Load(const FString& Path)
	{
		FVector HMDToZedVector;
		GConfig->GetVector(
			Section,
			TEXT("HMDToZedVector"),
			HMDToZedVector,
			*Path
			);

		FRotator HMDToZedRotator;
		GConfig->GetRotator(
			Section,
			TEXT("HMDToZedRotator"),
			HMDToZedRotator,
			*Path
			);
		CalibrationTransform = FTransform(HMDToZedRotator, HMDToZedVector);
	}

	FORCEINLINE void Save(const FString& Path) const
	{
		GConfig->SetVector(
			Section,
			TEXT("HMDToZedVector"),
			CalibrationTransform.GetLocation(),
			*Path
			);

		GConfig->SetRotator(
			Section,
			TEXT("HMDToZedRotator"),
			CalibrationTransform.Rotator(),
			*Path
			);
	}

	/** Zed to HMD offset */
	UPROPERTY(BlueprintReadWrite)
	FTransform CalibrationTransform;
};

/*
 * Rendering parameters
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlRenderingParameters
{
	GENERATED_BODY()
		
	const TCHAR* Section = TEXT("Rendering");

	FSlRenderingParameters()
		:
		PerceptionDistance(100.0f),
		SRemapEnable(false),
		ThreadingMode(ESlThreadingMode::TM_MultiThreaded)
	{}

	FORCEINLINE void Load(const FString& Path)
	{
		GConfig->GetFloat(
			Section,
			TEXT("PerceptionDistance"),
			PerceptionDistance,
			*Path
			);

		GConfig->GetBool(
			Section,
			TEXT("SRemapEnable"),
			SRemapEnable,
			*Path
		);

		int32 ConfigThreadingMode;
		GConfig->GetInt(
			Section,
			TEXT("ThreadingMode"),
			ConfigThreadingMode,
			*Path
			);
		ThreadingMode = static_cast<ESlThreadingMode>(ConfigThreadingMode);
	}

	FORCEINLINE void Save(const FString& Path) const
	{
		GConfig->SetFloat(
			Section,
			TEXT("PerceptionDistance"),
			PerceptionDistance,
			*Path
			);

		GConfig->SetBool(
			Section,
			TEXT("SRemapEnable"),
			SRemapEnable,
			*Path
		);

		GConfig->SetInt(
			Section,
			TEXT("ThreadingMode"),
			static_cast<int32>(ThreadingMode),
			*Path
			);
	}

	/** Distance in cm at which real object perfectly match their real size, between 75 and 300. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "75", ClampMax = "3000"))
	float PerceptionDistance;

	/** ! Experimental ! : enable SRemap. */
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SRemapEnable;

	/** Threading mode of the Grab. Multithreading is recommended for better performance. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlThreadingMode ThreadingMode;
};

/** Environmental lighting settings */
USTRUCT(BlueprintType)
struct FEnvironmentalLightingSettings
{
	GENERATED_USTRUCT_BODY()

	/** Image exposure */
	UPROPERTY(BlueprintReadOnly, Category = Exposure)
	float Exposure;

	FEnvironmentalLightingSettings()
		:
		Exposure(1)
	{
	}
};
