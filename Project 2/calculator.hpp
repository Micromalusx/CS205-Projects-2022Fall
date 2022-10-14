#pragma once
#include <string>
#include <string.h>

//函数声明1：判断是否是操作符
bool isOperator(char ch);

//函数声明2：获取优先级
int getPriority(char ch);

//函数声明3：后缀表达式计算
double calculate(const std::string str);

//函数声明4：判断是否为纯数字计算
bool allnumber(const std::string str);

//函数声明5：判断是否用到数学函数
bool mathfunction(const std::string str);

//函数声明6：判断是否是字母
bool isLetter(char ch);

//函数声明7：判断是否是变量运算
bool isVariable(const std::string str);