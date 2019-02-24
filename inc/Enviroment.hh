/*
 * Enviroment.hh
 *
 *  Created on: 05-12-2015
 *      Author: mateusz
 */

#ifndef ENVIROMENT_HH_
#define ENVIROMENT_HH_

#include <cmath>
#include "Ball.hh"

class Enviroment {
private:
	double _airDensity;
	double _dragCoeff;
	double _g;
	Ball* _ball;
public:
	Enviroment(Ball* ball, double airDensity, double dragCoeff, double g);
	Point calculateAcceleration(double t, Point y, Point v);
};

#endif /* ENVIROMENT_HH_ */
