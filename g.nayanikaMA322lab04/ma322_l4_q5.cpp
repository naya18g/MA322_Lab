#include<bits/stdc++.h>
using namespace std;

vector<long double>xn1,xn2,yn1,yn2;
long double sum_x1(0.0), sum_y1(0.0);

double norm(vector<double>y0, vector<double>y1)
{
    long double d;
    d = pow( pow((y1[0]-y0[0]),2) + pow((y1[1]-y0[1]),2),0.5 );
    return d;
}

vector<double> newton(double x, double y, int n) 
{   
   double epsilon = 0.0000001, det_F;
   vector<vector<double>>X (n+1, vector<double> (2));
   vector<vector<double>>inv_F (n+1, vector<double> (2));
   
   X[0][0] = x;
   X[0][1] = y;

   long double t;
   t = norm(X[0], X[1]);

   yn1.push_back(log(t));
   xn1.push_back(log(t));
   sum_x1 += log(t);
   sum_y1 += log(t);

   for(int i=1;i<=n;i++)
   {
    x = X[i-1][0];
    y = X[i-1][1];
    det_F = 3*(2*x + y*y*y)*(x*x - y*y) - (3*x*y*y)*(6*x*y) ;

    inv_F[i-1][0] = (3*(x*x - y*y)*(x*x + x*y*y*y -9) + (-3*x*y*y)*(3*x*x*y - y*y*y -4))/(1.0*det_F) ;
    inv_F[i-1][1] = ((-6*x*y)*(x*x + x*y*y*y -9) + (2*x + y*y*y)*(3*x*x*y - y*y*y -4))/ (1.0*det_F) ;
    
    X[i][0] = X[i-1][0] - inv_F[i-1][0];
    X[i][1] = X[i-1][1] - inv_F[i-1][1]; 
    
    t = norm(X[i-1], X[i]);

    yn1.push_back(log(t));
    xn1.push_back(log(t));
    sum_x1 += log(t);
    sum_y1 += log(t);

    if( (abs(X[i][0] - X[i-1][0]) <= epsilon) && (abs(X[i][1] - X[i-1][1]) <= epsilon) )	 
    {
      cout<<"The minimum number of iterations = "<<i<<endl;
      return X[i];
    }
   } 
   inv_F.clear();
   return X[n];  
}

void func(double x, double y, int n)
{
    cout<<"The initial value for x = "<<x<<endl; 
    cout<<"The initial value for y = "<<y<<endl;
    cout<<"The maximum number of iterations = "<<n<<endl;
    
    vector<double>X = newton(x,y,n);

    cout<<"The roots are : "<<endl;
    cout<<"x = "<<X[0]<<endl;
    cout<<"y = "<<X[1]<<endl;

    X.clear();
}

int main()
{
    int n = 10000;
    vector<vector<double>> v = {{1.2,2.5}, {-2,2.5}, {-1.2,-2.5}, {2,-2.5}} ;
    
    for(int j=0;j<4;j++)
    {
      func(v[j][0],v[j][1],n);
      double sm,sm2;
      sm = 0;
      sm2 = 0;
      sum_x1 -= xn1[xn1.size()- 1];
      sum_y1 -= yn1[0];
      sum_x1/= double(xn1.size()-1);
      sum_y1/= double(yn1.size()-1);
      for(int i=0; i<xn1.size()-1; i++)
      {
        sm += (xn1[i] - sum_x1)*(yn1[i+1] - sum_y1);
        sm2 += (xn1[i] - sum_x1)*(xn1[i] - sum_x1);
      }
      cout << "Order of Convergence using Newton's Method :\t" << sm/sm2 << endl;
      xn1.clear();
      xn2.clear();
      yn1.clear();
      yn2.clear();
    }
   
    return 0;
}