#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{   
    //input
    string str_a;
    string str_b;
    
    if (argc==3)
    {
        str_a = argv[1];
        str_b = argv[2];
    }
    
    string str_a0 = str_a;
    string str_b0 = str_b;

    int t1 = 0;
    int t2 = 0;
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < str_a.length(); i++)
    {
        if ((str_a[i]>=48 && str_a[i]<=57) || (str_a[i]==46) || (str_a[i]==101) || (str_a[i]=='-'))
        {
            t1 = t1 + 1;
            if (str_a[i]=='-')
            {
                n1 = n1 + 1;
            }
            continue;
        }
        else break;
    }
    for (int j = 0; j < str_b.length(); j++)
    {
        if ((str_b[j]>=48 && str_b[j]<=57) || (str_b[j]==46) || (str_b[j]==101) || (str_b[j]=='-'))
        {
            t2 = t2 + 1;
            if (str_b[j]=='-')
            {
                n2 = n2 + 1;
            }
            continue;
        }
        else break;
    }

    bool tp_a = 1;
    bool te_a = 1;
    bool tp_b = 1;
    bool te_b = 1;
    if (str_a0.find('.')!=string::npos)
    {
        tp_a = (str_a0.find_first_of('.')==str_a0.find_last_of('.')) && (str_a0.find_first_of('.')!=0);        
    }
    if (str_a0.find('e')!=string::npos)
    {
        te_a = (str_a0.find_first_of('e')==str_a0.find_last_of('e')) && (str_a0.find_first_of('e')!=0);
    }    
    if (str_b0.find('.')!=string::npos)
    {
        tp_b = (str_b0.find_first_of('.')==str_b0.find_last_of('.')) && (str_b0.find_first_of('.')!=0);
    }
    if (str_b0.find('e')!=string::npos)
    {
        te_b = (str_b0.find_first_of('e')==str_b0.find_last_of('e')) && (str_b0.find_first_of('e')!=0);
    }
    
    bool ta = tp_a && te_a;
    bool tb = tp_b && te_b;
    bool t_single = (str_a0 == ".") || (str_a0=="e") || (str_b0 == ".") || (str_b0=="e");
    bool t_fe = (str_a0 == ".e") || (str_a0=="e.") || (str_b0 == ".e") || (str_b0=="e.");
    
    bool tpe_a = 1;
    bool tpe_b = 1;
    if ((str_a0.find('.')!=string::npos) && (str_a0.find('e')!=string::npos) && ta)
    {
        tpe_a = str_a0.find_first_of('.') < str_a0.find_first_of('e');
    }
    if ((str_b0.find('.')!=string::npos) && (str_b0.find('e')!=string::npos) && tb)
    {
        tpe_b = str_b0.find_first_of('.') < str_b0.find_first_of('e');
    }
    bool tpe = tpe_a && tpe_b;

    bool neg_a = 1;
    bool neg_b = 1;
    bool neg   = 1;
    
    if (n1==1)
    {
        if (str_a[0]=='-')
            neg_a = 1;
        else
        {
            if ((str_a.find('e')!=string::npos) && te_a)
                neg_a = (str_a.find_first_of('-') == (str_a.find_first_of('e')+1) );
            else
                neg_a = 0;  
        }    
    }
    else if (n1==2)
        neg_a = (str_a.find_first_of('-')==0) && (str_a.find('e')!=string::npos) && te_a && (str_a.find_last_of('-') == (str_a.find_first_of('e')+1));
    else if (n1>2)
        neg_a = 0;
    
    if (n2==1)
    {
        if (str_b[0]=='-')
            neg_b = 1;
        else
        {
            if ((str_b.find('e')!=string::npos) && te_b)
                neg_b = (str_b.find_first_of('-') == (str_b.find_first_of('e')+1) );
            else
                neg_b = 0;  
        }    
    }
    else if (n2==2)
        neg_b = (str_b.find_first_of('-')==0) && (str_b.find('e')!=string::npos) && te_b && (str_b.find_last_of('-') == (str_b.find_first_of('e')+1));
    else if (n2>2)
        neg_b = 0;

    neg = neg_a && neg_b;

    bool cond = (t1==str_a.length()) && (t2==str_b.length()) && ta && tb && (!t_single) && (!t_fe) && tpe && neg;
    
    if ((str_a0[0]=='+') || (str_b0[0]=='+'))
    {
        cout << "Please input numbers without the positive sign." << endl;
    }
    else if(!cond)
    {
        cout << "The input cannot be inerpret as numbers!" << endl; //输入不符合要求
    }
    else if (argc!=3)
    {
         cout << "Please input two numbers." << endl;
    }
    else
    {
        //(大)整数乘法
        long long a_long;
        long long b_long;
        long long result_long;//output

        if (str_a.find('.')==string::npos && str_a.find('e')==string::npos && str_b.find('.')==string::npos && str_b.find('e')==string::npos)
        {
            a_long = stoll(str_a);
            b_long = stoll(str_b);
            result_long = a_long * b_long;

            cout << a_long << " * " << b_long << " = " << result_long << endl;
        }

        //浮点数乘法(浮点数*浮点数 and 整数*浮点数)
        double a_double;
        double b_double;
        double result_double;//output
        if ((str_a.find('.')!=string::npos || str_b.find('.')!=string::npos) && str_a.find('e')==string::npos && str_b.find('e')==string::npos)
        {   
            //如果检测到是整数，则转换为浮点数格式，最后直接进行浮点数乘法
            if (str_a.find('.') == string::npos)
            {   
                str_a = str_a + '.';          
            }

            if (str_b.find('.') == string::npos)
            {   
                str_b = str_b + '.';           
            }
            
            int a_firstpoint = str_a.find_first_of('.');
            int a_lastpoint  = str_a.find_last_of('.');
            int b_firstpoint = str_b.find_first_of('.');
            int b_lastpoint  = str_b.find_last_of('.');
            
            
            a_double = stod(str_a);
            b_double = stod(str_b);
            result_double = a_double * b_double;                

            int pa = str_a.length() - a_firstpoint - 1;
            int pb = str_b.length() - b_firstpoint - 1;
            int pr;
            if((pa+pb)<=15 && (pa+pb)>0)
            {
                pr = pa + pb;
            }
            else if((pa+pb)==0)
            {
                pr = 1;
            }
            else pr = 15;                

            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << setprecision(min(pa,15)) << a_double << " * ";
            cout << setprecision(min(pb,15)) << b_double << " = ";
            cout << setprecision(pr) << result_double << endl;
            //小数位太多会不精确，尝试多次发现小数位为15位时仍保持精准，15位以上开始丢失精度，所以精度设置为最大15
                                     
        }
   
        //大浮点数乘法(包含大整数，科学计数法表示，含e)
        if (str_a.find('e')!=string::npos || str_b.find('e')!=string::npos) // a b 至少一个含e
        {
            if (str_a.find('e')==string::npos && str_b.find('e')!=string::npos) //a不含e，b含e
            {                         
                if (str_b.find_first_of('e')==(str_b.length()-1))
                {
                    cout << "The input cannot be inerpret as numbers!" << endl;
                }
                else
                {
                    if (str_a.find('.')!=string::npos || str_b.find('.')!=string::npos)
                    {
                        string str_b1 = str_b.substr(0,str_b.find_first_of('e'));
                        string str_b2 = str_b.substr(str_b.find_first_of('e'),(str_b.length()-str_b.find_first_of('e')));
                        double a1 = stod(str_a);
                        double b1 = stod(str_b1);
                        double re1 = a1 * b1;
                        
                        string result1 = to_string(re1) + str_b2;

                        cout << str_a0 << " * " << str_b0 << " = " << result1 << endl;
                    }
                    else
                    {
                        string str_b1 = str_b.substr(0,str_b.find_first_of('e'));
                        string str_b2 = str_b.substr(str_b.find_first_of('e'),(str_b.length()-str_b.find_first_of('e')));
                        long long a1 = stoll(str_a);
                        long long b1 = stoll(str_b1);
                        long long re1 = a1 * b1;
                        
                        string result1 = to_string(re1) + str_b2;

                        cout << str_a0 << " * " << str_b0 << " = " << result1 << endl;
                    }      
                }
            }
            else if (str_a.find('e')!=string::npos && str_b.find('e')==string::npos)
            // a含e, b不含e
            {
                if (str_a.find_first_of('e')==(str_a.length()-1))
                {
                    cout << "The input cannot be inerpret as numbers!" << endl;
                }
                else
                {
                    if (str_a.find('.')!=string::npos || str_b.find('.')!=string::npos)
                    {
                        string str_a1 = str_a.substr(0,str_a.find_first_of('e'));
                        string str_a2 = str_a.substr(str_a.find_first_of('e'),(str_a.length()-str_a.find_first_of('e')));
                        double a2 = stod(str_a1);
                        double b2 = stod(str_b); 
                        double re2 = a2 * b2;
                        
                        string result2 = to_string(re2) + str_a2;

                        cout << str_a0 << " * " << str_b0 << " = " << result2 << endl;
                    }
                    
                    else
                    {
                        string str_a1 = str_a.substr(0,str_a.find_first_of('e'));
                        string str_a2 = str_a.substr(str_a.find_first_of('e'),(str_a.length()-str_a.find_first_of('e')));
                        long long a2 = stoll(str_a1);
                        long long b2 = stoll(str_b); 
                        long long re2 = a2 * b2;
                        
                        string result2 = to_string(re2) + str_a2;

                        cout << str_a0 << " * " << str_b0 << " = " << result2 << endl;
                    }
                }   
            }
            //相同格式进行大浮点数运算
            else if((str_a.find('e')!=string::npos) && (str_b.find('e')!=string::npos))
            {       
                int a_firste = str_a.find_first_of('e');
                int a_laste  = str_a.find_last_of('e');
                int b_firste = str_b.find_first_of('e');
                int b_laste  = str_b.find_last_of('e');

                bool test_b = (str_b.find_first_of('e')==(str_b.length()-1)) || (str_a.find_first_of('e')==(str_a.length()-1)); 

                if (test_b)
                {
                    cout << "The input cannot be inerpret as numbers!" << endl;
                }               
                else
                {                       
                    if (str_a.find('.')!=string::npos || str_b.find('.')!=string::npos)
                    {
                        string a_mul = str_a.substr(0,(a_firste));
                        string b_mul = str_b.substr(0,(b_firste));
                        string a_add = str_a.substr((a_firste+1),(str_a.length()-a_firste-1));
                        string b_add = str_b.substr((b_firste+1),(str_b.length()-b_firste-1));

                        double    a_d = stod(a_mul);
                        double    b_d = stod(b_mul);
                        long long a_l = stoll(a_add);
                        long long b_l = stoll(b_add);

                        double    r1 = a_d * b_d;
                        long long r2 = a_l + b_l;

                        string result_string = to_string(r1) + "e" + to_string(r2);

                        cout << str_a0 << " * " << str_b0 << " = " << result_string << endl;
                    }
                    else
                    {
                        string a_mul = str_a.substr(0,(a_firste));
                        string b_mul = str_b.substr(0,(b_firste));
                        string a_add = str_a.substr((a_firste+1),(str_a.length()-a_firste-1));
                        string b_add = str_b.substr((b_firste+1),(str_b.length()-b_firste-1));

                        long long a_d = stoll(a_mul);
                        long long b_d = stoll(b_mul);
                        long long a_l = stoll(a_add);
                        long long b_l = stoll(b_add);

                        long long r1 = a_d * b_d;
                        long long r2 = a_l + b_l;

                        string result_string = to_string(r1) + "e" + to_string(r2);

                        cout << str_a0 << " * " << str_b0 << " = " << result_string << endl;
                    }
                }
            }
        } 
    }
    return 0;
}