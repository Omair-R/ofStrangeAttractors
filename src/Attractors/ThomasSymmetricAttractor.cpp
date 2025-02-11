#include "ThomasSymmetricAttractor.h"


namespace att {
	std::array<real, 3> att::ThomasSymmetricAttractor::findDerivative(const std::array<real, 3>& current)
	{
		real x = current[0];
		real y = current[1];
		real z = current[2];

		real dx_dt = sin_func(y) - (m_b * x);
		real dy_dt = sin_func(z) - (m_b * y);
		real dz_dt = sin_func(x) - (m_b * z);

		return std::array<real, 3>{dx_dt, dy_dt, dz_dt};
	}
}
