#ifndef __TYPES_C_H__
#define __TYPES_C_H__

/**
 * @file
 * */

#define MAX_FUSED_CAMERAS 20
#define WITH_OBJECT_DETECTION 1
#ifdef WITH_UNLIMITED_CAMERA
#define MAX_CAMERA_PLUGIN 20
#else
#define MAX_CAMERA_PLUGIN 4
#endif

#define MAX_SUBMESH 1000

#include <stdbool.h>

#include "cuda.h"

/**
 \brief Structure representing a quaternion.
 */
struct SL_Quaternion {
	float x; /**< \brief First component of the quaternion.*/
	float y; /**< \brief Second component of the quaternion.*/
	float z; /**< \brief Third component of the quaternion.*/
	float w; /**< \brief Forth component of the quaternion.*/
};

/**
* \brief Structure representing a generic 2-dimensional vector.
*/
struct SL_Vector2 {
	/**
	\brief Fist component of the vector.
	*/
	float x;
	/**
	\brief Second component of the vector.
	*/
	float y;
};

/**
* \brief Structure representing a generic 3-dimensional vector.
*/
struct SL_Vector3 {
	/**
	\brief Fist component of the vector.
	*/
	float x;
	/**
	\brief Second component of the vector.
	*/
	float y;
	/**
	\brief Third component of the vector.
	*/
	float z;
};

/**
* \brief Structure representing a generic 4-dimensional vector.
*/
struct SL_Vector4 {
	/**
	\brief Fist component of the vector.
	*/
	float x;
	/**
	\brief Second component of the vector.
	*/
	float y;
	/**
	\brief Third component of the vector.
	*/
	float z;
	/**
	\brief Forth component of the vector.
	*/
	float w;
};

/**
* \brief Structure representing an unsigned char 2-dimensional vector.
*/
struct SL_Uchar2 {
	/**
	\brief Fist component of the vector.
	*/
	unsigned char x;
	/**
	\brief Second component of the vector.
	*/
	unsigned char y;
};

/**
* \brief Structure representing an unsigned char 3-dimensional vector.
*/
struct SL_Uchar3 {
	/**
	\brief Fist component of the vector.
	*/
	unsigned char x;
	/**
	\brief Second component of the vector.
	*/
	unsigned char y;
	/**
	\brief Third component of the vector.
	*/
	unsigned char z;
};

/**
* \brief Structure representing an unsigned char 4-dimensional vector.
*/
struct SL_Uchar4 {
	/**
	\brief Fist component of the vector.
	*/
	unsigned char x;
	/**
	\brief Second component of the vector.
	*/
	unsigned char y;
	/**
	\brief Third component of the vector.
	*/
	unsigned char z;
	/**
	\brief Fourth component of the vector.
	*/
	unsigned char w;
};

/**
* \brief Structure representing a generic 4*4 matrix.
*/
struct SL_Matrix4f {
	/**
	\brief Array containing the values fo the 4*4 matrix.
	*/
	float p[16];
};

/**
* \brief Structure representing a generic 3*3 matrix.
*/
struct SL_Matrix3f {
	/**
	\brief Array containing the values fo the 3*3 matrix.
	*/
	float p[9];
};

/**
\brief Structure containing positional tracking data giving the position and orientation of the camera in 3D space.

Different representations of position and orientation can be retrieved, along with timestamp and pose confidence.
*/
struct SL_PoseData {
	/**
	\brief Whether the tracking is activated or not.
	\note You should check that first if something is wrong.
     */
	bool valid;
	/**
	\brief Timestamp of the \ref SL_PoseData.
	
	This timestamp should be compared with the camera timestamp for synchronization.
	*/
	unsigned long long timestamp;
	struct SL_Quaternion rotation; /**< \brief Quaternion/orientation component of the \ref SL_PoseData.*/
	struct SL_Vector3 translation; /**< \brief Translation component of the \ref SL_PoseData.*/
	/**
	\brief Confidence/quality of the pose estimation for the target frame.

	A confidence metric of the tracking [0-100] with:
	- 0: tracking is lost
	- 100: tracking can be fully trusted
     */
	int pose_confidence;
	float pose_covariance[36]; /**< \brief 6x6 pose covariance matrix of translation (the first 3 values) and rotation in so3 (the last 3 values).*/
	/**
	\brief Twist of the camera available in reference camera.

	This expresses velocity in free space, broken into its linear and angular parts.
     */
	float twist[6];
	/**
	\brief Row-major representation of the 6x6 twist covariance matrix of the camera.

	This expresses the uncertainty of the twist.
     */
	float twist_covariance[36];
};

enum UNITY_PLAN_TYPE {
	UNITY_PLAN_TYPE_FLOOR,
	UNITY_PLAN_TYPE_HIT_HORIZONTAL,
	UNITY_PLAN_TYPE_HIT_VERTICAL,
	UNITY_PLAN_TYPE_HIT_UNKNOWN
};

/**
\brief Structure representing a plane defined by a point and a normal, or a plane equation.

\note The plane measurements are expressed in reference defined by SL_RuntimeParameters.reference_frame.
*/
struct SL_PlaneData {
	int error_code; /**< \brief \ref SL_ERROR_CODE returned by the ZED SDK when the plane detection was attempted.*/
	/**
	\brief Type of the plane defined by its orientation.
	\note It is deduced from the gravity vector and is therefore not available with on \ref SL_MODEL_ZED.
	*/
	enum UNITY_PLAN_TYPE type;
	struct SL_Vector3 plane_normal; /**< \brief Plane normalized normal vector.*/
	struct SL_Vector3 plane_center; /**< \brief Plane center point.*/
	struct SL_Vector3 plane_transform_position; /**< \brief Plane position relative to the global reference frame.*/
	struct SL_Quaternion plane_transform_orientation; /**< \brief Plane orientation relative to the global reference frame.*/
	/**
	\brief Plane equation coefficients ```{a, b, c, d}```.
	\note The plane equation has the following form: ```ax + by + cz = d```.
	*/
	struct SL_Vector4 plane_equation;
	struct SL_Vector2 extents; /**< \brief Width and height of the bounding rectangle around the plane contours.*/
	int bounds_size; /**< \brief Size of \ref bounds.*/
	/**
	\brief Array of 3D points forming a polygon bounds corresponding to the current visible limits of the plane.
	*/
	struct SL_Vector3 bounds[256]; //max 256 points but only BoundsSize are actually filled
};

/**
* \brief Structure containing data from the IMU sensor.
*/
struct SL_IMUData {
	/**
	\brief Whether the IMU sensor is available in your camera.
	*/
	bool is_available;
	/**
	\brief Data acquisition timestamp in nanoseconds.
	*/
	unsigned long long timestamp_ns;
	/**
	\brief Gets the angular velocity vector of the gyroscope in deg/s.

	The value is corrected from bias, scale and misalignment.
	\note The value can be directly ingested in an IMU fusion algorithm to extract a quaternion.
	\note Not available in SVO or STREAM mode.
	*/
	struct SL_Vector3 angular_velocity;
	/**
	\brief Linear acceleration vector (3x1) of the gyroscope in m/s².
	
	The value is corrected from bias, scale and misalignment.
	\note The value can be directly ingested in an IMU fusion algorithm to extract a quaternion.
	\note Not available in SVO or STREAM mode.
	*/
	struct SL_Vector3 linear_acceleration;
	/**
	\brief Angular velocity vector of the gyroscope in deg/s (uncorrected from the IMU calibration).
	\note The value is the exact raw values from the IMU.
	\note Not available in SVO or STREAM mode.
	*/
	struct SL_Vector3 angular_velocity_unc; //uncalibrated
	/**
	\brief Linear acceleration vector of the gyroscope in m/s² (uncorrected from the IMU calibration).
	\note The value is the exact raw values from the IMU.
	\note Not available in SVO or STREAM mode.
	*/
	struct SL_Vector3 linear_acceleration_unc; //uncalibrated
	/**
	\brief Orientation from the IMU sensor.
	*/
	struct SL_Quaternion orientation;
	/**
	\brief Covariance matrix of the orientation from the IMU sensor (\ref orientation).
	*/
	struct SL_Matrix3f orientation_covariance;
	/**
	\brief Covariance matrix of the angular velocity of the gyroscope in deg/s (\ref angular_velocity).
	\note Not available in SVO or STREAM mode.
	*/
	struct SL_Matrix3f angular_velocity_convariance;
	/**
	\brief Covariance matrix of the linear acceleration of the gyroscope in m/s² (\ref linear_acceleration).
	\note Not available in SVO or STREAM mode.
	*/
	struct SL_Matrix3f linear_acceleration_convariance;
};

/**
* \brief Structure containing data from the barometer sensor.
*/
struct SL_BarometerData {
	bool is_available; /**< \brief Whether the barometer sensor is available in your camera.*/
	unsigned long long timestamp_ns; /**< \brief Data acquisition timestamp in nanoseconds.*/
	float pressure; /**< \brief Ambient air pressure in hectopascal (hPa).*/
	float relative_altitude; /**< \brief Relative altitude from first camera position (at \ref sl_open_camera() time).*/
};

/**
* \brief Lists the different states of the magnetic heading.
*/
enum SL_HEADING_STATE {
	SL_HEADING_STATE_GOOD,/**< The heading is reliable and not affected by iron interferences. */
	SL_HEADING_STATE_OK,/**< The heading is reliable, but affected by slight iron interferences. */
	SL_HEADING_STATE_NOT_GOOD,/**< The heading is not reliable because affected by strong iron interferences. */
	SL_HEADING_STATE_NOT_CALIBRATED,/**< The magnetometer has not been calibrated. */
	SL_HEADING_STATE_MAG_NOT_AVAILABLE,/**< The magnetometer sensor is not available. */
	SL_HEADING_STATE_LAST
};

/**
* \brief Structure containing data from the magnetometer sensor.
*/
struct SL_MagnetometerData {
	/**
	\brief Whether the magnetometer sensor is available in your camera.
	*/
	bool is_available;
	/**
	\brief Data acquisition timestamp in nanoseconds.
	*/
	unsigned long long  timestamp_ns;
	/**
	\brief Magnetic field local vector in microtesla (μT).
	\note To calibrate the magnetometer sensor, please use \b ZED \b Sensor \b Viewer tool after placing the camera in the final operating environment.
	*/
	struct SL_Vector3 magnetic_field_c; //calibrated
	/**
	\brief Uncalibrated magnetic field local vector in microtesla (μT).
	\note The magnetometer raw values are affected by soft and hard iron interferences.
	\note The sensor must be calibrated by placing the camera in the working environment and using \b ZED \b Sensor \b Viewer tool.
	\note Not available in SVO or STREAM mode.
	*/
	struct SL_Vector3 magnetic_field_unc; //uncalibrated
	/**
	\brief Camera heading in degrees relative to the magnetic North Pole.
	\note The magnetic North Pole has an offset with respect to the geographic North Pole, depending on the geographic position of the camera.
	\note To get a correct magnetic heading, the magnetometer sensor must be calibrated using \b ZED \b Sensor \b Viewer tool.
	*/
	float magnetic_heading;
	/**
	\brief State of \ref magnetic_heading.
	*/
	enum SL_HEADING_STATE magnetic_heading_state;
	/**
	\brief Accuracy of \ref magnetic_heading measure in the range [0.0, 1.0].
	\note A negative value means that the magnetometer must be calibrated using \b ZED \b Sensor \b Viewer tool.
	*/
	float magnetic_heading_accuracy;
	/**
	\brief Realtime data acquisition rate in hertz (Hz).
	*/
	float effective_rate;
};

/**
* \brief Structure containing data from the temperature sensors.
*/
struct SL_TemperatureData {
	float imu_temp; /**< \brief Temperature in °C at the IMU location (-100 if not available).*/
	float barometer_temp; /**< \brief Temperature in °C at the barometer location (-100 if not available).*/
	float onboard_left_temp; /**< \brief Temperature in °C next to the left image sensor (-100 if not available).*/
	float onboard_right_temp; /**< \brief Temperature in °C next to the right image sensor (-100 if not available).*/
};

/**
\brief Structure containing all sensors data (except image sensors) to be used for positional tracking or environment study.

\note Some data are not available in SVO and streaming input mode.
\note They are specified by a note "Not available in SVO or STREAM mode." in the documentation of a specific data.
\note If nothing is mentioned in the documentation, they are available in all input modes.
*/
struct SL_SensorsData {
	//IMU data
	struct SL_IMUData imu; /**< \brief IMU data.*/
	struct SL_BarometerData barometer; /**< \brief Barometer data.*/
	struct SL_MagnetometerData magnetometer; /**< \brief Magnetometer data.*/
	struct SL_TemperatureData temperature; /**< \brief Temperature data.*/

	/**
	\brief Motion state of the camera.
	- static: 0
	- moving: 1
	- falling: 2
	*/
	int camera_moving_state;

	/**
	\brief Indicates if the Sensors data has been taken during a frame capture on sensor.

	If the value is 1, the data has been taken during the same time than a frame has been acquired by the left sensor (the time precision is linked to the IMU rate, therefore 800Hz == 1.3ms).
	\n If the value is 0, the data has not been taken during a frame acquisition.
	 */
	int image_sync_trigger;
};

enum USB_DEVICE {
	USB_DEVICE_OCULUS,
	USB_DEVICE_HTC,
	USB_DEVICE_STEREOLABS
};

struct USB_product {
	int id_vendor;
	int id_product;
};

/**
\brief Lists error codes in the ZED SDK.
 */
enum SL_ERROR_CODE {
	SL_ERROR_CODE_CORRUPTED_FRAME = -2,/**< The image could be corrupted, Enabled with the parameter InitParameters::enable_image_validity_check.*/
	SL_ERROR_CODE_CAMERA_REBOOTING = -1, /**< The camera is currently rebooting.*/
	SL_ERROR_CODE_SUCCESS, /**< Standard code for successful behavior.*/
	SL_ERROR_CODE_FAILURE, /**< Standard code for unsuccessful behavior.*/
	SL_ERROR_CODE_NO_GPU_COMPATIBLE, /**< No GPU found or CUDA capability of the device is not supported.*/
	SL_ERROR_CODE_NOT_ENOUGH_GPU_MEMORY, /**< Not enough GPU memory for this depth mode. Try a different mode (such as \ref SL_DEPTH_MODE_PERFORMANCE), or increase the minimum depth value (see SL_InitParameters.depth_minimum_distance).*/
	SL_ERROR_CODE_CAMERA_NOT_DETECTED, /**< No camera was detected.*/
	SL_ERROR_CODE_SENSORS_NOT_INITIALIZED, /**< The MCU that controls the sensors module has an invalid serial number. You can try to recover it by launching the <b>ZED Diagnostic</b> tool from the command line with the option <code>-r</code>.*/
	SL_ERROR_CODE_SENSORS_NOT_AVAILABLE, /**< A camera with sensor is detected but the sensors (IMU, barometer, ...) cannot be opened. Only the \ref SL_MODEL_ZED does not has sensors. Unplug/replug is required.*/
	SL_ERROR_CODE_INVALID_RESOLUTION, /**< In case of invalid resolution parameter, such as an upsize beyond the original image size in \ref sl_retrieve_image. */
	SL_ERROR_CODE_LOW_USB_BANDWIDTH, /**< Insufficient bandwidth for the correct use of the camera. This issue can occur when you use multiple cameras or a USB 2.0 port.*/
	SL_ERROR_CODE_CALIBRATION_FILE_NOT_AVAILABLE, /**< The calibration file of the camera is not found on the host machine. Use <b>ZED Explorer</b> or <b>ZED Calibration</b> to download the factory calibration file.*/
	SL_ERROR_CODE_INVALID_CALIBRATION_FILE, /**< The calibration file is not valid. Try to download the factory calibration file or recalibrate your camera using <b>ZED Calibration</b>.*/
	SL_ERROR_CODE_INVALID_SVO_FILE, /**< The provided SVO file is not valid.*/
	SL_ERROR_CODE_SVO_RECORDING_ERROR, /**< An error occurred while trying to record an SVO (not enough free storage, invalid file, ...).*/
	SL_ERROR_CODE_SVO_UNSUPPORTED_COMPRESSION, /**< An SVO related error, occurs when NVIDIA based compression cannot be loaded.*/
	SL_ERROR_CODE_END_OF_SVOFILE_REACHED, /**< SVO end of file has been reached.\n No frame will be available until the SVO position is reset.*/
	SL_ERROR_CODE_INVALID_COORDINATE_SYSTEM, /**< The requested coordinate system is not available.*/
	SL_ERROR_CODE_INVALID_FIRMWARE, /**< The firmware of the camera is out of date. Update to the latest version.*/
	SL_ERROR_CODE_INVALID_FUNCTION_PARAMETERS, /**< Invalid parameters have been given for the function. */
	SL_ERROR_CODE_CUDA_ERROR, /**< A CUDA error has been detected in the process, in \ref sl_grab() or sl_retrieve_xxx() only. Activate verbose in \ref sl_open_camera() for more info.*/
	SL_ERROR_CODE_CAMERA_NOT_INITIALIZED, /**< The ZED SDK is not initialized. Probably a missing call to \ref sl_open_camera().*/
	SL_ERROR_CODE_NVIDIA_DRIVER_OUT_OF_DATE, /**< Your NVIDIA driver is too old and not compatible with your current CUDA version. */
	SL_ERROR_CODE_INVALID_FUNCTION_CALL, /**< The call of the function is not valid in the current context. Could be a missing call of \ref sl_open_camera(). */
	SL_ERROR_CODE_CORRUPTED_SDK_INSTALLATION, /**< The ZED SDK was not able to load its dependencies or some assets are missing. Reinstall the ZED SDK or check for missing dependencies (cuDNN, TensorRT). */
	SL_ERROR_CODE_INCOMPATIBLE_SDK_VERSION, /**< The installed ZED SDK is incompatible with the one used to compile the program. */
	SL_ERROR_CODE_INVALID_AREA_FILE, /**< The given area file does not exist. Check the path. */
	SL_ERROR_CODE_INCOMPATIBLE_AREA_FILE, /**< The area file does not contain enough data to be used or the \ref SL_DEPTH_MODE used during the creation of the area file is different from the one currently set. */
	SL_ERROR_CODE_CAMERA_FAILED_TO_SETUP, /**< Failed to open the camera at the proper resolution. Try another resolution or make sure that the UVC driver is properly installed.*/
	SL_ERROR_CODE_CAMERA_DETECTION_ISSUE, /**< Your camera can not be opened. Try replugging it to another port or flipping the USB-C connector (if there is one).*/
	SL_ERROR_CODE_CANNOT_START_CAMERA_STREAM, /**< Cannot start the camera stream. Make sure your camera is not already used by another process or blocked by firewall or antivirus.*/
	SL_ERROR_CODE_NO_GPU_DETECTED, /**<  No GPU found. CUDA is unable to list it. Can be a driver/reboot issue.*/
	SL_ERROR_CODE_PLANE_NOT_FOUND, /**< Plane not found. Either no plane is detected in the scene, at the location or corresponding to the floor, or the floor plane doesn't match the prior given.*/
	SL_ERROR_CODE_MODULE_NOT_COMPATIBLE_WITH_CAMERA, /**< The module you try to use is not compatible with your camera \ref SL_MODEL. \note \ref SL_MODEL_ZED does not has an IMU and does not support the AI modules.*/
	SL_ERROR_CODE_MOTION_SENSORS_REQUIRED, /**< The module needs the sensors to be enabled (see SL_InitParameters.sensors_required). */
	SL_ERROR_CODE_MODULE_NOT_COMPATIBLE_WITH_CUDA_VERSION, /**< The module needs a newer version of CUDA. */
};

