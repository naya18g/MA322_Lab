#include<bits/stdc++.h>
using namespace std;

double simpson_3_8(int n, vector<double>x, vector<double>fx)
{
    double h, I=0;
    h = (x[3] - x[0])/(3.0) ;
    I = fx[0] + fx[n-1] ;

    for(int j = 1;j < n-1; j++)
    {
       if(j%3 == 0)
        I += 2*fx[j];
       else
        I += 3*fx[j]; 
    }

    I *= (3.0*h)/8.0 ;
    return I;
}

double simpson_1_3(int n, vector<double>x, vector<double>fx)
{
    double h, I=0;
    h = x[1] - x[0] ;
    I = fx[0] + fx[n-1] ;

    for(int j = 1;j < n-1; j++)
    {
       if(j%2 == 0)
        I += 2*fx[j];
       else
        I += 4*fx[j]; 
    }

    I *= h/3.0 ;
    return I;
}

double func(int n, vector<double>x, vector<double>fx)
{
   double I, I1, I2;

    if(n%3 == 1)
      I = simpson_3_8(n,x,fx);
    
    else if(n%3 == 2)
    {
        vector<double>x1;
        vector<double>x2;
        vector<double>f1;
        vector<double>f2;

        for(int i=0;i<n-4;i++)
        {
            x1.push_back(x[i]); 
            f1.push_back(fx[i]); 
        }

        for(int i=n-5;i<n;i++)
        {
            x2.push_back(x[i]); 
            f2.push_back(fx[i]);
        }

        I1 = simpson_3_8(n-4,x1,f1);
        I2 = simpson_1_3(5,x2,f2);
        
        I = I1 + I2;
    }

    else if(n%3 == 0)
    {
        vector<double>x1;
        vector<double>x2;
        vector<double>f1;
        vector<double>f2;

        for(int i=0;i<=n-3;i++)
        {
            x1.push_back(x[i]); 
            f1.push_back(fx[i]);
        }

        for(int i=n-3;i<n;i++)
        {
            x2.push_back(x[i]); 
            f2.push_back(fx[i]);
        }

        I1 = simpson_3_8(n-2,x1,f1);
        I2 = simpson_1_3(3,x2,f2);
        
        I = I1 + I2;
    }

    return I;
     
}