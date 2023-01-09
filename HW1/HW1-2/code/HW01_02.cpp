// HW01_02.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include "HW01_02.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

namespace MyGeometry
{
	double Point::Length(const Point& point)
	{
		return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
	}
	string Point::CoutPoint()
	{
		return "(" + to_string(x) + "," + to_string(y) + ")";
	}
	Point* LoadPoint(const char* filename, unsigned int& nPoint)
	{
		ifstream inFile;
		inFile.open(filename);
		if (!inFile.is_open())
		{
			cout << "Could not open the file " << filename << endl;
			cout << "Program terminating.\n";
			exit(EXIT_FAILURE);
		}
		nPoint = 0;
		float x, y;
		inFile >> x >> y;
		while (inFile.good())	// 計算點數量
		{
			nPoint++;
			inFile >> x >> y;
		}
		inFile.close();
		if (nPoint)	// 若點數量不為0，讀入文件中的資料，否則退出程式
		{
			Point* pointArray = new Point[nPoint];
			inFile.open(filename);
			inFile >> x >> y;
			int index = 0;
			while (inFile.good())
			{
				pointArray[index].x = x;
				pointArray[index++].y = y;
				inFile >> x >> y;
			}
			return pointArray;
		}	
		else
		{
			cout << "No point data in the file." << endl;
			exit(EXIT_FAILURE);
		}	
	}
	Point MinDistance(Point* pointArray, unsigned int nPoint)
	{
		Point minPoint = pointArray[0];
		double minDistance = abs(pointArray[0].x + pointArray[0].y - 1) / sqrt(2);	// P(x,y)與l:ax+by+c=0的距離為abs(a*x+b*y+c)/sqrt(a^2+b^2)
		for (int i = 1; i < nPoint; i++)
		{
			double currentDistance = abs(pointArray[i].x + pointArray[i].y - 1) / sqrt(2);
			if (currentDistance < minDistance)
			{
				minPoint = pointArray[i];
				minDistance = currentDistance;
			}
		}
		return minPoint;
	}
	void SortbyLength(Point* pointArray, unsigned int nPoint)
	{
		// 計算中心點
		Point centroid;
		double sum_x = 0;
		double sum_y = 0;
		for (int i = 0; i < nPoint; i++)
		{
			sum_x += pointArray[i].x;
			sum_y += pointArray[i].y;
		}
		centroid.x = sum_x / nPoint;
		centroid.y = sum_y / nPoint;
		// 進行排序
		for (int i = 0; i < nPoint - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < nPoint; j++)
				if (pointArray[j].Length(centroid) < pointArray[min].Length(centroid))
					min = j;
			if (min != i)
			{
				Point temp = pointArray[min];
				pointArray[min] = pointArray[i];
				pointArray[i] = temp;
			}
		}
	}
	void Report(const char* filename, Point* pointArray, unsigned int nPoint)
	{
		ofstream outFile;
		Point centroid;
		outFile.open(filename);
		outFile << "物件導向程式設計第一次作業" << endl;
		outFile << "E14075304 許笙杰" << endl;
		outFile << "點數目: " << nPoint << endl;
		outFile << "最接近x+y=1的點: " << MinDistance(pointArray, nPoint).CoutPoint() << endl;
		double sum_x = 0;
		double sum_y = 0;
		for (int i = 0; i < nPoint; i++)
		{
			sum_x += pointArray[i].x;
			sum_y += pointArray[i].y;
		}
		centroid.x = sum_x / nPoint;
		centroid.y = sum_y / nPoint;
		outFile << "平均點為: " << centroid.CoutPoint() << endl;
		SortbyLength(pointArray, nPoint);
		outFile << "與平均點最近的點: " << pointArray[0].CoutPoint() << "、距離為: " << pointArray[0].Length(centroid) << endl;
		outFile << "\\\\\\\\\\\\\\\\\\\//////////" << endl;
		outFile << "編號2函數以const Point reference作為引數，以double型式回傳\n";
		outFile << "使用reference輸入可直接使用點資料，優點為不會在記憶體額外產生新空間，計算兩點距離後以double回傳結果\n";
		outFile << "編號3函數不使用引數進行函式呼叫，將結果以string資料型態回傳\n";
		outFile << "直接使用Point結構的x和y轉換成字串後進行輸出，使用上較為快速\n";
		outFile << "編號4函數分別使用const string pointer輸入檔名和unsigned int reference輸入點數量變數，回傳資料型態為Point pointer\n";
		outFile << "const string pointer可讓使用者直接輸入字串作為檔名，由於點數量需要隨著迴圈進行改變內部資料值，因此設計reference使其可以直接對變數進行修改\n";
		outFile << "輸出方面則將從文字檔讀入的Point陣列以指標的形式進行回傳\n";
		outFile << "編號5函數以Point pointer型式輸入點陣列，並把點陣列大小以unsigned int的型式進行輸入，最後使用Point對距離最近的點進行回傳\n";
		outFile << "使用動態陣列時無法透過sizeof從指標得到陣列大小，因此需使用額外的引數nPoint將陣列大小輸入給函式，使用較為不便\n";
		outFile << "編號6函數使用Point pointer型式輸入點陣列，並把點陣列大小以unsigned int的型式進行輸入，不進行回傳\n";
		outFile << "進行排序時需直接移動各點在陣列中的相對位置，因此以pointer進行輸入，排序後直接跳出函式\n";
		outFile << "編號7函數使用const char pointer進行檔名輸入，並且利用Point pointer和unsigned int的型式輸入點陣列及其大小進行後續計算\n";
		outFile << "const string pointer可讓使用者直接輸入字串作為輸出文字檔名，如同上面函數使用pointer輸入陣列以及使用unsigned int作為陣列大小的輸入\n";
	}
}
