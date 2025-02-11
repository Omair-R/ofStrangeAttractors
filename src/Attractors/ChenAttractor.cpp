#include "ChenAttractor.h"

std::array<att::real, 3> att::ChenAttractor::findDerivative(const std::array<real, 3>& current)
{
	real x = current[0];
	real y = current[1];
	real z = current[2];

	real dx_dt = m_alpha * x - y * z;
	real dy_dt = m_beta * y + x * z;
	real dz_dt = m_delta * z + (x * y) / 3;

	return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
}
