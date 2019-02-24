#include "../inc/MatrixInversion.hh"


Matrix* MatrixInversion::inverse(Matrix* m)
{
	double det = 1.0 / Determinant(m);

	Matrix* result = new Matrix(m->size());

	Vector *temp = new Vector((m->size() - 1)*(m->size() - 1));
	Matrix* minor = new Matrix(m->size() - 1);

	for (int j = 0; j<m->size(); j++)
	{
		for (int i = 0; i<m->size(); i++)
		{
			// get the co-factor (matrix) of A(j,i)
			GetMinor(m, minor, j, i);
			(*result)[i][j] = det*Determinant(minor);
			if ((i + j) % 2 == 1)
				(*result)[i][j] = -(*result)[i][j];
		}
	}

	delete temp;
	delete minor;

	return result;
}

int MatrixInversion::GetMinor(Matrix* src, Matrix* dest, int row, int col)
{
	int colCount = 0, rowCount = 0;

	for (int i = 0; i < src->size(); i++)
	{
		if (i != row)
		{
			colCount = 0;
			for (int j = 0; j < src->size(); j++)
			{
				if (j != col)
				{
					(*dest)[rowCount][colCount] = (*src)[i][j];
					colCount++;
				}
			}
			rowCount++;
		}
	}

	return 1;
}

double MatrixInversion::Determinant(Matrix* m)
{
	if (m->size() == 1)
		return (*m)[0][0];

	float det = 0;

	Matrix* minor = new Matrix(m->size()-1);

	for (int i = 0; i < m->size(); i++)
	{
		GetMinor(m, minor, 0, i);
		det += (i % 2 == 1 ? -1.0 : 1.0) * (*m)[0][i] * Determinant(minor);
	}

	delete minor;

	return det;
}
