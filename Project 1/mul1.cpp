#include <iostream>
#include <string>
#include <iomanip>
//#include <typeinfo>
using namespace std;

int main(int argc, char **argv)
{   
    //input
    string str_a = argv[1];
    string str_b = argv[2];

    //(大)整数乘法
    long a_long;
    long b_long;
    long result_long;//output
    int il = 0;
    int jl = 0;

    for (int i = 0; i < str_a.length(); i++)
    {         
        if (str_a[i]>=48 && str_a[i]<=57)
        {   
            il = il + 1;
            continue;                      
        }
        else break;    
    }
    for (int j = 0; j < str_b.length(); j++)
    {
        if (str_b[j]>=48 && str_b[j]<=57)
        {   
            jl = jl + 1;
            continue;
        }
        else break;    
    }
    if (il==str_a.length() && jl==str_b.length())
    {
        a_long = stol(str_a);
        b_long = stol(str_b);
        result_long = a_long * b_long;

        cout << a_long << " * " << b_long << " = " << result_long << endl;
    }

    //浮点数乘法(浮点数*浮点数 and 整数*浮点数)
    double a_double;
    double b_double;
    double result_double;//output
    int id = 0;
    int jd = 0;
    if (str_a.find('.')!=string::npos || str_b.find('.')!=string::npos)
    {   
        //如果检测到是整数，则转换为浮点数格式，最后直接进行浮点数乘法
        if (str_a.find('.') == string::npos)
        {   int ii = 0;
            for (int i = 0; i < str_a.length(); i++)
            {
                if ((str_a[i]>=48 && str_a[i]<=57) | (str_a[i]=='.'))
                {
                    ii = ii + 1;
                    continue;
                }
                else break;                
            }
            if(ii==str_a.length())
            {
                str_a = str_a + '.';
            }            
        }

        if (str_b.find('.') == string::npos)
        {   int jj = 0;
            for (int i = 0; i < str_b.length(); i++)
            {
                if ((str_b[i]>=48 && str_b[i]<=57) | (str_b[i]=='.'))
                {
                    jj = jj + 1;
                    continue;
                }
                else break;                
            }
            if(jj==str_b.length())
            {
                str_b = str_b + '.';
            }            
        }
        
        int a_firstpoint = str_a.find_first_of('.');
        int a_lastpoint  = str_a.find_last_of('.');
        int b_firstpoint = str_b.find_first_of('.');
        int b_lastpoint  = str_b.find_last_of('.');

        if ((a_firstpoint==a_lastpoint) && (b_firstpoint==b_lastpoint)) //如果有两个小数点就报错
        {
            for (int i = 0; i < str_a.length(); i++)
            {
                if ((str_a[i]>=48 && str_a[i]<=57) || (str_a[i]=='.'))
                {
                    id = id + 1;
                    continue;
                }
                else break;
            }
            for (int j = 0; j < str_b.length(); j++)
            {
                if ((str_b[j]>=48 && str_b[j]<=57) || (str_b[j]=='.'))
                {
                    jd = jd + 1;
                    continue;
                }
                else break;
            }
            if (id==str_a.length() && jd==str_b.length())
            {
                a_double = stod(str_a);
                b_double = stod(str_b);
                result_double = a_double * b_double;                

                int pa = str_a.length() - a_firstpoint - 1;
                int pb = str_b.length() - b_firstpoint - 1;
                int pr;
                if ((pa+pb)<=15)
                {
                    pr = pa + pb;
                }
                else pr = 15;                

                cout.setf(ios_base::fixed, ios_base::floatfield);
                cout << setprecision(pa) <<a_double << " * ";
                cout << setprecision(pb) << b_double << " = ";
                cout << setprecision(pr) << result_double << endl;
                //小数位太多会不精确，尝试多次发现小数位为15位时仍保持精准，15位以上开始丢失精度，所以精度设置为最大15
            }                
        }
        else
        {
            cout << "The input cannot be inerpret as numbers!" << endl;
        }     
    }
    return  0;
}