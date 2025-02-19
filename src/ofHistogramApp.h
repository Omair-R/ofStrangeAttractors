#pragma once
#include "Artists.h"
#include "Attractors.h"
#include "ofAbstractAttractorApp.h"

class ofHistogramApp : public ofAbstractAttractorApp
{
public:

	ofHistogramApp(
		std::shared_ptr<att::AbstractAttractor<2>> attractor,
		int image_width, 
		int image_height,
		ofColor point_color,
		std::array<int, 2> drawing_margins = {0, 0},
		int max_iterations = 1000000,
		std::array<att::real, 2> init_position = { 1.0f, 1.0f },
		int init_iterations = 100,
		ofColor background_color = ofColor::black,
		int background_blend_strength = 100,
		const std::filesystem::path& file_name = ""
	);

	ofHistogramApp(
		std::shared_ptr<att::AbstractAttractor<2>> attractor,
		int image_width,
		int image_height,
		std::shared_ptr<att::Gradient> gradient,
		std::array<int, 2> drawing_margins = { 0, 0 },
		int max_iterations = 1000000,
		std::array<att::real, 2> init_position = { 1.0f, 1.0f },
		int init_iterations = 100,
		ofColor background_color = ofColor::black,
		int background_blend_strength = 100,
		const std::filesystem::path& file_name = ""
	);

	void setup();
	void update();
	void draw();

private:

	ofHistogramApp(
		int image_width,
		int image_height,
		int max_iterations,
		std::array<att::real, 2> init_position,
		int init_iterations,
		ofColor background_color,
		int background_blend_strength
	) {
		m_image_width = image_width;
		m_image_height = image_height;

		m_max_iterations = max_iterations;
		m_init_iteraltions = init_iterations;
		m_init_position = init_position;

		m_background_blend_strength = background_blend_strength;
		m_background_color = background_color;
	}

	int m_image_width;
	int m_image_height;

	int m_max_iterations;
	int m_init_iteraltions;
	std::array<att::real, 2> m_init_position;

	int m_background_blend_strength;
	ofColor m_background_color;

	std::shared_ptr<att::HistogramArtist> p_artist;
};

