#include<bits/stdc++.h>
using namespace std;

double legendre(double a, double b)
{
    double w = 1.0, x1 = 1.0/(sqrt(3.0)), x2 = -1.0/(sqrt(3.0)), I;
    
    x1 = (((b-a)/2.0)*x1) + ((b+a)/2.0) ;
    x2 = (((b-a)/2.0)*x2) + ((b+a)/2.0) ;

    I = ( (b-a)/2.0 ) * ( w*( exp(x1)*sin(x1) + exp(x2)*sin(x2)) );
    return I;
}
