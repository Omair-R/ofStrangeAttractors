#include "RosslerAttractor.h"

std::array<att::real, 3> att::RosslerAttractor::findDerivative(const std::array<real, 3>& current)
{
	real x = current[0];
	real y = current[1];
	real z = current[2];

	real dx_dt = - (y + z);
	real dy_dt = x + m_a * y;
	real dz_dt = m_b + z * (x - m_c);

	return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
}
