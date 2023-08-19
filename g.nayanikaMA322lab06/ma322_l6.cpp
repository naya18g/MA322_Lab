#include<bits/stdc++.h>
#include "ma322_l6_1b.h"
#include "ma322_l6_1c.h"

using namespace std;

int main()
{
    double res, res1, res2, a=-1, b=1, ans = 0.663494 ;
    res = legendre(a, b);
    res1 = chebyshev_1(a,b);
    res2 = chebyshev_2(a,b);

    cout<<"Integral using Gaussian-Legendre formula = "<<fixed<<setprecision(6)<<res<<endl; 
    cout<<"Analytical Integral = "<<fixed<<setprecision(6)<<ans<<endl;
    cout<<"Relative Error = "<<fixed<<setprecision(6)<<abs((res - ans)/ans)<<endl;
    
    cout<<endl;

    cout<<"Integral using Gaussian-Chebyshev (1st kind) formula = "<<fixed<<setprecision(6)<<res1<<endl;
    cout<<"This is non-integrable"<<endl;
    cout<<endl;

    cout<<"Integral using Gaussian-Chebyshev (2nd kind) formula = "<<fixed<<setprecision(6)<<res2<<endl;
    cout<<"This is non-integrable"<<endl;
    cout<<endl;
    
    return 0;
}