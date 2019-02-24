#ifndef MATRIXINVERSION_HH_
#define MATRIXINVERSION_HH_

#include "Matrix.hh"

class MatrixInversion {
private:
	int GetMinor(Matrix* src, Matrix* dest, int row, int col);
	double Determinant(Matrix* m);
public:
	Matrix* inverse(Matrix* m);
};

#endif /* MATRIXINVERSION_HH_ */
