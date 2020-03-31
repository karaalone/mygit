#include  <iostream> 
#include<iomanip> 
using  namespace  std; 
void  swap1(float  *a,  float  *b) 
{ 
	float c;
	c=*b;
	*b=*a;
	*a=c;
} 


void  swap2(float  &a,  float  &b) 
{ 
	float c;
	c=b;
	b=a;
	a=c;
} 


int  main() 
{ 
        float  m,n; 
        cin>>m>>n; 
        swap1(&m,&n); 
        cout<<fixed<<setprecision(2)<<m<<"  "<<n<<endl; 
        swap2(m,n); 
        cout<<fixed<<setprecision(2)<<m<<"  "<<n<<endl; 
        cin>>m; 
}