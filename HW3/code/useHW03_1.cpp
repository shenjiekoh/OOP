// useHW03_1.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "HW03_1.h"

using namespace std;

int main()
{
	// 使用default constructor建立三個立體物件
	IGeometry** arr = new IGeometry * [3];
	arr[0] = new Cuboid();
	arr[1] = new Pyramid();
	arr[2] = new Cylinder();

	cout << "arr[0] = new Cuboid()\n";
	cout << "Area of arr[0]: " << arr[0]->Area() << endl;
	cout << "Perimeter of arr[0]: " << arr[0]->Perimeter() << endl;
	cout << "Volume of arr[0]: " << arr[0]->Volume() << endl;
	cout << endl;
	cout << "arr[1] = new Pyramid()\n";
	cout << "Area of arr[1]: " << arr[1]->Area() << endl;
	cout << "Perimeter of arr[1]: " << arr[1]->Perimeter() << endl;
	cout << "Volume of arr[1]: " << arr[1]->Volume() << endl;
	cout << endl;
	cout << "arr[2] = new Cylinder()\n";
	cout << "Area of arr[2]: " << arr[2]->Area() << endl;
	cout << "Perimeter of arr[2]: " << arr[2]->Perimeter() << endl;
	cout << "Volume of arr[2]: " << arr[2]->Volume() << endl;
	cout << endl;

	srand(time(0));
	const double MIN = 0;
	const double MAX = 50;

	// 建立長方體cuboid
	Cuboid cuboid(rand() / double(RAND_MAX) * (MAX - MIN), rand() / double(RAND_MAX) * (MAX - MIN), 
				  rand() / double(RAND_MAX) * (MAX - MIN));
	cout << "Create cuboid using constructor:\n";
	cout << "Side length of cuboid: ";
	for (int i = 0; i < 3; i++)
		cout << cuboid.SideLength()[i] << "  ";
	cout << endl;
	cout << "Side area of cuboid: ";
	for (int i = 0; i < 3; i++)
		cout << cuboid.SideArea()[i] << "  ";
	cout << endl;
	cout << "Area of cuboid:  " <<cuboid.Area() << endl;
	cout << "Perimeter of cuboid: " << cuboid.Perimeter() << endl;
	cout << "Volume of cuboid: " << cuboid.Volume() << endl;

	cout << endl;

	// 建立三角錐pyramid
	Pyramid pyramid(rand() / double(RAND_MAX) * (MAX - MIN));
	cout << "Create pyramid using constructor:\n";
	cout << "Center of pyramid: " << pyramid.Center() << endl;
	cout << "Area of pyramid:  " << pyramid.Area() << endl;
	cout << "Perimeter of pyramid: " << pyramid.Perimeter() << endl;
	cout << "Volume of pyramid: " << pyramid.Volume() << endl;

	cout << endl;

	// 建立圓柱體cylinder
	Cylinder cylinder(rand() / double(RAND_MAX) * (MAX - MIN), rand() / double(RAND_MAX) * (MAX - MIN));
	cout << "Create cylinder using constructor:\n";
	cout << "Height of cylinder: " << cylinder.Height() << endl;
	cout << "Bottom area of cylinder: " << cylinder.BottomArea() << endl;
	cout << "Side area of cylinder: " << cylinder.SideArea() << endl;
	cout << "Area of cylinder:  " << cylinder.Area() << endl;
	cout << "Perimeter of cylinder: " << cylinder.Perimeter() << endl;
	cout << "Volume of cylinder: " << cylinder.Volume() << endl;

	cout << endl;

	// 利用cuboid建立新長方體cuboid2
	Cuboid cuboid2(cuboid);
	cout << "Copy cuboid to cuboid2:\n";
	cout << "Side length of cuboid2: ";
	for (int i = 0; i < 3; i++)
		cout << cuboid2.SideLength()[i] << "  ";
	cout << endl;
	cout << "Side area of cuboid2: ";
	for (int i = 0; i < 3; i++)
		cout << cuboid2.SideArea()[i] << "  ";
	cout << endl;
	cout << "Area of cuboid2:  " << cuboid2.Area() << endl;
	cout << "Perimeter of cuboid2: " << cuboid2.Perimeter() << endl;
	cout << "Volume of cuboid2: " << cuboid2.Volume() << endl;

	cout << endl;

	// 利用pyramid建立新三角錐pyramid2
	Pyramid pyramid2(pyramid);
	cout << "Copy pyramid to pyramid2:\n";
	cout << "Center of pyramid2: " << pyramid2.Center() << endl;
	cout << "Area of pyramid2:  " << pyramid2.Area() << endl;
	cout << "Perimeter of pyramid2: " << pyramid2.Perimeter() << endl;
	cout << "Volume of pyramid2: " << pyramid2.Volume() << endl;

	cout << endl;

	// 利用cylinder建立新圓柱體cylinder2
	Cylinder cylinder2(cylinder);
	cout << "Copy cylinder to cylinder2:\n";
	cout << "Height of cylinder2: " << cylinder2.Height() << endl;
	cout << "Bottom area of cylinder2: " << cylinder2.BottomArea() << endl;
	cout << "Side area of cylinder2: " << cylinder2.SideArea() << endl;
	cout << "Area of cylinder2:  " << cylinder2.Area() << endl;
	cout << "Perimeter of cylinder2: " << cylinder2.Perimeter() << endl;
	cout << "Volume of cylinder2: " << cylinder2.Volume() << endl;

	cout << endl;

	// 使用assignment operator更新cuboid2
	cuboid2 = Cuboid(rand() / double(RAND_MAX) * (MAX - MIN), rand() / double(RAND_MAX) * (MAX - MIN),
		rand() / double(RAND_MAX) * (MAX - MIN));
	cout << "Assign random cuboid to cuboid2:\n";
	cout << "Side length of cuboid2: ";
	for (int i = 0; i < 3; i++)
		cout << cuboid2.SideLength()[i] << "  ";
	cout << endl;
	cout << "Side area of cuboid2: ";
	for (int i = 0; i < 3; i++)
		cout << cuboid2.SideArea()[i] << "  ";
	cout << endl;
	cout << "Area of cuboid2:  " << cuboid2.Area() << endl;
	cout << "Perimeter of cuboid2: " << cuboid2.Perimeter() << endl;
	cout << "Volume of cuboid2: " << cuboid2.Volume() << endl;

	cout << endl;

	// 使用assignment operator更新pyramid2
	pyramid2 = Pyramid(rand() / double(RAND_MAX) * (MAX - MIN));
	cout << "Assign random pyramid to pyramid2:\n";
	cout << "Center of pyramid2: " << pyramid2.Center() << endl;
	cout << "Area of pyramid2:  " << pyramid2.Area() << endl;
	cout << "Perimeter of pyramid2: " << pyramid2.Perimeter() << endl;
	cout << "Volume of pyramid2: " << pyramid2.Volume() << endl;

	cout << endl;

	// 使用assignment operator更新cylinder2
	cylinder2 = Cylinder(rand() / double(RAND_MAX) * (MAX - MIN), rand() / double(RAND_MAX) * (MAX - MIN));
	cout << "Assign random cylinder to cylinder2:\n";
	cout << "Height of cylinder2: " << cylinder2.Height() << endl;
	cout << "Bottom area of cylinder2: " << cylinder2.BottomArea() << endl;
	cout << "Side area of cylinder2: " << cylinder2.SideArea() << endl;
	cout << "Area of cylinder2:  " << cylinder2.Area() << endl;
	cout << "Perimeter of cylinder2: " << cylinder2.Perimeter() << endl;
	cout << "Volume of cylinder2: " << cylinder2.Volume() << endl;

	for (int i = 0; i < 3; i++)
		delete arr[i];
	delete[] arr;
	system("pause");
	return 0;
}