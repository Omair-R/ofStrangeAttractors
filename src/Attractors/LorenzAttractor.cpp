#include "LorenzAttractor.h"

namespace att {
	
	std::array<real, 3> LorenzAttractor::findDerivative(const std::array<real, 3>& current)
	{
		real x = current[0];
		real y = current[1];
		real z = current[2];

		real dx_dt = m_sigma * (y - x);
		real dy_dt = x * (m_rho - z) - y;
		real dz_dt = x * y - m_beta * z;


		return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
	}
}
