#include "ofParticlesApp.h"

ofParticlesApp::ofParticlesApp(
	std::shared_ptr<att::AbstractAttractor<3>> attractor,
	int particle_num,
	ofColor point_color, 
	int max_iterations, 
	std::array<att::real, 3> max_position,
	std::array<att::real, 3> min_position,
	int drawing_speed,
	int init_iterations, 
	ofColor background_color
) : ofParticlesApp(
		drawing_speed,
		background_color
	)
{
	p_artist = std::make_shared<att::ParticleArtist>(particle_num);

	p_artist->init(
		attractor,
		max_iterations,
		init_iterations,
		max_position,
		min_position
	);

	p_artist->singularColorMode(point_color);
}

ofParticlesApp::ofParticlesApp(
	std::shared_ptr<att::AbstractAttractor<3>> attractor,
	int particle_num,
	std::shared_ptr<att::Gradient> gradient, 
	int max_iterations, 
	std::array<att::real, 3> max_position,
	std::array<att::real, 3> min_position,
	int drawing_speed,
	int init_iterations, 
	ofColor background_color
) : ofParticlesApp(
		drawing_speed,
		background_color
	)
{
	p_artist = std::make_shared<att::ParticleArtist>(particle_num);

	p_artist->init(
		attractor,
		max_iterations,
		init_iterations,
		max_position,
		min_position
	);

	p_artist->velocityBasedColorMode(gradient);
}

//--------------------------------------------------------------
void ofParticlesApp::setup() {
	ofEnableAlphaBlending();
	ofEnableDepthTest();

	m_cam.setDistance(10);
	m_cam.setNearClip(0.1);
}


//--------------------------------------------------------------
void ofParticlesApp::update() {
	p_artist->update(m_drawing_speed);
	//std::cout << "camera - dist: " << m_cam.getDistance() << "\n";
	//std::cout << "fov : " << m_cam.getFov() << "\n";
	//std::cout << "near dist : " << m_cam.getNearClip() << "\n";
	//std::cout << "far dist : " << m_cam.getFarClip() << "\n";
	//std::cout << "aspct ratio : " << m_cam.getAspectRatio() << "\n";
	//std::cout << " ---------------- \n";
}

//--------------------------------------------------------------
void ofParticlesApp::draw() {
	ofBackground(m_background_color);
	m_cam.begin();
	p_artist->draw();
	m_cam.end();
}
