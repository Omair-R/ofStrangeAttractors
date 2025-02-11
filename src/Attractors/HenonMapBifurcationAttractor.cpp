#include "HenonMapBifurcationAttractor.h"

std::array<att::real, 2> att::HenonMapBifurcationAttractor::findDerivative(const std::array<real, 2>& current)
{
	real x = current[0];
	real y = current[1];

	real dx_dt = 1 - m_a * x * x + y;
	real dy_dt = m_b * x;
	//dx_dt = (dx_dt - x) / m_step_size;
	//dy_dt = (dy_dt - y) / m_step_size;

	return std::array<real, 2>{dx_dt, dy_dt};
}