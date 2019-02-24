/*
 * Point.hh
 *
 *  Created on: 05-12-2015
 *      Author: mateusz
 */

#ifndef POINT_HH_
#define POINT_HH_

#include <iostream>
#include <stdlib.h>

class Point {
private:
	static const int _n=2;
	double _coord[_n];
public:
	Point();
	Point(double x, double y);
	Point(const Point& p);
	double& operator[](int index);
	double operator[](const int index) const;
	Point operator+(const Point w) const;
	Point operator*(const double c) const;
	Point operator/(const double c) const;
	double operator*(const Point p) const;
	Point& operator= (const Point &w);
};

#endif /* POINT_HH_ */
