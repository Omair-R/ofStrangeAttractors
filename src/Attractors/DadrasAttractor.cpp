#include "DadrasAttractor.h"

std::array<att::real, 3> att::DadrasAttractor::findDerivative(const std::array<real, 3>& current)
{
	real x = current[0];
	real y = current[1];
	real z = current[2];

	real dx_dt = y - m_a * x + m_b * y * z;
	real dy_dt = m_c * y - x * z + z;
	real dz_dt = m_d * x * y - m_e * z;

	return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
}
