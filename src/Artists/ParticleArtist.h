#pragma once
#include "AbstractArtist.h"
#include "../Gradient.h"

namespace att {

	/// <summary>
	/// This artist class draws a specified number of particles moving along the path of the attractor. 
	/// The initial positions of these particles is sampled randomly from a uniform distribution with preset minimum and maximum.
	/// </summary>
	class ParticleArtist :
		public AbstractArtist<3>
	{
	public:
		ParticleArtist(
			int particle_number,
			OdeSolver solver = OdeSolver::EULER
		);

		void init(
			std::shared_ptr<AbstractAttractor<3>> attractor,
			int iterations = 1000000,
			int init_iterations = 100,
			std::array<real, 3> max_initial_position= { 1.0, 1.0, 1.0 },
			std::array<real, 3> min_initial_position = { 0.0, 0.0, 0.0 }
		);

		/// <summary>
		/// Draws all the particles of the attractor onto the window/screen.
		/// </summary>
		void draw() override;
		
		/// <summary>
		/// This method does not apply to this class. IT WILL THROW AN ERROR. Use update instead.
		/// </summary>
		void dump() override;

		/// <summary>
		/// Periodically updates the position of each particle.
		/// </summary>
		/// <param name="update_speed">: The number of iterations to be taken in a single update frame.</param>
		/// <param name="reset">: Resets the system and starts from </param>
		void update(int update_speed = 1, bool reset = false) override;

		/// <summary>
		/// Enables signular color mode, which utilizes only one color to draw the attractor. 
		/// </summary>
		/// <param name="color"></param>
		virtual void singularColorMode(ofColor color) override;

		/// <summary>
		/// Enables gradient color mode. It uses the velocity of the particle to assign a position in the a gradient spectrum. 
		/// </summary>
		/// <param name="gradient"></param>
		virtual void velocityBasedColorMode(std::shared_ptr<att::Gradient> gradient);


	protected:
		void _init(
			std::shared_ptr<AbstractAttractor<3>> attractor,
			std::array<att::real, 3> init_position,
			int iterations = 1000000,
			int init_iterations = 100
		) override;

		void _singleStep() override;

		ofMesh m_attractor_mesh;
		int m_particle_number;
		std::vector<std::array<real, 3>> m_particles;

		std::array<real, 3> m_max_initial_position;
		std::array<real, 3> m_min_initial_position;

		std::shared_ptr<Gradient> m_gradient = nullptr;

		real m_max_mag = ATT_MIN_REAL;
		real m_min_mag = ATT_MAX_REAL;
	};

}