#pragma once
#include "AbstractAttractor.h"

namespace att {
	class TinkerbellAttractor :
		public AbstractAttractor<2>
	{
	public:
		TinkerbellAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 0.9f,
			real b = -0.6013f,
			real c = 2.0f,
			real d = 0.5f
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

