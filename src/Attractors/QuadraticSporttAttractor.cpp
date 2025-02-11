#include "QuadraticSporttAttractor.h"

std::array<att::real, 2> att::QuadraticSporttAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = m_a[0] + m_a[1] * x + m_a[2] * x * x + 
		m_a[3] * x * y + m_a[4] * y + m_a[5] * y * y;
	real dy_dt = m_a[6] + m_a[7] * x + m_a[8] * x * x +
		m_a[9] * x * y + m_a[10] * y + m_a[11] * y * y;
	dx_dt = (dx_dt - x) / m_step_size;
	dy_dt = (dy_dt - y) / m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};
}