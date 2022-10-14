#include "calculator.hpp"
#include <iostream>
#include <string.h>
#include <stack>
#include <math.h>
using namespace std;

//函数定义1：判断是否是操作符
bool isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    else
        return false;
}

//函数定义2：获取优先级
int getPriority(char ch)
{
    int level = 0;
    switch (ch)
    {
    case '(':
        level = 1;
        break;
    case '+':
        level = 2;
        break;
    case '-':
        level = 2;
        break;
    case '*':
        level = 3;
        break;
    case '/':
        level = 3;
        break;
    default:
        level = 0;
        break;
    }
    return level;
}

//函数定义3：后缀表达式的计算
double calculate(const std::string str)
{
    stack<double> s_cal;
    string space = " ";
    string s = "0123456789+-*/";

    int start = 0;
    int end = 0;
    double num = 0;
    double num1 = 0;
    double num2 = 0;

    for (int i = 0; i < str.length(); )
    {
        start = str.find_first_of(s, i);
        end = str.find_first_of(space, i);

        if (end == string::npos) //处理最后一个符号没有空格的情况
        {
            end = str.length();
        }

        string tempstr = str.substr(start, (end-start));
        if ((tempstr=="+") || (tempstr=="-") || (tempstr=="*") || (tempstr=="/"))
        {
            num1 = s_cal.top();
            s_cal.pop();
            num2 = s_cal.top();
            s_cal.pop();

            if (tempstr == "+")
            {
                num = num1 + num2;
                s_cal.push(num);
            }
            else if (tempstr == "-")
            {
                num = num2 - num1;
                s_cal.push(num);
            }
            else if (tempstr == "*")
            {
                num = num1 * num2;
                s_cal.push(num);
            }
            else
            {
                num = num2 / num1;
                s_cal.push(num);
            }   
        }
        else
        {
            double tempnum = stod(tempstr);
            s_cal.push(tempnum);
        }     
        i = end + 1;
    }

    return s_cal.top();
}

//函数定义4：判断是否为纯数字计算
bool allnumber(const std::string str)
{
    int a = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if ((ch>=48 && ch<=57) || isOperator(ch) || ch=='.' || ch=='(' || ch==')')
            a = a + 1;
        else break;
    }
    if (a==str.length())
        return true;
    else
        return false;      
}

//函数定义5：判断是否用到数学函数
bool mathfunction(const std::string str)
{
    string s1 = "abs";  //绝对值
    string s2 = "floor";//向下取整
    string s3 = "ceil"; //向上取整
    string s4 = "sqrt"; //平方根
    string s5 = "log";  //自然对数，e为底
    string s6 = "exp";  //e的多少次方
    string s7 = "sin";  //sin
    string s8 = "cos";  //cos
    string s9 = "tan";  //tan
    
    if (str.find(s1)==string::npos && str.find(s2)==string::npos && str.find(s3)==string::npos
    && str.find(s4)==string::npos && str.find(s5)==string::npos && str.find(s6)==string::npos
    && str.find(s7)==string::npos && str.find(s8)==string::npos && str.find(s9)==string::npos)
    {
        return false;
    }
    else
        return true;
}

//函数定义6：判断是否是字母
bool isLetter(char ch)
{
    if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
    {
        return true;
    }
    else
        return false;
}

//函数定义7：判断是否是变量运算
bool isVariable(const std::string str)
{
    if (str.find_first_of('=')!=string::npos)
    {
        int equal = str.find_first_of('=');
        if (equal==1)
        {
            char v = str[0];
            if (isLetter(v))
            {
                return true;
            }
            else
                return false;    
        }
        else
            return false;  
    }
    else
        return false; 
}