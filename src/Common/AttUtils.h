#pragma once
#include <array>
#include <string>
#include <algorithm>

namespace att {

	const char ALPHA_LETTERS[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
								"abcdefghijklmnopqrstuvwxyz";

	/// <summary>
	/// Translates the code introduced in Strange Attractors: Creating Patterns in Chaos by Julien C.Sprott
	/// into parameters.
	/// </summary>
	/// <typeparam name="N">The length of the code, corresponding to the number of parameters.</typeparam>
	/// <param name="code"></param>
	/// <returns>The attractor's translated parameters.</returns>
	template<unsigned int N>
	std::array<real, N> codeTranslator(std::string code) {
		if (code.length() != N) throw exception("Error: Code length does not match the output array.");

		std::transform(code.begin(), code.end(), code.begin(), ::tolower);
		int i = 0;
		std::array<real, N> a;
		for (char ch : code) {
			a[i] = ((ch - 'a') * 0.1) - 1.2;
			i++;
		}
		return a;
	}

	std::string generate_random_string(const int length) {
		std::string output;
		output.reserve(length);

		for (int i = 0; i < length; i++) 
			output += ALPHA_LETTERS[rand() % (sizeof(ALPHA_LETTERS) - 1)];

		return output;
	}
}
