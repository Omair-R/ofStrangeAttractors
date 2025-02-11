#pragma once
#include "ofMain.h"
#include "Artists.h"
#include "Attractors.h"

class ofParticlesApp : public ofBaseApp{
public:
	ofParticlesApp(
		std::shared_ptr<att::AbstractAttractor<3>> attractor,
		int particle_num,
		ofColor point_color,
		int max_iterations = 1000000,
		std::array<att::real, 3> init_position = { 1.0f, 1.0f, 1.0f },
		int drawing_speed = 1,
		int init_iterations = 1,
		ofColor background_color = ofColor::black
	);

	ofParticlesApp(
		std::shared_ptr<att::AbstractAttractor<3>> attractor,
		int particle_num,
		std::shared_ptr<att::Gradient> gradient,
		int max_iterations = 1000000,
		std::array<att::real, 3> init_position = { 1.0f, 1.0f, 1.0f },
		int drawing_speed = 1,
		int init_iterations = 1,
		ofColor background_color = ofColor::black
	);

	void setup();
	void update();
	void draw();

	void keyPressed(int key) {}
	void keyReleased(int key) {}
	void mouseMoved(int x, int y) {}
	void mouseDragged(int x, int y, int button) {}
	void mousePressed(int x, int y, int button) {}
	void mouseReleased(int x, int y, int button) {}
	void mouseEntered(int x, int y) {}
	void mouseExited(int x, int y) {}
	void windowResized(int w, int h) {}
	void dragEvent(ofDragInfo dragInfo) {}
	void gotMessage(ofMessage msg) {}

private:
	ofParticlesApp(
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

	std::shared_ptr <att::ParticleArtist> p_artist;
};

