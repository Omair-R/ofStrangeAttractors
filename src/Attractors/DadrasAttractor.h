#pragma once
#include "AbstractAttractor.h"

namespace att {
	class DadrasAttractor : public AbstractAttractor<3>
	{
	public:
		DadrasAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 3,
			real b = 2.7,
			real c = 1.7,
			real d = 2.0,
			real e = 9.0
		)
			:AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
			m_b = b;
			m_c = c;
			m_d = d;
			m_e = e;
		}

		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;
	private:
		real m_a;
		real m_b;
		real m_c;
		real m_d;
		real m_e;
	};
}