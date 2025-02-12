#include "CubicSporttAttractor.h"

std::array<att::real, 2> att::CubicSporttAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = m_a[0] + x * ( m_a[1] + x * (m_a[2] + m_a[3] * x + m_a[4] * y) +m_a[5] * y);
	dx_dt += y * ( m_a[7]  + y * (m_a[6] * x+ m_a[8] + m_a[9] * y));

	//dx_dt = m_a[0] +  m_a[1] * x + m_a[2] * x * x  + m_a[3] * x * x * x + m_a[4] * x * x * y;
	//dx_dt += m_a[5] * x * y + m_a[6] * x * y * y + m_a[7] * y + m_a[8] * y * y + m_a[9] * y * y * y;

	real dy_dt = m_a[10] + x * (m_a[11] + x * (m_a[12] + m_a[13] * x + m_a[14] * y) + m_a[15] * y);
	dy_dt += y * (m_a[17] + y * (m_a[16] * x + m_a[18] + m_a[19] * y));

	//real dy_dt = m_a[10] + m_a[11] * x + m_a[12] * x * x + m_a[13] * x * x * x + m_a[14] * x * x * y;
	//dy_dt += m_a[15] * x * y + m_a[16] * x * y * y + m_a[17] * y + m_a[18] * y * y + m_a[19] * y * y * y;

	dx_dt = (dx_dt - x) / m_step_size;
	dy_dt = (dy_dt - y) / m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};

}
