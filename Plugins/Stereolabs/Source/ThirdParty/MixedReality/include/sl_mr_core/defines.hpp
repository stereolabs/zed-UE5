//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#ifndef __DEFINES_H__
#define __DEFINES_H__

#ifdef _WIN32 
#ifdef SLMRCORE_NOEXPORT
#define SLMRCORE_API
#else
	#ifdef  SLMRCORE_EXPORT  
		#define SLMRCORE_API __declspec(dllexport)   
	#else  
		#define SLMRCORE_API __declspec(dllimport)   
	#endif
#endif
#else
    #define SLMRCORE_API
#endif

#include <cstdint>
#include <Eigen/Eigen>

namespace sl {
	namespace mr {


    /**
    \class Vector2
    \ingroup Core_group
    \brief Represents a two dimensions vector for both CPU and GPU.
     */
    template <typename T>
    class SLMRCORE_API Vector2 {
        static const int nbElem = 2;
    public:
        /// @cond

        union {

            struct {
                T x, y;
            };
            T v[nbElem];
        };
        /// @endcond

        inline int size() const {
            return nbElem;
        }

        Vector2() {
        }

        Vector2(const T &t) {
            this->x = t;
            this->y = t;
        }

        Vector2(const T *tp) {
            this->x = tp[0];
            this->y = tp[1];
        }

        Vector2(const T v0, const T v1) {
            this->x = v0;
            this->y = v1;
        }

        Vector2<T>(const Vector2<T> &v) {
            this->x = v.x;
            this->y = v.y;
        }

        const T *ptr() const {
            return &this->v[0];
        }

        inline Vector2 &setValues(const T *b) {
            this->x = b[0];
            this->y = b[1];
            return *this;
        }

        T &operator[](int i) {
            return this->v[i];
        }

        inline friend Vector2<T> &operator*=(Vector2<T>&itself, T d) {
            itself.x *= d;
            itself.y *= d;
            return itself;
        }

        inline friend Vector2<T> &operator*=(Vector2<T>&itself, const Vector2<T> &b) {
            itself.x *= b.x;
            itself.y *= b.y;
            return itself;
        }

        inline friend Vector2<T> &operator/=(Vector2<T>&itself, T d) {
            if (d == 0) return itself;
            itself.x /= d;
            itself.y /= d;
            return itself;
        }

        inline friend Vector2<T> &operator/=(Vector2<T>&itself, const Vector2<T> &b) {
            itself.x /= b.x;
            itself.y /= b.y;
            return itself;
        }

        inline friend Vector2<T> &operator+=(Vector2<T>&itself, const Vector2<T> &b) {
            itself.x += b.x;
            itself.y += b.y;
            return itself;
        }

        inline friend Vector2<T> &operator-=(Vector2<T>&itself, const Vector2<T> &b) {
            itself.x -= b.x;
            itself.y -= b.y;
            return itself;
        }

        /**
        \brief returns the norm of the vector
         */
        inline float norm() {
            return sqrt(this->x * this->x + this->y * this->y);
        }

        /**
        \brief returns the squared norm of the vector
         */
        inline float square() {
            return (this->x * this->x + this->y * this->y);
        }

        /**
        \brief returns the sum of the vector
         */
        inline float sum() {
            return (this->x + this->y);
        }

        /**
        \brief returns the dot product of two vector
         */
        inline float dot(const Vector2<T> &a, const Vector2<T> &b) {
            return (a.x * b.x + a.y * b.y);
        }

        /**
        \brief returns the distance between two vector
         */
        inline float distance(const Vector2<T> &a, const Vector2<T> &b) {
            return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
        }

        inline friend Vector2<T> operator+(const Vector2<T> &a, const Vector2<T> &b) {
            Vector2<T> tmp(a);
            return tmp += b;
        }

        inline friend Vector2<T> operator-(const Vector2<T> &a, const Vector2<T> &b) {
            Vector2<T> tmp(a);
            return tmp -= b;
        }

