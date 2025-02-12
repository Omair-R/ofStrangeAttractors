#include "QuadraticSporttAttractor.h"

std::array<att::real, 2> att::QuadraticSporttAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = m_a[0] + x * (m_a[1] + m_a[2] * x + m_a[3] * y);
	dx_dt += y * (m_a[4]  + m_a[5]  * y);

	real dy_dt = m_a[6] + x * (m_a[7] + m_a[8] * x + m_a[9] * y);
	dy_dt += y * (m_a[10] + m_a[11] * y);

	dx_dt = (dx_dt - x) / m_step_size;
	dy_dt = (dy_dt - y) / m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};
}