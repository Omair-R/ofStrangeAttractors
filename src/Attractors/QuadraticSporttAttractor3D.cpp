#include "QuadraticSporttAttractor3D.h"

std::array<att::real, 3> att::QuadraticSporttAttractor3D::findDerivative(const std::array<real, 3>& current)
{
	real x = current[0];
	real y = current[1];
	real z = current[2];

	real dx_dt = m_a[0] + m_a[1] * x + m_a[2] * x * x;
	dx_dt +=  m_a[5] * y + m_a[6] * y * y;
	dx_dt += m_a[8] * z + m_a[9] * z * z;
	dx_dt += m_a[3] * x * y + m_a[4] * x * z + m_a[7] * y * z;

	real dy_dt = m_a[10] + m_a[11] * x + m_a[12] * x * x;
	dy_dt += m_a[15] * y + m_a[16] * y * y;
	dy_dt += m_a[18] * z + m_a[19] * z * z;
	dy_dt += m_a[13] * x * y + m_a[14] * x * z + m_a[17] * y * z;

	real dz_dt = m_a[20] + m_a[21] * x + m_a[22] * x * x;
	dz_dt += m_a[25] * y + m_a[26] * y * y;
	dz_dt += m_a[28] * z + m_a[29] * z * z;
	dz_dt += m_a[23] * x * y + m_a[24] * x * z + m_a[27] * y * z;

	dx_dt = (dx_dt - x) / m_step_size;
	dy_dt = (dy_dt - y) / m_step_size;
	dz_dt = (dz_dt - z) / m_step_size;

	return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
}