        inline friend Vector2<T> operator*(const Vector2<T> &a, T b) {
            Vector2<T> tmp(a);
            return tmp *= b;
        }

        inline friend Vector2<T> operator*(const Vector2<T> &a, const Vector2<T> &b) {
            Vector2<T> tmp(a);
            return tmp *= b;
        }

        inline friend Vector2<T> operator/(const Vector2<T> &a, T b) {
            Vector2<T> tmp(a);
            return tmp /= b;
        }

        inline friend Vector2<T> operator/(const Vector2<T> &a, const Vector2<T> &b) {
            Vector2<T> tmp(a);
            return tmp /= b;
        }
    };

    /**
    \class Vector3
    \ingroup Core_group
    \brief Represents a three dimensions vector for both CPU and GPU.
     */
    template <typename T>
    class  SLMRCORE_API Vector3 {
        static const int nbElem = 3;
    public:
        /// @cond

        union {

            struct {
                T x, y, z;
            };

            struct {
                T r, g, b;
            };

            struct {
                T tx, ty, tz;
            };
            T v[nbElem];
        };
        /// @endcond

        inline int size() const {
            return nbElem;
        }

        Vector3() {
        }

        Vector3(const T &t) {
            this->x = t;
            this->y = t;
            this->z = t;
        }

        Vector3(const T *tp) {
            this->x = tp[0];
            this->y = tp[1];
            this->z = tp[2];
        }

        Vector3(const T v0, const T v1, const T v2) {
            this->x = v0;
            this->y = v1;
            this->z = v2;
        }

        Vector3<T>(const Vector3<T> &v) {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
        }

        Vector3<T>(const Vector2<T> &v, const T d = 0) {
            this->x = v.x;
            this->y = v.y;
            this->z = d;
        }

        const T *ptr() const {
            return &this->v[0];
        }

        inline Vector3<T> &setValues(const T *b) {
            this->x = b[0];
            this->y = b[1];
            this->z = b[2];
            return *this;
        }


        T &operator[](int i) {
            return this->v[i];
        }

        inline friend Vector3<T> &operator+=(Vector3<T>&itself, T d) {
            itself.x += d;
            itself.y += d;
            itself.z += d;
            return itself;
        }

        inline friend Vector3<T> &operator+=(Vector3<T>&itself, const Vector3<T> &b) {
            itself.x += b.x;
            itself.y += b.y;
            itself.z += b.z;
            return itself;
        }

        inline friend Vector3<T> &operator-=(Vector3<T>&itself, T d) {
            itself.x -= d;
            itself.y -= d;
            itself.z -= d;
            return itself;
        }

        inline friend Vector3<T> &operator-=(Vector3<T>&itself, const Vector3<T> &b) {
            itself.x -= b.x;
            itself.y -= b.y;
            itself.z -= b.z;
            return itself;
        }

        inline friend Vector3<T> &operator*=(Vector3<T>&itself, T d) {
            itself.x *= d;
            itself.y *= d;
            itself.z *= d;
            return itself;
        }

        inline friend Vector3<T> &operator*=(Vector3<T>&itself, const Vector3<T> &b) {
            itself.x *= b.x;
            itself.y *= b.y;
            itself.z *= b.z;
            return itself;
        }


        inline friend Vector3<T> &operator/=(Vector3<T>&itself, T d) {
            if (d == 0) return itself;
            itself.x /= d;
            itself.y /= d;
            itself.z /= d;
            return itself;
        }

        inline friend Vector3<T> &operator/=(Vector3<T>&itself, const Vector3<T> &b) {
            if (b.x != 0) itself.x /= b.x;
            if (b.y != 0) itself.y /= b.y;
            if (b.z != 0) itself.z /= b.z;
            return itself;
        }

        /**
        \brief returns the norm of the vector
         */
        inline float norm() {
            return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
        }

        /**
        \brief returns the squared norm of the vector
         */
        inline float square() {
            return (this->x * this->x + this->y * this->y + this->z * this->z);
        }

