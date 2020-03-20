#include <iostream>
#include <iomanip> 
using namespace std;

double comAdd(double x, double y)
{
	return x-y;
}

int main()
{
	double a, b, c, d;
	cin>>a>>b>>c>>d;
	cout<<setprecision(2)<<std::fixed<<comAdd(a, c)<<" "<<comAdd(b, d);
}
