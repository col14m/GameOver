#pragma once

#include "Vector.h"

#include <stdio.h>
#include <math.h>

class Vector
{
public:
	Vector();
	Vector(double x, double y);

	double GetX();
	double GetY();
	double GetLength();

	double SetX(double x);
	double SetY(double y);

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