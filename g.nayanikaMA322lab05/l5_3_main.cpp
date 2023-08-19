#include<bits/stdc++.h>
#include "l5_3_code.h"
using namespace std;

int main()
{
    int n;
    double t, I;
    vector<double>x;
    vector<double>fx;

    cout<<"Enter n"<<endl;
    cin>>n;

    cout<<"Enter x"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        x.push_back(t);
    }

    cout<<"Enter fx"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        fx.push_back(t);
    }
    
    I = func(n,x,fx);
    cout<<"I = "<<I<<endl;

    return 0;
}