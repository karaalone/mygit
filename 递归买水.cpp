#include <iostream>
using namespace std;

int buyWater(int b, int c,int a)      //bƿ�� c���� aˮ 
{
	if(b<2&&c<3) return a;
	else{ 
		return buyWater(b%2+b/2+c/3,c%3+c/3+b/2,b/2+c/3+a); 
		//           b%2�����򲻱� �����1��ƿ b/2ƿˮ c/3��ˮ 
		//           c%3�����򲻱� �����1��� c/3��ˮ b/2ƿˮ 
		//           b/2+c/3+a ˮ 
	}
}

int main()
{
	int a;
	cin>>a;
	cout<<buyWater(a,a,a);
	return 0;
}
