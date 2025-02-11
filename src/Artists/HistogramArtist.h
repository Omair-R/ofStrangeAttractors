#pragma once
#include "AbstractArtist.h"
#include "../Gradient.h"
#include <cmath>
#include <vector>
#include <array>

namespace att{
	class HistogramArtist :
		public AbstractArtist<2>
	{

	public:
		HistogramArtist(
			int histogram_width,
			int histogram_height,
			ofColor background_color = ofColor::black,
			std::array<int, 2> drawing_margin = {20, 20},
			ofPrimitiveMode mode = OF_PRIMITIVE_POINTS
		);

		void init(
			std::shared_ptr<AbstractAttractor<2>> attractor,
			std::array<att::real, 2> init_position,
			int iterations = 1000000,
			int init_iterations = 100
		);
		
		void draw() override;

		void dump() override;

		void update(int update_speed = 200, bool reset = false) override;

		virtual void singularColorMode(ofColor color) override;

		virtual void gradientColorMode(
			std::shared_ptr<att::Gradient> gradient
		);

		void enableBackgroundBlend(real blend_strength);

		void disableBackgroundBlend();

	protected:
		void _init(
			std::shared_ptr<AbstractAttractor<2>> attractor,
			std::array<att::real, 2> init_position,
			int iterations = 1000000,
			int init_iterations = 100
		) override;

		void _singleStep() override;

		void _reset2dVector();

		int m_histogram_width;
		int m_histogram_height;

		ofFloatImage m_attractor_image;

		std::vector<std::vector<int>> m_histogram;
		std::vector<std::array<real, 2>> m_positions;

		std::shared_ptr<Gradient> m_gradient = nullptr;

		real min_x = ATT_MAX_REAL;
		real max_x = ATT_MIN_REAL;
		real min_y = ATT_MAX_REAL;
		real max_y = ATT_MIN_REAL;

		real m_blend_strength = 1.0f;

		bool m_should_redraw = false;
		bool m_blend_with_background = false;

		ofColor m_background_color;
		std::array<int, 2> m_drawing_margin;
	};
}

