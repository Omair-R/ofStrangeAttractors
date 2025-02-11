#pragma once

#include "AbstractAttractor.h"

namespace att {
	class PeterDeJongAttractor :
		public AbstractAttractor<2>
	{
	public:
		PeterDeJongAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 0.970f,
			real b = -1.899f,
			real c = 1.381f,
			real d = -1.506f
		) : AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
			m_b = b;
			m_c = c;
			m_d = d;
		}
		std::array<real, 2> findDerivative(const std::array<real, 2>& current) override;

	private:
		real m_a;
		real m_b;
		real m_c;
		real m_d;
	};
}