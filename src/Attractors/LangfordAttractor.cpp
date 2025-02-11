#include "LangfordAttractor.h"

std::array<att::real, 3> att::LangfordAttractor::findDerivative(const std::array<real, 3>& current)
{
	real x = current[0];
	real y = current[1];
	real z = current[2];

	real dx_dt = (z - m_b) * x - m_d * y;
	real dy_dt = m_d * x + (z - m_b) * y;
	real dz_dt = m_c + m_a * z - (z * z * z) / 3 - (x * x + y * y) * (1 - m_e * z) + m_f * z * (x * x * x);


	return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
}
