#include<iostream>
using namespace std;

int main(){
    char b[8];
    int i, k, m, sum=0;
    for(i=0;i<8;i++){                   //i(�У� b[i]-'1'(�У� 
    	cin>>b[i];
		if(b[i]=='*')
			m=i;                         //��m��
    }
    for(i=0;i<8;i++){
		if(b[i] != '*'){
    		sum+=(b[i]-'1');
		}
	}
	k=28-sum;                           //��k��
    for(i=0;i<8;i++){
		if(b[i]!='*'){
			if(((k-(b[i]-'1')) == (m-i)) || ((k-(b[i]-'1')) == -(m-i))){   //б��
				cout << "No Answer";
				break;
			}
		}
	}
	if(i==8)
		cout << k+1;
	return 0;		 	
}
