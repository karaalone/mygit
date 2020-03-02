#include<iostream>
using namespace std;

int main(){
    char b[8];
    int i, k, m, sum=0;
    for(i=0;i<8;i++){                   //i(行） b[i]-'1'(列） 
    	cin>>b[i];
		if(b[i]=='*')
			m=i;                         //第m行
    }
    for(i=0;i<8;i++){
		if(b[i] != '*'){
    		sum+=(b[i]-'1');
		}
	}
	k=28-sum;                           //第k个
    for(i=0;i<8;i++){
		if(b[i]!='*'){
			if(((k-(b[i]-'1')) == (m-i)) || ((k-(b[i]-'1')) == -(m-i))){   //斜率
				cout << "No Answer";
				break;
			}
		}
	}
	if(i==8)
		cout << k+1;
	return 0;		 	
}
