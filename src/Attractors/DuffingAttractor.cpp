#include "DuffingAttractor.h"

std::array<att::real, 2> att::DuffingAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = y;
	real dy_dt = x - x * x * x - m_a * y + m_b * cos_func(m_w*m_t);

	m_t += m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};
}