/**
\brief Lists available resolutions.
\note The VGA resolution does not respect the 640*480 standard to better fit the camera sensor (672*376 is used).
\warning All resolutions are not available for every camera.
\warning You can find the available resolutions for each camera in <a href="https://www.stereolabs.com/docs/video/camera-controls#selecting-a-resolution">our documentation</a>.
 */
enum SL_RESOLUTION {
	SL_RESOLUTION_HD2K, /**< 2208*1242 (x2) \n Available FPS: 15*/
	SL_RESOLUTION_HD1080, /**< 1920*1080 (x2) \n Available FPS: 15, 30*/
	SL_RESOLUTION_HD1200, /**< 1920*1200 (x2) \n Available FPS: 15, 30, 60*/
	SL_RESOLUTION_HD720, /**< 1280*720 (x2) \n Available FPS: 15, 30, 60*/
	SL_RESOLUTION_SVGA, /**< 960*600 (x2) \n Available FPS: 15, 30, 60, 120*/
	SL_RESOLUTION_VGA, /**< 672*376 (x2) \n Available FPS: 15, 30, 60, 100*/
	SL_RESOLUTION_AUTO, /**< Select the resolution compatible with the camera: <ul><li>ZED X/X Mini: \ref SL_RESOLUTION_HD1200</li><li>other cameras: \ref SL_RESOLUTION_HD720</li></ul>*/
};

/**
\brief Lists available units for measures.
 */
enum SL_UNIT {
	SL_UNIT_MILLIMETER, /**< International System (1/1000 meters) */
	SL_UNIT_CENTIMETER, /**< International System (1/100 meters) */
	SL_UNIT_METER, /**< International System (1 meter) */
	SL_UNIT_INCH, /**< Imperial Unit (1/12 feet) */
	SL_UNIT_FOOT /**< Imperial Unit (1 foot) */
};

/**
\brief Lists available coordinates systems for positional tracking and 3D measures.

\image html CoordinateSystem.png
 */
enum SL_COORDINATE_SYSTEM {
	SL_COORDINATE_SYSTEM_IMAGE, /**< Standard coordinates system in computer vision.\n Used in OpenCV: see <a href="http://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html">here</a>. */
	SL_COORDINATE_SYSTEM_LEFT_HANDED_Y_UP, /**< Left-handed with Y up and Z forward.\n Used in Unity with DirectX. */
	SL_COORDINATE_SYSTEM_RIGHT_HANDED_Y_UP, /**< Right-handed with Y pointing up and Z backward.\n Used in OpenGL. */
	SL_COORDINATE_SYSTEM_RIGHT_HANDED_Z_UP, /**< Right-handed with Z pointing up and Y forward.\n Used in 3DSMax. */
	SL_COORDINATE_SYSTEM_LEFT_HANDED_Z_UP, /**< Left-handed with Z axis pointing up and X forward.\n Used in Unreal Engine. */
	SL_COORDINATE_SYSTEM_RIGHT_HANDED_Z_UP_X_FWD /**< Right-handed with Z pointing up and X forward.\n Used in ROS (REP 103). */
};

/**
\brief Lists possible camera states.
 */
enum SL_CAMERA_STATE {
	SL_CAMERA_STATE_AVAILABLE, /**< The camera can be opened by the ZED SDK. */
	SL_CAMERA_STATE_NOT_AVAILABLE, /**< The camera is already opened and unavailable. */
};

/**
\brief Lists ZED camera model.
 */
enum SL_MODEL {
	SL_MODEL_ZED, /**< ZED camera model */
	SL_MODEL_ZED_M, /**< ZED Mini (ZED M) camera model */
	SL_MODEL_ZED2, /**< ZED 2 camera model */
	SL_MODEL_ZED2i, /**< ZED 2i camera model */
	SL_MODEL_ZED_X, /**< ZED X camera model */
	SL_MODEL_ZED_XM /**< ZED X Mini (ZED XM) camera model */
};

/**
\brief Lists available memory type.
 */
enum SL_MEM
{
	SL_MEM_CPU, /**< Data will be stored on the CPU (processor side).*/
	SL_MEM_GPU  /**< Data will be stored on the GPU (graphic card side).*/
};

/**
\brief Lists available sensor types.
\note Sensors are not available on \ref SL_MODEL_ZED.
 */
enum SL_SENSOR_TYPE {
	SL_SENSOR_TYPE_ACCELEROMETER, /**< Three-axis accelerometer sensor to measure the inertial accelerations. */
	SL_SENSOR_TYPE_GYROSCOPE, /**< Three-axis gyroscope sensor to measure the angular velocities. */
	SL_SENSOR_TYPE_MAGNETOMETER, /**< Three-axis magnetometer sensor to measure the orientation of the device with respect to the Earth's magnetic field. */
	SL_SENSOR_TYPE_BAROMETER, /**< Barometer sensor to measure the atmospheric pressure. */
};

/**
\brief Lists available measurement units of onboard sensors.
\note Sensors are not available on \ref SL_MODEL_ZED.
 */
enum SL_SENSORS_UNIT {
	SL_SENSORS_UNIT_M_SEC_2, /**< m/s² (acceleration) */
	SL_SENSORS_UNIT_DEG_SEC, /**< deg/s (angular velocity) */
	SL_SENSORS_UNIT_U_T, /**< μT (magnetic field) */
	SL_SENSORS_UNIT_HPA, /**< hPa (atmospheric pressure) */
	SL_SENSORS_UNIT_CELSIUS, /**< °C (temperature) */
	SL_SENSORS_UNIT_HERTZ, /**< Hz (frequency) */
};

/**
\brief Lists possible sides on which to get data from.
*/
enum SL_SIDE {
	SL_SIDE_LEFT, /**< Left side only.*/
	SL_SIDE_RIGHT, /**< Right side only.*/
	SL_SIDE_BOTH /**< Left and right side.*/
};

/**
\brief Lists available input types in the ZED SDK.
 */
enum SL_INPUT_TYPE {
	SL_INPUT_TYPE_USB, /**< USB input mode */
	SL_INPUT_TYPE_SVO, /**<  SVO file input mode */
	SL_INPUT_TYPE_STREAM, /**< STREAM input mode (requires to use sl_enable_streaming() / sl_disable_streaming() on the "sender" side) */
	SL_INPUT_TYPE_GMSL /**< GMSL input mode (only on NVIDIA Jetson) */
};

/**
\brief Lists possible types of position matrix used to store camera path and pose.
 */
enum SL_REFERENCE_FRAME
{
	SL_REFERENCE_FRAME_WORLD,  /**< SL_PoseData will contain the motion with reference to the world frame (previously called SL_PATH).*/
	SL_REFERENCE_FRAME_CAMERA, /**< SL_PoseData will contain the motion with reference to the previous camera frame (previously called SL_POSE)*/
};

/**
\brief Lists possible time references for timestamps or data.
 */
enum SL_TIME_REFERENCE {
	SL_TIME_REFERENCE_IMAGE, /**< The requested timestamp or data will be at the time of the frame extraction. */
	SL_TIME_REFERENCE_CURRENT, /**< The requested timestamp or data will be at the time of the function call. */
};

/**
\brief Lists the different encoding types for image streaming.
 */
enum SL_STREAMING_CODEC {
	SL_STREAMING_CODEC_H264, /**< AVCHD/H264 encoding*/
	SL_STREAMING_CODEC_H265, /**< HEVC/H265 encoding*/
};

/**
\brief Lists available camera settings for the camera (contrast, hue, saturation, gain, ...).
\warning \ref SL_VIDEO_SETTINGS_GAIN and \ref SL_VIDEO_SETTINGS_EXPOSURE are linked in auto/default mode (see sl_set_camera_settings()).
 */
enum SL_VIDEO_SETTINGS
{
	SL_VIDEO_SETTINGS_BRIGHTNESS, /**< Brightness control \n Affected value should be between 0 and 8. \note Not available for ZED X/X Mini cameras.*/
	SL_VIDEO_SETTINGS_CONTRAST, /**< Contrast control \n Affected value should be between 0 and 8. \note Not available for ZED X/X Mini cameras.*/
	SL_VIDEO_SETTINGS_HUE, /**< Hue control \n Affected value should be between 0 and 11. \note Not available for ZED X/X Mini cameras.*/
	SL_VIDEO_SETTINGS_SATURATION, /**< Saturation control \n Affected value should be between 0 and 8.*/
	SL_VIDEO_SETTINGS_SHARPNESS, /**< Digital sharpening control \n Affected value should be between 0 and 8.*/
	SL_VIDEO_SETTINGS_GAMMA, /**< ISP gamma control \n Affected value should be between 1 and 9.*/
	SL_VIDEO_SETTINGS_GAIN, /**< Gain control \n Affected value should be between 0 and 100 for manual control. \note If \ref SL_VIDEO_SETTINGS_EXPOSURE is set to -1 (automatic mode), then \ref SL_VIDEO_SETTINGS_GAIN will be automatic as well.*/
	SL_VIDEO_SETTINGS_EXPOSURE, /**< Exposure control \n Affected value should be between 0 and 100 for manual control.\n The exposition is mapped linearly in a percentage of the following max values.\n Special case for <code>\ref SL_VIDEO_SETTINGS_EXPOSURE = 0</code> that corresponds to 0.17072ms.\n The conversion to milliseconds depends on the framerate: <ul><li>15fps & <code>\ref SL_VIDEO_SETTINGS_EXPOSURE = 100</code> -> 19.97ms</li><li>30fps & <code>\ref SL_VIDEO_SETTINGS_EXPOSURE = 100</code> -> 19.97ms</li><li>60fps & <code>\ref SL_VIDEO_SETTINGS_EXPOSURE = 100</code> -> 10.84072ms</li><li>100fps & <code>\ref SL_VIDEO_SETTINGS_EXPOSURE = 100</code> -> 10.106624ms</li></ul>*/
	SL_VIDEO_SETTINGS_AEC_AGC, /**< Defines if the \ref SL_VIDEO_SETTINGS_GAIN and \ref SL_VIDEO_SETTINGS_EXPOSURE are in automatic mode or not.\n Setting \ref SL_VIDEO_SETTINGS_GAIN or \ref SL_VIDEO_SETTINGS_EXPOSURE values will automatically set this value to 0.*/
	SL_VIDEO_SETTINGS_AEC_AGC_ROI, /**< Defines the region of interest for automatic exposure/gain computation.\n To be used with dedicated sl_set_roi_for_aec_agc() / sl_get_roi_for_aec_agc() functions.*/
	SL_VIDEO_SETTINGS_WHITEBALANCE_TEMPERATURE, /**< Color temperature control \n Affected value should be between 2800 and 6500 with a step of 100. \note Setting a value will automatically set \ref SL_VIDEO_SETTINGS_WHITEBALANCE_AUTO to 0.*/
	SL_VIDEO_SETTINGS_WHITEBALANCE_AUTO, /**< Defines if the white balance is in automatic mode or not.*/
	SL_VIDEO_SETTINGS_LED_STATUS, /**< Status of the front LED of the camera.\n Set to 0 to disable the light, 1 to enable the light.\n Default value is on. \note Requires camera firmware 1523 at least.*/
	SL_VIDEO_SETTINGS_EXPOSURE_TIME, /**< Real exposure time control in microseconds. \note Only available for ZED X/X Mini cameras.\note Replace \ref SL_VIDEO_SETTINGS_EXPOSURE setting.*/
	SL_VIDEO_SETTINGS_ANALOG_GAIN, /**< Real analog gain (sensor) control in mDB.\n The range is defined by Jetson DTS and by default [1000-16000]. \note Only available for ZED X/X Mini cameras.\note Replace \ref SL_VIDEO_SETTINGS_GAIN settings.*/
	SL_VIDEO_SETTINGS_DIGITAL_GAIN, /**< Real digital gain (ISP) as a factor. \n The range is defined by Jetson DTS and by default [1-256]. \note Only available for ZED X/X Mini cameras.\note Replace \ref SL_VIDEO_SETTINGS_GAIN settings.*/
	SL_VIDEO_SETTINGS_AUTO_EXPOSURE_TIME_RANGE, /**< Range of exposure auto control in microseconds.\n Used with sl_get_camera_settings_min_max().\n Min/max range between max range defined in DTS.\n By default: [28000 - <fps_time> or 19000] us.\note Only available for ZED X/X Mini cameras.*/
	SL_VIDEO_SETTINGS_AUTO_ANALOG_GAIN_RANGE, /**< Range of sensor gain in automatic control.\n Used with sl_get_camera_settings_min_max().\n Min/max range between max range defined in DTS.\n By default: [1000 - 16000] mdB. \note Only available for ZED X/X Mini cameras.*/
	SL_VIDEO_SETTINGS_AUTO_DIGITAL_GAIN_RANGE, /**< Range of digital ISP gain in automatic control.\n Used with sl_get_camera_settings_min_max().\n Min/max range between max range defined in DTS.\n By default: [1 - 256]. \note Only available for ZED X/X Mini cameras. */
	SL_VIDEO_SETTINGS_EXPOSURE_COMPENSATION, /**< Exposure-target compensation made after auto exposure.\n Reduces the overall illumination target by factor of F-stops.\n Affected value should be between 0 and 100 (mapped between [-2.0,2.0]).\n Default value is 50, i.e. no compensation applied. \note Only available for ZED X/X Mini cameras.*/
	SL_VIDEO_SETTINGS_DENOISING, /**< Level of denoising applied on both left and right images.\n Affected value should be between 0 and 100.\n Default value is 50. \note Only available for ZED X/X Mini cameras.*/
	SL_VIDEO_SETTINGS_LAST
};

const int SL_VIDEO_SETTINGS_VALUE_AUTO = -1;

/**
\brief Lists retrievable measures.
*/
enum SL_MEASURE {
	SL_MEASURE_DISPARITY, /**< Disparity map. Each pixel contains 1 float.\n Type: \ref SL_MAT_TYPE_F32_C1*/
	SL_MEASURE_DEPTH, /**< Depth map in sl::UNIT defined in SL_InitParameters::coordinate_unit. Each pixel contains 1 float.\n Type: \ref SL_MAT_TYPE_F32_C1*/
	SL_MEASURE_CONFIDENCE, /**< Certainty/confidence of the depth map. Each pixel contains 1 float.\n Type: \ref SL_MAT_TYPE_F32_C1*/
	SL_MEASURE_XYZ, /**< Point cloud. Each pixel contains 4 float (X, Y, Z, not used).\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_XYZRGBA, /**< Colored point cloud. Each pixel contains 4 float (X, Y, Z, color).\n The color should to be read as an unsigned char[4] representing the RGBA color.\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_XYZBGRA, /**< Colored point cloud. Each pixel contains 4 float (X, Y, Z, color).\n The color should to be read as an unsigned char[4] representing the BGRA color.\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_XYZARGB, /**< Colored point cloud. Each pixel contains 4 float (X, Y, Z, color).\n The color should to be read as an unsigned char[4] representing the ARGB color.\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_XYZABGR, /**< Colored point cloud. Each pixel contains 4 float (X, Y, Z, color).\n The color should to be read as an unsigned char[4] representing the ABGR color.\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_NORMALS, /**< Normal vectors map. Each pixel contains 4 float (X, Y, Z, 0).\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_DISPARITY_RIGHT, /**< Disparity map for right sensor. Each pixel contains 1 float.\n Type: \ref SL_MAT_TYPE_F32_C1*/
	SL_MEASURE_DEPTH_RIGHT, /**< Depth map for right sensor. Each pixel contains 1 float.\n Type: \ref SL_MAT_TYPE_F32_C1*/
	SL_MEASURE_XYZ_RIGHT, /**< Point cloud for right sensor. Each pixel contains 4 float (X, Y, Z, not used).\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_XYZRGBA_RIGHT, /**< Colored point cloud for right sensor. Each pixel contains 4 float (X, Y, Z, color).\n The color should to be read as an unsigned char[4] representing the RGBA color.\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_XYZBGRA_RIGHT, /**< Colored point cloud for right sensor. Each pixel contains 4 float (X, Y, Z, color).\n The color should to be read as an unsigned char[4] representing the BGRA color.\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_XYZARGB_RIGHT, /**< Colored point cloud for right sensor. Each pixel contains 4 float (X, Y, Z, color).\n The color should to be read as an unsigned char[4] representing the ARGB color.\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_XYZABGR_RIGHT, /**< Colored point cloud for right sensor. Each pixel contains 4 float (X, Y, Z, color).\n The color should to be read as an unsigned char[4] representing the ABGR color.\n Type: \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_NORMALS_RIGHT, /**< Normal vectors map for right view. Each pixel contains 4 float (X, Y, Z, 0).\n Type:  \ref SL_MAT_TYPE_F32_C4*/
	SL_MEASURE_DEPTH_U16_MM, /**< Depth map in millimeter whatever the sl::UNIT defined in SL_InitParameters::coordinate_unit.\n Invalid values are set to 0 and depth values are clamped at 65000.\n Each pixel contains 1 unsigned short.\n Type: \ref SL_MAT_TYPE_U16_C1.*/
	SL_MEASURE_DEPTH_U16_MM_RIGHT /**< Depth map in millimeter for right sensor. Each pixel contains 1 unsigned short.\n Type: \ref SL_MAT_TYPE_U16_C1.*/
};

/**
\brief Lists available views.
 */
enum SL_VIEW {
	SL_VIEW_LEFT, /**< Left BGRA image. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 */
	SL_VIEW_RIGHT, /**<  Right BGRA image. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 */
	SL_VIEW_LEFT_GRAY, /**< Left gray image. Each pixel contains 1 unsigned char.\n Type: \ref SL_MAT_TYPE_U8_C1 */
	SL_VIEW_RIGHT_GRAY, /**< Right gray image. Each pixel contains 1 unsigned char.\n Type: \ref SL_MAT_TYPE_U8_C1 */
	SL_VIEW_LEFT_UNRECTIFIED, /**< Left BGRA unrectified image. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 */
	SL_VIEW_RIGHT_UNRECTIFIED, /**< Right BGRA unrectified image. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 */
	SL_VIEW_LEFT_UNRECTIFIED_GRAY, /**< Left gray unrectified image. Each pixel contains 1 unsigned char.\n Type: \ref SL_MAT_TYPE_U8_C1 */
	SL_VIEW_RIGHT_UNRECTIFIED_GRAY, /**< Right gray unrectified image. Each pixel contains 1 unsigned char.\n Type: \ref SL_MAT_TYPE_U8_C1 */
	SL_VIEW_SIDE_BY_SIDE, /**< Left and right image (the image width is therefore doubled). Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 */
	SL_VIEW_DEPTH, /**< Color rendering of the depth. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 \note Use \ref SL_MEASURE_DEPTH with \ref sl_retrieve_measure() to get depth values.*/
	SL_VIEW_CONFIDENCE, /**< Color rendering of the depth confidence. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 \note Use \ref SL_MEASURE_CONFIDENCE with \ref sl_retrieve_measure() to get confidence values.*/
	SL_VIEW_NORMALS, /**< Color rendering of the normals. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 \note Use \ref SL_MEASURE_NORMALS with \ref sl_retrieve_measure() to get normal values.*/
	SL_VIEW_DEPTH_RIGHT, /**< Color rendering of the right depth mapped on right sensor. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 \note Use \ref SL_MEASURE_DEPTH_RIGHT with \ref sl_retrieve_measure() to get depth right values.*/
	SL_VIEW_NORMALS_RIGHT /**< Color rendering of the normals mapped on right sensor. Each pixel contains 4 unsigned char (B, G, R, A).\n Type: \ref SL_MAT_TYPE_U8_C4 \note Use \ref SL_MEASURE_NORMALS_RIGHT with \ref sl_retrieve_measure() to get normal right values.*/
};

