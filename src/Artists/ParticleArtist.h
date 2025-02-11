#pragma once
#include "AbstractArtist.h"
#include "../Gradient.h"

namespace att {
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

		void draw() override;

		void dump() override;

		void update(int update_speed = 200, bool reset = false) override;

		virtual void singularColorMode(ofColor color) override;

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