#pragma once
#include "AbstractAttractor.h"

namespace att {
	class ThomasSymmetricAttractor : public AbstractAttractor<3>
	{
	public:
		ThomasSymmetricAttractor(real step_size, bool calc_velocity = false, real b= 0.208186)
			:AbstractAttractor(step_size, calc_velocity)
		{
			m_b = b;
		}

		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;
	private:
		real m_b;
	};
}