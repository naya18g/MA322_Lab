#include<bits/stdc++.h>
using namespace std;

vector<double> newton(double x, double y, int n) 
{   
   double epsilon = 0.000001, det_F, a, b;
   vector<vector<double>>X (n+1, vector<double> (2));
   vector<vector<double>>inv_F (n+1, vector<double> (2));
   
   inv_F[0][0] = ((1 + cos(x-y))*(4*x*x + y*y - 4) + (-2*y)*( x+y - sin(x-y))) / (1.0*det_F) ;
   inv_F[0][1] = ((-1 + cos(x-y))*(4*x*x + y*y - 4) + (8*x)*( x+y - sin(x-y))) / (1.0*det_F) ;

   X[0][0] = x;
   X[0][1] = y;

   for(int i=1;i<=n;i++)
   {
    a = X[i-1][0];
    b = X[i-1][1];
    det_F = 8*a - 2*b + (8*a + 2*b)*cos(a-b) ;

    inv_F[i-1][0] = ((1 + cos(a-b))*(4*a*a + b*b - 4) + (-2*b)*( a+b - sin(a-b))) / (1.0*det_F) ;
    inv_F[i-1][1] = ((-1 + cos(a-b))*(4*a*a + b*b - 4) + (8*a)*( a+b - sin(a-b))) / (1.0*det_F) ;
    
    X[i][0] = X[i-1][0] - inv_F[i-1][0];
    X[i][1] = X[i-1][1] - inv_F[i-1][1]; 

    if( (abs(X[i][0] - X[i-1][0]) <= epsilon) && (abs(X[i][1] - X[i-1][1]) <= epsilon) )	 
      return X[i];
   } 

   return X[n];  
}

int main()
{
    double x = 1.0001, y = 0.0001;
    int n = 100000;

    cout<<"The initial value for x = "<<x<<endl; 
    cout<<"The initial value for y = "<<y<<endl;
    cout<<"The maximum number of iterations = "<<n<<endl;
    
    vector<double>X = newton(x,y,n);

    cout<<"The roots are : "<<endl;
    cout<<"x = "<<X[0]<<endl;
    cout<<"y = "<<X[1]<<endl;

    return 0;
}