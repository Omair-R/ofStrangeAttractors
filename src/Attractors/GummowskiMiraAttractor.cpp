#include "GummowskiMiraAttractor.h"

std::array<att::real, 2> att::GummowskiMiraAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = y + m_a * (1 - m_b * y * y) * y + _f(x);
	real dy_dt = _f(dx_dt) - x;
	dx_dt = (dx_dt - x) / m_step_size;
	dy_dt = (dy_dt - y) / m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};
}

att::real att::GummowskiMiraAttractor::_f(att::real x)
{
	real x2 = x * x;
	return m_c * x + (2 * (1 - m_c) * x2) / (1 + x2);
}