        /**
        \brief returns the sum of the vector
         */
        inline float sum() {
            return (this->x + this->y + this->z);
        }

        /**
        \brief returns the dot product of two vector
         */
        static inline float dot(const Vector3<T> &a, const Vector3<T> &b) {
            return (a.x * b.x + a.y * b.y + a.z * b.z);
        }

        /**
        \brief returns the distance between two vector
         */
        static inline float distance(const Vector3<T> &a, const Vector3<T> &b) {
            return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
        }

        /**
        \brief returns the cross product between two vector
         */
        static inline Vector3<T> cross(const Vector3<T> &a, const Vector3<T> &b) {
            Vector3<T> r;
            r.x = a.y * b.z - a.z * b.y;
            r.y = a.z * b.x - a.x * b.z;
            r.z = a.x * b.y - a.y * b.x;
            return r;
        }

        inline friend Vector3<T> operator+(const Vector3<T> &a, const Vector3<T> &b) {
            Vector3<T> tmp(a);
            return tmp += b;
        }

        inline friend Vector3<T> operator-(const Vector3<T> &a, const Vector3<T> &b) {
            Vector3<T> tmp(a);
            return tmp -= b;
        }

        inline friend Vector3<T> operator*(const Vector3<T> &a, T b) {
            Vector3<T> tmp(a);
            return tmp *= b;
        }

        inline friend Vector3<T> operator*(T a, const Vector3<T> &b) {
            Vector3<T> tmp(a);
            return tmp *= b;
        }

        inline friend Vector3<T> operator*(const Vector3<T> &a, const Vector3<T> &b) {
            Vector3<T> tmp(a);
            return tmp *= b;
        }


        inline friend Vector3<T> operator/(const Vector3<T> &a, T b) {
            Vector3<T> tmp(a);
            return tmp /= b;
        }

        inline friend Vector3<T> operator/(const Vector3<T> &a, const Vector3<T> &b) {
            Vector3<T> tmp(a);
            return tmp /= b;
        }
    };

    /**
    \class Vector4
    \ingroup Core_group
    \brief Represents a four dimensions vector for both CPU and GPU.
     */
    template <typename T>
    class SLMRCORE_API Vector4 {
        static const int nbElem = 4;
    public:
        /// @cond

        union {

            struct {
                T x, y, z, w;
            };

            struct {
                T r, g, b, a;
            };

            struct {
                T ox, oy, oz, ow;
            };
            T v[nbElem];
        };
        /// @endcond

        inline int size() const {
            return nbElem;
        }

        Vector4() {
        }

        Vector4(const T &t) {
            this->x = t;
            this->y = t;
            this->z = t;
            this->w = t;
        }

        Vector4(const T *tp) {
            this->x = tp[0];
            this->y = tp[1];
            this->z = tp[2];
            this->w = tp[3];
        }

        Vector4(const T v0, const T v1, const T v2, const T v3) {
            this->x = v0;
            this->y = v1;
            this->z = v2;
            this->w = v3;
        }

        Vector4<T>(const Vector4<T> &v) {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            this->w = v.w;
        }

        Vector4<T>(const Vector4<T> &v, const T d) {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            this->w = d;
        }

        Vector4<T>(const Vector3<T>& v, const T d = 0) {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            this->w = d;
        }

        const T *ptr() const {
            return &this->v[0];
        }

        inline Vector4<T> &setValues(const T *b) {
            this->x = b[0];
            this->y = b[1];
            this->z = b[2];
            this->w = b[3];
            return *this;
        }

        inline Vector4<T>& operator=(const Vector3<T>& other) {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            return *this;
        }

        T &operator[](int i) {
            return this->v[i];
        }

        const T &operator[](int i) const {
            return this->v[i];
        }

        inline friend Vector4<T> &operator+=(Vector4<T>&itself, T d) {
            itself.x += d;
            itself.y += d;
            itself.z += d;
            itself.w += d;
            return itself;
        }

