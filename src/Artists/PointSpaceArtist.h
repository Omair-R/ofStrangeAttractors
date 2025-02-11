#pragma once
#include "AbstractArtist.h"
#include <memory>
#include <cmath>
#include <vector>
#include <array>
#include "ParticleArtist.h"

namespace att {

	template <unsigned int N>
	class PointSpaceArtist :
		public AbstractArtist<N>
	{
	public:
		PointSpaceArtist(
			ofPrimitiveMode mode = OF_PRIMITIVE_POINTS,
			OdeSolver solver = OdeSolver::EULER
		);

		void init(
			std::shared_ptr<AbstractAttractor<N>> attractor,
			std::array<att::real, N> init_position,
			int iterations = 1000000,
			int init_iterations = 100
		);

		void draw() override;

		void dump() override;

		void update(int update_speed=200, bool reset=false) override;

		void velocityBasedColorMode(std::shared_ptr<Gradient> gradient);

	protected:
		void _init(
			std::shared_ptr<AbstractAttractor<N>> attractor,
			std::array<att::real, N> init_position,
			int iterations = 1000000,
			int init_iterations = 100
		) override;

		void _singleStep() override;

		ofMesh m_attractor_mesh;
		std::array<real, N> m_position;

		std::shared_ptr<Gradient> m_gradient = nullptr;
	};


	// ----- implementations ----------------------

	template<unsigned int N>
	inline PointSpaceArtist<N>::PointSpaceArtist(ofPrimitiveMode mode, OdeSolver solver) : AbstractArtist<N>(solver) {

		m_attractor_mesh.setMode(mode);
		m_attractor_mesh.enableColors();

	}

	template<unsigned int N>
	inline void PointSpaceArtist<N>::init(std::shared_ptr<AbstractAttractor<N>> attractor, std::array<att::real, N> init_position, int iterations, int init_iterations)
	{
		_init(
			attractor, 
			init_position,
			iterations,
			init_iterations
		);
	}

	template<unsigned int N>
	inline void PointSpaceArtist<N>::_init(
		std::shared_ptr<AbstractAttractor<N>> attractor, 
		std::array<att::real, N> init_position, 
		int iterations,
		int init_iterations)
	{
		if (attractor == nullptr) {
			throw std::exception("attractor property must not be null.");
		}
		p_attractor = attractor;
		m_position = init_position;
		m_iterations = iterations;

		m_position = p_attractor->init(m_position, init_iterations);

		m_initialized = true;
	}

	template<unsigned int N>
	void PointSpaceArtist<N>::draw() {
		if (!m_initialized)
			throw std::exception("drawing the attractor prior to initalization is not allowed.");
		m_attractor_mesh.draw();
	}

	template<unsigned int N>
	void PointSpaceArtist<N>::dump() {
		if (!m_initialized)
			throw std::exception("dumping the attractor prior to initalization is not allowed.");

		m_attractor_mesh.clear();

		std::vector<real> mag_vels;
		real max_mag = ATT_MIN_REAL;
		real min_mag = ATT_MAX_REAL;

		switch (m_color_mode)
		{

		case ColorMode::COLOR_MODE_SINGULAR:
			for (int i = 0; i < m_iterations; i++) {
				_singleStep();
				m_attractor_mesh.addColor(m_color);
			}
			break;

		case ColorMode::COLOR_MODE_VELOCITY_BASED:

			

			mag_vels.reserve(m_iterations);

			for (int i = 0; i < m_iterations; i++) {

				_singleStep();

				std::array<att::real, N> vel = p_attractor->getLastVelocity();
				real mag = magnitude(vel);
				
				max_mag = std::max(mag, max_mag);
				min_mag = std::min(mag, min_mag);

				mag_vels.emplace_back(mag);
			}

			for (int i = 0; i < m_iterations; i++) {
				real val = mag_vels[i];
				val = normalize(val, max_mag, min_mag);
				m_attractor_mesh.addColor(m_gradient->getColor(val));
			}

			break;

		default:
			break;
		}

		m_dumped = true;
	}

	template<unsigned int N>
	void PointSpaceArtist<N>::update(int update_speed, bool reset) {
		if (!m_initialized)
			throw std::exception("updating the attractor prior to initalization is not allowed.");

		if (m_dumped)
			throw std::exception("full graph was dumped, update mode requires the removal of the call to dump.");

		if (reset) {
			m_attractor_mesh.clear();
			m_current_iteration = 0;
		}

		for (int i = 0; i < update_speed; i++) {

			if (m_current_iteration >= m_iterations) {
				break;
			}

			_singleStep();

			float val;
			switch (m_color_mode)
			{
			case ColorMode::COLOR_MODE_SINGULAR:
				m_attractor_mesh.addColor(m_color);
				break;
			case ColorMode::COLOR_MODE_VELOCITY_BASED: // Update the gradient based on velocity wiht normalization.
				val = magnitude(p_attractor->getLastVelocity());
				val = ofClamp(val, 0, 255) / 255.0;
				m_attractor_mesh.addColor(m_gradient->getColor(val));
				break;
			default:
				break;
			}

			m_current_iteration += 1;
		}
		
	}
	template<unsigned int N>
	inline void PointSpaceArtist<N>::velocityBasedColorMode(std::shared_ptr<Gradient> gradient) {
		m_gradient = gradient;
		m_color_mode = att::COLOR_MODE_VELOCITY_BASED;
	}

	template<unsigned int N>
	void PointSpaceArtist<N>::_singleStep() {

		switch (m_solver)
		{
		case OdeSolver::EULER:
			m_position = p_attractor->eulerStep(m_position);
			break;
		case OdeSolver::RUNGE_KUTTA2:
			m_position = p_attractor->RK2Step(m_position);
			break;
		default:
			break;
		}

		ofVec3f position_vertex;

		switch (N) {
		case 2:
			position_vertex = ofVec3f(m_position[0], m_position[1], 0.0);
			break;
		case 3:
			position_vertex = ofVec3f(m_position[0], m_position[1], m_position[2]);
			break;
		default:
			break;
		}

		m_attractor_mesh.addVertex(position_vertex);
	}
}