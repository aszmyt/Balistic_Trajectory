/*
 * DifferentialSolver.hh
 *
 *  Created on: 05-12-2015
 *      Author: mateusz
 */

#ifndef DIFFERENTIALSOLVER_HH_
#define DIFFERENTIALSOLVER_HH_

#include "Point.hh"
#include "Enviroment.hh"

class DifferentialSolver {
private:
	Enviroment* _enviroment;
	double t0;
	double h;
	Point y0, dy0, d2y0;
public:
	DifferentialSolver(Enviroment* enviroment, double t0,Point y0, Point dy0, double h, Point d2y0);
	Point* Step(double& t1, Point y1, Point dy1, Point d2y1 );
};

#endif /* DIFFERENTIALSOLVER_HH_ */

