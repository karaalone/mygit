#include<stdio.h>
int main()
{
	int a[7][2], i, j, k, m, b[7];
	for(i=0;i<7;i++)
	    for(j=0;j<2;j++)
	        scanf("%d",&a[i][j]);
	for(i=0;i<7;i++)
	    b[i]=a[i][0]+a[i][1];   
    m=b[0];
    
    for(i=1;i<7;i++)
    {
    	if(b[i]>m)
    	{
    		m=b[i];
        	k=i;
		}
	}
	if(m>8)
	printf("%d",k+1); 
	else printf("0");
	return 0;
} 
