// HW03_1.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include "HW03_1.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Point::Point() : x(0), y(0), z(0) {};

Point::Point(double X, double Y, double Z) : x(X), y(Y), z(Z) {};

Point::~Point() {};

const double& Point::operator[](int i)const
{
	if (i == 0)
		return x;
	else if (i == 1)
		return y;
	else if (i == 2)
		return z;
	else
	{
		std::cout << "Subscript should be 0, 1, 2 only.";
		exit(EXIT_FAILURE);
	}
}

double& Point::operator[](int i)
{
	if (i == 0)
		return x;
	else if (i == 1)
		return y;
	else if (i == 2)
		return z;
	else
	{
		std::cout << "Subscript should be 0, 1, 2 only.";
		exit(EXIT_FAILURE);
	}
}

std::istream& operator>>(std::istream& is, Point& pt)
{
	is >> pt.x >> pt.y >> pt.z;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	os << "(" << pt.x << "," << pt.y << "," << pt.z << ")";
	return os;
}

Cuboid::Cuboid()
{
	vertices = new Point[8];
}

Cuboid::Cuboid(double l, double w, double h)
{
	const double MIN = -100;
	const double MAX = 100;
	double x = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	double y = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	double z = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	vertices = new Point[8];
	vertices[0] = Point(x, y, z);
	vertices[1] = Point(x + l, y, z);
	vertices[2] = Point(x + l, y + w, z);
	vertices[3] = Point(x, y + w, z);
	vertices[4] = Point(x, y, z + h);
	vertices[5] = Point(x + l, y, z + h);
	vertices[6] = Point(x + l, y + w, z + h);
	vertices[7] = Point(x, y + w, z + h);
}

Cuboid::~Cuboid()
{
	delete[] vertices;
}

Cuboid::Cuboid(const Cuboid& c)
{
	vertices = new Point[8];
	for (int i = 0; i < 8; i++)
		vertices[i] = c.vertices[i];
}

Cuboid& Cuboid::operator=(const Cuboid& c)
{
	delete[] vertices;
	vertices = new Point[8];
	for (int i = 0; i < 8; i++)
		vertices[i] = c.vertices[i];
	return *this;
}

double Cuboid::Area()
{
	double* area = this->SideArea();
	return 2 * (area[0] + area[1] + area[2]);
}

double Cuboid::Perimeter()
{
	double* length = this->SideLength();
	return 4 * (length[0] + length[1] + length[2]);
}

double Cuboid::Volume()
{
	double* length = this->SideLength();
	return length[0] * length[1] * length[2];
}

double* Cuboid::SideLength()
{
	double length[3];
	length[0] = abs(vertices[0][0] - vertices[1][0]);
	length[1] = abs(vertices[0][1] - vertices[3][1]);
	length[2] = abs(vertices[0][2] - vertices[4][2]);
	return length;
}

double* Cuboid::SideArea()
{
	double* length = this->SideLength();
	double area[3];
	area[0] = length[0] * length[1];
	area[1] = length[0] * length[2];
	area[2] = length[1] * length[2];
	return area;
}

Pyramid::Pyramid()
{
	vertices = new Point[4];
}

Pyramid::Pyramid(double a)
{
	const double MIN = -100;
	const double MAX = 100;
	double x = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	double y = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	double z = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	vertices = new Point[4];
	vertices[0] = Point(x + a / 2, y, z - a / (2 * sqrt(2)));
	vertices[1] = Point(x - a / 2, y, z - a / (2 * sqrt(2)));
	vertices[2] = Point(x, y + a / 2, z + a / (2 * sqrt(2)));
	vertices[3] = Point(x, y - a / 2, z + a / (2 * sqrt(2)));
}

Pyramid::~Pyramid()
{
	delete[] vertices;
}

Pyramid::Pyramid(const Pyramid& p)
{
	vertices = new Point[4];
	for (int i = 0; i < 4; i++)
		vertices[i] = p.vertices[i];
}

Pyramid& Pyramid::operator=(const Pyramid& p)
{
	delete[] vertices;
	vertices = new Point[4];
	for (int i = 0; i < 4; i++)
		vertices[i] = p.vertices[i];
	return *this;
}

double Pyramid::Area()
{
	double x2 = pow(vertices[0][0] - vertices[1][0], 2);
	double y2 = pow(vertices[0][1] - vertices[1][1], 2);
	double z2 = pow(vertices[0][2] - vertices[1][2], 2);
	double a2 = x2 + y2 + z2;

	return sqrt(3) * a2;
}

double Pyramid::Perimeter()
{
	double x2 = pow(vertices[0][0] - vertices[1][0], 2);
	double y2 = pow(vertices[0][1] - vertices[1][1], 2);
	double z2 = pow(vertices[0][2] - vertices[1][2], 2);
	double a = sqrt(x2 + y2 + z2);

	return 6 * a;
}

double Pyramid::Volume()
{
	double x2 = pow(vertices[0][0] - vertices[1][0], 2);
	double y2 = pow(vertices[0][1] - vertices[1][1], 2);
	double z2 = pow(vertices[0][2] - vertices[1][2], 2);
	double a = sqrt(x2 + y2 + z2);

	return sqrt(2) * pow(a, 3) / 12;
}

Point Pyramid::Center()
{
	double sum_x = 0;
	double sum_y = 0;
	double sum_z = 0;
	for (int i = 0; i < 4; i++)
	{
		sum_x += vertices[i][0];
		sum_y += vertices[i][1];
		sum_z += vertices[i][2];
	}
	return Point(sum_x / 4, sum_y / 4, sum_z / 4);
}

Cylinder::Cylinder() : Top(Point()), Bottom(Point()), r(0) {};

Cylinder::Cylinder(double h, double R)
{
	const double MIN = -100;
	const double MAX = 100;
	double x = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	double y = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	double z = MIN + rand() / double(RAND_MAX) * (MAX - MIN);
	Bottom = Point(x, y, z);
	Top = Point(x, y, z + h);
	r = R;
}

Cylinder::~Cylinder() {};

Cylinder::Cylinder(const Cylinder& c)
{
	Top = c.Top;
	Bottom = c.Bottom;
	r = c.r;
}

Cylinder& Cylinder::operator=(const Cylinder& c)
{
	Top = c.Top;
	Bottom = c.Bottom;
	r = c.r;
	return *this;
}

double Cylinder::Area()
{
	return 2 * this->BottomArea() + this->SideArea();
}

double Cylinder::Perimeter()
{
	const double PI = atan(1.0) * 4.0;
	return 4 * PI * r;
}

double Cylinder::Volume()
{
	const double PI = atan(1.0) * 4.0;
	return PI * r * r * this->Height();
}

double Cylinder::Height()
{
	double x2 = pow(Top[0] - Bottom[0], 2);
	double y2 = pow(Top[1] - Bottom[1], 2);
	double z2 = pow(Top[2] - Bottom[2], 2);
	return sqrt(x2 + y2 + z2);
}

double Cylinder::BottomArea()
{
	const double PI = atan(1.0) * 4.0;
	return PI * r * r;
}

double Cylinder::SideArea()
{
	const double PI = atan(1.0) * 4.0;
	double h = this->Height();
	return 2 * PI * r * h;
}