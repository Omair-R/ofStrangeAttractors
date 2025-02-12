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
	int window_width = 1920;
	int window_height = 1080;
	settings.setSize(window_width, window_height);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	//-----general artist and attractor settings.
	int drawing_speed = 2;
	int max_iters = 5'000'000;
	int init_iters = 100;
	att::OdeSolver ode_solver = att::OdeSolver::EULER;
	ofPrimitiveMode primative_mode = OF_PRIMITIVE_POINTS;

	ofColor attractor_color = ofColor(190, 129, 182, 100);

	//Some beautiful colors =============================================
	//ofColor background_color = ofColor::purple/5;
	//std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
	//	ofColor(147, 112, 219, 150), 
	//	ofColor(255, 218, 185, 150)
	//);
	//gradient_test->addColor(ofColor(200, 69, 69, 150), 0.01);
	//gradient_test->addColor(ofColor(200, 200, 18, 150), 0.1);

	//---------------
	//ofColor background_color = ofColor::blue / 5;
	//std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
	//	ofColor(24, 32, 111),
	//	ofColor(245, 226, 200)
	//);
	//gradient_test->addColor(ofColor(245, 226, 200), 0.05);

	////---------------
	/*ofColor background_color = ofColor(109, 67, 90);
	std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
		ofColor(177, 237, 232),
		ofColor(255, 252, 249)
	);*/

	//---------------
	/*ofColor background_color = ofColor::forestGreen / 5;
	std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
		ofColor(200, 223, 82),
		ofColor(254, 222, 0)
	);*/
	//gradient_test->addColor(ofColor(254, 222, 0), 0.05);

	//---------------
	/*ofColor background_color = ofColor(0, 182, 188)/3;
	std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
		ofColor(161, 219, 241),
		ofColor(228, 244, 243)
	);
	gradient_test->addColor(ofColor(228, 244, 243), 0.05);*/

	//---------------
	//ofColor background_color = ofColor(93, 89, 175)/2;
	//std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
	//	ofColor(190, 129, 182),
	//	ofColor(227, 144, 200)
	//);
	//gradient_test->addColor(ofColor(227, 144, 200), 0.05);

	//---------------
	//ofColor background_color = ofColor(249, 0, 103)/2;
	//std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
	//	ofColor(238, 202, 201),
	//	ofColor(240, 229, 208)
	//);
	//gradient_test->addColor(ofColor(240, 229, 208), 0.05);

	//---------------
	ofColor background_color = ofColor(59, 34, 68);
	std::shared_ptr<att::Gradient> gradient_test = std::make_shared< att::Gradient>(
		ofColor(45, 118, 112,150),
		ofColor(205, 150, 107,150)
	);
	//gradient_test->addColor(ofColor(205, 150, 107), 0.05);

	
	// 3D Attractor ===========================================================================================
	// 
	 std::array<att::real, 3> init_position{ 0.1f, 0.1f, 0.1f };
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::LorenzAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::ThomasSymmetricAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::LangfordAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::DadrasAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::HalvorsenAttractor>(0.01, true);
	std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::RosslerAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::RabinovichFabrikantAttractor>(0.01, true);
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::SprottBAttractor>(0.05, true);

	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::ChenAttractor>(0.01, true);

	//requires a codec for the 
	//std::array<att::real, 30> a = att::codeTranslator<30>("JKRADSXGDBHIJTQJJDICEJKYSTXFNU");
	//std::shared_ptr<att::AbstractAttractor<3>> attractor = std::make_shared<att::QuadraticSporttAttractor3D>(1.0, a, true);

	int particles = 10000;
	std::array<att::real, 3> max_init_pos = { 1.0f, 1.0f, 1.0f };
	std::array<att::real, 3> min_init_pos = { 0.0f, 0.0f, 0.0f };

	ofRunApp(window, make_shared<ofParticlesApp>(
		attractor,
		particles,
		gradient_test,
		max_iters,
		max_init_pos,
		min_init_pos,
		drawing_speed,
		init_iters,
		background_color
	));

	/*ofRunApp(window, make_shared<ofPointSpaceApp3D>(
	    attractor,
		gradient_test,
		ode_solver,
		primative_mode,
		max_iters,
		init_position,
		drawing_speed,
		init_iters,
		background_color
	));*/


	// 2D Attractor ===========================================================================================
	
	//std::array<att::real, 2> init_position{ 0.1f, 0.1f };
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CliffordAttractor>(1.2, false, 1.5, -1.8, 1.6, 0.9);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CliffordAttractor>(1.2, true, 1.7, 1.7, 0.6, 1.2);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CliffordAttractor>(1.2, false, -1.7, 1.3, -0.1, -1.2);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CliffordAttractor>(1.2, false, -1.7, 1.8, -1.9, -0.4);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CliffordAttractor>(1.2, false, 1.6, -0.6, -1.2, 1.6);
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CliffordAttractor>(1.2, false, 2, 2, 1, -1);
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
	//std::array<att::real, 12> a = att::codeTranslator<12>("ZPMSGCNFRENG");

	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::QuadraticSporttAttractor>(1.0, a, true);

	//requires a codec for the 
	//std::array<att::real, 20> a = att::codeTranslator<20>("JYCBMNFNYOEPYUGHHESU");
	//std::shared_ptr<att::AbstractAttractor<2>> attractor = std::make_shared<att::CubicSporttAttractor>(1.0, a, false);

	
	//---histogram specific settings.
	std::array<int, 2> margins = { 600, 200 };
	int attractor_width = window_width - margins[0] * 2;
	int attractor_height = window_height - margins[1] * 2;
	int blend_strength = 50;

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
		blend_strength
	));*/


	//ofRunApp(window, make_shared<ofPointSpaceApp2D>(
	//	attractor,
	//	gradient_test,
	//	ode_solver,
	//	primative_mode, 
	//	max_iters,
	//	init_position,
	//	drawing_speed,
	//	init_iters,
	//	background_color
	//));

	ofRunMainLoop();

}
