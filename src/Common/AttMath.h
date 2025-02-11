#pragma once
#include "AttTypes.h"

namespace att {

	template<unsigned int N>
	real magnitude(const std::array <real, N>& vec) {
		real mag_square = 0;
		for (int i = 0; i < N; i++) {
			mag_square += vec[i] * vec[i];
		}
		return std::sqrt(mag_square);
	}

	inline real normalize(real value, real max, real min) {
		if (max == min)
			return 1.0;
		return (value - min) / (max - min);
	}

	inline real fastSigmoid(real num) {
		return 0.5 * (num / (1 + abs(num))) + 0.5;
	}

}