#include<bits/stdc++.h>
using namespace std;
int main()
{
   double f,g;

   for(double i=-10;i<=-0.000000000001;i/=100)
   {
       f = (1-cos(i) )/(i*i*1.0) ;
       g = 2.0*pow(sin(i/2),2)/(i*i*1.0);
       
       cout<<"For i = "<<i<<" : "<<"    ";
       cout<<"f(x) = "<<setprecision(15)<<f<<" ;    ";
       cout<<"g(x) = "<<setprecision(15)<<g<<endl;
   }

   cout<<endl;
   
   for(double i=0.00000000001;i<=10;i*=100)
   {
       f = (1-cos(i) )/(i*i*1.0) ;
       g = 2.0*pow(sin(i/2),2)/(i*i*1.0);
       cout<<"For i = "<<i<<" : "<<"    ";
       cout<<"f(x) = "<<setprecision(15)<<f<<" ;    ";
       cout<<"g(x) = "<<setprecision(15)<<g<<endl;
   }

   return 0;
}