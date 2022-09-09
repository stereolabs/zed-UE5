//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#ifndef __ANTIDRIFT_H__
#define __ANTIDRIFT_H__

#include "sl_mr_core/defines.hpp"

namespace sl {
	namespace mr {

		/**
		 * \brief Initialize drift corrector. No functions can be called before initialization.
		 */
		SLMRCORE_API void driftCorrectorInitialize();

		/**
		 * \brief Shutdown drift corrector. No functions can be called after shutdown.
		 */
		SLMRCORE_API void driftCorrectorShutdown();

		/**
		 * \brief Compute the tracking data
		 * @param trackingData				The tracking data to apply anti drift to
		 * @param HMDTransform				The HMD transform
		 * @param latencyCorrectorTransform The latency corrector transform
		 * @param hasValidTrackingPosition  True if the position tracking is enabled
		 */
        SLMRCORE_API bool driftCorrectorGetTrackingData(sl::mr::trackingData& trackingData, const Eigen::Matrix4f& HMDTransform, const Eigen::Matrix4f& latencyCorrectorTransform, bool hasValidTrackingPosition, bool checkDrift);

		/**
		 * \brief Set calibration transform
		 * @param calibrationTransform The transform created from calibration
		 */
        SLMRCORE_API void driftCorrectorSetCalibrationTransform(const Eigen::Matrix4f& calibrationTransform);

		/**
		 * \brief Set const offset transform
		 * @param constOffsetTransform The transform
		 */
        SLMRCORE_API void driftCorrectorSetConstOffsetTransfrom(const Eigen::Matrix4f& constOffsetTransform);

		/**
		 * \brief Set the tracking offset transform
		 * @param trackingOffsetTransform The transform
		 */
        SLMRCORE_API void driftCorrectorSetTrackingOffsetTransfrom(const Eigen::Matrix4f& trackingOffsetTransform);
	}
}

#endif // __ANTIDRIFT_H__