        inline friend Vector4<T> &operator+=(Vector4<T>&itself, const Vector4<T> &b) {
            itself.x += b.x;
            itself.y += b.y;
            itself.z += b.z;
            itself.w += b.w;
            return itself;
        }

        inline friend Vector4<T> &operator-=(Vector4<T>&itself, T d) {
            itself.x -= d;
            itself.y -= d;
            itself.z -= d;
            itself.w -= d;
            return itself;
        }

        inline friend Vector4<T> &operator-=(Vector4<T>&itself, const Vector4<T> &b) {
            itself.x -= b.x;
            itself.y -= b.y;
            itself.z -= b.z;
            itself.w -= b.w;
            return itself;
        }

        inline friend Vector4<T> &operator*=(Vector4<T>&itself, T d) {
            itself.x *= d;
            itself.y *= d;
            itself.z *= d;
            itself.w *= d;
            return itself;
        }

        inline friend Vector4<T> &operator*=(Vector4<T>&itself, const Vector4<T> &b) {
            itself.x *= b.x;
            itself.y *= b.y;
            itself.z *= b.z;
            itself.w *= b.w;
            return itself;
        }



        inline friend Vector4<T> &operator/=(Vector4<T>&itself, T d) {
            if (d == 0) return itself;
            itself.x /= d;
            itself.y /= d;
            itself.z /= d;
            itself.w /= d;
            return itself;
        }

        inline friend Vector4<T> &operator/=(Vector4<T>&itself, const Vector4<T> &b) {
            if (b.x != 0) itself.x /= b.x;
            if (b.y != 0) itself.y /= b.y;
            if (b.z != 0) itself.z /= b.z;
            if (b.w != 0) itself.w /= b.w;
            return itself;
        }

        /**
        \brief returns the norm of the vector
         */
        inline float norm() {
            return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
        }

        /**
        \brief returns the squared norm of the vector
         */
        inline float square() {
            return (this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
        }

        /**
        \brief returns the sum of the vector
         */
        inline float sum() {
            return (this->x + this->y + this->z + this->w);
        }

        /**
        \brief returns the dot product of two vector
         */
        static inline float dot(const Vector4<T> &a, const Vector4<T> &b) {
            return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
        }

        /**
        \brief returns the distance between two vector
         */
        static inline float distance(const Vector4<T> &a, const Vector4<T> &b) {
            return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2) + pow(a.w - b.w, 2));
        }

        inline friend Vector4<T> operator-(const Vector4<T> &b) {
            Vector4<T> tmp;
            tmp.x = -b.x;
            tmp.y = -b.y;
            tmp.z = -b.z;
            tmp.w = -b.w;
            return tmp;
        }

        inline friend Vector4<T> operator+(const Vector4<T> &a, const Vector4<T> &b) {
            Vector4<T> tmp(a);
            return tmp += b;
        }

        inline friend Vector4<T> operator-(const Vector4<T> &a, const Vector4<T> &b) {
            Vector4<T> tmp(a);
            return tmp -= b;
        }

        inline friend Vector4<T> operator*(const Vector4<T> &a, T b) {
            Vector4<T> tmp(a);
            return tmp *= b;
        }

        inline friend Vector4<T> operator*(T a, const Vector4<T> &b) {
            Vector4<T> tmp(a);
            return tmp *= b;
        }

        inline friend Vector4<T> operator*(const Vector4<T> &a, const Vector4<T> &b) {
            Vector4<T> tmp(a);
            return tmp *= b;
        }

        inline friend Vector4<T> operator/(const Vector4<T> &a, T b) {
            Vector4<T> tmp(a);
            return tmp /= b;
        }

        inline friend Vector4<T> operator/(const Vector4<T> &a, const Vector4<T> &b) {
            Vector4<T> tmp(a);
            return tmp /= b;
        }
    };

        ///@{
        ///  @name Types definition

