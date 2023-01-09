// useHW02.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include "HW02.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	ifstream inFile;
	string digits = "0123456789";
	string filename = "HW2_SetA.txt";
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	int countA;
	string str;
	getline(inFile, str);
	if (inFile.good())
	{
		size_t index = str.find_first_of(digits);	// 從文件第一行找出數字所在index
		countA = stoi(str.substr(index));	// 轉為整數
	}
	else
	{
		cout << "Program aborted.\n";
		exit(EXIT_FAILURE);
	}
	Point* ptA = new Point[countA];
	for (int i = 0; i < countA; i++)
	{
		inFile >> ptA[i][0];
		inFile.get();
		inFile >> ptA[i][1];
		inFile.get();
	}
	inFile.close();

	filename = "HW2_SetB.txt";
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	int countB;
	getline(inFile, str);
	if (inFile.good())
	{
		size_t index = str.find_first_of(digits);
		countB = stoi(str.substr(index));
	}
	else
	{
		cout << "Program aborted.\n";
		exit(EXIT_FAILURE);
	}
	Point* ptB = new Point[countB];
	for (int i = 0; i < countB; i++)
	{
		inFile >> ptB[i][0];
		inFile.get();
		inFile >> ptB[i][1];
		inFile.get();
	}
	inFile.close();

	const int countC = 8;
	Point ptC[countC];
	int minval = 10;
	int maxval = 49;
	for (int i = 0; i < countC; i++)
	{
		ptC[i][0] = rand() % (maxval - minval + 1) + minval;
		ptC[i][1] = rand() % (maxval - minval + 1) + minval;
	}

	Set A = Set(ptA, countA);
	Set B = Set(ptB, countB);
	Set C = Set(ptC, countC);
	cout << "A:\n" << A << endl;
	cout << "B:\n" << B << endl;
	cout << "C:\n" << C << endl;
	cout << "A + B:\n" << A + B << endl;
	cout << "A + " << Point(9, 5) << ":\n" << A + Point(9, 5) << endl;
	cout << Point(16, 37) << " + B:\n" << Point(16, 37) + B << endl;
	cout << "A - B:\n" << A - B << endl;
	cout << "A - " << Point(1, 24) << ":\n" << A - Point(1, 24) << endl;
	cout << "B - A:\n" << B - A << endl;
	cout << "A += C, A:\n";
	A += C;
	cout << A << endl;
	cout << "Point: 可直接使用預設copy constructor、assignment operator、default destructor和address-of operator \n";
	cout << "Point類別的私有成員不是指標，做copy和assignment時可直接複製資料進行操作，物件在離開block時會直接從記憶體進行釋放，同時可直接取得物件地址\n";
	cout << "Set: 只可直接使用address-of operator\n";
	cout << "標頭檔內沒有宣告default constructor，所以不能使用預設的建構子，因Set類別內的私有成員含有指標，所以需要自行定義copy constructor、"
		"assignment operator和default destructor，避免因直接複製指標內容導致無意釋放資料的情形發生\n\n";
	cout << "#5輸出的結果可以assign給const int和int兩種資料，#6輸出的結果只能assign給int\n";
	cout << "使用#5時可保護物件本身內容不會改變，而使用#6時可以改變物件內容\n";
	system("PAUSE");
	return 0;
}