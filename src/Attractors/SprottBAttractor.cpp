#include "SprottBAttractor.h"

std::array<att::real, 3> att::SprottBAttractor::findDerivative(const std::array<real, 3>& current)
{
	real x = current[0];
	real y = current[1];
	real z = current[2];

	real dx_dt = m_a * y * z;
	real dy_dt = x - m_b * y;
	real dz_dt = m_c - x * y;

	return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
}
