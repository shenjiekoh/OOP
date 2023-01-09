// HW01_01.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
T FindMin(T* pArray, const int arraySize)
{
	T min = pArray[0];
	for (int i = 1; i < arraySize; i++)
		if (pArray[i] < min)
			min = pArray[i];
	return min;
}

template <>
const char* FindMin<const char*>(const char* pArray[], const int arraySize)
{
	const char* min = pArray[0];
	for (int i = 1; i < arraySize; i++)
		if (strlen(pArray[i]) < strlen(min))
			min = pArray[i];
	return min;
}

int main()
{
	const int shortSize = 6;
	const int doubleSize = 8;
	const int pcharSize = 10;
	short* pshort = new short[shortSize];
	double* pdouble = new double[doubleSize];

	srand(time(NULL));
	cout << "short array:\n";
	for (int i = 0; i < shortSize; i++)
	{
		pshort[i] = rand() % 10001;
		cout << pshort[i] << " ";
	}
	cout << "\ndouble array:\n";
	for (int i = 0; i < doubleSize; i++)
	{
		pdouble[i] = 1000. * rand() / (RAND_MAX + 1);
		cout << pdouble[i] << " ";
	}
	const char* ppchar[pcharSize] = { "@98w8jpn", "tV*d$Y6@Im7FahTA", "Dciob4", "k%4BIjgzO0&m", "6QtU", "*EKtPBFv8h#",
							"nKJHDq7R7EQ^fWny", "GLXT&6bKVgVU", "j1j&", "T7*kLNg7" };
	cout << "\nchar pointer array:\n";
	for (int i = 0; i < pcharSize; i++)
	{
		cout << ppchar[i] << endl;
	}

	cout << endl;
	short shortMin = FindMin(pshort, shortSize);
	double doubleMin = FindMin(pdouble, doubleSize);
	const char* pcharMin = FindMin(ppchar, pcharSize);
	cout << "Min of short array: " << shortMin << endl;
	cout << "Min of double array: " << doubleMin << endl;
	cout << "Shortest string: " << pcharMin << endl;
	cout << "Min address of char pointer array: " << (int*)pcharMin << endl;

	delete[] pshort;
	delete[] pdouble;
	system("PAUSE");
	return 0;
}