#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<stack>
#include<vector>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<iostream>

using namespace std;

class Calculator
{
public:
    Calculator();
    static char** create(int count, char* coll1, char* coll2, int maxNum, int len, int flag1);

    static int handle(char* eq);

    static int cal(char c, int flag = 0, int x = 0, int y = 0);

    static int random(int max);
};

#endif // CALCULATOR_H
