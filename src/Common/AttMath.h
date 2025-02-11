#pragma once
#include "AttTypes.h"

namespace att {

	/// <summary>
	/// Compute the magnitude(L2-norm) of an ND-vector.
	/// </summary>
	/// <typeparam name="N">Cardinality of the vector (dimensions).</typeparam>
	/// <param name="vec">: The input vector.</param>
	/// <returns>The magnitude of the vector.</returns>
	template<unsigned int N>
	real magnitude(const std::array <real, N>& vec) {
		real mag_square = 0;
		for (int i = 0; i < N; i++) {
			mag_square += vec[i] * vec[i];
		}
		return std::sqrt(mag_square);
	}

	/// <summary>
	/// Applies min-max normalization to a specific value given the max and min of a feature/data column. https://en.wikipedia.org/wiki/Normalization_(statistics)
	/// </summary>
	/// <param name="value">: The value to be normalized.</param>
	/// <param name="max">: The maximum of the data column.</param>
	/// <param name="min">: The minimum of the data column.</param>
	/// <returns></returns>
	inline real normalize(real value, real max, real min) {
		if (max == min)
			return 1.0;
		return (value - min) / (max - min);
	}

	/// <summary>
	/// Applies the sigmoid function. https://en.wikipedia.org/wiki/Sigmoid_function
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	inline real fastSigmoid(real num) {
		return 0.5 * (num / (1 + abs(num))) + 0.5;
	}

}