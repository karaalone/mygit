#include<stdio.h>
int fibo(int n) 
{   int f;
    if(n==1||n==2) f=1;
    else if(n>2) f=fibo(n-1)+fibo(n-2);
    return f;
}
int main()
{   int i, m;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {  printf("%d\n",fibo(m));
	}
	return 0;
}
