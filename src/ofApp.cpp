#include "ofApp.h"
#include <memory>

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableAlphaBlending();
	ofEnableDepthTest();

	m_cam.setDistance(10);
	m_cam.setNearClip(0.1);


	//p_attractor = std::make_shared<att::LorenzAttractor>(0.01, true);
	//p_attractor = std::make_shared<att::ThomasSymmetricAttractor>(0.01, true);
	//p_attractor = std::make_shared<att::LangfordAttractor>(0.01, true);
	//p_attractor = std::make_shared<att::ChenAttractor>(0.01, true);
	//p_attractor = std::make_shared<att::DadrasAttractor>(0.01, true);
	//p_attractor = std::make_shared<att::HalvorsenAttractor>(0.01, true);
	//p_attractor = std::make_shared<att::RosslerAttractor>(0.01, true);
	p_attractor = std::make_shared<att::RabinovichFabrikantAttractor>(0.01, true);
	//p_attractor = std::make_shared<att::SprottBAttractor>(0.05, true);

	//p_attractor = std::make_shared<att::CliffordAttractor>(1.2, false, 1.5, -1.8, 1.6, 0.9);
	//p_attractor = std::make_shared<att::PeterDeJongAttractor>(1.2, false);
	//p_attractor = std::make_shared<att::TinkerbellAttractor>(1.2, false);
	//p_attractor = std::make_shared<att::JohnnySvenssonAttractor>(1.2, false);
	//p_attractor = std::make_shared<att::HenonMapBifurcationAttractor>(1.2, false);
	//p_attractor = std::make_shared<att::GummowskiMiraAttractor>(1.2, false);
	//p_attractor = std::make_shared<att::DuffingAttractor>(0.01, false);
	//p_attractor = std::make_shared<att::HenonMapBifurcationAttractor>(0.01, false);

	artist.init(
		p_attractor,
		std::array<att::real, 3>{0.13,0.2,0.05},
		1000000,
		5
	);

	//artist.init(
	//	p_attractor,
	//	std::array<att::real, 2>{1.0f, 1.0f},
	//	5000000,
	//	100
	//);

	//artist.init(
	//	p_attractor,
	//	//std::array<att::real, 2>{1.0f, 1.0f},
	//	1000000,
	//	1,
	//	{1.0, 1.0, 1.0}
	//);

	//artist.enableBackgroundBlend(100);

	gradient_test = std::make_shared< att::Gradient>(ofColor(147, 112, 219), ofColor(255, 218, 185));
	gradient_test->addColor(ofColor(200, 69, 69), 0.01);
	gradient_test->addColor(ofColor(200, 200, 18), 0.1);
	//gradient_test->addColor(ofColor(255, 218, 185, 150), 0.1);
	//gradient_test->addColor(ofColor(217, 153, 40), 0.95);
	
	artist.singularColorMode(ofColor(181, 143, 206, 50));
	//artist.velocityBasedColorMode(gradient_test);
	//artist.gradientColorMode(gradient_test);

	//artist.dump();
	
}


//--------------------------------------------------------------
void ofApp::update(){
	artist.update(1);
	//std::cout << "camera - dist: " << m_cam.getDistance() << "\n";
	//std::cout << "fov : " << m_cam.getFov() << "\n";
	//std::cout << "near dist : " << m_cam.getNearClip() << "\n";
	//std::cout << "far dist : " << m_cam.getFarClip() << "\n";
	//std::cout << "aspct ratio : " << m_cam.getAspectRatio() << "\n";
	//std::cout << " ---------------- \n";
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	m_cam.begin();
	artist.draw();
	m_cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
