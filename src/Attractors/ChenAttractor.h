#pragma once
#include "AbstractAttractor.h"

namespace att {
	class ChenAttractor : public AbstractAttractor<3>
	{
	public:
		ChenAttractor(
			real step_size,
			bool calc_velocity = false,
			real alpha = 5.0, 
			real beta = -10.0, 
			real delta = -0.38
		)
			: AbstractAttractor(step_size, calc_velocity)
		{
			m_alpha = alpha;
			m_beta = delta;
			m_delta = beta;
		}
		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;

	private:
		real m_alpha;
		real m_beta;
		real m_delta;
	};
}


