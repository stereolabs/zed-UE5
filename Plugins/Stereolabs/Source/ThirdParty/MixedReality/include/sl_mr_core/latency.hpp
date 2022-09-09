//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#ifndef __LATENCY_H__
#define __LATENCY_H__

#include "sl_mr_core/defines.hpp"

namespace sl {
	namespace mr {

		enum EHmdType {
			eHmdType_Vive,
			eHmdType_Oculus
		};

		/**
		 * \brief Initialize latency corrector. No functions can be called before initialization.
		 */
		SLMRCORE_API void latencyCorrectorInitialize(EHmdType type);

		/**
		 * \brief Shutdown latency corrector. No functions can be called after shutdown.
		 */
		SLMRCORE_API void latencyCorrectorShutdown();

		/**
		* \brief Shutdown latency corrector. No functions can be called after shutdown.
		*/
        SLMRCORE_API void latencyCorrectorAdjOffset(unsigned long long offset);

		/**
		 * \brief Delete latency corrector
		 * @param keyPose		   The key
		 */
		SLMRCORE_API void latencyCorrectorAddKeyPose(const sl::mr::keyPose& keyPose);

		/**
		 * \brief Delete latency corrector
		 * @param timeStamp        Timestamp of the transform
		 * @param outTransform     Retrieved transform
		 * @return True if the transform is retrieved
		 */
        SLMRCORE_API bool latencyCorrectorGetTransform(unsigned long long timeStamp, Eigen::Matrix4f& outTransform, bool useLatencyTime = true);

		SLMRCORE_API void ComputeOptimSO3(std::vector<sl::mr::keyOrientation> serie1, std::vector<sl::mr::keyOrientation> serie2, sl::mr::keyOrientation& output);

	}
}

#endif // __LATENCY_H__ 
