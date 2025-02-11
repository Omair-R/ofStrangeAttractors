#include "HistogramArtist.h"

att::HistogramArtist::HistogramArtist(
	int histogram_width, 
	int histogram_height, 
	ofColor background_color,
	std::array<int, 2> drawing_margin,
	ofPrimitiveMode mode
) : AbstractArtist<2>(OdeSolver::EULER) {

	m_histogram_width = histogram_width;
	m_histogram_height = histogram_height;
	m_attractor_image.allocate(histogram_width, histogram_height, OF_IMAGE_COLOR);
	m_background_color = background_color;
	m_drawing_margin = drawing_margin;
}

void att::HistogramArtist::init(std::shared_ptr<AbstractAttractor<2>> attractor, std::array<att::real, 2> init_position, int iterations, int init_iterations)
{
	_init(
		attractor,
		init_position,
		iterations,
		init_iterations
	);
	
}

inline void att::HistogramArtist::_init(
	std::shared_ptr<AbstractAttractor<2>> attractor, 
	std::array<att::real, 2> init_position, 
	int iterations, 
	int init_iterations
) {

	m_positions.reserve(m_iterations);

	m_histogram.reserve(m_histogram_width);
	for (int i = 0; i < m_histogram_height; i++) {
		std::vector<int> row;
		row.reserve(m_histogram_width);
		for (int j = 0; j < m_histogram_width; j++) {
			row.emplace_back(0);
		}
		m_histogram.push_back(row);
	}

	if (attractor == nullptr) {
		throw std::exception("attractor property must not be null.");
	}
	p_attractor = attractor;
	m_position = init_position;
	m_init_position = init_position;
	m_iterations = iterations;

	m_position = p_attractor->init(m_position, init_iterations);

	m_initialized = true;
	
}

void att::HistogramArtist::draw() {
	if (!m_initialized)
		throw std::exception("drawing the attractor prior to initalization is not allowed.");

	if (m_should_redraw) {
		// TODO : optimize
		m_attractor_image.setColor(m_background_color);

		int max_count = 0;
		int min_count = ATT_MAX_INT;

		_reset2dVector();

		for (const std::array<real, 2>&position : m_positions) {

			std::array<int, 2> int_position{ 0.0, 0.0 };

			int_position[0] = int(normalize(position[0], max_x, min_x) * (m_histogram_width - 1));
			int_position[1] = int(normalize(position[1], max_y, min_y) * (m_histogram_height - 1));

			m_histogram[int_position[1]][int_position[0]] += 1;
			int count = m_histogram[int_position[1]][int_position[0]];

			max_count = std::max(count, max_count);
			min_count = std::min(count, min_count);
		}

		//m_positions.clear(); // TODO: decide if this is necessary.

		switch (m_color_mode)
		{
		case ColorMode::COLOR_MODE_SINGULAR:
			for (int r = 0; r < m_histogram_height; r++) {
				for (int c = 0; c < m_histogram_width; c++) {

					int val = m_histogram[r][c];
					if (val == 0)
						continue;

					ofColor color = m_color;

					if (m_blend_with_background) {
						float t = normalize(val, max_count, min_count);
						color = m_background_color.getLerped(m_color, ofClamp(t * m_blend_strength, 0, 1));
					}
						
					m_attractor_image.setColor(c, r, color);
				}
			}
			break;
		case ColorMode::COLOR_MODE_GRADIENT:
			for (int r = 0; r < m_histogram_height; r++) {
				for (int c = 0; c < m_histogram_width; c++) {

					int val = m_histogram[r][c];
					if (val == 0)
						continue;

					float t = normalize(val, max_count, min_count);

					ofColor color = m_gradient->getColor(t);

					if (m_blend_with_background) {
						color = m_background_color.getLerped(color, ofClamp(t * m_blend_strength, 0, 1));
					}

					m_attractor_image.setColor(c, r, color);
				}
			}
			break;
		default:
			break;
		}

		m_attractor_image.update();
		m_should_redraw = false;

		if (m_dumped) {
			m_positions.clear();
			m_positions = vector<std::array<att::real, 2>>();
		}
	}
	m_attractor_image.draw(m_drawing_margin[0], m_drawing_margin[1]);
}

void att::HistogramArtist::dump() {
	if (!m_initialized)
		throw std::exception("dumping the attractor prior to initalization is not allowed.");

	if (m_dumped) {
		m_positions.reserve(m_iterations);
	}

	for (int i = 0; i < m_iterations; i++) {
		_singleStep();
	}

	m_dumped = true;
	m_should_redraw = true;
}

void att::HistogramArtist::update(int update_speed, bool reset) {
	if (!m_initialized)
		throw std::exception("updating the attractor prior to initalization is not allowed.");

	if (m_dumped)
		throw std::exception("full graph was dumped, update mode requires the removal of the call to dump.");

	if (reset) {
		m_current_iteration = 0;
		m_positions.clear();
		m_position = m_init_position;
	}

	if (m_current_iteration < m_iterations) {
		for (int i = 0; i < update_speed; i++) {
			_singleStep();
		}
		m_current_iteration += update_speed;
		m_should_redraw = true;
	}
}

void att::HistogramArtist::singularColorMode(ofColor color)
{
	att::AbstractArtist<2>::singularColorMode(color);
	m_should_redraw = true;
}

inline void att::HistogramArtist::gradientColorMode(
	std::shared_ptr<att::Gradient> gradient
) {
	if (gradient == nullptr)
		throw exception("the gradient should not be null.");

	m_gradient = gradient;
	m_color_mode = ColorMode::COLOR_MODE_GRADIENT;

	m_should_redraw = true;
}

void att::HistogramArtist::enableBackgroundBlend(real blend_strength)
{
	m_blend_with_background = true;
	m_should_redraw = true;
	m_blend_strength = blend_strength;
}

void att::HistogramArtist::disableBackgroundBlend()
{
	m_blend_with_background = false;
	m_should_redraw = true;
	m_blend_strength = 1.0;
}

void att::HistogramArtist::_singleStep() {
	switch (m_solver)
	{
	case OdeSolver::EULER:
		m_position = p_attractor->eulerStep(m_position);
		break;
	case OdeSolver::RUNGE_KUTTA2:
		m_position = p_attractor->RK2Step(m_position);
		break;
	default:
		break;
	}

	if (m_position[0] != m_position[0] || m_position[1] != m_position[1])
		throw exception("Error: Unstable attractor. Adjust the parameters of the attractor so as to ensure stability.");

	m_positions.push_back(m_position);

	max_x = std::max(m_position[0], max_x);
	min_x = std::min(m_position[0], min_x);
	max_y = std::max(m_position[1], max_y);
	min_y = std::min(m_position[1], min_y);
}

inline void att::HistogramArtist::_reset2dVector()
{
	for (int r = 0; r < m_histogram_height; r++) {
		for (int c = 0; c < m_histogram_width; c++) {
			m_histogram[r][c] = 0;
		}
	}
}

