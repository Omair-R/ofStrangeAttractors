#pragma once
#include "AbstractAttractor.h"

namespace att {
	class QuadraticSporttAttractor3D :
		public AbstractAttractor<3>
	{
	public:
		QuadraticSporttAttractor3D(
			real step_size,
			std::array<real, 30> a,
			bool calc_velocity = false
			) : AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
		}
		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;

	private:
		std::array<real, 30> m_a;
	};
}

