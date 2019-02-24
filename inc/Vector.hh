#ifndef Vector_HH_
#define Vector_HH_

#include "../inc/Size.hh"
#include <iostream>

class Vector {
	private:
		int _size;
		double* _components;
	public:
		Vector operator+(const Vector w) const;
		Vector operator-(const Vector w) const;
		double operator*(const Vector w) const;
		Vector operator*(const double number) const;
		Vector operator/(const double number) const;
		double operator[](const unsigned int index) const;
		double &operator[](const unsigned int index);
		Vector& operator= (const Vector &w);
		Vector(int size);
		~Vector();
};


#endif /* Vector_HH_ */
