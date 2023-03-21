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
	DM_Quality		     	 UMETA(DisplayName = "Quality"),
	//DM_NeuralFast			 UMETA(DisplayName = "NeuralFast"),
	DM_Ultra				 UMETA(DisplayName = "Ultra"),
	DM_Neural				 UMETA(DisplayName = "Neural")
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
	IT_GMSL				 UMETA(DisplayName = "GMSL")
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
	EC_CameraRebooting  = 255		 UMETA(DisplayName = "Camera rebooting"),
 	EC_Success		    = 0			 UMETA(DisplayName = "Success"),
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
	EC_EndOfSVOFile                  UMETA(DisplayName = "End of SVO file reached"),
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
	M_ZedX					UMETA(DisplayName = "ZED X"),
	M_ZedXM					UMETA(DisplayName = "ZED X Mini"),
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
enum class ESlObjectDetectionModel : uint8
{
	ODM_MultiClassBoxFast			UMETA(DisplayName = "Multi class box fast"),
	ODM_MultiClassBoxMedium		    UMETA(DisplayName = "Multi class box medium"),
	ODM_MultiClassBoxAccurate		UMETA(DisplayName = "Multi class box accurate"),
	ODM_PersonHeadBoxFast			UMETA(DisplayName = "Person head box fast"),
	ODM_PersonHeadAccurateBox		UMETA(DisplayName = "Person head accurate box"),
	ODM_CustomBoxObjects			UMETA(DisplayName = "Custom box objects"),
};

