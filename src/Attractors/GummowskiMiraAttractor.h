#pragma once
#include "AbstractAttractor.h"
#include <cmath>
namespace att {
	class GummowskiMiraAttractor :
		public AbstractAttractor<2>
	{
	public:
		GummowskiMiraAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 0.01f,
			real b = 0.1f,
			real c = -0.46f
		) : AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
			m_b = b;
			m_c = c;
		}
		std::array<real, 2> findDerivative(const std::array<real, 2>& current) override;

	private:
		real _f(real x);
		real m_a;
		real m_b;
		real m_c;
	};
}

