#ifndef Matrix_HH_
#define Matrix_HH_

#include"../inc/Size.hh"
#include"Vector.hh"

class Matrix {
	private:
		int _size;
		Vector** _columns;
	public:
		Matrix(int size);
		~Matrix();
		void Transpose();;
		Vector* operator*(const Vector w) const;
		Vector operator[](const unsigned int column) const;
		Vector &operator[](const unsigned int column);
		Matrix &operator=(const Matrix m);
	    friend std::istream& operator >> (std::istream &In, Matrix &m);
	    friend std::ostream& operator << (std::ostream &Out, Matrix &m);
		int size();
};


std::istream& operator >> (std::istream &In, Matrix &m);
std::ostream& operator << (std::ostream &Out, Matrix &m);


#endif /* Matrix_HH_ */
