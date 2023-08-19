#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x=8,f,g;

    for(int i=1;i<=15;i++)
    {
      double x1;
      x1 = 1.0/pow(x,i);

      f = sqrt(x1*x1 +1) -1;
      g = (x1*x1*1.0)/(sqrt(x1*x1 +1) + 1);

      cout<<"For i = "<<i<<": "<<"    ";
      cout<<"f(x) = "<<setprecision(15)<<f<<";    ";
      cout<<"g(x) = "<<setprecision(15)<<g<<endl;
    }

    return 0;
}