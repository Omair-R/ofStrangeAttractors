#pragma once
#include "ofMain.h"
#include "Attractors.h"
#include "Artists.h"
#include <memory>
#include <array>
#include <cmath>
#include "Gradient.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
private:
	// 3d-attractors.
	//std::shared_ptr<att::LorenzAttractor> p_attractor;
	//std::shared_ptr<att::ThomasSymmetricAttractor> p_attractor;
	//std::shared_ptr<att::LangfordAttractor> p_attractor;
	//std::shared_ptr<att::ChenAttractor> p_attractor;
	//std::shared_ptr<att::DadrasAttractor> p_attractor;
	//std::shared_ptr<att::HalvorsenAttractor> p_attractor;
	//std::shared_ptr<att::RosslerAttractor> p_attractor;
	std::shared_ptr<att::RabinovichFabrikantAttractor> p_attractor;
	//std::shared_ptr<att::SprottBAttractor> p_attractor;

	// 2d-attractors best with the historgram artist.
	//std::shared_ptr<att::CliffordAttractor> p_attractor;
	//std::shared_ptr<att::PeterDeJongAttractor> p_attractor;
	//std::shared_ptr<att::TinkerbellAttractor> p_attractor;
	//std::shared_ptr<att::JohnnySvenssonAttractor> p_attractor;
	//std::shared_ptr<att::HenonMapBifurcationAttractor> p_attractor;
	//std::shared_ptr<att::GummowskiMiraAttractor> p_attractor;
	//std::shared_ptr<att::DuffingAttractor> p_attractor;
	//std::shared_ptr<att::HenonMapBifurcationAttractor> p_attractor;

	att::PointSpaceArtist<3> artist = att::PointSpaceArtist<3>(OF_PRIMITIVE_POINTS, att::OdeSolver::EULER);
	//att::PointSpaceArtist<2> artist = att::PointSpaceArtist<2>(OF_PRIMITIVE_POINTS, att::OdeSolver::EULER);
	//att::HistogramArtist artist = att::HistogramArtist(1280, 720);
	//att::ParticleArtist artist = att::ParticleArtist(100000);
	ofEasyCam m_cam;

	std::shared_ptr<att::Gradient> gradient_test = nullptr;
};
