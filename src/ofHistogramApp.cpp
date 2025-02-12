#include "ofHistogramApp.h"


ofHistogramApp::ofHistogramApp(
	std::shared_ptr<att::AbstractAttractor<2>> attractor,
	int image_width, 
	int image_height, 
	ofColor point_color,
	std::array<int, 2> drawing_margins,
	int max_iterations, 
	std::array<att::real, 2> init_position, 
	int init_iterations, 
	ofColor background_color, 
	int background_blend_strength,
	const std::filesystem::path& file_name) : ofHistogramApp(
		image_width,
		image_height,
		max_iterations,
		init_position,
		init_iterations,
		background_color,
		background_blend_strength
	)
{
	p_artist = std::make_shared<att::HistogramArtist>(
		m_image_width, 
		m_image_height, 
		background_color, 
		drawing_margins,
		OF_PRIMITIVE_POINTS,
		file_name);

	p_artist->singularColorMode(point_color);

	p_artist->init(
		attractor,
		m_init_position,
		m_max_iterations,
		m_init_iteraltions
	);

}

ofHistogramApp::ofHistogramApp(
	std::shared_ptr<att::AbstractAttractor<2>> attractor,
	int image_width, 
	int image_height, 
	std::shared_ptr<att::Gradient> gradient, 
	std::array<int, 2> drawing_margins,
	int max_iterations, std::array<att::real, 2> init_position, 
	int init_iterations, 
	ofColor background_color, 
	int background_blend_strength,
	const std::filesystem::path& file_name) : ofHistogramApp(
		image_width,
		image_height,
		max_iterations,
		init_position,
		init_iterations,
		background_color,
		background_blend_strength
	)
{
	p_artist = std::make_shared<att::HistogramArtist>(
		m_image_width,
		m_image_height,
		background_color,
		drawing_margins,
		OF_PRIMITIVE_POINTS,
		file_name);

	p_artist->gradientColorMode(gradient);

	p_artist->init(
		attractor,
		m_init_position,
		m_max_iterations,
		m_init_iteraltions
	);
}

void ofHistogramApp::setup()
{	
	p_artist->enableBackgroundBlend(m_background_blend_strength);
	p_artist->dump();
}

void ofHistogramApp::update()
{
}

void ofHistogramApp::draw()
{
	ofBackground(m_background_color);
	p_artist->draw();
}