/**
\brief Lists the different states of object tracking.
 */
enum SL_OBJECT_TRACKING_STATE
{
	SL_OBJECT_TRACKING_STATE_OFF,       /**< The tracking is not yet initialized.\n The object id is not usable. */
	SL_OBJECT_TRACKING_STATE_OK,        /**< The object is tracked. */
	SL_OBJECT_TRACKING_STATE_SEARCHING, /**< The object could not be detected in the image and is potentially occluded.\n The trajectory is estimated.*/
	SL_OBJECT_TRACKING_STATE_TERMINATE	/**< This is the last searching state of the track.\n The track will be deleted in the next sl_retrieve_objects(). */
};

/**
\brief Lists the different states of positional tracking.
 */
enum SL_POSITIONAL_TRACKING_STATE {
	SL_POSITIONAL_TRACKING_STATE_SEARCHING, /**< The camera is searching for a previously known position to locate itself.*/
	SL_POSITIONAL_TRACKING_STATE_OK, /**< The positional tracking is working normally.*/
	SL_POSITIONAL_TRACKING_STATE_OFF, /**< The positional tracking is not enabled.*/
	SL_POSITIONAL_TRACKING_STATE_FPS_TOO_LOW, /**< The effective FPS is too low to give proper results for motion tracking.\n Consider using performance parameters (\ref SL_DEPTH_MODE_PERFORMANCE, low camera resolution (\ref SL_RESOLUTION_VGA / \ref SL_RESOLUTION_SVGA or \ref SL_RESOLUTION_HD720).*/
	SL_POSITIONAL_TRACKING_STATE_SEARCHING_FLOOR_PLANE, /**< The camera is searching for the floor plane to locate itself with respect to it.\n The \ref SL_REFERENCE_FRAME_WORLD will be set afterward.*/
};

/**
\brief Lists the mode of positional tracking that can be used.
*/
enum SL_POSITIONAL_TRACKING_MODE {
	SL_POSITIONAL_TRACKING_MODE_STANDARD, /**< Default mode. Best compromise in performance and accuracy. */
	SL_POSITIONAL_TRACKING_MODE_QUALITY, /**< Improve accuracy in more challenging scenes such as outdoor repetitive patterns like extensive fields.\n Currently works best with \ref SL_DEPTH_MODE_ULTRA and requires more compute power. */
};

/**
\enum SL_REGION_OF_INTEREST_AUTO_DETECTION_STATE
\brief Lists the different states of region of interest auto detection.
 */
enum SL_REGION_OF_INTEREST_AUTO_DETECTION_STATE
{
	SL_REGION_OF_INTEREST_AUTO_DETECTION_STATE_RUNNING, /**< The region of interest auto detection is initializing.*/
	SL_REGION_OF_INTEREST_AUTO_DETECTION_STATE_READY, /**< The region of interest mask is ready, if auto_apply was enabled, the region of interest mask is being used*/
	SL_REGION_OF_INTEREST_AUTO_DETECTION_STATE_NOT_ENABLED, /**< The region of interest auto detection is not enabled*/
};


/**
\brief Lists the different states of spatial memory area export.
 */
enum SL_AREA_EXPORTING_STATE {
	SL_AREA_EXPORTING_STATE_SUCCESS, /**< The spatial memory file has been successfully created.*/
	SL_AREA_EXPORTING_STATE_RUNNING, /**< The spatial memory is currently being written.*/
	SL_AREA_EXPORTING_STATE_NOT_STARTED, /**< The spatial memory file exportation has not been called.*/
	SL_AREA_EXPORTING_STATE_FILE_EMPTY, /**< The spatial memory contains no data, the file is empty.*/
	SL_AREA_EXPORTING_STATE_FILE_ERROR, /**< The spatial memory file has not been written because of a wrong file name.*/
	SL_AREA_EXPORTING_STATE_SPATIAL_MEMORY_DISABLED, /**< The spatial memory learning is disabled. No file can be created.*/
};

/**
\brief Lists the different states of spatial mapping.
 */
enum SL_SPATIAL_MAPPING_STATE {
	SL_SPATIAL_MAPPING_STATE_INITIALIZING, /**< The spatial mapping is initializing.*/
	SL_SPATIAL_MAPPING_STATE_OK, /**< The depth and tracking data were correctly integrated in the mapping algorithm.*/
	SL_SPATIAL_MAPPING_STATE_NOT_ENOUGH_MEMORY, /**< The maximum memory dedicated to the scanning has been reached.\n The mesh will no longer be updated.*/
	SL_SPATIAL_MAPPING_STATE_NOT_ENABLED, /**< sl_enable_spatial_mapping() wasn't called or the scanning was stopped and not relaunched.*/
	SL_SPATIAL_MAPPING_STATE_FPS_TOO_LOW, /**< The effective FPS is too low to give proper results for spatial mapping.\n Consider using performance parameters (\ref SL_DEPTH_MODE_PERFORMANCE, low camera resolution (\ref SL_RESOLUTION_VGA / \ref SL_RESOLUTION_SVGA or \ref SL_RESOLUTION_HD720).*/
};

/**
\brief Lists the types of spatial maps that can be created.
 */
enum SL_SPATIAL_MAP_TYPE {
	SL_SPATIAL_MAP_TYPE_MESH, /**< The geometry is represented by a set of vertices connected by edges and forming faces.\n No color information is available.*/
	SL_SPATIAL_MAP_TYPE_FUSED_POINT_CLOUD /**< The geometry is represented by a set of 3D colored points.*/
};

/**
\brief Lists available mesh filtering intensities.
 */
enum SL_MESH_FILTER {
	SL_MESH_FILTER_LOW, /**< Clean the mesh by closing small holes and removing isolated faces.*/
	SL_MESH_FILTER_MEDIUM, /**< Soft faces decimation and smoothing.*/
	SL_MESH_FILTER_HIGH, /**< Drastically reduce the number of faces and apply a soft smooth.*/
};

/**
\brief Lists available mesh file formats.
 */
enum SL_MESH_FILE_FORMAT {
	SL_MESH_FILE_FORMAT_PLY, /**< Contains only vertices and faces.*/
	SL_MESH_FILE_FORMAT_PLY_BIN, /**< Contains only vertices and faces encoded in binary.*/
	SL_MESH_FILE_FORMAT_OBJ, /**< Contains vertices, normals, faces, and texture information (if possible).*/
};

/**
\brief Lists available depth computation modes.
 */
enum SL_DEPTH_MODE {
	SL_DEPTH_MODE_NONE, /** No depth map computation.\n Only rectified stereo images will be available.*/
	SL_DEPTH_MODE_PERFORMANCE, /** Computation mode optimized for speed.*/
	SL_DEPTH_MODE_QUALITY, /**< Computation mode designed for challenging areas with untextured surfaces.*/
	//SL_DEPTH_MODE_NEURAL_FAST, /**< End to End Neural disparity estimation, requires AI module */
	SL_DEPTH_MODE_ULTRA, /**< Computation mode that favors edges and sharpness.\n Requires more GPU memory and computation power.*/
	SL_DEPTH_MODE_NEURAL /**< End to End Neural disparity estimation.\n Requires AI module. */
};

/**
\brief Lists possible flip modes of the camera.
 */
enum SL_FLIP_MODE {
	SL_FLIP_MODE_OFF, /**< No flip applied. Default behavior.*/
	SL_FLIP_MODE_ON, /**< Images and camera sensors' data are flipped useful when your camera is mounted upside down.*/
	SL_FLIP_MODE_AUTO, /**< In LIVE mode, use the camera orientation (if an IMU is available) to set the flip mode.\n In SVO mode, read the state of this enum when recorded.*/
};

/**
\brief Lists available copy operation on matrix.
 */
enum SL_COPY_TYPE
{
	SL_COPY_TYPE_CPU_CPU, /**< Copy data from CPU to CPU.*/
	SL_COPY_TYPE_CPU_GPU, /**< Copy data from CPU to GPU.*/
	SL_COPY_TYPE_GPU_GPU, /**< copy data from GPU to GPU.*/
	SL_COPY_TYPE_GPU_CPU  /**< Copy data from GPU to CPU.*/
};

/**
\brief Lists available compression modes for SVO recording.
\note \ref SL_SVO_COMPRESSION_MODE_LOSSLESS is an improvement of previous lossless compression (used in ZED Explorer), even if size may be bigger, compression time is much faster.
 */
enum SL_SVO_COMPRESSION_MODE {
	SL_SVO_COMPRESSION_MODE_LOSSLESS, /**< PNG/ZSTD (lossless) CPU based compression.\n Average size: 42% of RAW*/
	SL_SVO_COMPRESSION_MODE_H264, /**< H264 (AVCHD) GPU based compression.\n Average size: 1% of RAW \note Requires a NVIDIA GPU.*/
	SL_SVO_COMPRESSION_MODE_H265, /**<  H265 (HEVC) GPU based compression.\n Average size: 1% of RAW \note Requires a NVIDIA GPU.*/
	SL_SVO_COMPRESSION_MODE_H264_LOSSLESS, /**< H264 Lossless GPU/Hardware based compression.\n Average size: 25% of RAW \n Provides a SSIM/PSNR result (vs RAW) >= 99.9%. \note Requires a NVIDIA GPU. */
	SL_SVO_COMPRESSION_MODE_H265_LOSSLESS, /**< H265 Lossless GPU/Hardware based compression.\n Average size: 25% of RAW \n Provides a SSIM/PSNR result (vs RAW) >= 99.9%. \note Requires a NVIDIA GPU. */
};

/**
\brief Lists available matrix formats.
\note Matrix type depends on image or measure type.
\note For the dependencies, see \ref SL_VIEW and \ref SL_MEASURE.
 */
enum SL_MAT_TYPE
{
	SL_MAT_TYPE_F32_C1, /**< 1-channel matrix of float*/
	SL_MAT_TYPE_F32_C2, /**< 2-channel matrix of float*/
	SL_MAT_TYPE_F32_C3, /**< 3-channel matrix of float*/
	SL_MAT_TYPE_F32_C4, /**< 4-channel matrix of float*/
	SL_MAT_TYPE_U8_C1,  /**< 1-channel matrix of unsigned char*/
	SL_MAT_TYPE_U8_C2,  /**< 2-channel matrix of unsigned char*/
	SL_MAT_TYPE_U8_C3,  /**< 3-channel matrix of unsigned char*/
	SL_MAT_TYPE_U8_C4,  /**< 4-channel matrix of unsigned char*/
	SL_MAT_TYPE_U16_C1, /**< 1-channel matrix of unsigned short*/
	SL_MAT_TYPE_S8_C4 /**< 4-channel matrix of signed char*/
};

/**
\brief List available object subclasses.

Given as hint, when using object tracking an object can change of \ref SL_OBJECT_SUBCLASS while keeping the same \ref SL_OBJECT_CLASS
(i.e.: frame n: \ref SL_OBJECT_SUBCLASS_MOTORBIKE, frame n+1: \ref SL_OBJECT_SUBCLASS_BICYCLE).
*/
enum SL_OBJECT_SUBCLASS
{
	SL_OBJECT_SUBCLASS_PERSON,       /**< \ref SL_OBJECT_CLASS_PERSON */
	SL_OBJECT_SUBCLASS_BICYCLE,      /**< \ref SL_OBJECT_CLASS_VEHICLE */
	SL_OBJECT_SUBCLASS_CAR,          /**< \ref SL_OBJECT_CLASS_VEHICLE */
	SL_OBJECT_SUBCLASS_MOTORBIKE,    /**< \ref SL_OBJECT_CLASS_VEHICLE */
	SL_OBJECT_SUBCLASS_BUS,          /**< \ref SL_OBJECT_CLASS_VEHICLE */
	SL_OBJECT_SUBCLASS_TRUCK,        /**< \ref SL_OBJECT_CLASS_VEHICLE */
	SL_OBJECT_SUBCLASS_BOAT,         /**< \ref SL_OBJECT_CLASS_VEHICLE */
	SL_OBJECT_SUBCLASS_BACKPACK,     /**< \ref SL_OBJECT_CLASS_BAG */
	SL_OBJECT_SUBCLASS_HANDBAG,      /**< \ref SL_OBJECT_CLASS_BAG */
	SL_OBJECT_SUBCLASS_SUITCASE,     /**< \ref SL_OBJECT_CLASS_BAG */
	SL_OBJECT_SUBCLASS_BIRD,        /**< \ref SL_OBJECT_CLASS_ANIMAL */
	SL_OBJECT_SUBCLASS_CAT,         /**< \ref SL_OBJECT_CLASS_ANIMAL */
	SL_OBJECT_SUBCLASS_DOG,         /**< \ref SL_OBJECT_CLASS_ANIMAL */
	SL_OBJECT_SUBCLASS_HORSE,       /**< \ref SL_OBJECT_CLASS_ANIMAL */
	SL_OBJECT_SUBCLASS_SHEEP,       /**< \ref SL_OBJECT_CLASS_ANIMAL */
	SL_OBJECT_SUBCLASS_COW,         /**< \ref SL_OBJECT_CLASS_ANIMAL */
	SL_OBJECT_SUBCLASS_CELLPHONE,   /**< \ref SL_OBJECT_CLASS_ELECTRONICS */
	SL_OBJECT_SUBCLASS_LAPTOP,      /**< \ref SL_OBJECT_CLASS_ELECTRONICS */
	SL_OBJECT_SUBCLASS_BANANA,      /**< \ref SL_OBJECT_CLASS_FRUIT_VEGETABLE */
	SL_OBJECT_SUBCLASS_APPLE,       /**< \ref SL_OBJECT_CLASS_FRUIT_VEGETABLE */
	SL_OBJECT_SUBCLASS_ORANGE,      /**< \ref SL_OBJECT_CLASS_FRUIT_VEGETABLE */
	SL_OBJECT_SUBCLASS_CARROT,      /**< \ref SL_OBJECT_CLASS_FRUIT_VEGETABLE */
	SL_OBJECT_SUBCLASS_PERSON_HEAD, /**< \ref SL_OBJECT_CLASS_PERSON */
	SL_OBJEC_SUBCLASS_SPORTSBALL 	/**< \ref SL_OBJECT_CLASS_SPORT*/

};

/**
\brief Lists the different states of an object's actions.
 */
enum SL_OBJECT_ACTION_STATE
{
	SL_OBJECT_ACTION_STATE_IDLE,   /**< The object is staying static. */
	SL_OBJECT_ACTION_STATE_MOVING, /**< The object is moving. */
};

/**
\brief Lists available models for the object detection module.
 */
enum SL_OBJECT_DETECTION_MODEL {
	SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_FAST, /**< Any objects, bounding box based. */
	SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_MEDIUM, /**< Any objects, bounding box based, compromise between accuracy and speed. */
	SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_ACCURATE, /**< Any objects, bounding box based, more accurate but slower than the base model. */
	SL_OBJECT_DETECTION_MODEL_PERSON_HEAD_BOX_FAST, /**< Bounding box detector specialized in person heads particularly well suited for crowded environments. The person localization is also improved. */
	SL_OBJECT_DETECTION_MODEL_PERSON_HEAD_BOX_ACCURATE, /**< Bounding box detector specialized in person heads, particularly well suited for crowded environments. The person localization is also improved, more accurate but slower than the base model.*/
	SL_OBJECT_DETECTION_MODEL_CUSTOM_BOX_OBJECTS, /**< For external inference, using your own custom model and/or frameworks. This mode disables the internal inference engine, the 2D bounding box detection must be provided. */
};
/**
\brief Lists available models for the body tracking module.
*/
enum SL_BODY_TRACKING_MODEL
{
	SL_BODY_TRACKING_MODEL_HUMAN_BODY_FAST, /**< Keypoints based, specific to human skeleton, real time performance even on Jetson or low end GPU cards. */
	SL_BODY_TRACKING_MODEL_HUMAN_BODY_MEDIUM, /**< Keypoints based, specific to human skeleton, compromise between accuracy and speed. */
	SL_BODY_TRACKING_MODEL_HUMAN_BODY_ACCURATE, /**< Keypoints based, specific to human skeleton, state of the art accuracy, requires powerful GPU. */
};

/**
 \brief Lists available  AI models.
*/
enum SL_AI_MODELS {
	SL_AI_MODELS_MULTI_CLASS_DETECTION, /**< Related to \ref SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_FAST*/
	SL_AI_MODELS_MULTI_CLASS_MEDIUM_DETECTION, /**< Related to \ref SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_MEDIUM*/
	SL_AI_MODELS_MULTI_CLASS_ACCURATE_DETECTION, /**< Related to \ref SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_ACCURATE*/
	SL_AI_MODELS_HUMAN_BODY_FAST_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_FAST*/
	SL_AI_MODELS_HUMAN_BODY_MEDIUM_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_MEDIUM*/
	SL_AI_MODELS_HUMAN_BODY_ACCURATE_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_ACCURATE*/
	SL_AI_MODELS_HUMAN_BODY_38_FAST_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_FAST*/
	SL_AI_MODELS_HUMAN_BODY_38_MEDIUM_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_FAST*/
	SL_AI_MODELS_HUMAN_BODY_38_ACCURATE_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_FAST*/
	//SL_AI_MODELS_HUMAN_BODY_70_FAST_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_FAST*/
	//SL_AI_MODELS_HUMAN_BODY_70_MEDIUM_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_MEDIUM*/
	//SL_AI_MODELS_HUMAN_BODY_70_ACCURATE_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_ACCURATE*/
	SL_AI_MODELS_PERSON_HEAD_DETECTION, /**< Related to \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_FAST*/
	SL_AI_MODELS_PERSON_HEAD_ACCURATE_DETECTION, /**< Related to \ref SL_OBJECT_DETECTION_MODEL_PERSON_HEAD_BOX_ACCURATE*/
	SL_AI_MODELS_REID_ASSOCIATION, /**< Related to \ref SL_BatchParameters.enable*/
	SL_AI_MODELS_NEURAL_DEPTH, /**< Related to \ref SL_DEPTH_MODE_NEURAL*/
	SL_AI_MODELS_LAST
};

/**
\brief Lists supported bounding box preprocessing.
 */
enum SL_OBJECT_FILTERING_MODE {
	SL_OBJECT_FILTERING_MODE_NONE, /**< The ZED SDK will not apply any preprocessing to the detected objects. */
	SL_OBJECT_FILTERING_MODE_NMS_3D, /**< The ZED SDK will remove objects that are in the same 3D position as an already tracked object (independent of class id). */
	SL_OBJECT_FILTERING_MODE_NMS_3D_PER_CLASS, /**< The ZED SDK will remove objects that are in the same 3D position as an already tracked object of the same class id. */
};


/**
\brief Lists supported skeleton body models.
*/
enum SL_BODY_FORMAT
{
	/**
	 * \brief 18-keypoint model
	 * \n Basic body model
	 */
	SL_BODY_FORMAT_BODY_18,
	/**
	 * \brief 34-keypoint model
	 * \note Requires body fitting enabled.
	 */
	SL_BODY_FORMAT_BODY_34,
	/**
	 * \brief 38-keypoint model
	 * \n Including simplified face, hands and feet.
	 *  \note Early Access
	 */
	SL_BODY_FORMAT_BODY_38,

#if 0
	/**
	 * \brief 70 keypoint model.
	 * Body model, including feet and full hands models (and simplified face)
	 */
	SL_BODY_FORMAT_BODY_70,
#endif
};
/**
\brief Lists supported models for skeleton keypoints selection.
*/
enum SL_BODY_KEYPOINTS_SELECTION
{
	/**
	 * \brief Full keypoint model
	 */
	SL_BODY_KEYPOINTS_SELECTION_FULL,
	/**
	 * \brief Upper body keypoint model
	 * \n Will output only upper body (from hip).
	 */
	SL_BODY_KEYPOINTS_SELECTION_UPPER_BODY,
	/**
	 * \brief Hands only
	 */
	//SL_BODY_KEYPOINTS_SELECTION_HAND
};


