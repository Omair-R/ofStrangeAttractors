#pragma once
#include "AbstractArtist.h"
#include "../Gradient.h"
#include <cmath>
#include <vector>
#include <array>

namespace att{

	/// <summary>
	/// This artist draws 2D attractors on a 2D histogram canvas. The dump mode is the recommended one.
	/// </summary>
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
		
		/// <summary>
		/// Draws the attractor as a histogram on the screen. It constructs the histogram, since it requires information about the space and attractor (min and max). Uses ofImage.
		/// </summary>
		void draw() override;

		/// <summary>
		/// Performes all the attractor system iterations at once, and keeps track of the positions in memory. It does not construct the histogram.
		/// </summary>
		void dump() override;

		/// <summary>
		/// Periodically updates the system. It stands in opposition to the dump method. It does not construct the histogram.
		/// </summary>
		/// <param name="update_speed">: The number of iterations to be taken in a single update frame.</param>
		/// <param name="reset">: Resets the system and starts from </param>
		void update(int update_speed = 1, bool reset = false) override;

		/// <summary>
		/// Enables signular color mode, which utilizes only one color to draw the attractor. 
		/// </summary>
		/// <param name="color"></param>
		virtual void singularColorMode(ofColor color) override;

		/// <summary>
		/// Enables gradient color mode, which utilizes a gradient spectrum to draw the attractor. 
		/// </summary>
		/// <param name="gradient"></param>
		virtual void gradientColorMode(
			std::shared_ptr<att::Gradient> gradient
		);

		/// <summary>
		/// blends the attractor points with the background. It assigns different alpha values based on the frequency of occurance.
		/// </summary>
		/// <param name="blend_strength"></param>
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
		std::array<real, 2> m_init_position;
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

