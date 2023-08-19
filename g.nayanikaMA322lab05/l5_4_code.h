#include<bits/stdc++.h>
using namespace std;

double sum_x(int n, vector<double>x)
{
    double s = 0;
    for(int i=0;i<n;i++)
     s += x[i];
    
    return s;
}

double sum_xy(int n, vector<double>x, vector<double>y)
{
    double s = 0;
    for(int i=0;i<n;i++)
     s += x[i]*y[i];
    
    return s;
}

double R_2(int n, vector<double>x, vector<double>y, double a, double b)
{
    double s = 0;
    for(int i=0;i<n;i++)
     s += pow( (y[i] - (a + b*x[i]) ),2) ;
    
    return s;
}

vector<double> func(int n, vector<double>x, vector<double>y)
{
    double s_x,s_y,s_x2,s_xy,a,b,r2;

    s_x = sum_x(n,x);
    s_y = sum_x(n,y);
    s_x2 = sum_xy(n,x,x);
    s_xy = sum_xy(n,x,y);

    a = ( (s_x2 * s_y) - (s_x * s_xy) )/(1.0*( n*s_x2 - s_x*s_x ) );
    b = ( n*s_xy - (s_x * s_y) )/(1.0*( n*s_x2 - s_x*s_x ) );
    r2 = R_2(n,x,y,a,b); 

    return {a,b,r2};
}