/**
 * \brief Semantic of human body parts and order of \ref SL_BodyData.keypoint for \ref SL_BODY_FORMAT_BODY_18.
 */
enum SL_BODY_18_PARTS
{
	SL_BODY_18_PARTS_NOSE, /**< 0*/
	SL_BODY_18_PARTS_NECK, /**< 1*/
	SL_BODY_18_PARTS_RIGHT_SHOULDER, /**< 2*/
	SL_BODY_18_PARTS_RIGHT_ELBOW, /**< 3*/
	SL_BODY_18_PARTS_RIGHT_WRIST, /**< 4*/
	SL_BODY_18_PARTS_LEFT_SHOULDER, /**< 5*/
	SL_BODY_18_PARTS_LEFT_ELBOW, /**< 6*/
	SL_BODY_18_PARTS_LEFT_WRIST, /**< 7*/
	SL_BODY_18_PARTS_RIGHT_HIP, /**< 8*/
	SL_BODY_18_PARTS_RIGHT_KNEE, /**< 9*/
	SL_BODY_18_PARTS_RIGHT_ANKLE, /**< 10*/
	SL_BODY_18_PARTS_LEFT_HIP, /**< 11*/
	SL_BODY_18_PARTS_LEFT_KNEE, /**< 12*/
	SL_BODY_18_PARTS_LEFT_ANKLE, /**< 13*/
	SL_BODY_18_PARTS_RIGHT_EYE, /**< 14*/
	SL_BODY_18_PARTS_LEFT_EYE, /**< 15*/
	SL_BODY_18_PARTS_RIGHT_EAR, /**< 16*/
	SL_BODY_18_PARTS_LEFT_EAR, /**< 17*/
	SL_BODY_18_PARTS_LAST
};

/**
 * \brief Semantic of human body parts and order of \ref SL_BodyData.keypoint for \ref SL_BODY_FORMAT_BODY_34.
 */
enum SL_BODY_34_PARTS
{
	SL_BODY_34_PARTS_PELVIS, /**< 0*/
	SL_BODY_34_PARTS_NAVAL_SPINE, /**< 1*/
	SL_BODY_34_PARTS_CHEST_SPINE, /**< 2*/
	SL_BODY_34_PARTS_NECK, /**< 3*/
	SL_BODY_34_PARTS_LEFT_CLAVICLE, /**< 4*/
	SL_BODY_34_PARTS_LEFT_SHOULDER, /**< 5*/
	SL_BODY_34_PARTS_LEFT_ELBOW, /**< 6*/
	SL_BODY_34_PARTS_LEFT_WRIST, /**< 7*/
	SL_BODY_34_PARTS_LEFT_HAND, /**< 8*/
	SL_BODY_34_PARTS_LEFT_HANDTIP, /**< 9*/
	SL_BODY_34_PARTS_LEFT_THUMB, /**< 10*/
	SL_BODY_34_PARTS_RIGHT_CLAVICLE, /**< 11*/
	SL_BODY_34_PARTS_RIGHT_SHOULDER, /**< 12*/
	SL_BODY_34_PARTS_RIGHT_ELBOW, /**< 13*/
	SL_BODY_34_PARTS_RIGHT_WRIST, /**< 14*/
	SL_BODY_34_PARTS_RIGHT_HAND, /**< 15*/
	SL_BODY_34_PARTS_RIGHT_HANDTIP, /**< 16*/
	SL_BODY_34_PARTS_RIGHT_THUMB, /**< 17*/
	SL_BODY_34_PARTS_LEFT_HIP, /**< 18*/
	SL_BODY_34_PARTS_LEFT_KNEE, /**< 19*/
	SL_BODY_34_PARTS_LEFT_ANKLE, /**< 20*/
	SL_BODY_34_PARTS_LEFT_FOOT, /**< 21*/
	SL_BODY_34_PARTS_RIGHT_HIP, /**< 22*/
	SL_BODY_34_PARTS_RIGHT_KNEE, /**< 23*/
	SL_BODY_34_PARTS_RIGHT_ANKLE, /**< 24*/
	SL_BODY_34_PARTS_RIGHT_FOOT, /**< 25*/
	SL_BODY_34_PARTS_HEAD, /**< 26*/
	SL_BODY_34_PARTS_NOSE, /**< 27*/
	SL_BODY_34_PARTS_LEFT_EYE, /**< 28*/
	SL_BODY_34_PARTS_LEFT_EAR, /**< 29*/
	SL_BODY_34_PARTS_RIGHT_EYE, /**< 30*/
	SL_BODY_34_PARTS_RIGHT_EAR, /**< 31*/
	SL_BODY_34_PARTS_LEFT_HEEL, /**< 32*/
	SL_BODY_34_PARTS_RIGHT_HEEL, /**< 33*/
	SL_BODY_34_PARTS_LAST
};


/**
 * \brief Semantic of human body parts and order of \ref SL_BodyData.keypoint for \ref SL_BODY_FORMAT_BODY_38.
 */
enum SL_BODY_38_PARTS
{
	SL_BODY_38_PARTS_PELVIS, /**< 0*/
	SL_BODY_38_PARTS_SPINE_1, /**< 1*/
	SL_BODY_38_PARTS_SPINE_2, /**< 2*/
	SL_BODY_38_PARTS_SPINE_3, /**< 3*/
	SL_BODY_38_PARTS_NECK, /**< 4*/
	SL_BODY_38_PARTS_NOSE, /**< 5*/
	SL_BODY_38_PARTS_LEFT_EYE, /**< 6*/
	SL_BODY_38_PARTS_RIGHT_EYE, /**< 7*/
	SL_BODY_38_PARTS_LEFT_EAR, /**< 8*/
	SL_BODY_38_PARTS_RIGHT_EAR, /**< 9*/
	SL_BODY_38_PARTS_LEFT_CLAVICLE, /**< 10*/
	SL_BODY_38_PARTS_RIGHT_CLAVICLE, /**< 11*/
	SL_BODY_38_PARTS_LEFT_SHOULDER, /**< 12*/
	SL_BODY_38_PARTS_RIGHT_SHOULDER, /**< 13*/
	SL_BODY_38_PARTS_LEFT_ELBOW, /**< 14*/
	SL_BODY_38_PARTS_RIGHT_ELBOW, /**< 15*/
	SL_BODY_38_PARTS_LEFT_WRIST, /**< 16*/
	SL_BODY_38_PARTS_RIGHT_WRIST, /**< 17*/
	SL_BODY_38_PARTS_LEFT_HIP, /**< 18*/
	SL_BODY_38_PARTS_RIGHT_HIP, /**< 19*/
	SL_BODY_38_PARTS_LEFT_KNEE, /**< 20*/
	SL_BODY_38_PARTS_RIGHT_KNEE, /**< 21*/
	SL_BODY_38_PARTS_LEFT_ANKLE, /**< 22*/
	SL_BODY_38_PARTS_RIGHT_ANKLE, /**< 23*/
	SL_BODY_38_PARTS_LEFT_BIG_TOE, /**< 24*/
	SL_BODY_38_PARTS_RIGHT_BIG_TOE, /**< 25*/
	SL_BODY_38_PARTS_LEFT_SMALL_TOE, /**< 26*/
	SL_BODY_38_PARTS_RIGHT_SMALL_TOE, /**< 27*/
	SL_BODY_38_PARTS_LEFT_HEEL, /**< 28*/
	SL_BODY_38_PARTS_RIGHT_HEEL, /**< 29*/
	// Hands
	SL_BODY_38_PARTS_LEFT_HAND_THUMB_4, /**< 30*/
	SL_BODY_38_PARTS_RIGHT_HAND_THUMB_4, /**< 31*/
	SL_BODY_38_PARTS_LEFT_HAND_INDEX_1, /**< 32*/
	SL_BODY_38_PARTS_RIGHT_HAND_INDEX_1, /**< 33*/
	SL_BODY_38_PARTS_LEFT_HAND_MIDDLE_4, /**< 34*/
	SL_BODY_38_PARTS_RIGHT_HAND_MIDDLE_4, /**< 35*/
	SL_BODY_38_PARTS_LEFT_HAND_PINKY_1, /**< 36*/
	SL_BODY_38_PARTS_RIGHT_HAND_PINKY_1, /**< 37*/
	SL_BODY_38_PARTS_LAST
};

#if 0
/**
 * \brief semantic of human body parts and order of \ref ObjectData::keypoint for BODY_FORMAT::BODY_70.
 */
enum SL_BODY_70_PARTS
{
	SL_BODY_70_PARTS_PELVIS,
	SL_BODY_70_PARTS_SPINE_1,
	SL_BODY_70_PARTS_SPINE_2,
	SL_BODY_70_PARTS_SPINE_3,
	SL_BODY_70_PARTS_NECK,
	SL_BODY_70_PARTS_NOSE,
	SL_BODY_70_PARTS_LEFT_EYE,
	SL_BODY_70_PARTS_RIGHT_EYE,
	SL_BODY_70_PARTS_LEFT_EAR,
	SL_BODY_70_PARTS_RIGHT_EAR,
	SL_BODY_70_PARTS_LEFT_CLAVICLE,
	SL_BODY_70_PARTS_RIGHT_CLAVICLE,
	SL_BODY_70_PARTS_LEFT_SHOULDER,
	SL_BODY_70_PARTS_RIGHT_SHOULDER,
	SL_BODY_70_PARTS_LEFT_ELBOW,
	SL_BODY_70_PARTS_RIGHT_ELBOW,
	SL_BODY_70_PARTS_LEFT_WRIST,
	SL_BODY_70_PARTS_RIGHT_WRIST,
	SL_BODY_70_PARTS_LEFT_HIP,
	SL_BODY_70_PARTS_RIGHT_HIP,
	SL_BODY_70_PARTS_LEFT_KNEE,
	SL_BODY_70_PARTS_RIGHT_KNEE,
	SL_BODY_70_PARTS_LEFT_ANKLE,
	SL_BODY_70_PARTS_RIGHT_ANKLE,
	SL_BODY_70_PARTS_LEFT_BIG_TOE,
	SL_BODY_70_PARTS_RIGHT_BIG_TOE,
	SL_BODY_70_PARTS_LEFT_SMALL_TOE,
	SL_BODY_70_PARTS_RIGHT_SMALL_TOE,
	SL_BODY_70_PARTS_LEFT_HEEL,
	SL_BODY_70_PARTS_RIGHT_HEEL,
	// Hands
	// Left
	SL_BODY_70_PARTS_LEFT_HAND_THUMB_1,
	SL_BODY_70_PARTS_LEFT_HAND_THUMB_2,
	SL_BODY_70_PARTS_LEFT_HAND_THUMB_3,
	SL_BODY_70_PARTS_LEFT_HAND_THUMB_4,
	SL_BODY_70_PARTS_LEFT_HAND_INDEX_1,
	SL_BODY_70_PARTS_LEFT_HAND_INDEX_2,
	SL_BODY_70_PARTS_LEFT_HAND_INDEX_3,
	SL_BODY_70_PARTS_LEFT_HAND_INDEX_4,
	SL_BODY_70_PARTS_LEFT_HAND_MIDDLE_1,
	SL_BODY_70_PARTS_LEFT_HAND_MIDDLE_2,
	SL_BODY_70_PARTS_LEFT_HAND_MIDDLE_3,
	SL_BODY_70_PARTS_LEFT_HAND_MIDDLE_4,
	SL_BODY_70_PARTS_LEFT_HAND_RING_1,
	SL_BODY_70_PARTS_LEFT_HAND_RING_2,
	SL_BODY_70_PARTS_LEFT_HAND_RING_3,
	SL_BODY_70_PARTS_LEFT_HAND_RING_4,
	SL_BODY_70_PARTS_LEFT_HAND_PINKY_1,
	SL_BODY_70_PARTS_LEFT_HAND_PINKY_2,
	SL_BODY_70_PARTS_LEFT_HAND_PINKY_3,
	SL_BODY_70_PARTS_LEFT_HAND_PINKY_4,
	//Right
	SL_BODY_70_PARTS_RIGHT_HAND_THUMB_1,
	SL_BODY_70_PARTS_RIGHT_HAND_THUMB_2,
	SL_BODY_70_PARTS_RIGHT_HAND_THUMB_3,
	SL_BODY_70_PARTS_RIGHT_HAND_THUMB_4,
	SL_BODY_70_PARTS_RIGHT_HAND_INDEX_1,
	SL_BODY_70_PARTS_RIGHT_HAND_INDEX_2,
	SL_BODY_70_PARTS_RIGHT_HAND_INDEX_3,
	SL_BODY_70_PARTS_RIGHT_HAND_INDEX_4,
	SL_BODY_70_PARTS_RIGHT_HAND_MIDDLE_1,
	SL_BODY_70_PARTS_RIGHT_HAND_MIDDLE_2,
	SL_BODY_70_PARTS_RIGHT_HAND_MIDDLE_3,
	SL_BODY_70_PARTS_RIGHT_HAND_MIDDLE_4,
	SL_BODY_70_PARTS_RIGHT_HAND_RING_1,
	SL_BODY_70_PARTS_RIGHT_HAND_RING_2,
	SL_BODY_70_PARTS_RIGHT_HAND_RING_3,
	SL_BODY_70_PARTS_RIGHT_HAND_RING_4,
	SL_BODY_70_PARTS_RIGHT_HAND_PINKY_1,
	SL_BODY_70_PARTS_RIGHT_HAND_PINKY_2,
	SL_BODY_70_PARTS_RIGHT_HAND_PINKY_3,
	SL_BODY_70_PARTS_RIGHT_HAND_PINKY_4,
	SL_BODY_70_PARTS_LAST
};
#endif

/**
* \brief Lists the types of possible position outputs.
*/
enum SL_POSITION_TYPE {
	SL_POSITION_TYPE_RAW,/**< The output position will be the raw position data. */
	SL_POSITION_TYPE_FUSION,/**< The output position will be the fused position projected into the requested camera repository. */
	///@cond SHOWHIDDEN 
	SL_POSITION_TYPE_LAST
	///@endcond
};

/**
* \brief Structure containing the width and height of an image.
*/
struct SL_Resolution {
	/**
	\brief Width of the image in pixels.
	*/
	long long width;
	/**
	\brief Height of the image in pixels.
	*/
	long long height;
};

/**
\brief Structure containing the options used to initialize a camera.

This class allows you to select multiple parameters for the camera to open such as the selected camera, resolution, depth mode, coordinate system, and units of measurement.
\n Once filled with the desired options, it should be passed to the sl_open_camera() function.

\note For more info, read about the ZED SDK C++ class it mirrors:
<a href="https://www.stereolabs.com/docs/api/structsl_1_1InitParameters.html">InitParameters</a>
*/
struct SL_InitParameters
{
	/**
	\brief Defines the input source to initialize and open an camera from.
	
	The SDK can handle different input types:
	- Select a camera by its ID (<i>/dev/videoX</i> on Linux, and 0 to N cameras connected on Windows)
	- Select a camera by its serial number
	- Open a recorded sequence in the SVO file format
	- Open a streaming camera from its IP address and port

	\note Available cameras and their id/serial number can be listed using sl_get_device_list() and sl_get_streaming_device_list().
	\note Each camera will create its own memory (CPU and GPU),
	therefore the number of cameras used at the same time can be limited by the configuration of your computer (GPU/CPU memory and capabilities).
	
	Default : (empty)
	\note See \ref SL_INPUT_TYPE for complementary information.
	*/
	enum  SL_INPUT_TYPE input_type;

	/**
	\brief Desired camera resolution.
	
	\note Small resolutions offer higher framerate and lower computation time.
	\note In most situations, \ref SL_RESOLUTION_HD720 at 60 FPS is the best balance between image quality and framerate.

	Default: <ul>
	<li>ZED X/X Mini: \ref SL_RESOLUTION_HD1200</li>
	<li>other cameras: \ref SL_RESOLUTION_HD720</li></ul>
	\note Available resolutions are listed here: \ref SL_RESOLUTION.
	 */
	enum  SL_RESOLUTION resolution;

	/**
	\brief Requested camera frame rate.
        
	If set to 0, the highest FPS of the specified \ref camera_resolution will be used.
	\n Default: 0
	\n\n See \ref SL_RESOLUTION for a list of supported frame rates.
	\note If the requested \ref camera_fps is unsupported, the closest available FPS will be used.
	 */
	int camera_fps;

	/**
	\brief Id for identifying which camera to use from the connected cameras.
	*/
	int camera_device_id;

	/**
	\brief Defines if a flip of the images is needed.
	
	If you are using the camera upside down, setting this parameter to \ref SL_FLIP_MODE_ON will cancel its rotation.
	\n The images will be horizontally flipped.
	\n Default: \ref SL_FLIP_MODE_AUTO
	\note From ZED SDK 3.2 a new \ref SL_FLIP_MODE enum was introduced to add the automatic flip mode detection based on the IMU gravity detection.
	\note This does not work on \ref SL_MODEL_ZED cameras since they do not have the necessary sensors.
	*/
	enum  SL_FLIP_MODE camera_image_flip;

	/**
	\brief Defines if a flip of the images is needed.
	
	At initialization, sl_open_camera() runs a self-calibration process that corrects small offsets from the device's factory calibration.
	\n A drawback is that calibration parameters will slightly change from one (live) run to another, which can be an issue for repeatability.
	\n If set to true, self-calibration will be disabled and calibration parameters won't be optimized, raw calibration parameters from the configuration file will be used.
	\n Default: false
	\note In most situations, self calibration should remain enabled.
	\note You can also trigger the self-calibration at anytime after sl_open_camera() by calling sl_update_self_calibration(), even if this parameter is set to true.
	*/
	bool camera_disable_self_calib;

	/**
	\brief Enable the measurement computation on the right images.

	By default, the ZED SDK only computes a single depth map, aligned with the left camera image.
	\n This parameter allows you to enable \ref SL_MEASURE_DEPTH_RIGHT and other \ref SL_MEASURE "SL_MEASURE_XXX_RIGHT" at the cost of additional computation time.
	\n For example, mixed reality pass-through applications require one depth map per eye, so this parameter can be activated.
	\n Default: false
	*/
	bool enable_right_side_measure;

	/**
	\brief Defines if the camera return the frame in real time mode.
	
	When playing back an SVO file, each call to \ref sl_grab() will extract a new frame and use it.
	\n However, it ignores the real capture rate of the images saved in the SVO file.
	\n Enabling this parameter will bring the SDK closer to a real simulation when playing back a file by using the images' timestamps.
	\n Default: false
	\note \ref sl_grab() will return an error when trying to play too fast, and frames will be dropped when playing too slowly.
	*/
	bool svo_real_time_mode;
	
	/**
	\brief \ref SL_DEPTH_MODE to be used.
	
	The ZED SDK offers several \ref SL_DEPTH_MODE, offering various levels of performance and accuracy.
	\n This parameter allows you to set the \ref SL_DEPTH_MODE that best matches your needs.
	\n Default: \ref SL_DEPTH_MODE_PERFORMANCE
	\note Available depth mode are listed here: \ref SL_DEPTH_MODE.
	*/
	enum SL_DEPTH_MODE depth_mode;
	
