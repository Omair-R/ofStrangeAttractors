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

		/// <summary>
		/// Initializes the attractor, by registering the initial coordinates and running a few warmup iterations.
		/// </summary>
		/// <param name="initial_coords">The starting coordinates of the system.</param>
		/// <param name="init_iterations">The number of initial/warmup iterations to perform before drawing.</param>
		/// <returns> An array that represents the position of the particle post warmup.</returns>
		virtual std::array<real, N> init(const std::array<real, N>& initial_coords, int init_iterations=100);

		/// <summary>
		/// Computes the gradient for use by the ODE solvers. This is the only method that attractor classes need to implement. 
		/// This method does not apply the step size and leaves it to solvers. If whichever equation pre-applies the step size, you should divide by the step size.
		/// </summary>
		/// <param name="current"> The current position of the particle.</param>
		/// <returns>An array that hosts the gradient.</returns>
		virtual std::array<real, N> findDerivative(const std::array<real, N>& current) = 0;

		/// <summary>
		/// Takes a step based on the Euler method for solveing ODEs. https://en.wikipedia.org/wiki/Euler_method
		/// </summary>
		/// <param name="current">The current position of the particle.</param>
		/// <returns>Next position for the particle.</returns>
		virtual std::array<real, N> eulerStep(const std::array<real, N>& current);

		/// <summary>
		/// Takes a step based on the Runge–Kutta method for solveing ODEs. RK2 signifies that k=2. https://en.wikipedia.org/wiki/Euler_method
		/// </summary>
		/// <param name="current">The current position of the particle.</param>
		/// <returns>Next position for the particle.</returns>
		virtual std::array<real, N> RK2Step(const std::array<real, N>& current);

		/// <summary>
		/// Returns the last recorded velocity value (gradient).
		/// </summary>
		/// <returns>An array that hosts the latest gradient.</returns>
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
