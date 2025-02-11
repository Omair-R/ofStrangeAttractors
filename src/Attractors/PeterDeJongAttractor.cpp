#include "PeterDeJongAttractor.h"

std::array<att::real, 2> att::PeterDeJongAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = sin_func(m_a * y) - cos_func(m_b * x);
	real dy_dt = sin_func(m_c * x) - cos_func(m_d * y);
	dx_dt = (dx_dt - x) / m_step_size;
	dy_dt = (dy_dt - y) / m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};
}