	/**
	\brief Defines whether the depth needs to be stabilized and to what extent.

	Regions of generated depth map can oscillate from one frame to another.
	\n These oscillations result from a lack of texture (too homogeneous) on an object and by image noise.
	\n This parameter controls a stabilization filter that reduces these oscillations.
	\n In the range [0-100]: <ul>
	<li>0 disable the depth stabilization (raw depth will be return)</li>
	<li>stabilization smoothness is linear from 1 to 100</li></ul>
	Default: 1
	
	\note The stabilization uses the positional tracking to increase its accuracy, 
	so the positional tracking module will be enabled automatically when set to a value different from 0.
	\note Note that calling sl_enable_positional_tracking() with your own parameters afterwards is still possible.
	*/
	int depth_stabilization;
	
	/**
	\brief Minimum depth distance to be returned, measured in the \ref SL_UNIT defined in \ref coordinate_unit.
	
	This parameter allows you to specify the minimum depth value (from the camera) that will be computed.
	
	\n In stereovision (the depth technology used by the camera), looking for closer depth values can have a slight impact on performance and memory consumption.
	\n On most modern GPUs, performance impact will be low. However, the impact of memory footprint will be visible.
	\n In cases of limited computation power, increasing this value can provide better performance.
	\n Default: -1 (corresponding values are available <a href="https://www.stereolabs.com/docs/depth-sensing/depth-settings#depth-range">here</a>)

	\note \ref depth_minimum_distance value cannot be greater than 3 meters.
	\note 0 will imply that \ref depth_minimum_distance is set to the minimum depth possible for each camera
	(those values are available <a href="https://www.stereolabs.com/docs/depth-sensing/depth-settings#depth-range">here</a>).
		*/
	float depth_minimum_distance;
	/**
	\brief Maximum depth distance to be returned, measured in the \ref SL_UNIT defined in \ref coordinate_unit.

	When estimating the depth, the ZED SDK uses this upper limit to turn higher values into <b>inf</b> ones.
	\note Changing this value has no impact on performance and doesn't affect the positional tracking nor the spatial mapping.
	\note It only change values the depth, point cloud and normals.
	 */
	float depth_maximum_distance;
	
	/**
	\brief Unit of spatial data (depth, point cloud, tracking, mesh, etc.) for retrieval.
	
	Default: \ref SL_UNIT_MILLIMETER
		*/
	enum  SL_UNIT coordinate_unit;
	
	/**
	\brief \ref SL_COORDINATE_SYSTEM to be used as reference for positional tracking, mesh, point clouds, etc.

	This parameter allows you to select the \ref SL_COORDINATE_SYSTEM used by the camera to return its measures.
	\n This defines the order and the direction of the axis of the coordinate system.
	\n Default: \ref SL_COORDINATE_SYSTEM_IMAGE
		*/
	enum  SL_COORDINATE_SYSTEM coordinate_system;
	
	/**
	\brief NVIDIA graphics card id to use.
	
	By default the SDK will use the most powerful NVIDIA graphics card found.
	\n However, when running several applications, or using several cameras at the same time, splitting the load over available GPUs can be useful.
	\n This parameter allows you to select the GPU used by the sl::Camera using an ID from 0 to n-1 GPUs in your PC.
	\n Default: -1
	\note A non-positive value will search for all CUDA capable devices and select the most powerful.
	 */
	int sdk_gpu_id;

	/**
	\brief Enable the ZED SDK verbose mode.
	
	This parameter allows you to enable the verbosity of the ZED SDK to get a variety of runtime information in the console.
	\n When developing an application, enabling verbose (<code>\ref sdk_verbose >= 1</code>) mode can help you understand the current ZED SDK behavior.
	\n However, this might not be desirable in a shipped version.
	\n Default: 0 (no verbose message)
	\note The verbose messages can also be exported into a log file.
	 */
	int sdk_verbose;
	/**
	\brief Requires the successful opening of the motion sensors before opening the camera.
	
	Default: false.

	\note If set to false, the ZED SDK will try to <b>open and use</b> the IMU (second USB device on USB2.0) and will open the camera successfully even if the sensors failed to open.
	
	This can be used for example when using a USB3.0 only extension cable (some fiber extension for example).
	\note This parameter only impacts the LIVE mode.
	\note If set to true, sl_open_camera() will fail if the sensors cannot be opened.
	\note This parameter should be used when the IMU data must be available, such as object detection module or when the gravity is needed.
	
	\n\note This setting is not taken into account for \ref SL_MODEL_ZED camera since it does not include sensors.
	 */
	bool sensors_required;
	
	/**
	\brief Enable the Enhanced Contrast Technology, to improve image quality.

	Default: true.
	
	\n If set to true, image enhancement will be activated in camera ISP. Otherwise, the image will not be enhanced by the IPS.
	\note This only works for firmware version starting from 1523 and up.
	 */
	bool enable_image_enhancement;

	/**
	\brief Define a timeout in seconds after which an error is reported if the sl_open_camera() function fails.

	Set to '-1' to try to open the camera endlessly without returning error in case of failure.
	\n Set to '0' to return error in case of failure at the first attempt.
	\n Default: 5.0
	\note This parameter only impacts the LIVE mode.
	 */
	float open_timeout_sec;

	/**
	\brief Define the behavior of the automatic camera recovery during sl_grab() function call.
        
	When async is enabled and there's an issue with the communication with the camera,
	sl_grab() will exit after a short period and return the \ref SL_ERROR_CODE_CAMERA_REBOOTING warning.
	\n The recovery will run in the background until the correct communication is restored.
	\n When \ref async_grab_camera_recovery is false, the sl_grab() function is blocking and will return
	only once the camera communication is restored or the timeout is reached.
    \n Default: false
	 */
	bool async_grab_camera_recovery;

	/**
	\brief Define a computation upper limit to the grab frequency.

	This can be useful to get a known constant fixed rate or limit the computation load while keeping a short exposure time by setting a high camera capture framerate.
	\n The value should be inferior to the SL_InitParameters::camera_fps and strictly positive.
	\note  It has no effect when reading an SVO file.
	
	This is an upper limit and won't make a difference if the computation is slower than the desired compute capping FPS.
	\note Internally the sl_grab() function always tries to get the latest available image while respecting the desired FPS as much as possible.
	 */
	float grab_compute_capping_fps;
	/**
	 Enable or disable the image validity verification.
	 This will perform additional verification on the image to identify corrupted data. This verification is done in the grab function and requires some computations.
	 If an issue is found, the grab function will output a warning as sl::ERROR_CODE::CORRUPTED_FRAME.
	 This version doesn't detect frame tearing currently.
	 \n default: disabled
	 */
	bool enable_image_validity_check;
};

/**
\brief Structure containing parameters that defines the behavior of sl_grab().

The default constructor sets all parameters to their default settings.
\note Parameters can be adjusted by the user.
*/
struct SL_RuntimeParameters
{
	/**
	\brief Reference frame in which to provides the 3D measures (point cloud, normals, etc.).
	
	Default: \ref SL_REFERENCE_FRAME_CAMERA
	 */
	enum SL_REFERENCE_FRAME reference_frame;

	/**
	\brief Defines if the depth map should be computed.
        
	Default: true
	\note If set to false, only the images are available.
	 */
	bool enable_depth;
        
	/**
	\brief Defines if the depth map should be completed or not.

	Default: false
	\note It is similar to the removed sl_SENSING_MODE_FILL.
	\warning Enabling this will override the confidence values \ref confidence_threshold
	and \ref texture_confidence_threshold as well as \ref remove_saturated_areas.
	 */
	bool enable_fill_mode;
        
	/**
	\brief Threshold to reject depth values based on their confidence.

	Each depth pixel has a corresponding confidence (\ref SL_MEASURE_CONFIDENCE) in the range [1, 100].
	\n Decreasing this value will remove depth data from both objects edges and low textured areas, to keep only confident depth estimation data.
	\n Default: 100 (no depth pixel will be rejected)
	\note Pixels with a value close to 100 are not to be trusted. Accurate depth pixels tends to be closer to lower values.
	\note It can be seen as a probability of error, scaled to 100.
	 */
	int confidence_threshold;
	
	/**
	\brief Threshold to reject depth values based on their texture confidence.

	The texture confidence range is [1, 100].
	\n Decreasing this value will remove depth data from image areas which are uniform.
	\n Default: 100 (no depth pixel will be rejected)
	\note Pixels with a value close to 100 are not to be trusted. Accurate depth pixels tends to be closer to lower values.
	 */
	int texture_confidence_threshold;

	/**
	\brief Defines if the saturated area (luminance>=255) must be removed from depth map estimation.

	Default: true
	\note It is recommended to keep this parameter at true because saturated area can create false detection.
	 */
	bool remove_saturated_areas;
};

/**
\brief Structure containing information about the properties of a camera.
    
\note A \ref camera_model \ref SL_MODEL_ZED_M with an id '-1' can be due to an inverted USB-C cable.
*/
struct SL_DeviceProperties {
	/**
	\brief State of the camera.

	Default: \ref SL_CAMERA_STATE_NOT_AVAILABLE
	 */
	enum  SL_CAMERA_STATE camera_state;

	/**
	\brief Id of the camera.

	Default: -1
	 */
	int id;

	/**
	\brief Model of the camera.
	 */
	enum  SL_MODEL camera_model;

	/**
	\brief Serial number of the camera.

	Default: 0
    \warning Not provided for Windows.
	 */

	unsigned int sn;
	/**
	\brief Input type of the camera.
	 */
	enum SL_INPUT_TYPE input_type;
};

/**
\brief Structure containing the intrinsic parameters of a camera.
*/
struct SL_CameraParameters {
	/**
	\brief Focal length in pixels along x axis.
	 */
	float fx;

	/**
	\brief Focal length in pixels along y axis.
	 */
	float fy;

	/**
	\brief Optical center along x axis, defined in pixels (usually close to width / 2).
	 */
	float cx;

	/**
	\brief Optical center along y axis, defined in pixels (usually close to height / 2).
	 */
	float cy;

	/**
	\brief Distortion factor : [k1, k2, p1, p2, k3, k4, k5, k6, s1, s2, s3, s4].
	
	Radial (k1, k2, k3, k4, k5, k6), Tangential (p1,p2) and Prism (s1, s2, s3, s4) distortion.
	 */
	double disto[12];

	/**
	\brief Vertical field of view, in degrees.
	 */
	float v_fov;

	/**
	\brief Horizontal field of view, in degrees.
	 */
	float h_fov;

	/**
	\brief Diagonal field of view, in degrees.
	 */
	float d_fov;

	/**
	\brief Size in pixels of the images given by the camera.
	 */
	struct SL_Resolution image_size;

	/**
	\brief Real focal length in millimeters.
	 */
	float focal_length_metric;
};

/**
\brief Structure containing intrinsic and extrinsic parameters of the camera (translation and rotation).

That information about the camera will be returned by sl_get_camera_information().

\note The calibration/rectification process, called during sl_open_camera(), is using the raw parameters defined in the SNXXX.conf file, where XXX is the serial number of the camera.
\note Those values may be adjusted or not by the self-calibration to get a proper image alignment.
\note After sl_open_camera() is done (with or without self-calibration activated), most of the stereo parameters (except baseline of course) should be 0 or very close to 0.
\note It means that images after rectification process (given by sl_retrieve_image()) are aligned as if they were taken by a "perfect" stereo camera, defined by the new \ref SL_CalibrationParameters.
\warning CalibrationParameters are returned in \ref SL_COORDINATE_SYSTEM_IMAGE, they are not impacted by the SL_InitParameters.coordinate_system.
 */
struct SL_CalibrationParameters
{
	/**
	\brief Intrinsic \ref SL_CameraParameters of the left camera.
	*/
	struct SL_CameraParameters left_cam;
	/**
	\brief Intrinsic \ref SL_CameraParameters of the right camera.
	*/
	struct SL_CameraParameters right_cam;
	/**
	\brief Left to right camera rotation, expressed in user coordinate system and unit (defined by SL_InitParameters.coordinate_system).
	*/
	struct SL_Vector4 rotation;
	/**
	\brief Left to right camera translation, expressed in user coordinate system and unit (defined by SL_InitParameters.coordinate_system).
	*/
	struct SL_Vector3 translation;
};

/**
\brief Structure containing information about a single sensor available in the current device.

Information about the camera sensors is available in the \ref SL_CameraInformation struct returned by \ref sl_get_camera_information().
\note This structure is meant to be used as a read-only container.
\note Editing any of its fields will not impact the ZED SDK.
*/
struct SL_SensorParameters {
	enum  SL_SENSOR_TYPE type; /**< \brief Type of the sensor.*/
	float resolution; /**< \brief Resolution of the sensor. */
	float sampling_rate; /**< \brief Sampling rate (or ODR) of the sensor. */
	struct SL_Vector2 range; /**< \brief Range of the sensor (minimum: `range.x`, maximum: `range.y`). */
	float noise_density; /**< \brief White noise density given as continuous (frequency-independent).\note The units will be expressed in ```sensor_unit / √(Hz)```.\note `NAN` if the information is not available. */
	float random_walk; /**< \brief Random walk derived from the Allan Variance given as continuous (frequency-independent).\note The units will be expressed in ```sensor_unit / √(Hz)```.\note `NAN` if the information is not available. */
	enum  SL_SENSORS_UNIT sensor_unit; /**< \brief Unit of the sensor. */
	bool is_available; /**< \brief Whether the sensor is available in your camera.*/
};


/**
\brief Structure containing information about the camera sensor. 
\note This object is meant to be used as a read-only container, editing any of its field won't impact the ZED SDK.
\warning \ref SL_CalibrationParameters are returned in \ref SL_COORDINATE_SYSTEM_IMAGE, they are not impacted by the \ref SL_InitParameters.coordinate_system.
*/
struct SL_CameraConfiguration {
	/**
	\brief Intrinsics and extrinsic stereo parameters for rectified/undistorted images.
	*/
	struct SL_CalibrationParameters calibration_parameters;
	/**
	\brief Intrinsics and extrinsic stereo parameters for unrectified/distorted images.
	*/
	struct SL_CalibrationParameters calibration_parameters_raw;
	/**
	\brief Internal firmware version of the camera.
	*/
	unsigned int firmware_version;
	/**
	\brief FPS of the camera.
	*/
	float fps;
	/**
	\brief Resolution of the camera.
	*/
	struct SL_Resolution resolution;
};

/**
\brief Structure containing information about all the sensors available in the current device.

Information about the camera sensors is available in the \ref SL_CameraInformation struct returned by \ref sl_get_camera_information().
\note This structure is meant to be used as a read-only container.
\note Editing any of its fields will not impact the ZED SDK.
*/
struct SL_SensorsConfiguration
{
	/**
	\brief Firmware version of the sensor module.
	\note 0 if no sensors are available (\ref SL_MODEL_ZED).
	*/
	unsigned int firmware_version;
	/**
	\brief IMU to left camera rotation (quaternion).
	\note It contains the rotation between the IMU frame and camera frame.
	*/
	struct SL_Vector4 camera_ium_rotation;
	/**
	\brief IMU to left camera translation.
	\note It contains the translation between the IMU frame and camera frame.
	*/
	struct SL_Vector3 camera_imu_translation;
	/**
	\brief Magnetometer to IMU rotation (quaternion).
	\note It contains rotation between IMU frame and magnetometer frame.
	*/
	struct SL_Vector4 ium_magnetometer_rotation;
	/**
	\brief Magnetometer to IMU translation (quaternion).
	\note It contains translation between IMU frame and magnetometer frame.
	*/
	struct SL_Vector3 ium_magnetometer_translation;
	/**
	\brief Configuration of the accelerometer.
	*/
	struct SL_SensorParameters accelerometer_parameters;
	/**
	\brief Configuration of the gyroscope.
	*/
	struct SL_SensorParameters gyroscope_parameters;
	/**
	\brief Configuration of the magnetometer.
	*/
	struct SL_SensorParameters magnetometer_parameters;
	/**
	\brief Configuration of the barometer.
	*/
	struct SL_SensorParameters barometer_parameters;
};


/**
\brief Structure containing information of a single camera (serial number, model, input type, etc.)

That information about the camera will be returned by sl_get_camera_information().

\note This object is meant to be used as a read-only container, editing any of its field won't impact the SDK.
 */
struct SL_CameraInformation {
	/**
	\brief Serial number of the camera.
	*/
	unsigned int serial_number;
	/**
	\brief Model of the camera (see \ref SL_MODEL).
	*/
	enum SL_MODEL camera_model;
	/**
	\brief Input type used in the ZED SDK.
	*/
	enum SL_INPUT_TYPE input_type;
	/**
	\brief Camera configuration parameters stored in a \ref SL_CameraConfiguration.
	*/
	struct SL_CameraConfiguration camera_configuration;
	/**
	\brief Sensors configuration parameters stored in a \ref SL_SensorsConfiguration.
	*/
	struct SL_SensorsConfiguration sensors_configuration;
};


/**
\brief Structure containing a set of parameters for the positional tracking module initialization.

The default constructor sets all parameters to their default settings.
\note Parameters can be user adjusted.
*/
struct SL_PositionalTrackingParameters
{
	/**
	\brief Rotation of the camera in the world frame when the camera is started.

	Default: Identity quaternion
	*/
	struct SL_Quaternion initial_world_rotation;
	/**
	\brief Position of the camera in the world frame when the camera is started.

	Default: Null vector
	*/
	struct SL_Vector3 initial_world_position;
	/**
	\brief Whether the camera can remember its surroundings.

	This helps correct positional tracking drift and can be helpful for positioning different cameras relative to one other in space.
	\n Default: true

	\warning This mode requires more resources to run, but greatly improves tracking accuracy.
	\warning We recommend leaving it on by default.
	*/
	bool enable_area_memory;
	/**
	\brief Whether to enable smooth pose correction for small drift correction.

    Default: false
	*/
	bool enable_pose_smothing;
	/**
	\brief Initializes the tracking to be aligned with the floor plane to better position the camera in space.

	Default: false
	\note This launches floor plane detection in the background until a suitable floor plane is found.
	\note The tracking will start in \ref SL_POSITIONAL_TRACKING_STATE_SEARCHING state.

	\warning This features does not work with \ref SL_MODEL_ZED since it needs an IMU to classify the floor.
	\warning The camera needs to look at the floor during initialization for optimum results.
	*/
	bool set_floor_as_origin;
	/**
	\brief Whether to define the camera as static.
	
	If true, it will not move in the environment. This allows you to set its position using \ref initial_world_position and \ref initial_world_rotation.
	\n All ZED SDK functionalities requiring positional tracking will be enabled without additional computation.
	\n \ref sl_get_position() will return the values set as \ref initial_world_position and \ref initial_world_rotation.
	\n Default: false
	*/
	bool set_as_static;
	/**
	\brief Whether to enable the IMU fusion.

	When set to false, only the optical odometry will be used.
	\n Default: true
	\note This setting has no impact on the tracking of a camera.
	\note \ref SL_MODEL_ZED does not have an IMU.
	*/
	bool enable_imu_fusion;
	/**
	\brief Whether to enable the IMU fusion.

	When set to false, only the optical odometry will be used.
	\n Default: true
	\note This setting has no impact on the tracking of a camera
	\note \ref SL_MODEL_ZED does not have an IMU.
	 */
	float depth_min_range;
	/**
	\brief Whether to override 2 of the 3 components from \ref initial_world_rotation using the IMU gravity.

	Default: true
	\note This parameter does nothing on sl.ZED.MODEL since it does not have an IMU.
	 */
	bool set_gravity_as_origin;
	/**
	\brief Positional tracking mode used.
	
	Can be used to improve accuracy in some types of scene at the cost of longer runtime.
	\n Default: \ref SL_POSITIONAL_TRACKING_MODE_STANDARD
	*/
	enum SL_POSITIONAL_TRACKING_MODE mode;

};

