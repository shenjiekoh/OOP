// HW05_02.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef std::string KeyType;
typedef std::pair<const KeyType, int> Pair;
typedef std::map<KeyType, int> Map;

int main()
{
	using namespace std;
	Map jimmy;
	string jimmy_friends_name[] = { "Alan","Zoe","Jack","Gabriel","Evelyn","Karen" };
	int jimmy_friends_age[] = { 19,26,23,22,20,26 };
	for (int i = 0; i < sizeof(jimmy_friends_name) / sizeof(jimmy_friends_name[0]); i++)
		jimmy.insert(Pair(jimmy_friends_name[i], jimmy_friends_age[i]));

	Map jerry;
	string jerry_friends_name[] = { "Peter","Karen", "Louis","Catie","Mac","Amber","Megan" };
	int jerry_friends_age[] = { 25,26,18,21,30,22,24 };
	for (int i = 0; i < sizeof(jerry_friends_name) / sizeof(jerry_friends_name[0]); i++)
		jerry.insert(Pair(jerry_friends_name[i], jerry_friends_age[i]));

	Map combined(jimmy);
	combined.insert(jerry.begin(), jerry.end());
	Map::iterator it;
	cout << "Name\t\tAge\n";
	for (it = combined.begin(); it != combined.end(); ++it)
		cout << (*it).first << "\t\t" << (*it).second << endl;
	cout << endl;

	const int ageRange = 30 - 18 + 1;
	int age_count1[ageRange] = {};
	int age_count2[ageRange] = {};
	int age_count3[ageRange] = {};
	for (it = jimmy.begin(); it != jimmy.end(); ++it)
	{
		int index = (*it).second - 18;
		age_count1[index]++;
	}
	for (it = jerry.begin(); it != jerry.end(); ++it)
	{
		int index = (*it).second - 18;
		age_count2[index]++;
	}
	for (it = combined.begin(); it != combined.end(); ++it)
	{
		int index = (*it).second - 18;
		age_count3[index]++;
	}

	cout << "Jimmy's friends' age:\n";
	for (int i = 0; i < ageRange; i++)
		cout << 18 + i << " years old: " << age_count1[i] << endl;
	cout << endl;
	cout << "Jerry's friends' age:\n";
	for (int i = 0; i < ageRange; i++)
		cout << 18 + i << " years old: " << age_count2[i] << endl;
	cout << endl;
	cout << "Their friends' age:\n";
	for (int i = 0; i < ageRange; i++)
		cout << 18 + i << " years old: " << age_count3[i] << endl;
	return 0;
}
