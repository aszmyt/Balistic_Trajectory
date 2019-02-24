#include "../inc/Interpolation.hh"
#include "../inc/Vector.hh"
#include "../inc/MatrixInversion.hh"
#include <cmath>
#include <iostream>

using namespace std;

Vector* Interpolation::interpolate(double x[],double y[])
{
	Matrix* A = new Matrix(4);
	Vector* u = new Vector(4);

	(*A)[0][0]=1;
	(*A)[0][1]=x[0];
	(*A)[0][2]=pow(x[0],2);
	(*A)[0][3]=pow(x[0],3);

	(*A)[1][0]=1;
	(*A)[1][1]=x[1];
	(*A)[1][2]=pow(x[1],2);
	(*A)[1][3]=pow(x[1],3);

	(*A)[2][0]=1;
	(*A)[2][1]=x[2];
	(*A)[2][2]=pow(x[2],2);
	(*A)[2][3]=pow(x[2],3);

	(*A)[3][0]=1;
	(*A)[3][1]=x[3];
	(*A)[3][2]=pow(x[3],2);
	(*A)[3][3]=pow(x[3],3);

	(*u)[0]=y[0];
	(*u)[1]=y[1];
	(*u)[2]=y[2];
	(*u)[3]=y[3];

	MatrixInversion inversion;
	Matrix* inversedA = inversion.inverse(A);
	Vector* result = multiple(inversedA,u);

	return result;
}

Vector* Interpolation::multiple(Matrix* m, Vector* v)
{
	Vector* result = new Vector(4);
	double sum;
	for(int i=0;i<m->size();i++)
	{
		sum=0;
		for(int j=0;j<m->size();j++)
		{
			sum+= (*m)[i][j]*(*v)[j];
		}
		(*result)[i]=sum;
	}
	return result;
}
