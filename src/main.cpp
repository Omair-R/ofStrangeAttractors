#include "ofMain.h"
#include "ofPointSpaceApp3D.h"
#include "ofPointSpaceApp2D.h"
#include "ofHistogramApp.h"
#include "ofParticlesApp.h"
#include "Common/AttUtils.h"
#include <array>
//========================================================================
int main( ){

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	int window_width = 1180;
	int window_height = 820;
	settings.setSize(window_width, window_height);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	//-----general artist and attractor settings.
	int drawing_speed = 1000;
	int max_iters = 1'000'000;
	int init_iters = 100;
	att::OdeSolver ode_solver = att::OdeSolver::EULER;
	ofPrimitiveMode primative_mode = OF_PRIMITIVE_POINTS;

	ofColor background_color = ofColor::purple/5;
	ofColor attractor_color = ofColor(181, 143, 206, 150);
	std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
		ofColor(147, 112, 219, 100), 
		ofColor(255, 218, 185, 100)
	);
	gradient_test->addColor(ofColor(200, 69, 69, 100), 0.01);
	gradient_test->addColor(ofColor(200, 200, 18, 100), 0.1);

	
	// 3D Attractor ===========================================================================================
	// 
	 //std::array<att::real, 3> init_position{ 0.1f, 0.1f, 0.1f };
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::LorenzAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::ThomasSymmetricAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::LangfordAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::DadrasAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::HalvorsenAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::RosslerAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::RabinovichFabrikantAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::SprottBAttractor>(0.05, true);

	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::ChenAttractor>(0.01, true);

	//requires a codec for the 
	//std::array<att::real, 30> a = att::codeTranslator<30>("JKRADSXGDBHIJTQJJDICEJKYSTXFNU");
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::QuadraticSporttAttractor3D>(1.0, a, false);

	int particles = 10000;
	std::array<att::real, 3> max_init_pos = { 1.0f, 1.0f, 1.0f };
	std::array<att::real, 3> min_init_pos = { 0.0f, 0.0f, 0.0f };

	//ofRunApp(window, make_shared<ofParticlesApp>(
	//	attractor,
	//	particles,
	//	attractor_color,
	//	max_iters,
	//	max_init_pos,
	//	min_init_pos,
	//	drawing_speed,
	//	init_iters,
	//	background_color
	//));

	/*ofRunApp(window, make_shared<ofPointSpaceApp3D>(
	    attractor,
		attractor_color,
		ode_solver,
		primative_mode,
		max_iters,
		init_position,
		drawing_speed,
		init_iters,
		background_color
	));*/


	// 2D Attractor ===========================================================================================
	
	std::array<att::real, 2> init_position{ 0.0f, 0.0f };
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CliffordAttractor>(1.2, false, 1.5, -1.8, 1.6, 0.9);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::PeterDeJongAttractor>(1.2, false);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::JohnnySvenssonAttractor>(1.2, false);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::GummowskiMiraAttractor>(1.2, false);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::DuffingAttractor>(0.01, false);

	//init_position = { -0.72f, -0.64f}; //unstable for many other initial values.
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::TinkerbellAttractor>(1.2, false);

	//init_position = { 0.01f, 0.01f }; //unstable for larger values.
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::HenonMapBifurcationAttractor>(0.01, false);

	//requires a codec for the 
	//std::array<att::real, 12> a = att::codeTranslator<12>("CVQKGHQTPHTE");
	//std::array<att::real, 12> a = att::codeTranslator<12>("AGHNFODVNJCP");
	//std::array<att::real, 12> a = att::codeTranslator<12>("ELXAPXMPQOBT");
	//std::array<att::real, 12> a = att::codeTranslator<12>("JTTSMBOGLLQF");
	//std::array<att::real, 12> a = att::codeTranslator<12>("QKOCSIDVTPGY");
	//std::array<att::real, 12> a = att::codeTranslator<12>("QLOIARXYGHAJ");
	//std::array<att::real, 12> a = att::codeTranslator<12>("TJUBWEDNRORR");
	std::array<att::real, 12> a = att::codeTranslator<12>("ZPMSGCNFRENG");

	std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::QuadraticSporttAttractor>(1.0, a, true);

	//requires a codec for the 
	//std::array<att::real, 20> a = att::codeTranslator<20>("JYCBMNFNYOEPYUGHHESU");
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CubicSporttAttractor>(1.0, a, false);

	
	//---histogram specific settings.
	std::array<int, 2> margins = { 50, 50 };
	int attractor_width = window_width - margins[0] * 2;
	int attractor_height = window_height - margins[1] * 2;
	int blend_strength = 300;

	/*ofRunApp(window, make_shared<ofHistogramApp>(
		attractor,
		attractor_width,
		attractor_height,
		gradient_test,
		margins,
		max_iters,
		init_position,
		init_iters,
		background_color,
		blend_strength,
		"attractor.jpg"
	));*/


	ofRunApp(window, make_shared<ofPointSpaceApp2D>(
		attractor,
		gradient_test,
		ode_solver,
		primative_mode, 
		max_iters,
		init_position,
		drawing_speed,
		init_iters,
		background_color
	));

	ofRunMainLoop();

}