/**
\brief Structure containing a set of parameters for the region of interest

*/
struct SL_RegionOfInterestParameters
{
	/**
	 \brief Filtering how far object in the ROI should be considered, this is useful for a vehicle for instance

	 Default: 2.5 meters
	 */
	float depth_far_threshold_meters;

	/**
	 \brief By default consider only the lower half of the image, can be useful to filter out the sky

	 Default: 0.5, correspond to the lower half of the image
	 */
	float image_height_ratio_cutoff;

	/**
	 \brief Once computed the ROI computed will be automatically applied

	 Default: Enabled
	 */
	bool auto_apply;
};

/**
\brief Structure containing a set of parameters for the plane detection functionality.

The default constructor sets all parameters to their default settings.
\note Parameters can be adjusted by the user.
*/
struct SL_PlaneDetectionParameters {

	/**
	 \brief Controls the spread of plane by checking the position difference.

	 Default: 0.15 meters
	 */
	float max_distance_threshold;

	/**
	 \brief Controls the spread of plane by checking the angle difference.

	 Default: 15 degrees
	 */
	float normal_similarity_threshold;
};

/**
\brief Structure containing information about the status of the recording.
 */
struct SL_RecordingStatus {
	/**
     \brief Report if the recording has been enabled.
	 */
	bool is_recording;
	/**
     \brief Report if the recording has been paused.
	 */
	bool is_paused;
	/**
     \brief Status of current frame.
	 
	 True for success or false if the frame could not be written in the SVO file.
	 */
	bool status;
	/**
     \brief Compression time for the current frame in milliseconds.
	 */
	double current_compression_time;
	/**
     \brief Compression ratio (% of raw size) for the current frame.
	 */
	double current_compression_ratio;
	/**
     \brief Average compression time in milliseconds since beginning of recording.
	 */
	double average_compression_time;
	/**
     \brief Average compression ratio (% of raw size) since beginning of recording.
	 */
	double average_compression_ratio;
};

/**
\brief Structure containing the options used to record.
 */
struct SL_RecordingParameters {
	/**
	\brief Filename of the file to save the recording into.
	 */
	unsigned char video_filename[256];

	/**
	\brief Compression mode the recording.
	
	Default: \ref SL_SVO_COMPRESSION_MODE_H264
	 */
	enum SL_SVO_COMPRESSION_MODE compression_mode;

	/**
	\brief Overrides the default bitrate of the SVO file, in kbits/s.

	Default: 0 (the default values associated with the resolution)
	\note Only works if \ref compression_mode is H264 or H265.
	\note Available range: 0 or [1000 - 60000]
	 */
	unsigned int bitrate;

	/**
	\brief Framerate for the recording file.

	Default: 0 (camera framerate will be taken)
	\warning This framerate must be below or equal to the camera framerate and camera framerate must be a multiple of the target framerate.
	\warning It means that it must respect <code camera_framerate%target_framerate == 0</code>.
	\warning Allowed framerates are 15,30, 60 or 100 if possible.
	\warning Any other values will be discarded and camera FPS will be taken.
	 */
	unsigned int target_framerate;

	/**
	\brief  Defines whether to decode and re-encode a streaming source.

	Default: false
	\note If set to false, it will avoid decoding/re-encoding and convert directly streaming input into a SVO file.
	\note This saves a encoding session and can be especially useful on NVIDIA Geforce cards where the number of encoding session is limited.
	\note \ref compression_mode, \ref target_framerate and \ref bitrate will be ignored in this mode.
	 */
	bool transcode_streaming_input;
};

/**
\brief Structure containing the options used to stream with the ZED SDK.
\note Parameters can be adjusted by the user.
 */
struct SL_StreamingParameters {

	/**
	\brief Encoding used for streaming.
		*/
	enum SL_STREAMING_CODEC codec;

	/**
	\brief Port used for streaming.
	\warning Port must be an even number. Any odd number will be rejected.
	\warning Port must be opened.
	 */
	unsigned short port;

	/**
	\brief Defines the streaming bitrate in Kbits/s
	
	| \ref SL_STREAMING_CODEC	   | \ref SL_RESOLUTION 	   | FPS   | bitrate (kbps) |
	|------------------------------|---------------------------|-------|----------------|
	| \ref SL_STREAMING_CODEC_H264 | \ref SL_RESOLUTION_HD2K   |   15  |     8500       |
	| \ref SL_STREAMING_CODEC_H264 | \ref SL_RESOLUTION_HD1080 |   30  |    12500       |
	| \ref SL_STREAMING_CODEC_H264 | \ref SL_RESOLUTION_HD720  |   60  |     7000       |
	| \ref SL_STREAMING_CODEC_H265 | \ref SL_RESOLUTION_HD2K   |   15  |     7000       |
	| \ref SL_STREAMING_CODEC_H265 | \ref SL_RESOLUTION_HD1080 |   30  |    11000       |
	| \ref SL_STREAMING_CODEC_H265 | \ref SL_RESOLUTION_HD720  |   60  |     6000       |
	Default: 0 (it will be set to the best value depending on your resolution/FPS)
	\note Available range: [1000 - 60000]
	 */
	unsigned int bitrate;

	/**
	\brief GOP size in number of frames.

    Default: -1 (the GOP size will last at maximum 2 seconds, depending on camera FPS)
    \note The GOP size determines the maximum distance between IDR/I-frames. Very high GOP size will result in slightly more efficient compression, especially on static scenes. But latency will increase.
    \note Maximum value: 256
	 */
	int gop_size;

	/**
	\brief Defines whether the adaptive bitrate is enable.

    Default: false
    \note Bitrate will be adjusted depending the number of packet dropped during streaming.
    \note If activated, the bitrate can vary between [bitrate/4, bitrate].
    \warning Currently, the adaptive bitrate only works when "sending" device is a NVIDIA Jetson (X1, X2, Xavier, Nano).
	 */
	bool adaptative_bitrate;

	/**
	\brief Size of a single chunk.

	Default: 16084
	\note Stream buffers are divided into X number of chunks where each chunk is  \ref chunk_size bytes long.
	\note You can lower \ref chunk_size value if network generates a lot of packet lost: this will
	generates more chunk for a single image, but each chunk sent will be lighter to avoid inside-chunk corruption.
	\note Increasing this value can decrease latency.

	\n \note Available range: [1024 - 65000]
	 */
	unsigned short chunk_size;


	/**
	\brief Framerate for the streaming output.

	Default: 0 (camera framerate will be taken)
	\warning This framerate must be below or equal to the camera framerate.
	\warning Allowed framerates are 15, 30, 60 or 100 if possible.
	\warning Any other values will be discarded and camera FPS will be taken.
	 */
	unsigned int target_framerate;
};

/**
\brief Structure containing information about the properties of a streaming device. 
 */
struct SL_StreamingProperties {
	/**
	\brief IP address of the streaming device.
	 */
	unsigned char ip[16];

	/**
	\brief Streaming port of the streaming device.

	Default: 0
	 */
	unsigned short port;

	/**
	\brief Serial number of the streaming camera.

	Default: 0
	 */
	unsigned int serial_number;

	/**
	\brief Current bitrate of encoding of the streaming device.

	Default: 0
	 */
	int current_bitrate;

	/**
	\brief Current codec used for compression in streaming device.

	Default: \ref SL_STREAMING_CODEC_H265
	 */
	enum SL_STREAMING_CODEC codec;
};

/**
\brief Structure containing a set of parameters for the spatial mapping module.

The default constructor sets all parameters to their default settings.
\note Parameters can be adjusted by the user.
*/
struct SL_SpatialMappingParameters {
	/**
	\brief Spatial mapping resolution in meters.

	Default: 0.05f
	 */
	float resolution_meter;
	/**
	\brief Depth range in meters.

	Can be different from the value set by SL_InitParameters.depth_maximum_distance.
	\note Set to 0 by default. In this case, the range is computed from \ref resolution_meter
	and from the current internal parameters to fit your application.
	 */
	float range_meter;
	/**
	\brief Whether to save the texture.

	If set to true, you will be able to apply the texture to your mesh after it is created.
	\n Default: false
	\note This option will consume more memory.
	\note This option is only available for \ref SL_SPATIAL_MAP_TYPE_MESH.
	 */
	bool save_texture;
	/**
	\brief Whether to only use chunks.

	If set to false, you will ensure consistency between the mesh and its inner chunk data.
	\n Default: false
	\note Updating the mesh is time-consuming.
	\note Setting this to true results in better performance.
	 */
	bool use_chunk_only;
	/**
	\brief The maximum CPU memory (in MB) allocated for the meshing process.

	Default: 2048
	 */
	int max_memory_usage;
	/**
	\brief Whether to inverse the order of the vertices of the triangles.

	If your display process does not handle front and back face culling, you can use this to correct it.
	\n Default: false
	\note This option is only available for \ref SL_SPATIAL_MAP_TYPE_MESH.
	 */
	bool reverse_vertex_order;
	/**
	\brief The type of spatial map to be created.

	This dictates the format that will be used for the mapping (e.g. mesh, point cloud).
	\n See \ref SL_SPATIAL_MAP_TYPE.
	 */
	enum SL_SPATIAL_MAP_TYPE map_type;
	/**
	\brief Control the integration rate of the current depth into the mapping process.

	This parameter controls how many times a stable 3D points should be seen before it is integrated into the spatial mapping.
	\n Default: 0 (this will define the stability counter based on the mesh resolution, the higher the resolution, the higher the stability counter)
	*/
	int stability_counter;
};


#if WITH_OBJECT_DETECTION
#define MAX_NUMBER_OBJECT 75
#define MAX_TRAJECTORY_SIZE 200

/**
\brief Structure containing a set of parameters for batch object detection.

The default constructor sets all parameters to their default settings.
\note Parameters can be user adjusted.
*/
struct SL_BatchParameters
{
	/**
	\brief Whether to enable the batch option in the object detection module.

	Batch queueing system provides:
	- deep-learning based re-identification
	- trajectory smoothing and filtering

	Default: false
    \note To activate this option, \ref enable must be set to true.
	 */
	bool enable;
	/**
	\brief Max retention time in seconds of a detected object.

	After this time, the same object will mostly have a different id.
	 */
	float id_retention_time;
	/**
	\brief Trajectories will be output in batch with the desired latency in seconds.

	During this waiting time, re-identification of objects is done in the background.
	\note Specifying a short latency will limit the search (falling in timeout) for previously seen object ids but will be closer to real time output.
	\note Specifying a long latency will reduce the change of timeout in re-identification but increase difference with live output.
	 */
	float latency;
};

/**
\brief Structure containing AI model status.
*/
struct SL_AI_Model_status {
	bool downloaded; /**< \brief The model file is currently present on the host.*/
	bool optimized; /**< \brief An engine file with the expected architecture is found.*/
};

/**
\brief Structure containing a set of parameters for the object detection module.

The default constructor sets all parameters to their default settings.
\note Parameters can be user adjusted.
*/
struct SL_ObjectDetectionParameters
{
	/**
	\brief Id of the module instance.

	This is used to identify which object detection module instance is used.
	 */
	unsigned int instance_module_id;
	/**
	\brief Whether the object detection is synchronized to the image or runs in a separate thread.

	If set to true, the detection is run on every \ref sl_grab().
	\n Otherwise, the thread runs at its own speed, which can lead to new detection once in a while.
	\n Default: true
	*/
	bool image_sync; // data synchronized
	/**
	\brief Whether the object detection system includes object tracking capabilities across a sequence of images.

	Default: true
	 */
	bool enable_tracking;
	/**
	\brief Whether the object masks will be computed.

	Default: false
	 */
	bool enable_segmentation;
	/**
	\brief \ref SL_OBJECT_DETECTION_MODEL to use.
	
	Default: \ref SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_FAST
	 */
	enum  SL_OBJECT_DETECTION_MODEL detection_model;
	/**
	\brief Upper depth range for detections.
	
	Default: -1.f (value set in SL_InitParameters.depth_maximum_distance)
	\note The value cannot be greater than SL_InitParameters.depth_maximum_distance and its unit is defined in SL_InitParameters.coordinate_unit.
	 */
	float max_range;
	/**
	 \brief Batching system parameters.

	Batching system (introduced in 3.5) performs short-term re-identification with deep-learning and trajectories filtering.
	\n SL_BatchParameters.enable must to be true to use this feature (by default disabled).
	 */
	struct SL_BatchParameters batch_parameters;
	/**
	\brief Filtering mode that should be applied to raw detections.

	Default: \ref SL_OBJECT_FILTERING_MODE_NMS_3D (same behavior as previous ZED SDK version)
	\note This parameter is only used in detection model [SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_XXX](\ref SL_OBJECT_DETECTION_MODEL)
	and \ref SL_OBJECT_DETECTION_MODEL_CUSTOM_BOX_OBJECTS.
	\note For custom object, it is recommended to use \ref SL_OBJECT_FILTERING_MODE_NMS_3D_PER_CLASS or \ref SL_OBJECT_FILTERING_MODE_NONE.
	\note In this case, you might need to add your own NMS filter before ingesting the boxes into the object detection module.
	*/
	enum SL_OBJECT_FILTERING_MODE filtering_mode;
	/**
	\brief Prediction duration of the ZED SDK when an object is not detected anymore before switching its state to \ref SL_OBJECT_TRACKING_STATE_SEARCHING.
	
	It prevents the jittering of the object state when there is a short misdetection.
    \n The user can define their own prediction time duration.
	\n Default: 0.2f
    \note During this time, the object will have \ref SL_OBJECT_TRACKING_STATE_OK state even if it is not detected.
    \note The duration is expressed in seconds.
    \warning \ref prediction_timeout_s will be clamped to 1 second as the prediction is getting worse with time.
    \warning Setting this parameter to 0 disables the ZED SDK predictions.
	*/
	float prediction_timeout_s;
	/**
	\brief Whether to allow inference to run at a lower precision to improve runtime and memory usage.

	It might increase the initial optimization time and could include downloading calibration data or calibration cache and slightly reduce the accuracy.
	\note The fp16 is automatically enabled if the GPU is compatible and provides a speed up of almost x2 and reduce memory usage by almost half, no precision loss.
	\note This setting allow int8 precision which can speed up by another x2 factor (compared to fp16, or x4 compared to fp32) and half the fp16 memory usage, however some accuracy could be lost.
	\note The accuracy loss should not exceed 1-2% on the compatible models.
	\note The current compatible models are all [SL_AI_MODELS_HUMAN_BODY_XXXX](\ref SL_AI_MODELS).
	 */
	bool allow_reduced_precision_inference;
};

/**
\brief Lists available object classes.
 */
enum SL_OBJECT_CLASS
{
	SL_OBJECT_CLASS_PERSON,          /**< For people detection */
	SL_OBJECT_CLASS_VEHICLE,         /**< For vehicle detection (cars, trucks, buses, motorcycles, etc.) */
	SL_OBJECT_CLASS_BAG,             /**< For bag detection (backpack, handbag, suitcase, etc.) */
	SL_OBJECT_CLASS_ANIMAL,          /**< For animal detection (cow, sheep, horse, dog, cat, bird, etc.) */
	SL_OBJECT_CLASS_ELECTRONICS,     /**< For electronic device detection (cellphone, laptop, etc.) */
	SL_OBJECT_CLASS_FRUIT_VEGETABLE, /**< For fruit and vegetable detection (banana, apple, orange, carrot, etc.) */
	SL_OBJECT_CLASS_SPORT,			 /**< For sport-related object detection (sport ball, etc.) */
	SL_OBJECT_CLASS_LAST
};


/**
\brief Structure containing a set of runtime parameters for the object detection module.

The default constructor sets all parameters to their default settings.
\note Parameters can be adjusted by the user.
*/
struct SL_ObjectDetectionRuntimeParameters
{
	/**
	\brief Confidence threshold.

	From 1 to 100, with 1 meaning a low threshold, more uncertain objects and 99 very few but very precise objects.
	\n Default: 20.f
	\note If the scene contains a lot of objects, increasing the confidence can slightly speed up the process, since every object instance is tracked.
	\note \ref detection_confidence_threshold is used as a fallback when SL_ObjectDetectionRuntimeParameters.object_confidence_threshold is partially set
	 */
	float detection_confidence_threshold;
	/**
	\brief Defines which object types to detect and track.

	\note Fewer object types can slightly speed up the process since every object is tracked.
	\note Will output only the selected classes.
	 */
	int object_class_filter[(int)SL_OBJECT_CLASS_LAST];
	/**
	\brief Array of confidence thresholds for each class (can be empty for some classes).
    \note SL_ObjectDetectionRuntimeParameters.detection_confidence_threshold will be taken as fallback/default value.
	 */
	int object_confidence_threshold[(int)SL_OBJECT_CLASS_LAST];
};

/**
\brief Structure containing a set of parameters for the body tracking module.

The default constructor sets all parameters to their default settings.
\note Parameters can be user adjusted.
 */
struct SL_BodyTrackingParameters {
	/**
	\brief Id of the module instance.

	This is used to identify which body tracking module instance is used.
	 */
	unsigned int instance_module_id;

	/**
	\brief Whether the body tracking is synchronized to the image or runs in a separate thread.

	If set to true, the detection is run on every \ref sl_grab().
	\n Otherwise, the thread runs at its own speed, which can lead to new detection once in a while.
	\n Default: true
	*/
	bool image_sync;

	/**
	\brief Whether the body tracking system includes body/person tracking capabilities across a sequence of images.

	Default: true
	 */
	bool enable_tracking;

	/**
	\brief Whether the body/person masks will be computed.

	Default: false
	 */
	bool enable_segmentation;

	/**
	\brief \ref SL_BODY_TRACKING_MODEL to use.
	
	Default: \ref SL_BODY_TRACKING_MODEL_HUMAN_BODY_ACCURATE
	 */
	enum SL_BODY_TRACKING_MODEL detection_model;

	/**
	\brief Whether to apply the body fitting.

	Default: false
	 */
	bool enable_body_fitting;

	/**
	\brief Body format to be outputted by the ZED SDK with \ref sl_retrieve_bodies().
	
	Default: \ref SL_BODY_FORMAT_BODY_18
	 */
	enum SL_BODY_FORMAT body_format;

	/**
	\brief Selection of keypoints to be outputted by the ZED SDK with \ref sl_retrieve_bodies().
    
	Default: \ref SL_BODY_KEYPOINTS_SELECTION_FULL
	 */
	enum SL_BODY_KEYPOINTS_SELECTION body_selection;

