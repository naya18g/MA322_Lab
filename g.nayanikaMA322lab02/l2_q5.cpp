#include <bits/stdc++.h>
using namespace std;

double epsilon = double(pow(10,-7));
double sm = 0;

double func(double x)
{
	double f;
    f = x*x*x + x*x - 5*x + 3 ;
	return f;
} 

double derf(double x)
{
    double f;
    f =  3*x*x + 2*x - 5 ;
    return f;
}

void summ()
{
    sm++;
}




vector<long double>xn1,xn2,xn3,yn1,yn2,yn3,xn4,yn4;
long double sum_x1(0.0),sum_x2(0.0),sum_x3(0.0),sum_y1(0.0),sum_y2(0.0),sum_y3(0.0),sum_x4(0.0),sum_y4(0.0);

double secant()
{
	double x0 = 5.0;
    double x1 = 4.99;
    double a1 = func(x0);
    double a2;

    yn2.push_back(log(abs(x1 - x0)));
    xn2.push_back(log(abs(x1 - x0)));
    sum_x2 += log(abs(x1 - x0));
    sum_y2 += log(abs(x1 - x0));

    while(abs(x1 - x0) > epsilon)
    {
        a1 = func(x1);
        a2 = (double(a1 - func(x0)))/(double(x1 - x0));
        if(a2 == 0)
        {
            cout << "Error" << endl;
            return x1;
        }

        x0 = x1;
        x1 = x0 - double(a1/a2);

        yn2.push_back(log(abs(x1 - x0)));
        xn2.push_back(log(abs(x1 - x0)));

        sum_x2 += log(abs(x1 - x0));
        sum_y2 += log(abs(x1 - x0));
    }

    return x1;
}

double newton(double x)
{
    double y0 = x;
    double a1 = func(y0);
    double a2 = derf(y0);
    if(a2 == 0)
    {
        cout << "Error" <<endl;
        return y0;
    }
    double y1  = y0 - double(a1/a2);
    yn1.push_back(log(abs(y1 - y0)));
    xn1.push_back(log(abs(y1 - y0)));
    sum_x1 += log(abs(y1 - y0));
    sum_y1 += log(abs(y1 - y0));
    while(abs(y1 - y0) > epsilon)
    {
        a1 = func(y1);
        a2 = derf(y1);
        if(a2 == 0)
        {
            cout << "Error" <<  endl;
            return y1;
        }
        y0 = y1;
        y1 = y0 - double(a1/a2);
        yn1.push_back(log(abs(y1 - y0)));
        xn1.push_back(log(abs(y1 - y0)));
        sum_x1 += log(abs(y1 - y0));
        sum_y1 += log(abs(y1 - y0));
    }
	return y1;
}

double method2(double x)
{
    double y0 = x;
    double a1 = func(y0);
    double a2 = derf(y0);
    if(a2 == 0)
    {
        cout << "Error" <<endl;
        return y0;
    }
    double y1  = y0 - 2.0*double(a1/a2);
    yn3.push_back(log(abs(y1 - y0)));
    xn3.push_back(log(abs(y1 - y0)));
    sum_x3 += log(abs(y1 - y0));
    sum_y3 += log(abs(y1 - y0));
    while(abs(y1 - y0) > epsilon)
    {
        a1 = func(y1);
        a2 = derf(y1);
        if(a2 == 0)
        {
            cout << "Error" <<endl;
            return y1;
        }
        y0 = y1;
        y1 = y0 - 2.0*double(a1/a2);
        yn3.push_back(log(abs(y1 - y0)));
        xn3.push_back(log(abs(y1 - y0)));
        sum_x3 += log(abs(y1 - y0));
        sum_y3 += log(abs(y1 - y0));
    }
	return y1;
}

double method4(double x)
{
    double y0 = x;
    double a1 = func(y0);
    double a2 = derf(y0);
    if(a2 == 0)
    {
        cout << "Error" <<endl;
        return y0;
    }
    double y1  = y0 - 3.0*double(a1/a2);
    yn4.push_back(log(abs(y1 - y0)));
    xn4.push_back(log(abs(y1 - y0)));
    sum_x4 += log(abs(y1 - y0));
    sum_y4 += log(abs(y1 - y0));
    while(abs(y1 - y0) > epsilon)
    {
        a1 = func(y1);
        a2 = derf(y1);
        if(a2 == 0)
        {
            cout << "Error" <<endl;
            return y1;
        }
        y0 = y1;
        y1 = y0 - 3.0*double(a1/a2);
        yn4.push_back(log(abs(y1 - y0)));
        xn4.push_back(log(abs(y1 - y0)));
        sum_x4 += log(abs(y1 - y0));
        sum_y4 += log(abs(y1 - y0));
    }
	return y1;
}

int main()
{
    cout << "When x = 2, the roots are :- " << endl;
    cout << fixed << setprecision(12);

    cout << "Newton's Method : \t\t" << newton(double(5*1.0)) << endl; 
    cout << "Secant Method : \t\t" << secant() << endl; 
    cout << "The New Method : \t\t" << method2(double(5*1.0)) << endl; 
    cout << "When m = 3 :\t\t" << method4(double(5*1.0)) << endl; 

    long double sm = 0.0;
    long double sm2 = 0.0;
    sum_x2 -= xn2[xn2.size()- 1];
    sum_y2 -= yn2[0];
    sum_x2/= double(xn2.size()-1);
    sum_y2/= double(yn2.size()-1);

    for(int i=0; i<xn2.size()-1; i++)
    {
        sm += (xn2[i] - sum_x2)*(yn2[i+1] - sum_y2);
        sm2 += (xn2[i] - sum_x2)*(xn2[i] - sum_x2);
        summ();
    }

    cout << "Order of Convergence :-" << endl;
    cout << "Secant Method :\t\t" << sm/sm2 << endl;

    sm = 0;
    sm2 = 0;
    sum_x1 -= xn1[xn1.size()- 1];
    sum_y1 -= yn1[0];
    sum_x1/= double(xn1.size()-1);
    sum_y1/= double(yn1.size()-1);
    for(int i=0; i<xn1.size()-1; i++)
    {
        sm += (xn1[i] - sum_x1)*(yn1[i+1] - sum_y1);
        sm2 += (xn1[i] - sum_x1)*(xn1[i] - sum_x1);
    }
    cout << "Newton's Method :\t" << sm/sm2 << endl;
    sm = 0;
    sm2 = 0;
    sum_x3 -= xn3[xn3.size()- 1];
    sum_y3 -= yn3[0];
    sum_x3/= double(xn3.size()-1);
    sum_y3/= double(yn3.size()-1);
    for(int i=0; i<xn3.size()-1; i++)
    {
        sm += (xn3[i] - sum_x3)*(yn3[i+1] - sum_y3);
        sm2 += (xn3[i] - sum_x3)*(xn3[i] - sum_x3);
    }
    cout << "The New Method :\t\t" << sm/sm2 << endl;
    sm = 0;
    sm2 = 0;
    sum_x4 -= xn4[xn4.size()- 1];
    sum_y4 -= yn4[0];
    sum_x4/= double(xn4.size()-1);
    sum_y4/= double(yn4.size()-1);
    for(int i=0; i<xn4.size()-1; i++)
    {
        sm += (xn4[i] - sum_x4)*(yn4[i+1] - sum_y4);
        sm2 += (xn4[i] - sum_x4)*(xn4[i] - sum_x4);
    }
    cout << "When m = 3 :- \t\t" << sm/sm2 << endl;
}