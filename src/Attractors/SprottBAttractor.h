#pragma once
#include "AbstractAttractor.h"

namespace att {
	class SprottBAttractor : public AbstractAttractor<3>
	{
	public:
		SprottBAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 0.4,
			real b = 1.2,
			real c = 1.0
		)
			:AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
			m_b = b;
			m_c = c;

		}

		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;
	private:
		real m_a;
		real m_b;
		real m_c;
	};
}