        #ifndef float1
            typedef float float1;
        #endif

        #ifndef float2
            typedef Vector2<float> float2;
        #endif

        #ifndef float3
            typedef Vector3<float> float3;
        #endif

        #ifndef float4
            typedef Vector4<float> float4;
        #endif

        #ifndef uchar1
            typedef unsigned char uchar1;
        #endif

        #ifndef uchar2
            typedef Vector2<unsigned char> uchar2;
        #endif

        #ifndef uchar3
            typedef Vector3<unsigned char> uchar3;
        #endif

        #ifndef uchar4
            typedef Vector4<unsigned char> uchar4;
        #endif

        #ifndef double1
            typedef double double1;
        #endif

        #ifndef double2
            typedef Vector2<double> double2;
        #endif

        #ifndef double3
            typedef Vector3<double> double3;
        #endif

        #ifndef double4
            typedef Vector4<double> double4;
        #endif

        #ifndef uint1
            typedef unsigned int uint1;
        #endif

        #ifndef uint2
            typedef Vector2<unsigned int> uint2;
        #endif

        #ifndef uint3
            typedef Vector3<unsigned int> uint3;
        #endif

        #ifndef uint4
            typedef Vector4<unsigned int> uint4;
        #endif

        struct SLMRCORE_API Resolution {
           int width;
           int height;
        };

		/**
		 * \enum HMD_DEVICE_TYPE
		 * \ingroup Enumerations
		 * \brief Types of HMD supported
		 */
		enum class HMD_DEVICE_TYPE : uint8_t {
			HMD_DEVICE_TYPE_UNKNOWN,
			HMD_DEVICE_TYPE_OCULUS,
			HMD_DEVICE_TYPE_HTC
		};

		struct SLMRCORE_API Intrinsic
		{
			float fx;
			float fy;
			float cx;
			float cy;
		};

		/**
		 * \struct noiseFactors
		 * \brief Factors of each channel for noise generation
		 */
		struct SLMRCORE_API noiseFactors {

            noiseFactors(sl::mr::float2 r, sl::mr::float2 g, sl::mr::float2 b)
				:
				r(r),
				g(g),
				b(b)
			{}

			/** r channel */
            sl::mr::float2 r;

			/** g channel */
            sl::mr::float2 g;

			/** b channel */
            sl::mr::float2 b;
		};


		/**
		* \struct trackingData
		* \brief Tracking data
		*/
		struct SLMRCORE_API trackingData {
			/** Path transform from tracking origin ((0, 0, 0) in world space relative to left eye) */
            Eigen::Matrix4f zedPathTransform;

			/** Zed world space transform ((Location/rotation in world space) with anti drift in stereo) */
            Eigen::Matrix4f  zedWorldTransform;

			/**	Zed world transform without camera offset (Head location/rotation) */
            Eigen::Matrix4f  offsetZedWorldTransform;

			/** Tracking state */
            int trackingState;
		};

        typedef unsigned long long latencyTime;

		/**
		* \struct keyPose
		* \brief A pair transform/time stamp
		*/
		struct SLMRCORE_API keyPose {
			keyPose()
			{}

            keyPose(Eigen::Matrix4f  transform, unsigned long long timeStamp)
				:
				transform(transform),
				timeStamp(timeStamp)
			{}

			/** The pose transform */
            Eigen::Matrix4f transform;

			/** The pose time stamp */
            unsigned long long timeStamp;
		};


		/**
		* \struct keyPose
		* \brief A pair transform/time stamp
		*/
		struct SLMRCORE_API keyOrientation {
			keyOrientation()
			{}

            keyOrientation(Eigen::Quaternionf orientation, unsigned long long timeStamp)
				:
				orientation(orientation),
				timeStamp(timeStamp)
			{}

			/** The pose transform */
            Eigen::Quaternionf orientation;

			/** The pose time stamp */
           unsigned long long timeStamp;
		};
	}
}

#endif // __DEFINES_H__
