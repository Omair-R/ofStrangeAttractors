#include "ofPointSpaceApp2D.h"

ofPointSpaceApp2D::ofPointSpaceApp2D(
	std::shared_ptr<att::AbstractAttractor<2>> attractor,
	ofColor point_color, 
	att::OdeSolver ode_solver, 
	ofPrimitiveMode primative_mode, 
	int max_iterations, 
	std::array<att::real, 2> init_position, 
	int drawing_speed, 
	int init_iterations, 
	ofColor background_color) : ofPointSpaceApp2D(
		max_iterations,
		init_position,
		drawing_speed,
		init_iterations,
		background_color
	)
{
	p_artist = std::make_shared<att::PointSpaceArtist<2>>(primative_mode, ode_solver);

	p_artist->init(
		attractor,
		m_init_position,
		m_max_iterations,
		m_init_iteraltions
	);

	p_artist->singularColorMode(point_color);
}

ofPointSpaceApp2D::ofPointSpaceApp2D(
	std::shared_ptr<att::AbstractAttractor<2>> attractor,
	std::shared_ptr<att::Gradient> gradient, 
	att::OdeSolver ode_solver, 
	ofPrimitiveMode primative_mode, 
	int max_iterations, 
	std::array<att::real, 2> init_position, 
	int drawing_speed, 
	int init_iterations, 
	ofColor background_color) : ofPointSpaceApp2D(
		max_iterations,
		init_position,
		drawing_speed,
		init_iterations,
		background_color
	)
{
	p_artist = std::make_shared<att::PointSpaceArtist<2>>(primative_mode, ode_solver);

	p_artist->init(
		attractor,
		m_init_position,
		m_max_iterations,
		m_init_iteraltions
	);

	p_artist->velocityBasedColorMode(gradient);
}

//--------------------------------------------------------------
void ofPointSpaceApp2D::setup() {
	ofEnableAlphaBlending();
	ofEnableDepthTest();

	m_cam.setDistance(10);
	m_cam.setNearClip(0.1);
}


//--------------------------------------------------------------
void ofPointSpaceApp2D::update() {
	p_artist->update(m_drawing_speed);
	//std::cout << "camera - dist: " << m_cam.getDistance() << "\n";
	//std::cout << "fov : " << m_cam.getFov() << "\n";
	//std::cout << "near dist : " << m_cam.getNearClip() << "\n";
	//std::cout << "far dist : " << m_cam.getFarClip() << "\n";
	//std::cout << "aspct ratio : " << m_cam.getAspectRatio() << "\n";
	//std::cout << " ---------------- \n";
}

//--------------------------------------------------------------
void ofPointSpaceApp2D::draw() {
	ofBackground(m_background_color);
	m_cam.begin();
	p_artist->draw();
	m_cam.end();
}
