// useHW01_02.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include "HW01_02.h"

using namespace MyGeometry;

int main()
{
	unsigned int nPoint;
	Point* pointArray = LoadPoint("Point_HW1.txt", nPoint);
	Report("Report_HW01_02.txt", pointArray, nPoint);
	delete[] pointArray;
	system("PAUSE");
	return 0;
}