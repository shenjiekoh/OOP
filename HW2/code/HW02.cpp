// HW02.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include "HW02.h"

Point::Point() :x(0), y(0) {}

Point::Point(int X, int Y) : x(X), y(Y) {}

Point::~Point() {}

const int& Point::operator[](int i)const
{
	if (i == 0)
		return x;
	else if (i == 1)
		return y;
	else
	{
		std::cout << "Subscript should be 0 or 1 only.";
		exit(EXIT_FAILURE);
	}
}

int& Point::operator[](int i)
{
	if (i == 0)
		return x;
	else if (i == 1)
		return y;
	else
	{
		std::cout << "Subscript should be 0 or 1 only.";
		exit(EXIT_FAILURE);
	}
}

std::istream& operator>>(std::istream& is, Point& pt)
{
	is >> pt.x >> pt.y;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	os << "(" << pt.x << "," << pt.y << ")";
	return os;
}

Set::Set(const Point* pt, int num)
{
	count = num;
	set = new Point[count];
	for (int i = 0; i < count; i++)
		set[i] = pt[i];
}

Set::Set(const Set& s)
{
	count = s.count;
	set = new Point[count];
	for (int i = 0; i < count; i++)
		set[i] = s.set[i];
}

Set::~Set()
{
	delete[] set;
}

Set& Set::operator=(const Set& s)
{
	delete[] set;
	count = s.count;
	set = new Point[count];
	for (int i = 0; i < count; i++)
		set[i] = s.set[i];
	return *this;
}

bool Set::element(const Point& pt)
{
	int index = 0;
	while (index < count)
	{
		if (set[index][0] == pt[0] && set[index][1] == pt[1])
			return true;
		index++;
	}
	return false;
}

Set Set::operator+(const Point& pt)
{
	if (this->element(pt))	// 輸入元素已包含在集合內，直接回傳原集合
		return *this;
	Set Union(set, count + 1);
	Union.set[count] = pt;
	return Union;
}

Set Set::operator+(const Set& s)
{
	int repeat = 0;
	for (int i = 0; i < s.count; i++)	// 計算重複元素數量
		if (this->element(s.set[i]))
			repeat++;
	if (repeat == count)	// 元素完全重複，則回傳原集合
		return *this;

	Set union_set(set, count + s.count - repeat);
	for (int i = 0, j = count; i < s.count; i++)
	{
		if (this->element(s.set[i]))
			continue;
		union_set.set[j++] = s.set[i];
	}
	return union_set;
}

Set operator+(const Point& pt, Set& s)
{
	return s + pt;
}

Set Set::operator-(const Point& pt)
{
	if (!this->element(pt))	// 若輸入元素不在集合內，回傳原集合
		return *this;
	else
	{
		Point* diff = new Point[count - 1];
		for (int i = 0, j = 0; i < count, j < count - 1; i++)
		{
			if (set[i][0] == pt[0] && set[i][1] == pt[1])
				continue;
			diff[j++] = set[i];
		}
		return Set(diff, count - 1);
	}
}

Set Set::operator-(const Set& s)
{
	int repeat = 0;
	for (int i = 0; i < s.count; i++)	// 計算重複元素數量
		if (this->element(s.set[i]))
			repeat++;
	if (repeat == 0)	// 若兩集合沒有重複元素，回傳原集合
		return *this;
	Point* diff = new Point[count - repeat];
	for (int i = 0, j = 0; i < count, j < count - repeat; i++)
	{
		if (this->element(s.set[i]))
			continue;
		diff[j++] = set[i];
	}
	return Set(diff, count - repeat);
}

Set& Set::operator+=(const Set& s)
{
	if (this == &s)	// 輸入集合與原集合相等，回傳原集合
		return *this;
	*this = *this + s;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Set& s)
{
	os << "Point count: " << s.count << std::endl;
	for (int i = 0; i < s.count; i++)
		os << s.set[i] << std::endl;
	return os;
}