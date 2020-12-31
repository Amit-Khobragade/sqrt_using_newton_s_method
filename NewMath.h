#pragma once
#include <stdexcept>

namespace newfunc {
	template <class T>
	double sqrt( T num, double accuracy = static_cast< double >(0.01) ) {
		double n = static_cast< double >(num);
		double x = n;
		double root = 0;
		if (n < 0.0)
			throw std::invalid_argument( "can't take square root of a number smaller than 0" );
		if (accuracy < 0 || accuracy > 1)
			throw std::invalid_argument( "Invalid Accuracy" );

		while (true) {
			root = 0.5 * (x + (n / x));
			if (std::abs( root - x ) < accuracy)
				break;
			x = root;
		}
		return root;
	}
}