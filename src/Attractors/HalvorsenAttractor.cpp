#include "HalvorsenAttractor.h"

std::array<att::real, 3> att::HalvorsenAttractor::findDerivative(const std::array<real, 3>& current)
{
	real x = current[0];
	real y = current[1];
	real z = current[2];

	real dx_dt = -m_a * x - 4 * y - 4 * z - y * y;
	real dy_dt = -m_a * y - 4 * z - 4 * x - z * z;
	real dz_dt = -m_a * z - 4 * x - 4 * y - x * x;

	return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
}
