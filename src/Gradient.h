#pragma once
#include "ofMain.h"
#include "Common/AttTypes.h"
#include <vector>
#include <utility>
#include <algorithm>

namespace att {
	
	using colorPos = std::pair<ofColor, real>;

	class Gradient {

	public:

		Gradient(ofColor first, ofColor last) {
			m_definers.push_back(colorPos(first, 0.0));
			m_definers.push_back(colorPos(last, 1.0));
		}

		Gradient(const Gradient& gradient) {
			m_definers = gradient.m_definers;
		}

		Gradient(Gradient&& gradient) noexcept
			: m_definers( std::move(gradient.m_definers))
		{}

		void addColor(const ofColor& color, real position) {

			if (position <= 0.0 || position >= 1.0)
				throw std::exception("the position of the color in the gradient should be strictly between 0 and 1");
			
			m_definers.push_back(colorPos(color, ofClamp(position + ofRandom(_EPSILON), 0.0, 1.0 - _EPSILON)));

			std::sort(m_definers.begin(), m_definers.end(), _colorPosComp);
		}

		ofColor getColor(real position) {

			if (position < 0.0 || position > 1.0)
				throw std::exception("the position of the color in the gradient should be between 0 and 1");

			if (position == 0.0)
				return m_definers.front().first;

			if (position == 1.0)
				return m_definers.back().first;

			auto it = std::upper_bound(m_definers.begin(), m_definers.end(), colorPos(ofColor::black, position), _colorPosComp);

			colorPos firstColor = *(it - 1);
			colorPos secondColor = *it;

			return firstColor.first.getLerped(secondColor.first, normalize(position, secondColor.second, firstColor.second));
		}

	protected:

		std::function<bool(colorPos, colorPos)> _colorPosComp = [](const colorPos a, const colorPos b) {
			return a.second < b.second;
		};

		std::vector<colorPos> m_definers;
		const real _EPSILON = 0.0001;
	};
}
