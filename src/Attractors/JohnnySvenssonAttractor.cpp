#include "JohnnySvenssonAttractor.h"

std::array<att::real, 2> att::JohnnySvenssonAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = m_d *  sin_func(m_a * x) - sin_func(m_b * y);
	real dy_dt = m_c *  cos_func(m_a * x) + cos_func(m_b * y);
	dx_dt = (dx_dt - x) / m_step_size;
	dy_dt = (dy_dt - y) / m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};
}