/*
* List of available models for body tracking.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBodyTrackingModel : uint8
{
	BTM_HumanBodyFast			UMETA(DisplayName = "Human body fast"),
	BTM_HumanBodyMedium			UMETA(DisplayName = "Human body medium"),
	BTM_HumanBodyAccurate		UMETA(DisplayName = "Human body accurate")

};

UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlAIModels : uint8
{
	AIM_MultiClassFastDetection		    UMETA(DisplayName = "Multi class fast Detection"),
	AIM_MultiClassMediumDetection		UMETA(DisplayName = "Multi class medium Detection"),
	AIM_MultiClassAccurateDetection		UMETA(DisplayName = "Multi class accurate Detection"),
	AIM_HumanBodyFastDetection			UMETA(DisplayName = "Human body fast Detection"),
	AIM_HumanBodyMediumDetection		UMETA(DisplayName = "Human body medium Detection"),
	AIM_HumanBodyAccurateDetection		UMETA(DisplayName = "Human body accurate Detection"),
	AIM_HumanBody38FastDetection		UMETA(DisplayName = "Human body 38 fast Detection"),
	AIM_HumanBody38MediumDetection		UMETA(DisplayName = "Human body 38 medium Detection"),
	AIM_HumanBody38AccurateDetection	UMETA(DisplayName = "Human body 38 accurate Detection"),
	AIM_HumanBody70FastDetection		UMETA(DisplayName = "Human body 70 fast Detection"),
	AIM_HumanBody70MediumDetection		UMETA(DisplayName = "Human body 70 medium Detection"),
	AIM_HumanBody70AccurateDetection	UMETA(DisplayName = "Human body 70 accurate Detection"),
	AIM_PersonHeadFastDetection			UMETA(DisplayName = "Person head fast Detection"),
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
	BF_BODY_18    UMETA(DisplayName = "Body 18"),
	BF_BODY_34    UMETA(DisplayName = "Body 34"),
	BF_BODY_38    UMETA(DisplayName = "Body 38"),
	BF_BODY_70	  UMETA(DisplayName = "Body 70")
};

/*
* List of supported skeleton body model.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBodyKeypointsSelection : uint8
{
	BKS_FULL          UMETA(DisplayName = "Full"),
	BKS_UPPER_BODY	  UMETA(DisplayName = "Upper body"),
	//BKS_HAND	      UMETA(DisplayName = "Hand"),
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
* List of human body parts and order of SlBodyData::keypoint for BODY_FORMAT::Body_18.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBody18Parts : uint8 {
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
* List of human body parts and order of SlBodyData::keypoint for BODY_FORMAT::BODY_34.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBody34Parts : uint8 {
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
	RIGHT_HEEL = 33,
	LAST = 34
};

/*
* List of human body parts and order of SlBodyData::keypoint for BODY_FORMAT::BODY_38.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBody38Parts : uint8 {
	PELVIS = 0,
	SPINE_1 = 1,
	SPINE_2 = 2,
	SPINE_3 = 3,
	NECK = 4,
	NOSE = 5,
	LEFT_EYE = 6,
	RIGHT_EYE = 7,
	LEFT_EAR = 8,
	RIGHT_EAR = 9,
	LEFT_CLAVICLE = 10,
	RIGHT_CLAVICLE = 11,
	LEFT_SHOULDER = 12,
	RIGHT_SHOULDER = 13,
	LEFT_ELBOW = 14,
	RIGHT_ELBOW = 15,
	LEFT_WRIST = 16,
	RIGHT_WRIST = 17,
	LEFT_HIP = 18,
	RIGHT_HIP = 19,
	LEFT_KNEE = 20,
	RIGHT_KNEE = 21,
	LEFT_ANKLE = 22,
	RIGHT_ANKLE = 23,
	LEFT_BIG_TOE = 24,
	RIGHT_BIG_TOE = 25,
	LEFT_SMALL_TOE = 26,
	RIGHT_SMALL_TOE = 27,
	LEFT_HEEL = 28,
	RIGHT_HEEL = 29,
	// Hands
	LEFT_HAND_THUMB_4 = 30, // tip
	RIGHT_HAND_THUMB_4 = 31,
	LEFT_HAND_INDEX_1 = 32, // knuckle
	RIGHT_HAND_INDEX_1 = 33,
	LEFT_HAND_MIDDLE_4 = 34, // tip
	RIGHT_HAND_MIDDLE_4 = 35,
	LEFT_HAND_PINKY_1 = 36, // knuckle
	RIGHT_HAND_PINKY_1 = 37,
	LAST = 38
};

/*
* List of human body parts and order of SlBodyData::keypoint for BODY_FORMAT::BODY_70.
*/
UENUM(BlueprintType, Category = "Stereolabs|Enum")
enum class ESlBody70Parts : uint8 {
	PELVIS = 0,
	SPINE_1 = 1,
	SPINE_2 = 2,
	SPINE_3 = 3,
	NECK = 4,
	NOSE = 5,
	LEFT_EYE = 6,
	RIGHT_EYE = 7,
	LEFT_EAR = 8,
	RIGHT_EAR = 9,
	LEFT_CLAVICLE = 10,
	RIGHT_CLAVICLE = 11,
	LEFT_SHOULDER = 12,
	RIGHT_SHOULDER = 13,
	LEFT_ELBOW = 14,
	RIGHT_ELBOW = 15,
	LEFT_WRIST = 16,
	RIGHT_WRIST = 17,
	LEFT_HIP = 18,
	RIGHT_HIP = 19,
	LEFT_KNEE = 20,
	RIGHT_KNEE = 21,
	LEFT_ANKLE = 22,
	RIGHT_ANKLE = 23,
	LEFT_BIG_TOE = 24,
	RIGHT_BIG_TOE = 25,
	LEFT_SMALL_TOE = 26,
	RIGHT_SMALL_TOE = 27,
	LEFT_HEEL = 28,
	RIGHT_HEEL = 29,
	// Hands
	// Left
	LEFT_HAND_THUMB_1 = 30,
	LEFT_HAND_THUMB_2 = 31,
	LEFT_HAND_THUMB_3 = 32,
	LEFT_HAND_THUMB_4 = 33, // tip
	LEFT_HAND_INDEX_1 = 34, // knuckle
	LEFT_HAND_INDEX_2 = 35,
	LEFT_HAND_INDEX_3 = 36,
	LEFT_HAND_INDEX_4 = 37, // tip
	LEFT_HAND_MIDDLE_1 = 38,
	LEFT_HAND_MIDDLE_2 = 39,
	LEFT_HAND_MIDDLE_3 = 40,
	LEFT_HAND_MIDDLE_4 = 41,
	LEFT_HAND_RING_1 = 42,
	LEFT_HAND_RING_2 = 43,
	LEFT_HAND_RING_3 = 44,
	LEFT_HAND_RING_4 = 45,
	LEFT_HAND_PINKY_1 = 46,
	LEFT_HAND_PINKY_2 = 47,
	LEFT_HAND_PINKY_3 = 48,
	LEFT_HAND_PINKY_4 = 49,
	// Right
	RIGHT_HAND_THUMB_1 = 50,
	RIGHT_HAND_THUMB_2 = 51,
	RIGHT_HAND_THUMB_3 = 52,
	RIGHT_HAND_THUMB_4 = 53,
	RIGHT_HAND_INDEX_1 = 54,
	RIGHT_HAND_INDEX_2 = 55,
	RIGHT_HAND_INDEX_3 = 56,
	RIGHT_HAND_INDEX_4 = 57,
	RIGHT_HAND_MIDDLE_1 = 58,
	RIGHT_HAND_MIDDLE_2 = 59,
	RIGHT_HAND_MIDDLE_3 = 60,
	RIGHT_HAND_MIDDLE_4 = 61,
	RIGHT_HAND_RING_1 = 62,
	RIGHT_HAND_RING_2 = 63,
	RIGHT_HAND_RING_3 = 64,
	RIGHT_HAND_RING_4 = 65,
	RIGHT_HAND_PINKY_1 = 66,
	RIGHT_HAND_PINKY_2 = 67,
	RIGHT_HAND_PINKY_3 = 68,
	RIGHT_HAND_PINKY_4 = 69,
	LAST = 70
};


