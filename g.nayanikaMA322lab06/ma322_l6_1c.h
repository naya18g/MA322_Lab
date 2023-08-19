#include<bits/stdc++.h>
using namespace std;

double chebyshev_1(double a, double b)
{
    double x1 = 1.0/(sqrt(2.0)), x2 = -1.0/(sqrt(2.0)), w1 = 1.570796327, w2 = 1.570796327, I ;
    
    x1 = (((b-a)/2.0)*x1) + ((b+a)/2.0) ;
    x2 = (((b-a)/2.0)*x2) + ((b+a)/2.0) ;

    I = ( (b-a)/2.0 ) * ( w1*( exp(x1)*sin(x1) ) + w2*( exp(x2)*sin(x2) ) );
    return I;
}

double chebyshev_2(double a, double b)
{
    double x1 = 0.5, x2 = -0.5, w1 = 0.7853981634, w2 = 0.7853981634, I ;
    
    x1 = (((b-a)/2.0)*x1) + ((b+a)/2.0) ;
    x2 = (((b-a)/2.0)*x2) + ((b+a)/2.0) ;

    I = ( (b-a)/2.0 ) * ( w1*( exp(x1)*sin(x1) ) + w2*( exp(x2)*sin(x2) ) );
    return I;
}
