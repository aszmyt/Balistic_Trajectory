#include"../inc/Matrix.hh"
#include <cstdlib>

Matrix::Matrix(int size)
{
	this->_size=size;
	_columns = new Vector*[_size];

	for(int i=0;i<_size;i++)
		_columns[i] = new Vector(_size);
}

void Matrix::Transpose() {
	Matrix trans = *this;
	for(int i=0;i<_size;i++) {
		for(int j=0;j<_size;j++) {
			_columns[i][j]=trans[j][i];
		}
	}
}

Vector* Matrix::operator*(const Vector w) const {
	Vector* product = new Vector(_size);
	for(int i=0;i<_size;i++) {
		(*product)[i] = (*(_columns)[i]*w);
	}
	return product;
}

Vector Matrix::operator[](const unsigned int column) const {
	return *(_columns)[column];
}
Vector& Matrix::operator[](const unsigned int column) {
	return *(_columns)[column];
}

Matrix& Matrix::operator=(const Matrix m) {
	for(int i;i<_size;i++) {
		*(_columns)[i]=m[i];
	}
	return *this;
}

int Matrix::size()
{
	return _size;
}

Matrix::~Matrix()
{
	for(int i=0;i<_size;i++)
		delete _columns[i];
	delete[] _columns;
}
