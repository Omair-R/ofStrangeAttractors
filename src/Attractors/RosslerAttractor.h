#pragma once
#include "AbstractAttractor.h"

namespace att {
	class RosslerAttractor : public AbstractAttractor<3>
	{
	public:
		RosslerAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 0.2,
			real b = 0.2,
			real c = 5.7
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