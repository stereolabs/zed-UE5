//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "sl_mr_core/defines.hpp"
#include <sl_mr_core/slgo/core/base_binary_edge.h>
#include <sl_mr_core/slgo/core/base_unary_edge.h>
#include <sl_mr_core/slgo/core/base_multi_edge.h>
#include <sl_mr_core/slgo/core/base_vertex.h>
#include <sl_mr_core/slgo/core/g2o_core_api.h>
#include <sl_mr_core/slgo/core/sparse_optimizer.h>
#include <sl_mr_core/slgo/core/optimization_algorithm_levenberg.h>
#include <sl_mr_core/slgo/core/optimization_algorithm_gauss_newton.h>
#include <sl_mr_core/slgo/core/block_solver.h>
#include <sl_mr_core/slgo/core/solver.h>
#include <sl_mr_core/slgo/solvers/dense/linear_solver_dense.h>
#include <sl_mr_core/slgo/stuff/misc.h>
#include "sl_mr_core/sophus/so3.hpp"
#include <memory>
#include <deque>


namespace sl {
	namespace mr {

		struct SO3data
		{
            unsigned long long timestampMicroSec;
			Sophus::SO3d data;
		};

		struct SO3result
		{
			int delayMicroSec;
			Sophus::SO3d passageMatrix1to2;
		};


		class VertexSO3 : public sl_mr_g2o::BaseVertex<3, Sophus::SO3d> {
		public:
			EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

			VertexSO3();
			virtual bool read(std::istream& is);
			virtual bool write(std::ostream& os) const;
			virtual void oplusImpl(const double* update_);
			virtual void setToOriginImpl();
		};

		class VertexTimeShift : public sl_mr_g2o::BaseVertex<1, double>
		{
		public:
			EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

			VertexTimeShift();
			virtual bool read(std::istream& is);
			virtual bool write(std::ostream& os) const;
			virtual void oplusImpl(const double* update_);
			virtual void setToOriginImpl();
		};

		class EdgeSO3Calib : public sl_mr_g2o::BaseMultiEdge<3, SO3data>
		{
		public:
			EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

			EdgeSO3Calib(std::shared_ptr<std::deque<SO3data>> interpolatedSerieIn);
			virtual bool read(std::istream& is);
			virtual bool write(std::ostream& os) const;
			void computeError();
            Sophus::SO3d InterpolateSO3(unsigned long long timestamp);


		private:
			std::shared_ptr<std::deque<SO3data>> interpolatedSerie;
		};


		class SLMRCORE_API CalibratorSO3
		{
		public:
			CalibratorSO3();

		public:
			SO3result Calibrate();

			std::shared_ptr<std::deque<SO3data>> serie1;
			std::shared_ptr<std::deque<SO3data>> serie2;

		private:
			std::shared_ptr<sl_mr_g2o::SparseOptimizer> optimizer;
		};


	}
}
