#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

vector<double>x(8);
vector<double>fx(8);
vector<vector<double>>g(8, vector<double>(8));

void fx_generate()
{
   for(int i=0;i<fx.size();i++)
    g[0][i] = fx[i];

   for(int i=1;i<=fx.size();i++) 
   {
      for(int j=0;j<fx.size()-i;j++)
        g[i][j] = (g[i-1][j+1] - g[i-1][j])/(1.0*(x[j+i] - x[j]) ); 
   }
}

double func(double y)
{
    double p;

    p = g[0][0] +(y-x[0])*g[1][0] +(y-x[0])*(y-x[1])*g[2][0] +(y-x[0])*(y-x[1])*(y-x[2])*g[3][0] 
    +(y-x[0])*(y-x[1])*(y-x[2])*(y-x[3])*g[4][0] +(y-x[0])*(y-x[1])*(y-x[2])*(y-x[3])*(y-x[4])*g[5][0]
    +(y-x[0])*(y-x[1])*(y-x[2])*(y-x[3])*(y-x[4])*(y-x[5])*g[6][0]
    +(y-x[0])*(y-x[1])*(y-x[2])*(y-x[3])*(y-x[4])*(y-x[5])*(y-x[6])*g[7][0];

    return p;
}

void graph()
{
	ofstream file("data.dat");
	long double i = 0;

	for(i=0;i<=3.5;i+=0.00001)
	 file<<i<<' '<<func(i)<<endl;

	file.close();
}

int main()
{
    x = {0, 1, 2, 2.5, 3, 3.5, 4};
    fx = {2.5, 0.5, 0.5, 1.5, 1.5, 1.125, 0};
    
    fx_generate();

    double p1,p2;
    p1 = func(0.5);
    p2 = func(1.5);

    cout<<"f(0.5) = "<<p1<<endl;
    cout<<"f(1.5) = "<<p2<<endl;

    graph();

    return 0;
}