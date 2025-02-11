#pragma once
#include "ofMain.h"
#include <array>

namespace att {

	#ifdef ATT_FLOAT
		using real = float;
		#define cos_func cosf
		#define sin_func sinf
		#define round_func roundf
		
		#define ATT_MAX_REAL std::numeric_limits<float>::max();
		#define ATT_MIN_REAL std::numeric_limits<float>::min();

	#else // ATT_FLOAT
		using real = double;
		#define cos_func cos
		#define sin_func sin
		#define round_func round

		#define ATT_MAX_REAL std::numeric_limits<double>::max();
		#define ATT_MIN_REAL std::numeric_limits<double>::min();

	#endif // ATT_FLOAT

	#define ATT_MAX_INT std::numeric_limits<int>::max();
	#define ATT_MAX_LONG std::numeric_limits<long>::max();
	#define TRANSPARENT_COLOR ofColor(0,0,0,0) 

	enum ColorMode {
		COLOR_MODE_SINGULAR,
		COLOR_MODE_VELOCITY_BASED,
		COLOR_MODE_GRADIENT
	};

	enum OdeSolver {
		EULER,
		RUNGE_KUTTA2
	};

	
}