#include "calculator.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100005;

string ap_add(const std::string a, const std::string b)
{
	string str_a = a;
    string str_b = b;
    string str_a0 = a;
    string str_b0 = b;
    string frac_a;
    string frac_b;
    int pointa = 0;
    int pointb = 0;
    int fraclen = 0;

    if ((str_a0.find('.')!=string::npos) || (str_b0.find('.')!=string::npos))
    {
        if (str_a.find('.')!=string::npos)
        {
            pointa = str_a.find_first_of('.');
            frac_a = str_a.substr( pointa+1, str_a.length()-pointa-1 );
        }
        else
        {
            str_a = str_a + ".0";
            pointa = str_a.find_first_of('.');
            frac_a = str_a.substr( pointa+1, str_a.length()-pointa-1 );
        }

        if (str_b.find('.')!=string::npos)
        {
            pointb = str_b.find_first_of('.');
            frac_b = str_b.substr( pointb+1, str_b.length()-pointb-1 );
        }
        else
        {
            str_b = str_b + ".0";
            pointb = str_b.find_first_of('.');
            frac_b = str_b.substr( pointb+1, str_b.length()-pointb-1 );
        }

        if (str_a.find('.')!=string::npos && str_b.find('.')!=string::npos)
        {
            if (frac_a.length() > frac_b.length())
            {
                fraclen = frac_a.length();
                for (int i = 1; i <= (frac_a.length()-frac_b.length()); i++)
                {
                    str_b = str_b + '0';
                }
                pointb = str_b.find_first_of('.');
                frac_b = str_b.substr( pointb+1, str_b.length()-pointb-1 );
            }
            else if (frac_b.length() > frac_a.length())
            {
                fraclen = frac_b.length();
                for (int i = 1; i <= (frac_b.length()-frac_a.length()); i++)
                {
                    str_a = str_a + '0';
                }
                pointa = str_a.find_first_of('.');
                frac_a = str_a.substr( pointa+1, str_a.length()-pointa-1 );
            }
            else fraclen = frac_a.length();

            str_a = str_a.erase(str_a.find('.'),1);
            str_b = str_b.erase(str_b.find('.'),1);
        }
    }
    
    int res[maxn] = {0};
    int lena = str_a.length();
	int lenb = str_b.length();
    reverse(str_a.begin(), str_a.end()); //翻转数组
    reverse(str_b.begin(), str_b.end());
	int len = max(lena, lenb);
	for(int i=0; i<len; i++)
	{
        if ( i < lena)
        {
           res[i] = res[i] + (str_a[i] - '0');
        }
        if (i < lenb)
        {
            res[i] = res[i] + (str_b[i] - '0');
        }

		if(res[i] >= 10)
		{
			res[i+1] = res[i+1] + res[i]/10;
			res[i] = res[i] % 10;
		}
	}

	string result = {};

    if(res[len] > 0)
    {
        result = result + to_string(res[len]);
    }
	for(int i=len-1; i>=0; i--)
    {
        result = result + to_string(res[i]);
    }

    if ((str_a0.find('.')!=string::npos) || (str_b0.find('.')!=string::npos))
    {
        string result1 = result.substr(0, result.length()-fraclen);
        string result2 = result.substr(result.length()-fraclen, fraclen);
        result = result1 + "." + result2;
    }

    return result;
}

