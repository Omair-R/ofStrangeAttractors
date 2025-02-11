#include "ofMain.h"
#include "ofApp.h"
#include "ofPointSpaceApp3D.h"
#include "ofPointSpaceApp2D.h"
#include "ofHistogramApp.h"
#include "ofParticlesApp.h"
#include <array>
//========================================================================
int main( ){

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1180, 820);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(ofColor(147, 112, 219), ofColor(255, 218, 185));
	gradient_test->addColor(ofColor(200, 69, 69), 0.01);
	gradient_test->addColor(ofColor(200, 200, 18), 0.1);

	// 3D Attractor ===========================================================================================
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::LorenzAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::ThomasSymmetricAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::LangfordAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::ChenAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::DadrasAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::HalvorsenAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::RosslerAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::RabinovichFabrikantAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::SprottBAttractor>(0.05, true);

	/*ofRunApp(window, make_shared<ofParticlesApp>(
		attractor,
		10000,
		ofColor(181, 143, 206, 150)
	));*/

	/*ofRunApp(window, make_shared<ofPointSpaceApp3D>(
	    attractor,
		ofColor(181, 143, 206, 150)
	));*/


	// 2D Attractor ===========================================================================================
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CliffordAttractor>(1.2, false, 1.5, -1.8, 1.6, 0.9);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::PeterDeJongAttractor>(1.2, false);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::JohnnySvenssonAttractor>(1.2, false);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::GummowskiMiraAttractor>(1.2, false);
	std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::DuffingAttractor>(0.01, false);

	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::QuadraticSporttAttractor>(0.01, false);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::TinkerbellAttractor>(1.2, false);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::HenonMapBifurcationAttractor>(0.01, false);

	ofRunApp(window, make_shared<ofHistogramApp>(
		attractor,
		1080,
		720,
		gradient_test,
		std::array<int, 2> {50, 50},
		1000000,
		std::array<att::real, 2>{1.0, 1.0},
		100,
		ofColor::purple/5,
		150
	));

	/*ofRunApp(window, make_shared<ofPointSpaceApp2D>(
		attractor,
		ofColor(181, 143, 206, 150)
	));*/

	ofRunMainLoop();

}
