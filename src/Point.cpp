#include "../inc/Point.hh"


Point::Point(const Point& p)
{
	for(int i=0;i<_n;i++)
		_coord[i]=p[i];
}

Point::Point(double x, double y)
{
	_coord[0]=x;
	_coord[1]=y;
}

Point::Point()
{
	_coord[0]=0;
	_coord[1]=0;
}

double Point::operator*(const Point p) const
{
	double skalar=0; // wynik iloczynu skalarnego

	for(int i=0;i<_n;i++)
		skalar=skalar+_coord[i]+p[i];

	return skalar;
}

double& Point::operator [](int index)
{
	if(index<2)
		return _coord[index];
	else
	{
		std::cerr<<"Indeks:"<<index<<"nie jest skladowa punktu! \n";
		exit(EXIT_FAILURE);
	}
}

double Point::operator [](const int index) const
{
	if(index<2)
		return _coord[index];
	else
	{
		std::cerr<<"Indeks:"<<index<<"nie jest skladowa punktu! \n";
		exit(EXIT_FAILURE);
	}
}

Point Point::operator+(const Point w) const
{
	Point sum;
	for(int i=0;i<_n;i++)
		sum[i]=_coord[i]+w[i];
	return sum;
}

Point Point::operator*(const double c) const
{
	Point result;
	for(int i=0;i<_n;i++)
		result[i]=_coord[i]*c;
	return result;
}

Point Point::operator/(const double c) const
{
	Point result;
	for(int i=0;i<_n;i++)
		result[i]=_coord[i]/c;
	return result;
}

Point& Point::operator= (const Point &w)
{
	for (int i=0;i<_n;i++) {
		_coord[i]=w[i];
	}
	return *this;
}