string ap_sub(const std::string a, const std::string b)
{
	string str_a = a;
    string str_b = b;
    string str_a0 = a;
    string str_b0 = b;
    string frac_a;
    string frac_b;
    string int_a;
    string int_b;
    int pointa = 0;
    int pointb = 0;
    int fraclen = 0;
    string result = {};

    if ((str_a0.find('.')!=string::npos) || (str_b0.find('.')!=string::npos))//a-b
    {
        if (str_a.find('.')!=string::npos)
        {
            pointa = str_a.find_first_of('.');
            frac_a = str_a.substr( pointa+1, str_a.length()-pointa-1 );
        }
        else
        {
            str_a = str_a + ".0";
            pointa = str_a.find_first_of('.');
            frac_a = str_a.substr( pointa+1, str_a.length()-pointa-1 );
        }

        if (str_b.find('.')!=string::npos)
        {
            pointb = str_b.find_first_of('.');
            frac_b = str_b.substr( pointb+1, str_b.length()-pointb-1 );
        }
        else
        {
            str_b = str_b + ".0";
            pointb = str_b.find_first_of('.');
            frac_b = str_b.substr( pointb+1, str_b.length()-pointb-1 );
        }

        if (str_a.find('.')!=string::npos && str_b.find('.')!=string::npos)
        {
            if (frac_a.length() > frac_b.length())
            {
                fraclen = frac_a.length();
                for (int i = 1; i <= (frac_a.length()-frac_b.length()); i++)
                {
                    str_b = str_b + '0';
                }
                pointb = str_b.find_first_of('.');
                frac_b = str_b.substr( pointb+1, str_b.length()-pointb-1 );
            }
            else if (frac_b.length() > frac_a.length())
            {
                fraclen = frac_b.length();
                for (int i = 1; i <= (frac_b.length()-frac_a.length()); i++)
                {
                    str_a = str_a + '0';
                }
                pointa = str_a.find_first_of('.');
                frac_a = str_a.substr( pointa+1, str_a.length()-pointa-1 );
            }
            else fraclen = frac_a.length();

            int_a = str_a.substr(0, pointa);
            int_b = str_b.substr(0, pointb);

            if(int_a.length() < int_b.length())
            {
                result = result + "-";
                swap(str_a, str_b);
            }
            
            if(int_a.length() == int_b.length())
            {             
                if (int_a==int_b)
                {
                    for(int i = 0; i < fraclen; i++)
                    {
                        if(frac_b[i] < frac_a[i]) break;
                        else if(frac_b[i] == frac_a[i]) continue;
                        else if(frac_b[i] > frac_a[i])
                        {
                            result = result + "-";
                            swap(str_a, str_b);
                            break;
                        }
                    }
                }
                else
                {
                    for(int i = 0; i<int_a.length(); i++)
                    {
                        if(int_b[i] < int_a[i]) break;
                        else if(int_b[i] == int_a[i]) continue;
                        else if(int_b[i] > int_a[i])
                        {
                            result = result + "-";
                            swap(str_a, str_b);
                            break;
                        }
                    }
                }
            }

            str_a = str_a.erase(str_a.find('.'),1);
            str_b = str_b.erase(str_b.find('.'),1);
        }
    }
    
    int res[maxn] = {0};
    int lena = str_a.length();
	int lenb = str_b.length();
    reverse(str_a.begin(), str_a.end()); //翻转数组
    reverse(str_b.begin(), str_b.end());
	int len = max(lena, lenb);

    if((str_a0.find('.')==string::npos) && (str_b0.find('.')==string::npos))
    {
        if(lena < lenb)
        {
            result = result + "-";
            swap(str_a, str_b);
        }
        
        if(lena == lenb)
        {
            for(int i = lena-1; i>=0; i--)
            {
                if(str_b[i] < str_a[i]) break;
                else if(str_b[i] == str_a[i]) continue;
                else if(str_b[i] > str_a[i])
                {
                    result = result + "-";
                    swap(str_a, str_b);
                    break;
                }
            }
        }
    }

	for (int i = 0; i < len; i++)
    {
        if (str_a[i]>='0' && str_a[i]<='9')
        {
            res[i] = res[i] + (str_a[i] - '0');
        }
        
        if(str_b[i]>='0' && str_b[i]<='9')
        {
            res[i] = res[i] - (str_b[i] - '0');
        }
        
        if(res[i] < 0)
        {
            res[i+1] = res[i+1] - 1;
            res[i] = res[i] + 10;
        }
    }


    if ((str_a0.find('.')!=string::npos) || (str_b0.find('.')!=string::npos))
    {
        for (int i = len-1; i >= 0; i--)
        {
            result = result + to_string(res[i]);
        }
        string result1 = result.substr(0, result.length()-fraclen);
        string result2 = result.substr(result.length()-fraclen, fraclen);
        result = result1 + "." + result2;
        int p = result.find_first_of('.');
        int zero = 0;

        if (result[0]!='-')
        {
            for (int i = 0; i < p; i++)
            {
                if (result[i]=='0' && result[i+1]!='.')
                {
                    zero = zero + 1;
                    continue;
                }
                else break;     
            }
        }
        else
        {
            for (int i = 1; i < p; i++)
            {
                if (result[i]=='0' && result[i+1]!='.')
                {
                    zero = zero + 1;
                    continue;
                }
                else break;     
            }
        }

        if (zero>0)
        {
            if (result[0]=='-')
                result = result.erase(1,zero);
            else
                result = result.erase(0,zero);
        }
    }

    if ((str_a0.find('.')==string::npos) && (str_b0.find('.')==string::npos))
    {
        while(res[len-1]==0 && len>1)
        {
            len = len - 1; 
        }
        if (len==1)
        {
            result = result + to_string(res[0]);  
            return result;
        }
        for (int i = len-1; i >= 0; i--)
        {
            result = result + to_string(res[i]);
        }
    }
    return result;   
}

