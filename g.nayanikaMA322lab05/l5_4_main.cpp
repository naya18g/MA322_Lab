#include<bits/stdc++.h>
#include "l5_4_code.h"
using namespace std;

int main()
{
    int n;
    double t;

    vector<double>x;
    vector<double>y;
    vector<double>res;

    cout<<"Enter n"<<endl;
    cin>>n;

    cout<<"Enter x"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        x.push_back(t);
    }

    cout<<"Enter y"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        y.push_back(t);
    }
    
    res = func(n,x,y);

    cout<<"a = "<<res[0]<<endl;
    cout<<"b = "<<res[1]<<endl;
    cout<<"R^2 = "<<res[2]<<endl;

    if(res[1]<0)
     cout<<"f(x) = "<<res[0]<<" - "<<abs(res[1])<<"x"<<endl;
    else if(res[1]== 0)
     cout<<"f(x) = "<<res[0]<<endl;
    else 
     cout<<"f(x) = "<<res[0]<<" + "<<res[1]<<"x"<<endl;

    return 0;
}