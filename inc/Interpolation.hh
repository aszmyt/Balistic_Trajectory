/*
 * Interpolation.hh
 *
 *  Created on: 08-12-2015
 *      Author: mateusz
 */

#ifndef INTERPOLATION_HH_
#define INTERPOLATION_HH_

#include "Matrix.hh"
#include "Vector.hh"

class Interpolation {
private:
	Vector* multiple(Matrix* m, Vector* v);
public:
	Vector* interpolate(double x[],double y[]);
};

#endif /* INTERPOLATION_HH_ */
