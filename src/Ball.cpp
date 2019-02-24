#include "../inc/Ball.hh"

Ball::Ball(Point startPosition,Point startVelocity, double mass, double radius)
{
	this->_startPosition=startPosition;
	_trace.push_back(new Point(_startPosition));
	this->_mass=mass;
	this->_surface=M_PI*radius*radius;
	this->_startVelocity=startVelocity;
}

void Ball::setNextTracePoint(Point* p)
{
	_trace.push_back(p);
}

std::vector<Point*>& Ball::getTrace()
{
	return _trace;
}

Point Ball::getInitialPoint()
{
	return _startPosition;
}

double Ball::getMass()
{
	return _mass;
}

double Ball::getSurface()
{
	return _surface;
}

Point Ball::getStartVelocity()
{
	return _startVelocity;
}
