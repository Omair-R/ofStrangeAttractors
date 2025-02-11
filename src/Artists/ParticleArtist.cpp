#include "ParticleArtist.h"

att::ParticleArtist::ParticleArtist(int particle_number, OdeSolver solver)
	: AbstractArtist<3>(solver)
{
	m_attractor_mesh.setMode(OF_PRIMITIVE_POINTS);
	m_attractor_mesh.enableColors();

	m_particle_number = particle_number;
	m_particles.reserve(particle_number);
}

void att::ParticleArtist::init(
	std::shared_ptr<AbstractAttractor<3>> attractor,
	int iterations,
	int init_iterations,
	std::array<real, 3> max_initial_position,
	std::array<real, 3> min_initial_position
)
{
	_init(
		attractor,
		std::array<att::real, 3>{0.0, 0.0, 0.0},
		iterations,
		init_iterations
	);

	for (int i = 0; i < m_particle_number; i++) {
		std::array<real, 3> particle;
		for (int j = 0; j < 3; j++) {
			particle[j] = ofRandom(min_initial_position[j], max_initial_position[j]);
		}
		particle = p_attractor->init(particle, init_iterations);
		m_particles.push_back(particle);
		m_attractor_mesh.addVertex(ofVec3f(m_particles[i][0], m_particles[i][1], m_particles[i][2]));
		m_attractor_mesh.addColor(m_color);
	}

	m_max_initial_position = max_initial_position;
	m_min_initial_position = min_initial_position;
	
	m_initialized = true;
}

void att::ParticleArtist::draw()
{
	if (!m_initialized)
		throw std::exception("drawing the attractor prior to initalization is not allowed.");
	m_attractor_mesh.draw();
}

void att::ParticleArtist::dump()
{
	throw std::exception("The particle artist does not dump images, use the update method instead.");
}

void att::ParticleArtist::update(int update_speed, bool reset)
{
	if (!m_initialized)
		throw std::exception("updating the attractor prior to initalization is not allowed.");

	
	if (reset) {
		for (int i = 0; i < m_particle_number; i++) {
			for (int j = 0; j < 3; j++) {
				m_particles[i][j] = ofRandom(m_min_initial_position[j], m_max_initial_position[j]);
			}
		}
		m_current_iteration = 0;
	}

	for (int i = 0; i < update_speed; i++) {
		if (m_current_iteration >= m_iterations) {
			break;
		}
		_singleStep();
		m_current_iteration += 1;
	}
	
}

inline void att::ParticleArtist::singularColorMode(ofColor color) {
	AbstractArtist<3>::singularColorMode(color);
	for (int i = 0; i < m_particle_number; i++) {
		m_attractor_mesh.setColor(i, m_color);
	}
}

void att::ParticleArtist::velocityBasedColorMode(std::shared_ptr<att::Gradient> gradient){
	m_gradient = gradient;
	m_color_mode = att::ColorMode::COLOR_MODE_VELOCITY_BASED;
}

void att::ParticleArtist::_init(std::shared_ptr<AbstractAttractor<3>> attractor, std::array<att::real, 3> init_position, int iterations, int init_iterations)
{
	if (attractor == nullptr) {
		throw std::exception("attractor property must not be null.");
	}
	p_attractor = attractor;
	m_iterations = iterations;
}

void att::ParticleArtist::_singleStep()
{
	for (int i = 0; i < m_particle_number; i++) {
		switch (m_solver)
		{
		case OdeSolver::EULER:
			m_particles[i] = p_attractor->eulerStep(m_particles[i]);
			break;
		case OdeSolver::RUNGE_KUTTA2:
			m_particles[i] = p_attractor->RK2Step(m_particles[i]);
			break;
		default:
			break;
		}

		m_attractor_mesh.setVertex(i, ofVec3f(m_particles[i][0], m_particles[i][1], m_particles[i][2]));

		if (m_color_mode == att::ColorMode::COLOR_MODE_VELOCITY_BASED) {
			auto velocity = p_attractor->getLastVelocity();

			real mag = att::magnitude(velocity);

			m_max_mag = std::max(mag, m_max_mag);
			m_min_mag = std::min(mag, m_min_mag);

			real t = att::normalize(mag, m_max_mag, m_min_mag);

			m_attractor_mesh.setColor(i, m_gradient->getColor(t));
		}
		
	}
	
}

