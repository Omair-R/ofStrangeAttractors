#pragma once
#include <array>
#include <limits>
#include "../Common/AttTypes.h"
#include "../Common/AttMath.h"

namespace att {

	template<unsigned int N>
	class AbstractAttractor
	{

	public:
		AbstractAttractor(real step_size, bool calc_velocity);
		virtual ~AbstractAttractor() {}

		virtual std::array<real, N> init(const std::array<real, N>& initial_coords, int init_iterations=100);
		virtual std::array<real, N> findDerivative(const std::array<real, N>& current) = 0;

		virtual std::array<real, N> eulerStep(const std::array<real, N>& current);
		virtual std::array<real, N> RK2Step(const std::array<real, N>& current);
		virtual std::array<real, N> getLastVelocity();

	protected:
		real m_step_size;
		std::array<real, N> m_velocity{};
		bool m_is_calc_velocity = false;

	};


	template<unsigned int N>
	inline AbstractAttractor<N>::AbstractAttractor(real step_size, bool calc_velocity)
	{
		m_step_size = step_size;
		m_is_calc_velocity = calc_velocity;
	}

	template<unsigned int N>
	std::array<real, N> AbstractAttractor<N>::init(const std::array<real, N>& initial_coords, int init_iterations)
	{
		std::array<real, N> current = initial_coords;

		for (int i = 0; i < init_iterations; i++) {
			current = eulerStep(current);
		}

		return current;
	}

	template<unsigned int N>
	std::array<real, N> AbstractAttractor<N>::eulerStep(const std::array<real, N>& current)
	{
		std::array<real, N> updates = current;
		std::array<real, N> derivatives = findDerivative(current);

		if(m_is_calc_velocity){
			m_velocity = derivatives;
		}

		for (int i = 0; i < N; i++) {
			updates[i] += m_step_size * derivatives[i];
		}

		return updates;
	}

	template<unsigned int N>
	std::array<real, N> AbstractAttractor<N>::RK2Step(const std::array<real, N>& current)
	{
		std::array<real, N> updates = current;
		std::array<real, N> mid_updates = current;

		std::array<real, N> derivatives = findDerivative(current);

		for (int i = 0; i < N; i++) {
			mid_updates[i] += m_step_size * derivatives[i];
		}

		std::array<real, N> second_derivatives = findDerivative(mid_updates);

		for (int i = 0; i < N; i++) {

			float dt = (derivatives[i] + second_derivatives[i]) * 0.5;

			updates[i] += m_step_size * dt;

			if (m_is_calc_velocity) {
				m_velocity[i] = dt;
			}
		}

		return updates;
	}

	template<unsigned int N>
	inline std::array<real, N> AbstractAttractor<N>::getLastVelocity()
	{
		return m_velocity;
	}

}
