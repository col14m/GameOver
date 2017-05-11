#pragma once

#include <stdio.h>
#include <math.h>

class Vector
{
public:
	Vector(double x, double y);

	double GetX();
	double GetY();
	double GetLength();

	void Dump();
	void Dump(FILE *file);


	friend Vector operator +(const Vector &first, const Vector &second);
	friend Vector operator *(double number, const Vector &vector);
	friend Vector operator %(Vector &vector, long number);
private:
	double x_, y_;
};

Vector operator +(const Vector &first, const Vector &second);
Vector operator *(double number, const Vector &vector);


Vector::Vector(double x, double y) :
	x_(x),
	y_(y)
{};


double Vector::GetX()
{
	return x_;
}

double Vector::GetY()
{
	return y_;
}//

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
	vector.x_ = ((long) vector.x_) % number;
	//yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy;
	
	return vector;
}