/************************************************************************/
/*							    Structs				    				*/
/************************************************************************/

/*
 * Bone descriptor, pair of ESlBodyParts
 * To be used in the correspondance array in ZEDPlayerController
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBody18Bone
{
	GENERATED_BODY()

	FSlBody18Bone()
	{}

	FSlBody18Bone(ESlBody18Parts first, ESlBody18Parts second)
	{
		FirstEnd = first;
		SecondEnd = second;
	}

	/** First end of the bone */
	UPROPERTY(BlueprintReadOnly)
	ESlBody18Parts FirstEnd;

	/** Second end of the bone */
	UPROPERTY(BlueprintReadOnly)
	ESlBody18Parts SecondEnd;
};


/*
 * Bone descriptor, pair of ESlBodyParts
 * To be used in the correspondance array in ZEDPlayerController
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBody34Bone
{
	GENERATED_BODY()

		FSlBody34Bone()
	{}

	FSlBody34Bone(ESlBody34Parts first, ESlBody34Parts second)
	{
		FirstEnd = first;
		SecondEnd = second;
	}

	/** First end of the bone */
	UPROPERTY(BlueprintReadOnly)
	ESlBody34Parts FirstEnd;

	/** Second end of the bone */
	UPROPERTY(BlueprintReadOnly)
	ESlBody34Parts SecondEnd;
};

/*
 * Bone descriptor, pair of ESlBodyParts
 * To be used in the correspondance array in ZEDPlayerController
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBody38Bone
{
	GENERATED_BODY()

		FSlBody38Bone()
	{}

	FSlBody38Bone(ESlBody38Parts first, ESlBody38Parts second)
	{
		FirstEnd = first;
		SecondEnd = second;
	}

	/** First end of the bone */
	UPROPERTY(BlueprintReadOnly)
		ESlBody38Parts FirstEnd;

	/** Second end of the bone */
	UPROPERTY(BlueprintReadOnly)
		ESlBody38Parts SecondEnd;
};

