#pragma once
#include "AbstractAttractor.h"

namespace att {
	class JohnnySvenssonAttractor :
		public AbstractAttractor<2>
	{
	public:
		JohnnySvenssonAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 1.4f,
			real b = 1.4f,
			real c = 1.56f,
			real d = -6.56f
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

