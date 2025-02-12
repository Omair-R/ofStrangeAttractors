#pragma once
#include "AbstractAttractor.h"

namespace att {
	class CubicSporttAttractor :
		public AbstractAttractor<2>
	{
	public:
		CubicSporttAttractor(
			real step_size,
			std::array<real, 20> a,
			bool calc_velocity = false
			) : AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
		}
		std::array<real, 2> findDerivative(const std::array<real, 2>& current) override;

	private:
		std::array<real, 20> m_a;
	};
}

