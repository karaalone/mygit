#include <iostream>
using namespace std;

int buyWater(int b, int c,int a)      //b瓶子 c盖子 a水 
{
	if(b<2&&c<3) return a;
	else{ 
		return buyWater(b%2+b/2+c/3,c%3+c/3+b/2,b/2+c/3+a); 
		//           b%2不够则不变 够则进1余瓶 b/2瓶水 c/3盖水 
		//           c%3不够则不变 够则进1余盖 c/3盖水 b/2瓶水 
		//           b/2+c/3+a 水 
	}
}

int main()
{
	int a;
	cin>>a;
	cout<<buyWater(a,a,a);
	return 0;
}
