#include "../inc/DifferentialSolver.hh"

DifferentialSolver::DifferentialSolver(Enviroment* enviroment, double t0,Point y0, Point dy0, double h, Point d2y0)
{
	this->_enviroment=enviroment;
	this->t0 = t0;
	this->y0 = y0;
	this->dy0 = dy0;
	this->h = h;
	this->d2y0 = d2y0;
}

Point* DifferentialSolver::Step(double& t1, Point y1, Point dy1, Point d2y1 )
{
	double h2 = h*h;
	Point k1 = d2y0;
	Point k2 = _enviroment->calculateAcceleration(t0 + h/2, y0 + dy0*h/2 + k1*h2/8, dy0 + k1*h/2);
	Point k3 = _enviroment->calculateAcceleration(t0 + h/2, y0 +  dy0*h/2 + k2*h2/8 , dy0 + k2*h/2);
	Point k4 = _enviroment->calculateAcceleration(t0 + h, y0 + dy0*h + k3*h2/2, dy0 + k3*h);

	t1 = t0+h;
	y1 = y0 + dy0*h + (k1 + k2 + k3)*h2/6;
	dy1 = dy0 + (k1 + k2*2 + k3*2 + k4)*h/6;
	d2y1 = _enviroment->calculateAcceleration(t1, y1, dy1);

	Point* position = new Point(y1);

	t0=t1;
	y0=y1;
	dy0=dy1;
	d2y0=d2y1;

	return position;
}
