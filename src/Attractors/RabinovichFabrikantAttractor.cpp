#include "RabinovichFabrikantAttractor.h"

std::array<att::real, 3> att::RabinovichFabrikantAttractor::findDerivative(const std::array<real, 3>& current)
{
	real x = current[0];
	real y = current[1];
	real z = current[2];

	real dx_dt = y * (z - 1 + x * x) + m_gamma * x;
	real dy_dt = x * (3 * z + 1 - x * x) + m_gamma * y;
	real dz_dt = -2 * z * (m_alpha + x * y);

	return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
}
