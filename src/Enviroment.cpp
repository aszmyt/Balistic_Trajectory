#include "../inc/Enviroment.hh"


Enviroment::Enviroment(Ball* ball, double airDensity, double dragCoeff, double g)
{
	this->_ball=ball;
	this->_airDensity=airDensity;
	this->_dragCoeff=dragCoeff;
	this->_g=g;
}

Point Enviroment::calculateAcceleration(double t, Point y, Point v)
{
	double vx = v[0];
	double vy = v[1];
	double vxSqr = vx*vx;
	double vySqr = vy*vy;
	double vSqr = vxSqr+vySqr;
	double vTotal = sqrt(vSqr);

	double cosAlpha = 1;
	double cosBeta = 0;
	if (vTotal > 1.0e-12)
	{
	   cosAlpha = vx / vTotal;
	   cosBeta = vy / vTotal;
	 }

	double drag = 0.5 * _dragCoeff * _airDensity * vSqr * _ball->getSurface();
	double dragX = -drag * cosAlpha;
	double dragY = -drag * cosBeta;

	Point force(dragX, -_ball->getMass()*_g+dragY);

	Point acceleration = force/_ball->getMass();

	return acceleration;
}
