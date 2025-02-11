#pragma once
#include "AbstractAttractor.h"

namespace att {
	class LangfordAttractor : public AbstractAttractor<3>
	{
	public:
		LangfordAttractor(
			real step_size, 
			bool calc_velocity = false,
			real a = 0.95,
			real b = 0.7,
			real c = 0.6,
			real d = 3.5,
			real e = 0.25,
			real f = 0.1
			)
			:AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
			m_b = b;
			m_c = c;
			m_d = d;
			m_e = e;
			m_f = f;
		}

		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;
	private:
		real m_a;
		real m_b;
		real m_c;
		real m_d;
		real m_e;
		real m_f;
	};
}