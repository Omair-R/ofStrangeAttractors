#pragma once
#include "AbstractAttractor.h"

namespace att {
	class DuffingAttractor :
		public AbstractAttractor<2>
	{
	public:
		DuffingAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 0.25f,
			real b = 0.3f,
			real w = 1.0f
		) : AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
			m_b = b;
			m_w = w;
		}
		std::array<real, 2> findDerivative(const std::array<real, 2>& current) override;

	private:
		real m_a;
		real m_b;
		real m_w;
		real m_t = 0;
	};
}

