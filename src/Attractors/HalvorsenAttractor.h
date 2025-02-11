#pragma once
#include "AbstractAttractor.h"

namespace att {
	class HalvorsenAttractor : public AbstractAttractor<3>
	{
	public:
		HalvorsenAttractor(
			real step_size, 
			bool calc_velocity = false,
			real a = 1.89)
			:AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
		}

		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;
	private:
		real m_a;
	};
}