string ap_mul(const std::string a, const std::string b)
{
    string str_a = a;
    string str_b = b;

    if (a[0]=='-')
    {
        str_a.erase(0, 1);
    }
    if (b[0]=='-')
    {
        str_b.erase(0, 1);
    }
    
    if(str_a.length()<str_b.length()) 
        return ap_mul(b, a);

    int fraclen = 0;
    if (a.find('.')!=string::npos || b.find('.')!=string::npos)
    {
        if (a.find('.')==string::npos)
        {
            str_a = str_a + ".0";
        }
        
        if (b.find('.')==string::npos)
        {
            str_b = str_b + ".0";
        }
        
        if (str_a.find('.')!=string::npos || str_b.find('.')!=string::npos)
        {
            int pointa = str_a.find_first_of('.');
            int pointb = str_b.find_first_of('.');
            string frac_a = str_a.substr(pointa+1, str_a.length()-pointa-1);
            string frac_b = str_b.substr(pointb+1, str_b.length()-pointb-1);

            fraclen = frac_a.length() + frac_b.length();

            str_a = str_a.erase(pointa, 1);
            str_b = str_b.erase(pointb, 1);
        }
    }
        
    reverse(str_a.begin(), str_a.end());
    reverse(str_b.begin(), str_b.end());
    int lena = str_a.length();
    int lenb = str_b.length();
    vector<int> re(lena+lenb, 0);
    string result;

    for(int i=0; i<lena; i++)
    {
        for(int j=0; j<lenb; j++)
        {
            re[i+j] = re[i+j] + (str_a[i]-'0')*(str_b[j]-'0');
        }
    }
    for(int i=0; i<re.size()-1; i++)
    {
        re[i+1] = re[i+1] + re[i]/10;
        re[i] = re[i] % 10;
    }
    int t = re.back();
    re.back() = t%10;
    t = t / 10; 
    while(t)
    {
        re.push_back(t%10);
        t = t / 10; 
    }
    while(re.size() > 1 && re.back() == 0) 
        re.pop_back();

    for (int i = re.size()-1; i>=0; i--)
    {
        result = result + to_string(re[i]);
    }

    if (a.find('.')!=string::npos || b.find('.')!=string::npos)
    {
        string re_int = result.substr(0, result.length()-fraclen);
        string re_frac = result.substr(result.length()-fraclen, fraclen);
        result = re_int + "." + re_frac;
    }


    if (a[0]=='-' && b[0]!='-')
    {
        result = "-" + result;
    }

    if (a[0]!='-' && b[0]=='-')
    {
        result = "-" + result;
    }
    
    return result;
}

string div(const std::string a, const std::string b)
{
    double da = stod(a);
    double db = stod(b);
    double re = db/da;
    string res = to_string(re);
    return res;
}

string ap_calculate(const std::string str)
{
    stack<std::string> s_cal;
    string space = " ";
    string s = "0123456789+-*/";

    int start = 0;
    int end = 0;
    string num;
    string num1;
    string num2;

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
                if (num2[0]=='-')
                {
                    num2.erase(0, 1);
                    num = ap_sub(num1, num2);
                    s_cal.push(num);
                }
                else if (num1[0]=='-')
                {
                    num1.erase(0, 1);
                    num = ap_sub(num2, num1);
                    s_cal.push(num);
                }
                
                else
                {
                    num = ap_add(num1, num2);
                    s_cal.push(num);
                }
            }
            else if (tempstr == "-")
            {
                num = ap_sub(num2, num1);
                //num = to_string(stod(num2) - stod(num1));                
                s_cal.push(num);
            }
            else if (tempstr == "*")
            {
                num = ap_mul(num1, num2);
                s_cal.push(num);
            }
            else
            {
                num = div(num1, num2);
                s_cal.push(num);
            }   
        }
        else
        {
            //double tempnum = stod(tempstr);
            s_cal.push(tempstr);
        }     
        i = end + 1;
    }

    return s_cal.top();
}

