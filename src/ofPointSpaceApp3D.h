#pragma once
#include "ofMain.h"
#include "Artists.h"
#include "Attractors.h"
#include "ofAbstractAttractorApp.h"

class ofPointSpaceApp3D : public ofAbstractAttractorApp {

public:
	ofPointSpaceApp3D(
		std::shared_ptr<att::AbstractAttractor<3>> attractor,
		ofColor point_color,
		att::OdeSolver ode_solver = att::OdeSolver::EULER,
		ofPrimitiveMode primative_mode = OF_PRIMITIVE_POINTS,
		int max_iterations = 1000000,
		std::array<att::real, 3> init_position = { 1.0f, 1.0f, 1.0f },
		int drawing_speed = 1,
		int init_iterations = 1,
		ofColor background_color = ofColor::black
	);

	ofPointSpaceApp3D(
		std::shared_ptr<att::AbstractAttractor<3>> attractor,
		std::shared_ptr<att::Gradient> gradient,
		att::OdeSolver ode_solver = att::OdeSolver::EULER,
		ofPrimitiveMode primative_mode = OF_PRIMITIVE_POINTS,
		int max_iterations = 1000000,
		std::array<att::real, 3> init_position = { 1.0f, 1.0f, 1.0f },
		int drawing_speed = 1,
		int init_iterations = 1,
		ofColor background_color = ofColor::black
	);

	void setup();
	void update();
	void draw();

private:
	ofPointSpaceApp3D(
		int max_iterations = 1000000,
		std::array<att::real, 3> init_position = { 1.0f, 1.0f, 1.0f },
		int drawing_speed = 1,
		int init_iterations = 1,
		ofColor background_color = ofColor::black
	) {
		m_max_iterations = max_iterations;
		m_init_iteraltions = init_iterations;
		m_init_position = init_position;
		m_background_color = background_color;
		m_drawing_speed = drawing_speed;
	}

	ofEasyCam m_cam;

	int m_drawing_speed;

	int m_max_iterations;
	int m_init_iteraltions;
	std::array<att::real, 3> m_init_position;

	ofColor m_background_color;

	std::shared_ptr < att::PointSpaceArtist<3>> p_artist;

};

