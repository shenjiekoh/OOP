// HW01_02.h
// Copyright 2021 許笙杰 E14075304 機械四乙

#pragma once
#ifndef HW01_02
#define HW01_02
#include <string>
using std::string;

namespace MyGeometry
{
	struct Point
	{
		float x;
		float y;
		double Length(const Point& point);
		string CoutPoint();
	};
	Point* LoadPoint(const char* filename, unsigned int& nPoint);
	Point MinDistance(Point* pointArray, unsigned int nPoint);
	void SortbyLength(Point* pointArray, unsigned int nPoint);
	void Report(const char* filename, Point* pointArray, unsigned int nPoint);
}
#endif