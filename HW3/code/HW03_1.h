// HW03_1.h
// Copyright 2021 許笙杰 E14075304 機械四乙
#pragma once
#ifndef HW03_1
#define HW03_1

#include <iostream>

class Point
{
private:
	double x;
	double y;
	double z;

public:
	Point();
	Point(double, double, double);
	~Point();

	const double& operator[](int i)const;
	double& operator[](int i);
	friend std::istream& operator>>(std::istream&, Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

class IGeometry
{
public:
	virtual double Area() = 0;
	virtual double Perimeter() = 0;
	virtual double Volume() = 0;
};

class Cuboid :public IGeometry
{
private:
	Point* vertices;

public:
	Cuboid();
	Cuboid(double, double, double);
	virtual ~Cuboid();
	Cuboid(const Cuboid&);
	Cuboid& operator=(const Cuboid&);

	virtual double Area();
	virtual double Perimeter();
	virtual double Volume();

	double* SideLength();
	double* SideArea();
};

class Pyramid :public IGeometry
{
private:
	Point* vertices;

public:
	Pyramid();
	Pyramid(double);
	virtual ~Pyramid();
	Pyramid(const Pyramid&);
	Pyramid& operator=(const Pyramid&);

	virtual double Area();
	virtual double Perimeter();
	virtual double Volume();

	Point Center();
};

class Cylinder :public IGeometry
{
private:
	Point Top;
	Point Bottom;
	double r;

public:
	Cylinder();
	Cylinder(double, double);
	virtual ~Cylinder();
	Cylinder(const Cylinder&);
	Cylinder& operator=(const Cylinder&);

	virtual double Area();
	virtual double Perimeter();
	virtual double Volume();

	double Height();
	double BottomArea();
	double SideArea();
};

#endif