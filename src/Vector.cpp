#include "../inc/Vector.hh"
#include <cstdlib>

Vector& Vector::operator= (const Vector &w) {
	for (int i=0;i<_size;i++) {
		_components[i]=w[i];
	}
	return *this;
}

Vector::Vector(int size) {
	this->_size=size;
	_components = new double[_size];
	for(int i=0;i<_size;i++)
		_components[i]=0;
}

Vector Vector::operator*(const double number) const {
	Vector* product = new Vector(_size);

	for(int i=0;i<_size;i++) {
		(*product)[i]=number*_components[i];
	}
	return *product;
}

Vector Vector::operator/(const double number) const {
	Vector* quotient = new Vector(_size);
	if(number==0.0) {
		std::cerr<<"Nie mozna dzielic przez 0 \n";
	}

	for(int i=0;i<_size;i++) {
		(*quotient)[i]=_components[i]/number;
	}
	return *quotient;
}

double &Vector::operator[](const unsigned int index) {
	if(index>=_size) {
		std::cout<<"index przekracza _size Vectora!\n";
		exit(EXIT_FAILURE);

		}
		return _components[index];
}

double Vector::operator[](const unsigned int index) const {
	if(index>=_size) {
		std::cout<<"index przekracza _size Vectora!\n";
		exit(EXIT_FAILURE);
	}
	return _components[index];
}

Vector Vector::operator+(const Vector w) const {
	Vector* sum_vector = new Vector(_size);

	for(int i=0;i<_size;i++) {
		sum_vector[i]=_components[i]+w._components[i];
	}
	return *sum_vector;
}

Vector Vector::operator-(const Vector w) const {
	Vector* diff_vector = new Vector(_size);

	for(int i=0;i<_size;i++) {
		diff_vector[i]=_components[i]-w._components[i];
	}
	return *diff_vector;
}

double Vector::operator*(const Vector w) const {
	double scalar=0;

	for(int i=0;i<_size;i++) {
		scalar=scalar+_components[i]+w._components[i];
	}
	return scalar;
}

Vector::~Vector()
{
	delete[] _components;
}
