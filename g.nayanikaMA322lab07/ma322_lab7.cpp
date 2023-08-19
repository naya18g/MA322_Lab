#include<bits/stdc++.h>
using namespace std ;

double fxt(double x, double t)
{
   double a;
   a = x + exp(t) + (t*x) ;
   return a;
}


double ft(double x, double t)
{
   double a;
   a = exp(t) + x ;
   return a;
}


double fx(double x, double t)
{
   double a;
   a = 1.0 + t ; 
   return a;
}


void taylor_3(double h)
{
   vector<double>x;
   x.push_back(2.0);
   double t, a, b, c;
   int i;
   
   for(i=0,t=1.0;i<20;i++, t+= h) 
   {
      a = ft(x[i],t) ;
      b = fx(x[i],t) ;
      c = fxt(x[i],t) ;

      x.push_back( x[i] + (h*c) + ( h*h*0.5*(a + (b*c) ) ) + ( (h*h*h*( exp(t) + c + c + b*(a + (b*c) ) ) )/6.0 ) );
   }

   cout<<"Taylor's Method of Order 3 :"<<endl;
   for(int i=0;i<x.size();i++)
   {
     cout<<"x("<<fixed<<setprecision(1)<<(1.0 + (h*i) )<<") = " ;
     cout<<fixed<<setprecision(6)<<x[i]<<endl;
   }
}


void bdf_euler(double h)
{
   vector<double>x;
   x.push_back(2.0);
   double t = 1.0;
   int i=0;

   while(t <= 3.0)
   {
      t += h;
      x.push_back( (x[i] + h*exp(t))/(1 -h - h*t) );
      //xn = xn-1 + hf(xn, tn) 
      i++;
   }
   
   cout<<"Implicit Euler's Method :"<<endl; 
   for(int i=0;i<x.size();i++)
   {
     cout<<"x("<<fixed<<setprecision(1)<<(1.0 + (h*i) )<<") = " ;
     cout<<fixed<<setprecision(6)<<x[i]<<endl;
   }

}


int main()
{
   taylor_3(0.1);
   cout<<endl;
   bdf_euler(0.1);

   return 0;
}


