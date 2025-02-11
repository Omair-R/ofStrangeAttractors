#include "CliffordAttractor.h"

namespace att{
    std::array<real, 2> att::CliffordAttractor::findDerivative(const std::array<real, 2>& current)
    {
		real x = current[0];
		real y = current[1];

		real dx_dt = sin_func(m_a * y) + m_c * cos_func(m_a * x);
		dx_dt = (dx_dt - x) / m_step_size;
		real dy_dt = sin_func(m_b * x) + m_d * cos_func(m_b * y);
		dy_dt = (dy_dt - y) / m_step_size;

		return std::array<real, 2>{dx_dt, dy_dt};
    }
}