	/**
	\brief Upper depth range for detections.
	
	Default: -1.f (value set in SL_InitParameters.depth_maximum_distance)
	\note The value cannot be greater than SL_InitParameters.depth_maximum_distance and its unit is defined in SL_InitParameters.coordinate_unit.
	 */
	float max_range;

#if 0
	/**
	 \brief Batching system parameters.
	 Batching system (introduced in 3.5) performs short-term re-identification with deep learning and trajectories filtering.
	 * \n BatchParameters::enable must to be true to use this feature (by default disabled)
	 */
	struct SL_BatchParameters batch_parameters;
#endif
	/**
	\brief Prediction duration of the ZED SDK when an object is not detected anymore before switching its state to \ref SL_OBJECT_TRACKING_STATE_SEARCHING.
	
	It prevents the jittering of the object state when there is a short misdetection.
    \n The user can define their own prediction time duration.
	\n Default: 0.2f
    \note During this time, the object will have \ref SL_OBJECT_TRACKING_STATE_OK state even if it is not detected.
    \note The duration is expressed in seconds.
    \warning \ref prediction_timeout_s will be clamped to 1 second as the prediction is getting worse with time.
    \warning Setting this parameter to 0 disables the ZED SDK predictions.
	*/
	float prediction_timeout_s;
	/**
	\brief Whether to allow inference to run at a lower precision to improve runtime and memory usage.

	It might increase the initial optimization time and could include downloading calibration data or calibration cache and slightly reduce the accuracy.
	\note The fp16 is automatically enabled if the GPU is compatible and provides a speed up of almost x2 and reduce memory usage by almost half, no precision loss.
	\note This setting allow int8 precision which can speed up by another x2 factor (compared to fp16, or x4 compared to fp32) and half the fp16 memory usage, however some accuracy could be lost.
	\note The accuracy loss should not exceed 1-2% on the compatible models.
	\note The current compatible models are all [SL_AI_MODELS_HUMAN_BODY_XXXX](\ref SL_AI_MODELS).
	 */
	bool allow_reduced_precision_inference;
};

/**
\brief Structure containing a set of runtime parameters for the body tracking module.

The default constructor sets all parameters to their default settings.
\note Parameters can be adjusted by the user.
 */
struct SL_BodyTrackingRuntimeParameters {
	/**
	\brief Confidence threshold.

	From 1 to 100, with 1 meaning a low threshold, more uncertain objects and 99 very few but very precise objects.
	\n Default: 20.f
	\note If the scene contains a lot of objects, increasing the confidence can slightly speed up the process, since every object instance is tracked.
	 */
	float detection_confidence_threshold;

	/**
	\brief Minimum threshold for the keypoints.

	The ZED SDK will only output the keypoints of the skeletons with threshold greater than this value.
	\n Default: 0
	\note It is useful, for example, to remove unstable fitting results when a skeleton is partially occluded.
	 */
	int minimum_keypoints_threshold;
	/**
	\brief Control of the smoothing of the fitted fused skeleton.

	It is ranged from 0 (low smoothing) and 1 (high smoothing).
	Default: 0
	 */
	float skeleton_smoothing;
};

/**
\brief Structure containing data of a detected object such as its \ref bounding_box, \ref label, \ref id and its 3D \ref position.
*/
struct SL_ObjectData
{
	/**
	\brief Object identification number.

	It is used as a reference when tracking the object through the frames.
	\note Only available if SL_ObjectDetectionParameters.enable_tracking is activated.
	\note Otherwise, it will be set to -1.
	 */
	int id;
	/**
	\brief Unique id to help identify and track AI detections.

    It can be either generated externally, or by using \ref sl_generate_unique_id() or left empty.
	*/
	unsigned char unique_object_id[37];

	/**
	\brief Object raw label.

	It is forwarded from \ref SL_CustomBoxObjectData when using \ref SL_OBJECT_DETECTION_MODEL_CUSTOM_BOX_OBJECTS.
	*/
	int raw_label;
	/**
	\brief Object class/category to identify the object type.
	 */
	enum  SL_OBJECT_CLASS label;
	/**
	\brief Object sub-class/sub-category to identify the object type.
	 */
	enum  SL_OBJECT_SUBCLASS sublabel;
	/**
	\brief Object tracking state.
	 */
	enum  SL_OBJECT_TRACKING_STATE tracking_state;
	/**
	\brief Object action state.
	 */
	enum  SL_OBJECT_ACTION_STATE action_state;
	/**
	\brief Object 3D centroid.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 position;
	/**
	\brief Detection confidence value of the object.
	
	From 0 to 100, a low value means the object might not be localized perfectly or the label (\ref SL_OBJECT_CLASS) is uncertain.
	 */
	float confidence;

	/**
	\brief Mask defining which pixels which belong to the object (in \ref bounding_box_2d and set to 255) and those of the background (set to 0).
	\warning The mask information is only available for tracked objects (\ref SL_OBJECT_TRACKING_STATE_OK) that have a valid depth.
	\warning Otherwise, the mask will not be initialized.
	*/
	int* mask;
	//int* mask; //IntPtr to an sl::Mat object.

	/**
	\brief 2D bounding box of the object represented as four 2D points starting at the top left corner and rotation clockwise.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	\code
	A ------ B
	| Object |
	D ------ C
	\endcode
     */
	struct SL_Vector2 bounding_box_2d[4];
	/**
	\brief 3D centroid of the head of the object (a person).
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	\warning Not available with [SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_XXX](\ref SL_OBJECT_DETECTION_MODEL).
	 */
	struct SL_Vector3 head_position;
	/**
	\brief Defines the object 3D velocity
	\note It is defined in ```SL_InitParameters.coordinate_unit / s``` and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 velocity;
	/**
	\brief 3D object dimensions: width, height, length.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 dimensions;
	/**
	\brief 3D bounding box of the object represented as eight 3D points.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	\code
       1 ------ 2
      /        /|
     0 ------ 3 |
     | Object | 6
     |        |/
     4 ------ 7
    \endcode
	 */
	struct SL_Vector3 bounding_box[8];
	/**
	\brief 3D bounding box of the head of the object (a person) represented as eight 3D points.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	\warning Not available with [SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_XXX](\ref SL_OBJECT_DETECTION_MODEL).
	 */
	struct SL_Vector3 head_bounding_box[8];
	/**
	\brief 2D bounding box of the head of the object (a person) represented as four 2D points starting at the top left corner and rotation clockwise.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	\warning Not available with [SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_XXX](\ref SL_OBJECT_DETECTION_MODEL).
	 */
	struct SL_Vector2 head_bounding_box_2d[4];
	/**
	\brief Covariance matrix of the 3D position.
	\note It is represented by its upper triangular matrix value
	\code
			= [p0, p1, p2]
			[p1, p3, p4]
			[p2, p4, p5]
	\endcode
	where pi is ```position_covariance[i]```
	 */
	float position_covariance[6];
};

/**
\brief Structure that store externally detected objects.

The objects can be ingested with sl_ingest_custom_box_objects() to extract 3D and tracking information over time.
*/
struct SL_CustomBoxObjectData {
	/**
	\brief Unique id to help identify and track AI detections.

    It can be either generated externally, or by using \ref sl_generate_unique_id() or left empty.
	*/
	char unique_object_id[37];
	/**
	\brief 2D bounding box of the object represented as four 2D points starting at the top left corner and rotation clockwise.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	\code
	A ------ B
	| Object |
	D ------ C
	\endcode
	*/
	struct SL_Vector2 bounding_box_2d[4];

	/**
	\brief Object label.

	This information is passed-through and can be used to improve object tracking.
	\note It should define an object class. This means that any similar object (in classification) should share the same label number.
	*/
	int label;

	/**
	\brief Detection confidence value of the object.
	\note The value should be in ```[0-1]```.
	\note It can be used to improve the object tracking.
	*/
	float probability;
	/**
	\brief Provide hypothesis about the object movements (degrees of freedom or DoF) to improve the object tracking.
	- true: 2 DoF projected alongside the floor plane. Case for object standing on the ground such as person, vehicle, etc. 
	\n The projection implies that the objects cannot be superposed on multiple horizontal levels. 
	- false: 6 DoF (full 3D movements are allowed).

	\note This parameter cannot be changed for a given object tracking id.
	\note It is advised to set it by labels to avoid issues.
	*/
	bool is_grounded;
};

/**
\brief Structure containing the results of the object detection module.

The detected objects are listed in \ref object_list.
\note Since the data is transmitted from C++ to C, the size of the structure must be constant.
\note Therefore, there is a limitation of 75 objects in the image.
*/
struct SL_Objects
{
	/**
	\brief Number of detected objects.
	\note You can use it to iterate through the \ref object_list array.
	 */
	int nb_objects;
	/**
	\brief Timestamp corresponding to the frame acquisition. 

    This value is especially useful for the async mode to synchronize the data.
	 */
	unsigned long long timestamp;
	/**
	\brief Whether \ref object_list has already been retrieved or not.
	 */
	int is_new;
	/**
	\brief Whether both the object tracking and the world orientation has been setup.
	 */
	int is_tracked;
	/**
	\brief Current \ref SL_OBJECT_DETECTION_MODEL used.
	 */
	enum  SL_OBJECT_DETECTION_MODEL detection_model;
	/**
	\brief Array of detected objects.
	\note Since the data is transmitted from C++ to C, the size of the structure must be constant.
	\note Therefore, there is a limitation of 75 objects in the image.
	 */
	struct SL_ObjectData object_list[MAX_NUMBER_OBJECT];
};

/**
\brief Structure containing data of a detected body/person such as its \ref bounding_box, \ref id and its 3D \ref position.
*/
struct SL_BodyData
{
	/**
	\brief Body/person identification number.

	It is used as a reference when tracking the body through the frames.
	\note Only available if SL_BodyTrackingParameters.enable_tracking is activated.
	\note Otherwise, it will be set to -1.
	 */
	int id;
	/**
	\brief Unique id to help identify and track AI detections.

    It can be either generated externally, or by using \ref sl_generate_unique_id() or left empty.
	*/
	unsigned char unique_object_id[37];
	/**
	\brief Body/person tracking state.
	 */
	enum  SL_OBJECT_TRACKING_STATE tracking_state;
	/**
	\brief Body/person action state.
	 */
	enum  SL_OBJECT_ACTION_STATE action_state;
	/**
	\brief Body/person 3D centroid.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 position;
	/**
	\brief Body/person 3D velocity.
	\note It is defined in ```SL_InitParameters.coordinate_unit / s``` and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 velocity;
	/**
	\brief Covariance matrix of the 3D position.
	\note It is represented by its upper triangular matrix value
	\code
			= [p0, p1, p2]
			[p1, p3, p4]
			[p2, p4, p5]
	\endcode
	where pi is ```position_covariance[i]```
	 */
	float position_covariance[6];
	/**
	\brief Detection confidence value of the body/person.

	From 0 to 100, a low value means the body might not be localized perfectly.
	 */
	float confidence;

	/**
	\brief Mask defining which pixels which belong to the body/person (in \ref bounding_box_2d and set to 255) and those of the background (set to 0).
	\warning The mask information is only available for tracked bodies (\ref SL_OBJECT_TRACKING_STATE_OK) that have a valid depth.
	\warning Otherwise, the mask will not be initialized.
	*/
	int* mask;
	//int* mask; //IntPtr to an sl::Mat object.

	/**
	\brief 2D bounding box of the body/person represented as four 2D points starting at the top left corner and rotation clockwise.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	\code
	A ------ B
	| Object |
	D ------ C
	\endcode
     */
	struct SL_Vector2 bounding_box_2d[4];
	/**
	\brief 3D centroid of the head of the body/person.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 head_position;

	/**
	\brief 3D body/person dimensions: width, height, length.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 dimensions;
	/**
	\brief 3D bounding box of the body/person represented as eight 3D points.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
    \code
       1 ------ 2
      /        /|
     0 ------ 3 |
     | Object | 6
     |        |/
     4 ------ 7
    \endcode
	 */
	struct SL_Vector3 bounding_box[8];
	/**
	\brief 3D bounding box of the head of the body/person represented as eight 3D points.
	\note It is defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 head_bounding_box[8];
	/**
	\brief 2D bounding box of the head of the body/person represented as four 2D points starting at the top left corner and rotation clockwise.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	 */
	struct SL_Vector2 head_bounding_box_2d[4];
	/**
	\brief Set of useful points representing the human body in 2D.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	\warning In some cases, eg. body partially out of the image, some keypoints can not be detected. They will have negatives coordinates.
	 */
	struct SL_Vector2 keypoint_2d[38];
	/**
	\brief Set of useful points representing the human body in 3D.
	\note They are defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	\warning In some cases, eg. body partially out of the image or missing depth data, some keypoints can not be detected. They will have non finite values.
	 */
	struct SL_Vector3 keypoint[38];

	/**
	\brief Array of detection confidences for each keypoint.
	\note They can not be lower than the SL_BodyTrackingRuntimeParameters.detection_confidence_threshold.
	\warning In some cases, eg. body partially out of the image or missing depth data, some keypoints can not be detected. They will have non finite values.
	 */
	float keypoint_confidence[38];
	/**
	\brief Array of detection covariance for each keypoint.
	\warning In some cases, eg. body partially out of the image or missing depth data, some keypoints can not be detected. Their covariances will be 0.
	 */
	float keypoint_covariances[38][6];
	/**
	\brief Array of local position (position of the child keypoint with respect to its parent expressed in its parent coordinate frame) for each keypoint.
	\note They are expressed in \ref SL_REFERENCE_FRAME_CAMERA or \ref SL_REFERENCE_FRAME_WORLD.
	\warning Not available with \ref SL_BODY_FORMAT_BODY_18.
	*/
	struct SL_Vector3 local_position_per_joint[38];
	/**
	\brief Array of local orientation for each keypoint.
	\note The orientation is represented by a \ref SL_Quaternion (```SL_Quaternion q = SL_Quaternion(qx, qy, qz, qw);```)
	\warning Not available with \ref SL_BODY_FORMAT_BODY_18.
	*/
	struct SL_Quaternion local_orientation_per_joint[38];
	/**
	\brief Global root orientation of the skeleton.

	The orientation is also represented by a quaternion with the same format as \ref local_orientation_per_joint.
	\note The global root position is already accessible in \ref keypoint attribute by using the root index of a given \ref SL_BODY_FORMAT.
	\warning Not available with \ref SL_BODY_FORMAT_BODY_18.
	*/
	struct SL_Quaternion global_root_orientation;
};

/**
\brief Structure containing the results of the body tracking module.

The detected bodies/persons are listed in \ref body_list.
*/
struct SL_Bodies
{
	/**
	\brief Number of detected bodies/persons.
	\note You can use it to iterate through the \ref body_list array.
	 */
	int nb_bodies;
	/**
	\brief Timestamp corresponding to the frame acquisition. 

    This value is especially useful for the async mode to synchronize the data.
	 */
	unsigned long long timestamp;
	/**
	\brief Whether \ref body_list has already been retrieved or not.
	 */
	int is_new;
	/**
	\brief Whether both the body tracking and the world orientation has been setup.
	 */
	int is_tracked;
	/**
	\brief Array of bodies/persons.
	\note Since the data is transmitted from C++ to C, the size of the structure must be constant.
	\note Therefore, there is a limitation of 75 objects in the image.
	 */
	struct SL_BodyData body_list[MAX_NUMBER_OBJECT];
};

/**
\brief Structure containing batched data of a detected objects from the object detection module.

This structure can be used to store trajectories.
*/
struct SL_ObjectsBatch {
	/**
	\brief Number of objects in the \ref SL_ObjectsBatch.
	
	Use this to iterate through the top of \ref positions / \ref velocities / \ref bounding_boxes / etc.
	\note Objects with greater indexes are empty.
	*/
	int nb_data;
	int id; /**< \brief Id of the batch.*/
	enum SL_OBJECT_CLASS label; /**< \brief Objects class/category to identify the object type.*/
	enum SL_OBJECT_SUBCLASS sublabel; /**< \brief Objects sub-class/sub-category to identify the object type.*/
	enum SL_OBJECT_TRACKING_STATE tracking_state; /**< \brief Objects tracking state.*/
	struct SL_Vector3 positions[MAX_TRAJECTORY_SIZE]; /**< \brief Array of positions for each object.*/
	float position_covariances[MAX_TRAJECTORY_SIZE][6]; /**< \brief Array of positions' covariances for each object. */
	struct SL_Vector3 velocities[MAX_TRAJECTORY_SIZE]; /**< \brief Array of 3D velocities for each object.*/
	unsigned long long timestamps[MAX_TRAJECTORY_SIZE]; /**< \brief Array of timestamps for each object.*/
	
	/**
	\brief Array of 2D bounding boxes for each object.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	\code
	A ------ B
	| Object |
	D ------ C
	\endcode
	*/
	struct SL_Vector2 bounding_boxes_2d[MAX_TRAJECTORY_SIZE][4];
	/**
	\brief Array of 3D bounding boxes for each object.
	\note They are defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	\code
       1 ------ 2
      /        /|
     0 ------ 3 |
     | Object | 6
     |        |/
     4 ------ 7
	\endcode
	*/
	struct SL_Vector3 bounding_boxes[MAX_TRAJECTORY_SIZE][8];

	float confidences[MAX_TRAJECTORY_SIZE]; /**< \brief Array of confidences for each object.*/
	enum SL_OBJECT_ACTION_STATE action_states[MAX_TRAJECTORY_SIZE]; /**< \brief Array of action states for each object.*/

	/**
	\brief Array of 2D bounding box of the head for each object (person).
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	\warning Not available with [SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_XXX](\ref SL_OBJECT_DETECTION_MODEL).
	 */
	struct SL_Vector2 head_bounding_boxes_2d[MAX_TRAJECTORY_SIZE][4];
	/**
	\brief Array of 3D bounding box of the head for each object (person).
	\note They are defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	\warning Not available with [SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_XXX](\ref SL_OBJECT_DETECTION_MODEL).
	 */
	struct SL_Vector3 head_bounding_boxes[MAX_TRAJECTORY_SIZE][8];
	/**        
	\brief Array of 3D centroid of the head for each object (person).
	\note They are defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	\warning Not available with [SL_OBJECT_DETECTION_MODEL_MULTI_CLASS_BOX_XXX](\ref SL_OBJECT_DETECTION_MODEL).
	 */
	struct SL_Vector3 head_positions[MAX_TRAJECTORY_SIZE];
};

#if 0
/**
* \brief Structure containing batched data of a detected bodies/persons from the body tracking module.
*/
struct SL_BodiesBatch {
	/**
	\brief Number of detected bodies/persons.
	\note You can use it to iterate through the \ref positions / \ref velocities / \ref boundingBoxes / etc. array.
	*/
	int nb_data;
	int id; /**< Id of the batch.*/
	enum SL_OBJECT_TRACKING_STATE tracking_state; /**< Bodies/persons tracking state.*/
	struct SL_Vector3 positions[MAX_TRAJECTORY_SIZE]; /**< \brief Array of positions for each body/person.*/
	float position_covariances[MAX_TRAJECTORY_SIZE][6]; /**< \brief Array of positions' covariances for each body/person. */
	struct SL_Vector3 velocities[MAX_TRAJECTORY_SIZE]; /**< \brief Array of 3D velocities for each body/person.*/
	unsigned long long timestamps[MAX_TRAJECTORY_SIZE]; /**< \brief Array of timestamps for each body/person.*/
	
	/**
	\brief Array of 2D bounding boxes for each body/person.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	\code
	A ------ B
	| Object |
	D ------ C
	\endcode
	*/
	struct SL_Vector2 bounding_boxes_2d[MAX_TRAJECTORY_SIZE][4];
	/**
	\brief Array of 3D bounding boxes for each body/person.
	\note They are defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	\code
       1 ------ 2
      /        /|
     0 ------ 3 |
     | Object | 6
     |        |/
     4 ------ 7
	\endcode
	*/
	struct SL_Vector3 bounding_boxes[MAX_TRAJECTORY_SIZE][8];

	float confidences[MAX_TRAJECTORY_SIZE]; /**< \brief Array of confidences for each body/person.*/
	enum SL_OBJECT_ACTION_STATE action_states[MAX_TRAJECTORY_SIZE]; /**< \brief Array of action states for each body/person.*/

