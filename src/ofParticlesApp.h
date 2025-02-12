#pragma once
#include "ofMain.h"
#include "Artists.h"
#include "Attractors.h"
#include "ofAbstractAttractorApp.h"

class ofParticlesApp : public ofAbstractAttractorApp {
public:
	ofParticlesApp(
		std::shared_ptr<att::AbstractAttractor<3>> attractor,
		int particle_num,
		ofColor point_color,
		int max_iterations = 1000000,
		std::array<att::real, 3> max_position = { 1.0f, 1.0f, 1.0f },
		std::array<att::real, 3> min_position = { 0.0f, 0.0f, 0.0f },
		int drawing_speed = 1,
		int init_iterations = 1,
		ofColor background_color = ofColor::black
	);

	ofParticlesApp(
		std::shared_ptr<att::AbstractAttractor<3>> attractor,
		int particle_num,
		std::shared_ptr<att::Gradient> gradient,
		int max_iterations = 1000000,
		std::array<att::real, 3> max_position = { 1.0f, 1.0f, 1.0f },
		std::array<att::real, 3> min_position = { 0.0f, 0.0f, 0.0f },
		int drawing_speed = 1,
		int init_iterations = 1,
		ofColor background_color = ofColor::black
	);

	void setup();
	void update();
	void draw();

private:
	ofParticlesApp(
		int drawing_speed = 1,
		ofColor background_color = ofColor::black
	) {
		m_background_color = background_color;
		m_drawing_speed = drawing_speed;
	}

	ofEasyCam m_cam;

	int m_drawing_speed;

	ofColor m_background_color;

	std::shared_ptr <att::ParticleArtist> p_artist;
};

