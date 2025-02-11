#include "TinkerbellAttractor.h"

std::array<att::real, 2> att::TinkerbellAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = x * x - y * y + m_a * x + m_b * y;
	real dy_dt = 2 * x * y + m_c * x + m_d * y;
	dx_dt = (dx_dt - x) / m_step_size;
	dy_dt = (dy_dt - y) / m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};
}
