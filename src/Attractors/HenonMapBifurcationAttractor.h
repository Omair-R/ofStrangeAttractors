#pragma once
#include "AbstractAttractor.h"

namespace att {
	class HenonMapBifurcationAttractor :
		public AbstractAttractor<2>
	{
	public:
		HenonMapBifurcationAttractor(
			real step_size,
			bool calc_velocity = false,
			real a = 0.1f,
			real b = 0.03f
		) : AbstractAttractor(step_size, calc_velocity)
		{
			m_a = a;
			m_b = b;
		}
		std::array<real, 2> findDerivative(const std::array<real, 2>& current) override;

	private:
		real m_a;
		real m_b;
	};
}

