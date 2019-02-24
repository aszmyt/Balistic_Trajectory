#include <iostream>
#include <fstream>

#include "../inc/Ball.hh"
#include "../inc/Enviroment.hh"
#include "../inc/DifferentialSolver.hh"
#include "../inc/lacze_do_gnuplota.hh"

#include "../inc/Matrix.hh"
#include "../inc/MatrixInversion.hh"
#include "../inc/Vector.hh"
#include "../inc/Interpolation.hh"

#define DATA "data.txt"

#define POINT_TO_INTERPOL 4

//zakresy wyswietlania
#define X1 0
#define X2 300
#define Y1 0
#define Y2 500

using namespace std;

int main() {

	std::fstream file;
	file.open( DATA, std::ios::out );

	/*CHART*/
	PzG::LaczeDoGNUPlota  Lacze;
	Lacze.DodajNazwePliku(DATA,PzG::RR_Punktowy,1);
	Lacze.Inicjalizuj();  // Start gnuplota
	Lacze.ZmienTrybRys(PzG::TR_2D);
	Lacze.UstawZakresY(Y1,Y2);
	Lacze.UstawZakresX(X1,X2);

	double startTime=0;
	double simulationTime=1000;
	double h=0.1;

	int mass = 3;
	int radious = 0.1;

	double startVelocityX = 10;
	double startVelocityY = 80;
	Point startVelocity(startVelocityX, startVelocityY);

	Point initialPosition(0, 0);

	double airDensity=1.29;
	double dragCoeff=0.5;
	double g=9.81;

	Ball* ball = new Ball(initialPosition,startVelocity, mass, radious);
	Enviroment* enviroment = new Enviroment(ball,airDensity,dragCoeff,g);

	Point startAcceleration = enviroment->calculateAcceleration(startTime, initialPosition, startVelocity);

	DifferentialSolver solver(enviroment, startTime, initialPosition, startVelocity, h, startAcceleration);

	double time;
	Point position;
	Point velocity;
	Point acceleration;
	Point* actualPosition;
	int pointsNumber=0;

	do
	{
		actualPosition = solver.Step(time, position, velocity, acceleration);
		ball->setNextTracePoint(actualPosition);
		if ((*actualPosition)[1]<0)
			break;
		if(file.good())
			file<<(*actualPosition)[0]<<" "<<(*actualPosition)[1]<<"\n";


	}while(time<simulationTime);

	Lacze.Rysuj();

	file.close();

	/*INTERPOLATION*/

	int scale = ball->getTrace().size()/3-1;

	double x[POINT_TO_INTERPOL];
	double y[POINT_TO_INTERPOL];

	for(int i=0;i<POINT_TO_INTERPOL;i++)
	{
		x[i]=(*ball->getTrace()[scale*i])[0];
		y[i]=(*ball->getTrace()[scale*i])[1];
	}

	Interpolation inter;

	Vector* result = inter.interpolate(x,y);

	cout<<"Interpolacja: ";
	cout<<(*result)[3]<<"x^3	"<<(*result)[2]<<"x^2	"<<(*result)[1]<<"x	"<<(*result)[0]<<"\n";

	  char  c;
	         cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
	         cin >> noskipws >> c;

	/*
	Matrix* m = new Matrix(3);
	(*m)[0][0]=1;
	(*m)[0][1]=-2;
	(*m)[0][2]=3;
	(*m)[1][0]=1;
	(*m)[1][1]=2;
	(*m)[1][2]=-3;
	(*m)[2][0]=1;
	(*m)[2][1]=-2;
	(*m)[2][2]=6;
	MatrixInversion inversion;
	Matrix* res = inversion.inverse(m);

	cout<<(*res)[0][0]<<" ";
	cout<<(*res)[0][1]<<" ";
	cout<<(*res)[0][2]<<"\n";
	cout<<(*res)[1][0]<<" ";
	cout<<(*res)[1][1]<<" ";
	cout<<(*res)[1][2]<<"\n";
	cout<<(*res)[2][0]<<" ";
	cout<<(*res)[2][1]<<" ";
	cout<<(*res)[2][2];
*/
	return 0;

}


