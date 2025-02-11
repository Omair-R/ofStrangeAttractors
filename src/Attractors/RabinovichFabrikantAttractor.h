#pragma once
#include "AbstractAttractor.h"

namespace att {
	class RabinovichFabrikantAttractor : public AbstractAttractor<3>
	{
	public:
		RabinovichFabrikantAttractor(
			real step_size,
			bool calc_velocity = false,
			real alpha = 0.14,
			real gamma = 0.1
		)
			:AbstractAttractor(step_size, calc_velocity)
		{
			m_alpha = alpha;
			m_gamma = gamma;
		}

		std::array<real, 3> findDerivative(const std::array<real, 3>& current) override;
	private:
		real m_alpha;
		real m_gamma;
	};
}