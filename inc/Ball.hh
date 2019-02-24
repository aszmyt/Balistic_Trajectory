#ifndef BALL_HH_
#define BALL_HH_

#include <vector>
#include <cmath>
#include "Point.hh"

class Ball {
private:
	Point _startPosition;
	Point _startVelocity;
	double _mass, _surface;
	std::vector<Point*> _trace;
public:
	Ball(Point initialPoint,Point startVelocity, double mass, double surface);
	void setNextTracePoint(Point* p);
	Point getInitialPoint();
	double getMass();
	double getSurface();
	Point getStartVelocity();
	std::vector<Point*>& getTrace();
};

#endif /* BALL_HH_ */