/*
 * Bone descriptor, pair of ESlBodyPartsPose70
 * To be used in the correspondance array in ZEDPlayerController
 */
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBody70Bone
{
	GENERATED_BODY()

		FSlBody70Bone()
	{}

	FSlBody70Bone(ESlBody70Parts first, ESlBody70Parts second)
	{
		FirstEnd = first;
		SecondEnd = second;
	}

	/** First end of the bone */
	UPROPERTY(BlueprintReadOnly)
		ESlBody70Parts FirstEnd;

	/** Second end of the bone */
	UPROPERTY(BlueprintReadOnly)
		ESlBody70Parts SecondEnd;
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

	/** The camera ID*/
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
		bEnableDepth(true),
		ConfidenceThreshold(95),
		TextureConfidenceThreshold(100),
		ReferenceFrame(ESlReferenceFrame::RF_World),
		bRemoveSaturatedAreas(true)
	{
	}

	FORCEINLINE void Load(const FString& Path)
	{
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
		bSetGravityAsOrigin(true),
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

	/** Set Gravity As Origin
	*This setting allows you to override 2 of the 3 rotations from initial_world_transform using the IMU gravity
	* default : true
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSetGravityAsOrigin;

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
		InputType(ESlInputType::IT_USB),
		SerialNumber(0),
		SvoPath(""),
		bLoop(false),
		StreamIP(""),
		StreamPort(30000),
		Resolution(ESlResolution::R_HD1080),
		FPS(30),
		DepthMode(ESlDepthMode::DM_Ultra),
		DepthMinimumDistance(10.0f),
		DepthMaximumDistance(4000.0f),
		GPUID(-1.0f),
		Unit(ESlUnit::DU_Centimeter),
		CoordinateSystem(ESlCoordinateSystem::CS_Cartesian),
		bRealTime(false),
		bVerbose(false),
		bDisableSelfCalibration(false),
		VerticalFlipImage(ESlFlipMode::FP_AUTO),
		bEnableRightSideMeasure(false),
		DepthStabilization(1),
		OptionalSettingPath(""),
		OptionalOpencvCalibrationFile(""),
		bSensorsRequired(false),
		bEnableImageEnhancement(true),
		OpenTimeoutSec(5.0f),
		VerboseFilePath(""),
		bAsyncGrabCameraRecovery(false)
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

		GConfig->GetInt(
			Section,
			TEXT("SerialNumber"),
			SerialNumber,
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

		GConfig->GetBool(
			Section,
			TEXT("AsyncGrabCameraRecovery"),
			bAsyncGrabCameraRecovery,
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
			TEXT("SerialNumber"),
			static_cast<int32>(SerialNumber),
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
			TEXT("bAsyncGrabCameraRecovery"),
			bAsyncGrabCameraRecovery,
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

	/* Serial number of the camera (default is 0)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SerialNumber;

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

	/**
	 Define the behavior of the automatic camera recovery during grab() function call. When async is enabled and there's an issue with the communication with the camera
	 the grab() will exit after a short period and return the ERROR_CODE::CAMERA_REBOOTING warning. The recovery will run in the background until the correct communication is restored.
	 When async_grab_camera_recovery is false, the grab() function is blocking and will return only once the camera communication is restored or the timeout is reached.
	 The default behavior is synchronous, like previous ZED SDK versions
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAsyncGrabCameraRecovery;

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

	/** Verbose file path */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString VerboseFilePath;
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
	bool bEnableSegmentation;

	/* Enable human pose estimation with skeleton keypoints output. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectDetectionModel DetectionModel;

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

	/**
	\brief Allow inference to run at a lower precision to improve runtime and memory usage,
	 * it might increase the initial optimization time and could include downloading calibration data or calibration cache and slightly reduce the accuracy
	 * \note The fp16 is automatically enabled if the GPU is compatible and provides a speed up of almost x2 and reduce memory usage by almost half, no precision loss.
	 * \note This setting allow int8 precision which can speed up by another x2 factor (compared to fp16, or x4 compared to fp32) and half the fp16 memory usage, however some accuracy can be lost.
	 * The accuracy loss should not exceed 1-2% on the compatible models.
	 * The current compatible models are all HUMAN_BODY_XXXX
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)

	bool bAllowReducedPrecisionInference;

	FSlObjectDetectionParameters() :
		bImageSync(true),
		bEnableTracking(true),
		bEnableSegmentation(false),
		DetectionModel(ESlObjectDetectionModel::ODM_MultiClassBoxFast),
		MaxRange(-1.0f),
		BatchParameters(FSlBatchParameters()),
		FilteringMode(ESlObjectFilteringMode::OFM_NMS3D),
		PredictionTimeout_s(0.2f),
		bAllowReducedPrecisionInference(false)
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

	FSlObjectDetectionRuntimeParameters() :
		DetectionConfidenceThreshold(35.0f)
	{
		ObjectClassFilter = TArray<int>();
		ObjectClassFilter.Init(0, (int)SL_OBJECT_CLASS_LAST);

		ObjectClassDetectionConfidenceThreshold = TMap<int, float>();

		for (int i = 0; i < (int)SL_OBJECT_CLASS_LAST; i++) {
			ObjectClassDetectionConfidenceThreshold.Add(i, 35.0f);
		}
	}
};

USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlObjectData
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("ObjectData");

	/* Object identification number, used as a reference when tracking the object through the frames.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	/* Unique ID to help identify and track AI detections. Can be either generated externally, or using generate_unique_id() or left empty.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UniqueObjectId;

	/* Object label, forwarded from CustomBoxObjectData when using DETECTION_MODEL::CUSTOM_BOX_OBJECTS.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RawLabel;

	/* Object category. Identify the object type.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectClass Label;

	/* Object subclass.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectSubClass Sublabel;

	/* Defines the object tracking state.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectTrackingState TrackingState;

	/* Defines the object action state.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectActionState ActionState;

	/* Defines the object 3D centroid. Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Position;

	/* Defines the object 3D velocity Defined in sl:InitParameters::UNIT / seconds, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity;

	/* the covariance matrix of the 3d position, represented by its upper triangular matrix value
	*	[p0, p1, p2]
	*	[p1, p3, p4]
	*	[p2, p4, p5]
	*	where pi is position_covariance[i]*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> PositionCovariance;

	/*2D bounding box of the person represented as four 2D points starting at the top left corner and rotation clockwise. Expressed in pixels on the original image resolution, [0,0] is the top left corner.
	*	A ------ B
	*	| Object |
	*	D ------ C
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> BoundingBox2D;

	/* Defines for the bounding_box_2d the pixels which really belong to the object (set to 255) and those of the background (set to 0).*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlMat Mask;

	/* Defines the detection confidence value of the object. From 0 to 100, a low value means the object might not be localized perfectly or the label (OBJECT_CLASS) is uncertain.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Confidence;

	/* 3D bounding box of the person represented as eight 3D points Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.
	*	  1 ------ 2
	*	 /        /|
	*	0 ------ 3 |
	*	| Object | 6
	*	|        |/
	*	4 ------ 7
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> BoundingBox;

	/* 3D object dimensions: width, height, length Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Dimensions;

	/* Bounds the head with four 2D points. Expressed in pixels on the original image resolution.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> HeadBoundingBox2D;

	/* Bounds the head with eight 3D points. Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> HeadBoundingBox;

	/* 3D head centroid. Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HeadPosition;
};

USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlObjects
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("Objects");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlTimestamp Timestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSlObjectData> ObjectList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsNew;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsTracked;
};

/*
* Body Tracking parameters
*/
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBodyTrackingParameters
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("BodyTracking");

	/* Defines if the object detection is synchronized to the image or runs in a separate thread.	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bImageSync;

	/* Defines if the object detection will track objects across images flow.	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableTracking;

	/* Defines if the mask object will be computed. 	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableSegmentation;

	/* Enable human pose estimation with skeleton keypoints output. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlBodyTrackingModel DetectionModel;

	/* Enable body fitting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableBodyFitting;

	/* Defines the body format output by the sdk when \ref retrieveBodies is called. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlBodyFormat BodyFormat;

	/* Defines the body format output by the sdk when \ref retrieveBodies is called. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlBodyKeypointsSelection BodySelection;

	/* Defines a upper depth range for detections. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxRange;

	/*When an object is not detected anymore, the SDK will predict its positions during a short period of time before switching its state to SEARCHING.
	/* Defines the duration of this prediction.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PredictionTimeout_s;
	/**
	\brief Allow inference to run at a lower precision to improve runtime and memory usage,
	 * it might increase the initial optimization time and could include downloading calibration data or calibration cache and slightly reduce the accuracy
	 * \note The fp16 is automatically enabled if the GPU is compatible and provides a speed up of almost x2 and reduce memory usage by almost half, no precision loss.
	 * \note This setting allow int8 precision which can speed up by another x2 factor (compared to fp16, or x4 compared to fp32) and half the fp16 memory usage, however some accuracy can be lost.
	 * The accuracy loss should not exceed 1-2% on the compatible models.
	 * The current compatible models are all HUMAN_BODY_XXXX
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAllowReducedPrecisionInference;

	FSlBodyTrackingParameters() :
		bImageSync(true),
		bEnableTracking(true),
		bEnableSegmentation(false),
		DetectionModel(ESlBodyTrackingModel::BTM_HumanBodyMedium),
		MaxRange(-1.0f),
		PredictionTimeout_s(0.2f),
		bAllowReducedPrecisionInference(false),
		BodySelection(ESlBodyKeypointsSelection::BKS_FULL),
		BodyFormat(ESlBodyFormat::BF_BODY_38),
		bEnableBodyFitting(true)
	{}
};

/*
* Object Detection parameters
*/
USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBodyTrackingRuntimeParameters
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("BodyTrackingRuntime");

	/* Defines the confidence threshold: interval between 1 and 99. A confidence of 1 meaning a low threshold, more uncertain objects and 99 very few but very precise objects.  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DetectionConfidenceThreshold;

	/* the SDK will outputs skeleton with more detected keypoints than this threshold*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinimumKeypointsThreshold;

	FSlBodyTrackingRuntimeParameters():
		DetectionConfidenceThreshold(20.0f),
		MinimumKeypointsThreshold(-1)
	{}
};


USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBodyData
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("BodyData");

	/* Object identification number, used as a reference when tracking the object through the frames.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Id;

	/* Unique ID to help identify and track AI detections. Can be either generated externally, or using generate_unique_id() or left empty.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UniqueObjectId;

	/* Defines the object tracking state.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectTrackingState TrackingState;

	/* Defines the object action state.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESlObjectActionState ActionState;

	/* Defines the object 3D centroid. Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Position;

	/* Defines the object 3D velocity Defined in sl:InitParameters::UNIT / seconds, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity;

	/* the covariance matrix of the 3d position, represented by its upper triangular matrix value
	*	[p0, p1, p2]
	*	[p1, p3, p4]
	*	[p2, p4, p5]
	*	where pi is position_covariance[i]*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> PositionCovariance;

	/*2D bounding box of the person represented as four 2D points starting at the top left corner and rotation clockwise. Expressed in pixels on the original image resolution, [0,0] is the top left corner.
	*	A ------ B
	*	| Object |
	*	D ------ C
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> BoundingBox2D;

	/* Defines for the bounding_box_2d the pixels which really belong to the object (set to 255) and those of the background (set to 0).*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlMat Mask;

	/* Defines the detection confidence value of the object. From 0 to 100, a low value means the object might not be localized perfectly or the label (OBJECT_CLASS) is uncertain.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Confidence;

	/* 3D bounding box of the person represented as eight 3D points Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.
	*	  1 ------ 2
	*	 /        /|
	*	0 ------ 3 |
	*	| Object | 6
	*	|        |/
	*	4 ------ 7
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> BoundingBox;

	/* 3D object dimensions: width, height, length Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Dimensions;

	/* A set of useful points representing the human body, expressed in 2D, respect to the original image resolution.
	* We use a classic 18 points representation, the points semantic and order is given by BODY_PARTS. Expressed in pixels on the original image resolution, [0,0] is the top left corner.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> Keypoint2D;

	/* A set of useful points representing the human body, expressed in 3D. We use a classic 18 points representation, the points semantic and order is given by BODY_PARTS.
	* Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Keypoint;

	/* Bounds the head with four 2D points. Expressed in pixels on the original image resolution.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> HeadBoundingBox2D;

	/* Bounds the head with eight 3D points. Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> HeadBoundingBox;

	/* 3D head centroid. Defined in sl:InitParameters::UNIT, expressed in RuntimeParameters::measure3D_reference_frame.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HeadPosition;

	/* Per keypoint detection confidence, can not be lower than the ObjectDetectionRuntimeParameters::detection_confidence_threshold.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> KeypointConfidence;

	/* Per keypoint local position (the position of the child keypoint with respect to its parent expressed in its parent coordinate frame)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> LocalPositionPerJoint;

	/* Per keypoint local orientation.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuat> LocalOrientationPerJoint;

	/* global root orientation of the skeleton. The orientation is also represented by a quaternion with the same format as local_orientation_per_joint*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FQuat GlobalRootOrientation;

};

USTRUCT(BlueprintType, Category = "Stereolabs|Struct")
struct STEREOLABS_API FSlBodies
{
	GENERATED_BODY()

	const TCHAR* Section = TEXT("Bodies");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlTimestamp Timestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSlBodyData> BodyList;

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
		SRemapEnable(false)
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
	}

	/** Distance in cm at which real object perfectly match their real size, between 75 and 300. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "75", ClampMax = "3000"))
	float PerceptionDistance;

	/** ! Experimental ! : enable SRemap. */
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SRemapEnable;
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