int main()
{
    cout << "Please input what you want to calculate:" << endl;
    char ch[maxn] = {};
    cin.getline(ch, maxn);

    string str = ch;
    int varN = 0;

    if (isVariable(str)) //variable,转换成纯数字计算式之后，中缀->后缀->后缀表达式计算
    {
        varN = 1;
        string str_v;
        string str_vcal; //含变量的计算式
        string str_value = str.substr(2, str.length()-2); //储存变量值
        vector<char> var_store;
        vector<string> value_store;

        var_store.push_back(str[0]);
        value_store.push_back(str_value);

        while (true)
        {        
            char ch_v[maxn] = {};
            cin.getline(ch_v, maxn);
            str_v = ch_v;

            if (isVariable(str_v))
            {
                varN = varN + 1;
                string value = str_v.substr(2, str_v.length()-2);
                var_store.push_back(str_v[0]);
                value_store.push_back(value);
                continue;
            }
            else
            {
                str_vcal = str_v;
                break;
            }
        }

        string str_ncal = str_vcal; //代入数值后的计算式（不含变量）
        int istart = 0;
        
        for (int i = 0; i < str_vcal.length(); i++)
        {            
            if (isLetter(str_vcal[i]))
            {   
                for (int j = 0; j < varN; j++)
                {
                    if (var_store[j]==str_vcal[i])
                    {
                        str_ncal.replace(str_ncal.find(str_vcal[i]), 1, value_store[j]);
                    }
                    else continue;
                }
            }
            else continue;
        }

        str = str_ncal;
    }

    
    if (allnumber(str)) //纯算数计算
    {
        //获取字符串长度
        int len = str.length();
        //初始化stack，s_op存运算符，s_conv存中间结果，最后s_conv逆序输出
        stack<char> s_op;
        stack<char> s_conv;
        //输出目标，后缀表达式
        char ch_conv[len] = {};
        //遍历字符串，按优先级放入中间结果栈
        for (int i = 0; i < len; i++)
        {
            if ((str[i]>=48 && str[i]<=57) || str[i]=='.') //数字-直接放入栈
            {
                s_conv.push(str[i]);
            }
            else if (isOperator(str[i])) //操作符-判断优先级
            {
                
                while (true)
                {
                    if (s_op.empty() || getPriority(str[i]) > getPriority(s_op.top())) //操作符栈为空或优先级更大时放入，包括栈顶是'('的情况
                    {
                        s_op.push(str[i]);
                        s_conv.push(' '); //如果输入的数超过个位无法区分，加空格来区分
                        break;
                    }
                    else //优先级小或相等的时候拿出栈顶，再进行循环
                    {
                        s_conv.push(' ');
                        char c1 = s_op.top();
                        s_op.pop();
                        s_conv.push(c1);
                    }
                }    
            }
            else //括号
            {
                if (str[i]=='(')
                {
                    s_op.push(str[i]);
                }
                else //str[i]=')'的情况
                {
                    while (s_op.top()!='(')
                    {
                        s_conv.push(' ');
                        char c2 = s_op.top();
                        s_op.pop();
                        s_conv.push(c2);
                    }
                    s_op.pop(); //丢掉'('
                } 
            }       
        }
        
        while (s_op.empty()==0)
        {
            s_conv.push(' '); 
            char c3 = s_op.top();
            s_op.pop();
            s_conv.push(c3);
        }

        //此时栈s_conv从底部往上为后缀表达式顺序，要按顺序赋给ch_conv
        //可以利用s_op将s_conv中数据的顺序颠倒，再赋给ch_conv
        
        while (s_conv.empty()==0)
        {
            char c4 = s_conv.top();
            s_conv.pop();
            s_op.push(c4);
        }

        int ci = 0;
        while (s_op.empty()==0)
        {
            ch_conv[ci] = s_op.top();
            ci = ci + 1;
            s_op.pop();
        }

        ch_conv[ci] = '\0';
        //至此，获得了后缀表达式

        //后缀表达式计算,先将char*转成string类型
        string str_cal;
        str_cal = ch_conv;
        
        string result = ap_calculate(str_cal);
        //double result = calculate(str_cal);
        
        cout << result << endl;
    }
    else if (mathfunction(str)) //简单的数学函数计算
    {
        string str_fun;
        string str_num;
        int n1 = str.find_first_of('(');
        int n2 = str.find_first_of(')');

        str_fun = str.substr(0, n1);
        str_num = str.substr(n1+1, n2-n1-1);

        double n = stod(str_num);
        double result = 0;
        if (str_fun == "abs")
        {
            result = abs(n);
        }
        else if (str_fun == "floor")
        {
            result = floor(n);
        }
        else if (str_fun == "ceil")
        {
            result = ceil(n);
        }
        else if (str_fun == "sqrt")
        {
            result = sqrt(n);
        }
        else if (str_fun == "log")
        {
            result = log(n);
        }
        else if (str_fun == "exp")
        {
            result = exp(n);
        }
        else if (str_fun == "sin")
        {
            result = sin(n);
        }
        else if (str_fun == "cos")
        {
            result = cos(n);
        }
        else if (str_fun == "tan")
        {
            result = tan(n);
        }

        cout << result << endl;   
    }
    else
    {
        cout << "Please input your expression in an appropriate format." << endl;
    }
    
    return 0;

}
