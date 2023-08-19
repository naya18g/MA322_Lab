#include <bits/stdc++.h>
using namespace std;

int main()
{

	string fx,dfx,inp;
	cout<<"Type \"Bisection\", \"Newton\", \"Secant\" for the required method"<<endl;
	
	string s;cin>>s;
	cout<<"Give the input for the function f(x)"<<endl;
	cin>>fx;

	if(s == "Bisection")
	{
		dfx="eps";
		cout<<"Give the input for a and b, such that f(a)*f(b) < 0"<<endl;
		long double a,b;
		cin>>a>>b;

		cout<<"Give the input for the maximum number of steps"<<endl;
		int c;
		cin>>c;

		cout<<"Give the input for the required precision"<<endl;
		long double d;
		cin>>d;

		cout<<endl;
		cout<<endl;

		inp = "\n\
		eps = "+to_string(d)+" ;\n\
	    mx = "+to_string(c)+" ;\n\
	    cout<<Bisection("+to_string(a)+" , "+to_string(b)+" )<<endl;";
	
	
	}
	
	else if(s=="Newton")
	{
		cout<<"Give the input for the function f(x)"<<endl;
		cin>>dfx;

		cout<<"Give the input for the starting point"<<endl;
		long double a;
		cin>>a;

		cout<<"Give the input for the maximum number of steps"<<endl;
		int c;
		cin>>c;

		cout<<"Give the input for the required precision"<<endl;
		long double d;
		cin>>d;

		inp = "\n\
	    eps = "+to_string(d)+" ;\n\
	    mx = "+to_string(c)+" ;\n\
	    cout<<Newton("+to_string(a)+" )<<endl;";
	}
	
	else
	{
		dfx="eps";
		cout<<"Give the input for x0 and x1, such that f(x0)*f(x1) < 0"<<endl;
		long double a,b;
		cin>>a>>b;

		cout<<"Give the input for the maximum number of steps"<<endl;
		int c;
		cin>>c;

		cout<<"Give the input for the required precision"<<endl;
		long double d;
		cin>>d;

		inp = "\n\
	eps = "+to_string(d)+" ;\n\
	mx = "+to_string(c)+" ;\n\
	cout<<Secant("+to_string(a)+" , "+to_string(b)+" )<<endl;";
	}



	
	
	
	string a="#include<bits/stdc++.h>\n\
\n\
using namespace std;\n\
\n\
long double eps;\n\
int mx;\n\
long double f(long double x){\n\
	return ";
	string b=" ;\n\
}\n\
\n\
long double df(long double x){\n\
	return ";
	string c =" ;\n\
}\n\
long double Newton(long double x){\n\
	int cnt=0;\n\
	while(1){\n\
		cnt++;\n\
		long double y = f(x)/df(x);\n\
		if(abs(y)<eps){\n\
			return x;\n\
		}\n\
		x-=y;\n\
		if(cnt==mx){\n\
			break;\n\
		}\n\
	}\n\
	return x;\n\
}\n\
\n\
long double Bisection(long double l,long double r){\n\
	if(f(l)*f(r)>0){\n\
		cout<<\"lower and upper bound for bisection method is not feasible\";\n\
		return 0;\n\
	}\n\
	int cnt=0;\n\
	while(abs(r-l)>eps){\n\
		cnt++;\n\
		long double mid=(l+r)/2;\n\
		if(f(mid)==0){\
			l=mid;\
			break;\
		}\
		if(f(l)*f(mid)<0){\n\
			r=mid;\n\
		}else{\n\
			l=mid;\n\
		}\n\
		if(cnt==mx){\n\
			break;\n\
		}\n\
	}\n\
	return l;\n\
}\n\
\n\
long double Secant(long double x0, long double x1){\n\
	int cnt=0;\n\
	while(abs(x1-x0)>eps){\n\
		cnt++;\n\
		long double x2=x1;\n\
		if(abs(f(x1)-f(x0))<eps){\n\
			break;\n\
		}\n\
		x1 = x1 - (f(x1))*(x1-x0)/(f(x1)-f(x0));\n\
		x0 = x2;\n\
		if(cnt==mx){\n\
			break;\n\
		}\n\
	}\n\
	return x1;\n\
}\n\
\n\
int main(){\n";
	
	string d="\n};";
	string code = a+fx+b+dfx+c+inp+d;
	
	system("touch temp.cpp");
	ofstream fout;
	fout.open("new_code.cpp");
	fout<<code<<endl;

	system("g++ new_code.cpp -o new_code");
	system("./new_code");
	system("new_code.cpp");
}