	/**
	\brief Array of 2D keypoints for each body/person.
	\warning In some cases, eg. body partially out of the image or missing depth data, some keypoints can not be detected. They will have non finite values.
	*/
	struct SL_Vector2 keypoints_2d[MAX_TRAJECTORY_SIZE][70];
	/**
	\brief Array of 3D keypoints for each body/person.
	\warning In some cases, eg. body partially out of the image or missing depth data, some keypoints can not be detected. They will have non finite values.
	*/
	struct SL_Vector3 keypoints[MAX_TRAJECTORY_SIZE][70];

	/**
	\brief Array of 2D bounding box of the head for each body/person.
	\note Expressed in pixels on the original image resolution, ```[0, 0]``` is the top left corner.
	 */
	struct SL_Vector2 head_bounding_boxes_2d[MAX_TRAJECTORY_SIZE][4];
	/**
	\brief Array of 3D bounding box of the head for each body/person.
	\note They are defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 head_bounding_boxes[MAX_TRAJECTORY_SIZE][8];
	/**        
	\brief Array of 3D centroid of the head for each body/person.
	\note They are defined in SL_InitParameters.coordinate_unit and expressed in SL_RuntimeParameters.reference_frame.
	 */
	struct SL_Vector3 head_positions[MAX_TRAJECTORY_SIZE];

	/**
	\brief Array of detection confidences array for each keypoint for each body/person.
	\note They can not be lower than the SL_BodyTrackingRuntimeParameters.detection_confidence_threshold.
	\warning In some cases, eg. body partially out of the image or missing depth data, some keypoints can not be detected. They will have non finite values.
	 */
	float keypoints_confidences[MAX_TRAJECTORY_SIZE][70];
};

#endif

/**
\brief Structure defining a 2D rectangle with top-left corner coordinates and width/height in pixels.
*/
struct SL_Rect
{
	/** 
	\brief x coordinates of top-left corner.
	*/
	int x;
	/** 
	\brief y coordinates of top-left corner.
	*/
	int y;
	/** 
	\brief Width of the rectangle in pixels.
	*/
	int width;
	/** 
	\brief Height of the rectangle in pixels.
	*/
	int height;
};

#endif

/**
\brief Structure defining the input type used in the ZED SDK.

It can be used to select a specific camera with an id or serial number, or from a SVO file.
*/
struct SL_InputType
{
	/**
	\brief Current input type.
	*/
	enum SL_INPUT_TYPE input_type;

	/**
	\brief Serial number of the camera.
	*/
	unsigned int serial_number;

	/**
	\brief Id of the camera.
	*/
	unsigned int id;

	/**
	\brief Path to the SVO file.
	*/
	char svo_input_filename[256];

	/**
	\brief IP address of the streaming camera.
	*/
	char stream_input_ip[128];

	/**
	\brief Port of the streaming camera.
	*/
	unsigned short stream_input_port;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// FUSION API /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
\enum SL_FUSION_ERROR_CODE
\brief Lists the types of error that can be raised by the Fusion.
*/
enum SL_FUSION_ERROR_CODE {
	SL_FUSION_ERROR_CODE_WRONG_BODY_FORMAT = -7, /**< The senders are using different body formats.\n Consider changing them. */
	SL_FUSION_ERROR_CODE_NOT_ENABLE = -6, /**< The following module was not enabled. */
	SL_FUSION_ERROR_CODE_INPUT_FEED_MISMATCH = -5, /**< Some sources are provided by SVO and others by LIVE stream. */
	SL_FUSION_ERROR_CODE_CONNECTION_TIMED_OUT = -4, /**< Connection timed out. Unable to reach the sender.\n Verify the sender's IP/port. */
	SL_FUSION_ERROR_CODE_MEMORY_ALREADY_USED = -3, /**< Intra-process shared memory allocation issue.\n Multiple connections to the same data. */
	SL_FUSION_ERROR_CODE_BAD_IP_ADDRESS = -2, /**< The provided IP address format is incorrect.\n Please provide the IP in the format 'a.b.c.d', where (a, b, c, d) are numbers between 0 and 255. */
	SL_FUSION_ERROR_CODE_FAILURE = -1, /**< Standard code for unsuccessful behavior. */
	SL_FUSION_ERROR_CODE_SUCCESS = 0, /**< Standard code for successful behavior. */
	SL_FUSION_ERROR_CODE_FUSION_ERRATIC_FPS = 1, /**< Significant differences observed between sender's FPS. */
	SL_FUSION_ERROR_CODE_FUSION_FPS_TOO_LOW = 2, /**< At least one sender has an FPS lower than 10 FPS. */
	SL_FUSION_ERROR_CODE_INVALID_TIMESTAMP = 3, /**< Problem detected with the ingested timestamp.\n Sample data will be ignored. */
	SL_FUSION_ERROR_CODE_INVALID_COVARIANCE = 4, /**< Problem detected with the ingested covariance.\n Sample data will be ignored. */
	SL_FUSION_ERROR_CODE_NO_NEW_DATA_AVAILABLE = 5 /**< All data from all sources has been consumed.\n No new data is available for processing. */
};

/**
\enum SL_SENDER_ERROR_CODE
\brief Lists the types of error that can be raised during the Fusion by senders.
*/
enum SL_SENDER_ERROR_CODE {
	SL_SENDER_ERROR_CODE_DISCONNECTED = -1, /**< The sender has been disconnected.*/
	SL_SENDER_ERROR_CODE_SUCCESS = 0, /**< Standard code for successful behavior.*/
	SL_SENDER_ERROR_CODE_GRAB_ERROR = 1, /**< The sender encountered a grab error.*/
	SL_SENDER_ERROR_CODE_ERRATIC_FPS = 2, /**< The sender does not run with a constant frame rate.*/
	SL_SENDER_ERROR_CODE_FPS_TOO_LOW = 3 /**< The frame rate of the sender is lower than 10 FPS.*/
};

/**
\enum SL_COMM_TYPE
\brief Lists the different types of communications available for Fusion module.
*/
enum SL_COMM_TYPE
{
	SL_COMM_TYPE_LOCAL_NETWORK, /**< The sender and receiver are on the same local network and communicate by RTP.\n The communication can be affected by the local network load.*/
	SL_COMM_TYPE_INTRA_PROCESS /**< Both sender and receiver are declared by the same process and can be in different threads.\n This type of communication is optimized.*/
};

struct  SL_CommunicationParameters
{
	enum SL_COMM_TYPE communication_type;
	unsigned int ip_port;
	char ip_add[128];
};

/**
\brief Useful struct to store the Fusion configuration, can be read from /write to a JSON file.
 */
struct SL_FusionConfiguration {
	/**
	The serial number of the used ZED camera.
	*/
	int serial_number;

	/**
	The communication parameters to connect this camera to the Fusion.
	*/
	struct SL_CommunicationParameters comm_param;

	/**
	The WORLD SL_Vector3 of the camera for Fusion.
	*/
	struct SL_Vector3 position;

	/**
	The WORLD SL_Quaternion of the camera for Fusion.
	*/
	struct SL_Quaternion rotation;

	/**
	The input type for the current camera.
	*/
	struct SL_InputType input_type;
};


/**
\brief Holds the options used to initialize the \ref Fusion object.
 */
struct SL_InitFusionParameters
{
	/**
	 * \brief This parameter allows you to select the unit to be used for all metric values of the SDK (depth, point cloud, tracking, mesh, and others).
	 *
	 *  Default : \ref SL_UNIT "SL_UNIT_MILLIMETER"
	 */
	enum SL_UNIT coordinate_units;

	/**
	 * \brief Positional tracking, point clouds and many other features require a given \ref SL_COORDINATE_SYSTEM to be used as reference.
	 * This parameter allows you to select the \ref COORDINATE_SYSTEM used by the \ref SL_Camera to return its measures.
	 * 
	 * This defines the order and the direction of the axis of the coordinate system.
	 * \n Default : \ref SL_COORDINATE_SYSTEM "SL_COORDINATE_SYSTEM_IMAGE"
	 */
	enum SL_COORDINATE_SYSTEM coordinate_system;

	/**
	 * \brief It allows users to extract some stats of the Fusion API like drop frame of each camera, latency, etc...
	 *
	 */
	bool output_performance_metrics;

	/**
	 * \brief Enable the verbosity mode of the SDK.
	 * 
	*/
	bool verbose;

	/**
	 * @brief If specified change the number of period necessary for a source to go in timeout without data. For example, if you set this to 5
	 * then, if any source do not receive data during 5 period, these sources will go to timeout and will be ignored.
	 * 
	 */
	unsigned int timeout_period_number;
};

/**
\brief Holds the options used to initialize the body tracking module of the \ref Fusion.
 */
struct SL_BodyTrackingFusionParameters
{
	/**
	* \brief Defines if the object detection will track objects across images flow.
	*
	* Default: true
	*/
	bool enable_tracking;

	/**
	* \brief Defines if the body fitting will be applied
	*
	* Default: false
	* \note If you enable it and the camera provides data as BODY_18 the fused body format will be BODY_34.
	*/
	bool enable_body_fitting;
};

/**
\brief Holds the options used to change the behavior of the body tracking module at runtime.
 */
struct SL_BodyTrackingFusionRuntimeParameters
{
	/**
	 * \brief If the fused skeleton has less than skeleton_minimum_allowed_keypoints keypoints, it will be discarded.
	 * 
	 * Default: -1.
	 */
	int skeleton_minimum_allowed_keypoints;
	/**
	 * \brief If a skeleton was detected in less than skeleton_minimum_allowed_camera cameras, it will be discarded.
	 *
	 * Default: -1.
	 */
	int skeleton_minimum_allowed_camera;

	/**
	 * \brief This value controls the smoothing of the tracked or fitted fused skeleton.
	 * 
	 * It is ranged from 0 (low smoothing) and 1 (high smoothing).
	 * \n Default: 0.
	 */
	float skeleton_smoothing;
};

/**
\brief Used to identify a specific camera in the Fusion API
 */
struct SL_CameraIdentifier {
	unsigned long long int sn;
};

/**
\brief Holds the metrics of a sender in the fusion process.
 */
struct SL_CameraMetrics
{
	struct SL_CameraIdentifier uuid;

	/**
	 * \brief FPS of the received data.
	 * 
	 */
	float received_fps;

	/**
	 * \brief Latency (in seconds) of the received data.
	 * 
	 */
	float received_latency;

	/**
	 * \brief Latency (in seconds) after Fusion synchronization.
	 * 
	 */
	float synced_latency;

	/**
	 * \brief If no data present is set to false.
	 * 
	 */
	bool is_present;

	/**
	 * \brief Gives the percent of detection par image during the last second in %, a low value means few detections occurs lately.
	 * 
	 */
	float ratio_detection;

	/**
	 * \brief Average time difference for the current fused data.
	 * 
	 */
	float delta_ts;
};

/**
\brief Holds the metrics of the fusion process.
 */
struct SL_FusionMetrics {
	/**
	 * \brief Mean number of camera that provides data during the past second.
	 * 
	 */
	float mean_camera_fused;

	/**
	 * \brief Standard deviation of the data timestamp fused, the lower the better.
	 * 
	 */
	float mean_stdev_between_camera;

	/**
	 * \brief Sender metrics.
	 * 
	 */
	struct SL_CameraMetrics camera_individual_stats[MAX_FUSED_CAMERAS];
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// GNSS API //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
\brief Lists the different states of the GNSS calibration.
*/
enum SL_GNSS_CALIBRATION_STATE {
	SL_GNSS_CALIBRATION_STATE_NOT_CALIBRATED = 0, /**< The GNSS/VIO calibration has not been completed yet.\n Please continue moving the robot while ingesting GNSS data to perform the calibration.*/
	SL_GNSS_CALIBRATION_STATE_CALIBRATED = 1, /**< The GNSS/VIO calibration is completed.*/
	SL_GNSS_CALIBRATION_STATE_RE_CALIBRATION_IN_PROGRESS = 2 /**< A GNSS/VIO re-calibration is in progress in the background.\n Current geo-tracking services may not be accurate.*/
};


/**
\brief Structure containing GNSS data to be used for positional tracking as prior.
 */
struct SL_GNSSData
{
	/**
	 * \brief Longitude in radian.
	 * 
	 */
	double longitude;
	/**
	 * \brief Latitude in radian.
	 * 
	 */
	double latitude;
	/**
	 * \brief Altitude in meters.
	 * 
	 */
	double altitude;
	/**
	 * \brief Timestamp of the GNSS position in nanoseconds (must be aligned with the camera time reference).
	 * 
	 */
	unsigned long long ts;
	/**
	 * \brief Covariance of the position in meter (must be expressed in the ENU coordinate system).
	 * 
	 * For eph, epv GNSS sensors, set it as follow: ```{eph*eph, 0, 0, 0, eph*eph, 0, 0, 0, epv*epv}```.
	 */
	double position_covariance[9];
	/**
	 * \brief Longitude standard deviation.
	 *
	 */
	double longitude_std;
	/**
	 * \brief Latitude standard deviation.
	 *
	 */
	double latitude_std;
	/**
	 * \brief Altitude standard deviation.
	 *
	 */
	double altitude_std;
};

/**
 * \brief Represents a world position in LatLng format.
 *
 */
struct SL_LatLng
{
	/**
	 * \brief Latitude coordinate in radian.
	 *
	 */
	double latitude;
	/**
	 * \brief Longitude coordinate in radian.
	 *
	 */
	double longitude;
	/**
	 * \brief Altitude coordinate in meters.
	 *
	 */
	double altitude;
};

/**
 * \brief Holds Geo reference position.
 *
 */
struct SL_GeoPose
{
	/**
	 * The translation defining the pose in ENU.
	 */
	struct SL_Vector3 translation;
	/**
	 * The rotation defining the pose in ENU.
	 */
	struct SL_Quaternion rotation;
	/**
	 * The pose covariance in ENU.
	 */
	float pose_covariance[36];
	/**
	 * The horizontal accuracy.
	 */
	double horizontal_accuracy;
	/**
	 * The vertical accuracy.
	*/
	double vertical_accuracy;
	/**
	 * The latitude, longitude, altitude.
	 */
	struct SL_LatLng latlng_coordinates;
	/**
	 * The heading.
	 */
	double heading;
	/**
	 * \brief The timestamp of SL_GeoPose.
	 *
	 */
	unsigned long long timestamp;
};

/**
 * \brief Represents a world position in ECEF format.
 *
 */
struct SL_ECEF 
{
	/**
	 * \brief x coordinate of SL_ECEF.
	 *
	 */
	double x;
	/**
	 * \brief y coordinate of SL_ECEF.
	 *
	 */
	double y;
	/**
	 * \brief z coordinate of SL_ECEF.
	 *
	 */
	double z;
};

/**
 * \brief Represents a world position in UTM format.
 *
 */
struct SL_UTM
{
	/**
	 * \brief Northing coordinate.
	 *
	 */
	double northing;
	/**
	 * \brief Easting coordinate.
	 *
	 */
	double easting;
	/**
	 * \brief Gamma coordinate.
	 *
	 */
	double gamma;
	/**
	 * \brief UTMZone of the coordinate.
	 *
	 */
	char UTMZone[256];
};

/**
 * \brief Holds the options used for calibrating GNSS / VIO.
*/
struct SL_GNSSCalibrationParameters {
	/**
	 * \brief This parameter defines the target yaw uncertainty at which the calibration process between GNSS and VIO concludes.
	 * The unit of this parameter is in radian.
	 * 
	 * Default: 0.1 radians
	 */
	float target_yaw_uncertainty;
	/**
	 * @brief When this parameter is enabled (set to true), the calibration process between GNSS and VIO accounts for the uncertainty in the determined translation, thereby facilitating the calibration termination.
	 * The maximum allowable uncertainty is controlled by the 'target_translation_uncertainty' parameter.
	 * 
	 * Default: false
	 */
	bool enable_translation_uncertainty_target;
	/**
	 * \brief This parameter defines the target translation uncertainty at which the calibration process between GNSS and VIO concludes.
	 * 
	 * Default: 10e-2 (10 centimeters)
	 */
	float target_translation_uncertainty;
	/**
	 * \brief This parameter determines whether reinitialization should be performed between GNSS and VIO fusion when a significant disparity is detected between GNSS data and the current fusion data.
	 * It becomes particularly crucial during prolonged GNSS signal loss scenarios.
	 * 
	 * Default: true
	 */
	bool enable_reinitialization;
	/**
	 * \brief This parameter determines the threshold for GNSS/VIO reinitialization.
	 * If the fused position deviates beyond out of the region defined by the product of the GNSS covariance and the gnss_vio_reinit_threshold, a reinitialization will be triggered.
	 * 
	 * Default: 5
	 */
	float gnss_vio_reinit_threshold;
	/**
	 * \brief If this parameter is set to true, the fusion algorithm will used a rough VIO / GNSS calibration at first and then refine it.
	 * This allow you to quickly get a fused position.
	 * 
	 * Default: true
	 */
	bool enable_rolling_calibration;
};

/**
 * \brief Holds the options used for initializing the positional tracking fusion module.
 *
 */
struct SL_PositionalTrackingFusionParameters {
	/**
	 * \brief This attribute is responsible for enabling or not GNSS positional tracking fusion.
	 *
	 * Default: false
	 */
	bool enable_GNSS_fusion;
	/**
	 * \brief Control the VIO / GNSS calibration process.
	 * 
	 */
	struct SL_GNSSCalibrationParameters gnss_calibration_parameters;
};

#if 0

///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Spatial Mapping ////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
\class SpatialMappingFusionParameters
\ingroup Fusion_group
\brief Sets the spatial mapping parameters.

Instantiating with the default constructor will set all parameters to their default values.
\n You can customize these values to fit your application, and then save them to a preset to be loaded in future executions.

\note Users can adjust these parameters as they see fit.
	*/
struct SL_SpatialMappingFusionParameters
{
	/**
	\brief Spatial mapping resolution in meters. Should fit \ref allowed_resolution.
	* Default is 0.05f meter.
	 */
	float resolution_meter;

	/**
	\brief Depth range in meters.
	Can be different from the value set by \ref sl::InitParameters::depth_maximum_distance.
	\n Set to 0 by default. In this case, the range is computed from resolution_meter
	and from the current internal parameters to fit your application.
	 */
	float range_meter;

	/**
	\brief Set to false if you want to ensure consistency between the mesh and its inner chunk data.
	* Set to false by Default.
	\note Updating the mesh is time-consuming. Setting this to true results in better performance.
	 */
	bool use_chunk_only;

	/**
	\brief The maximum CPU memory (in MB) allocated for the meshing process.
	* Default is 2048 MB.
	 */
	int max_memory_usage;

	/**
	 * \brief Control the disparity noise (standard deviation) in px. set a very small value (<0.1) if the depth map of the scene is accurate.
	 * set a big value (>0.5) if the depth map is noisy.
	 * Default is 0.3f.
	 */
	float disparity_std;

	/**
   \brief Adjust the weighting factor for the current depth during the integration process.
	By default, the value is set to 1, which results in the complete integration and fusion of the current depth with the previously integrated depth.
	Setting it to 0 discards all previous data and solely integrates the current depth.
	*/
	float decay;

	bool enable_forget_past;

	/**
	\brief Control the integration rate of the current depth into the mapping process.
	This parameter controls how many times a stable 3D points should be seen before it is integrated into the spatial mapping.
	Default value is 0, this will define the stability counter based on the mesh resolution, the higher the resolution, the higher the stability counter.
	 */
	int stability_counter;
	/**
	\brief The type of spatial map to be created. This dictates the format that will be used for the mapping(e.g. mesh, point cloud). See \ref SPATIAL_MAP_TYPE
	 * Default value is SL_SPATIAL_MAP_TYPE_MESH
	 */
	enum SL_SPATIAL_MAP_TYPE map_type;
};
#endif

#endif
