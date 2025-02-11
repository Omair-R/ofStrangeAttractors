#pragma once
#include "AbstractAttractor.h"

namespace att {
	class LorenzAttractor : public AbstractAttractor<3>
	{
	public:
		LorenzAttractor(real step_size, bool calc_velocity = false, real sigma = 10.0f, real rho = 28.0f, real beta = 8 / 3)
			: AbstractAttractor(step_size, calc_velocity)
		{
			m_sigma = sigma;
			m_rho = rho;
			m_beta = beta;
		}
		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;

	private:
		real m_sigma;
		real m_rho;
		real m_beta;
	};
}


