#pragma once
#include "ofMain.h"
#include "../Attractors.h"
#include "AbstractArtist.h"

namespace att {

	template <unsigned int N>
	class AbstractArtist {
	public:

		AbstractArtist(
			OdeSolver solver = OdeSolver::EULER
		) {
			m_color_mode = ColorMode::COLOR_MODE_SINGULAR;
			m_solver = solver;
		}

		/// <summary>
		/// Readies the attractor for drawing all at once. It stands in opposition to the update method. 
		/// </summary>
		virtual void dump() = 0;

		/// <summary>
		/// Periodically updates the system. It stands in opposition to the dump method. 
		/// </summary>
		/// <param name="update_speed">: The number of iterations to be taken in a single update frame.</param>
		/// <param name="reset">: Resets the system and starts from </param>
		virtual void update(int update_speed = 200, bool reset = false) = 0;

		/// <summary>
		/// Draws the attractor onto the window/screen.
		/// </summary>
		virtual void draw() = 0;

		/// <summary>
		/// Enables signular color mode, which utilizes only one color to draw the attractor. 
		/// </summary>
		/// <param name="color"></param>
		virtual void singularColorMode(ofColor color) {
			m_color = color;
			m_color_mode = ColorMode::COLOR_MODE_SINGULAR;
		}


	protected:
		virtual void _init(
			std::shared_ptr<AbstractAttractor<N>> attractor,
			std::array<att::real, N> init_position,
			int iterations = 1000000,
			int init_iterations = 100
		) = 0;

		virtual void _singleStep() = 0;

		std::shared_ptr<AbstractAttractor<N>> p_attractor;

		
		std::array<real, N> m_position;
		int m_iterations = 0;
		int m_step_size = 0.01;

		int m_current_iteration = 0;

		ColorMode m_color_mode;
		OdeSolver m_solver;

		ofColor m_color = ofFloatColor(1.0, 1.0, 1.0, 0.1);

		bool m_initialized = false;
		bool m_dumped = false;
	};
}
