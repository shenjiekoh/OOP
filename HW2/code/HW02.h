// HW02.h
// Copyright 2021 許笙杰 E14075304 機械四乙
#pragma once
#ifndef HW02_H
#define HW02_h

#include <iostream>

class Set;

class Point
{
private: //#1
	int x;
	int y;

public:
	Point();//#2
	Point(int, int);//#3 
	~Point();//#4

	const int& operator[](int i)const;//#5
	int& operator[](int i);//#6
	friend std::istream& operator>>(std::istream&, Point&);//#7 
	friend std::ostream& operator<<(std::ostream&, const Point&);//#8
};
class Set
{
private: //#9
	Point* set;
	int count;

public:
	Set(const Point*, int);//#10
	Set(const Set&);//#11
	~Set();//#12
	Set& operator=(const Set&);//#13
	bool element(const Point&);//#14
	Set operator+(const Point&);//#15 Set+Point
	Set operator+(const Set&);//#15 Set+Set
	friend Set operator+(const Point&, Set&);//#15 Point+Set
	Set operator-(const Point&);//#16 Set-Point
	Set operator-(const Set&);//#16 Set-Set
	Set& operator+=(const Set&);//#17
	friend std::ostream& operator<<(std::ostream&, const Set&);//#18
};

#endif