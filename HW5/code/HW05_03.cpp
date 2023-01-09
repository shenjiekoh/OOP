// HW05_03.cpp
// Copyright 2021 許笙杰 E14075304 機械四乙

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    const int NUM = 10000000;
    vector<int> vi0(NUM);
    generate(vi0.begin(), vi0.end(), rand);
    vector<int> vi1(vi0);
    list<int> li1(vi0.begin(), vi0.end());

    // 方法a
    double etime1;
    clock_t stime1 = clock();
    sort(vi1.begin(), vi1.end());
    etime1 = (double(clock()) - double(stime1)) / CLOCKS_PER_SEC;
    cout << etime1;
    cout << endl;

    // 方法b
    double etime2;
    clock_t stime2 = clock();
    li1.sort();
    etime2 = (static_cast<double>(clock()) - static_cast<double>(stime2)) / CLOCKS_PER_SEC;
    cout << etime2;
    cout << endl;

    // 方法c
    li1.assign(vi0.begin(), vi0.end());
    double etime3;
    clock_t stime3 = clock();
    copy(li1.begin(), li1.end(), vi1.begin());
    sort(vi1.begin(), vi1.end());
    li1.assign(vi1.begin(), vi1.end());
    etime3 = (static_cast<double>(clock()) - static_cast<double>(stime3)) / CLOCKS_PER_SEC;
    cout << etime3;

    return 0;
}
