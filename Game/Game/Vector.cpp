#include <assert.h>
#include "Vector\Vector.h"

Vector::Vector(double x, double y) :
	x_(x),
	y_(y)
{};

Vector::Vector() :
	x_(0),
	y_(0)
{};


double Vector::GetX()
{
	return x_;
}

double Vector::GetY()
{
	return y_;
}

double Vector::GetLength()
{
	return sqrt(x_*x_ + y_*y_);
}


void Vector::Dump()
{
	printf("Vector {%3.3lf, %3.3lf};\n", x_, y_);
}

void Vector::Dump(FILE *file)
{
	assert(file);

	fprintf(file, "Vector {%3.3lf; %3.3lf};\n", x_, y_);
}


Vector operator +(const Vector &first, const Vector &second)
{
	return Vector(first.x_ + second.x_, first.y_ + second.y_);
}

Vector operator *(double number, const Vector &vector)
{
	return Vector(number * vector.x_, number * vector.y_);
}

Vector operator %(Vector &vector, long number)
{
	vector.x_ = ((long)vector.x_) % number;
	//yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy;
	//Vector tmp = 
	return vector;
}

double Vector::SetY(double y)
{
	y_ = y;
	return y;
}

double Vector::SetX(double x)
{
	x_ = x;
	return x;
}