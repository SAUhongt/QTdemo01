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

    //自动生成算式
    /*
    count: 算式生成数量
    coll1：低优先级运算符
    cool2: 高优先级运算符
    maxNum: 生成的最大数
    len: 算式长度
    flag1: 是否带括号

    */
    static char** create(int count, char* coll1, char* coll2, int maxNum, int len, int flag1);

    //计算算式，并返回答案
    static int handle(char* eq);

    //返回运算符优先级或者计算结果
    static int cal(char c, int flag = 0, int x = 0, int y = 0);
    //生成最大数为max且不为零
    static int random(int max, int min = 1);

    //去除某个字符
    static void delete_char(char str[], int target);
};

#endif // CALCULATOR_H
