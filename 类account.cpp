#include <iostream>
#include <iomanip>
using  namespace  std;

class Account
{
	public:
		void init(const char a[19], const char b[20], const char c[3], int d, double e);//���� 
		void deposit(double m);//��Ǯ 
		void withdraw(double n);//ȡǮ 
		void printmoney();
	private:
		char id[18], name[20], sex[2];
		double money, getMoney, takeMoney;
		int age, k;
};
void Account::init(const char a[19], const char b[20], const char c[3], int d,double e)
{
	int i=0;
	for(i=0;i<19;i++){
		id[i]=a[i];
	}
	for(i=0;b[i]!='\0';i++){
		name[i]=b[i];
	}
	sex[0]=c[0];
	age=d;
	double j=(int)(e*100);
	e*=100;
	if(j==e){
		money=e/100;
	}
	else {
		cout<<"������Ľ��Ϸ�\n"; 
		money=0;
	}
}
void Account::deposit(double m)
{
	double j=(int)(m*100);
	m*=100;
	if(j==m){
		getMoney=m/100;
		takeMoney=0;
	}
	else{
		cout<<"������Ľ��Ϸ�\n"; 
		getMoney=0;	
	}
}
void Account::withdraw(double n)
{
	double j=(int)(n*100);
	n*=100;
	if(j==n){
		takeMoney=n/100;
		getMoney=0;
	}
	else {
		cout<<"������Ľ��Ϸ�\n";
		takeMoney=0;
	}
	if(money<takeMoney){
		cout<<"���Ĵ�����\n"; 
	} 
}
void Account::printmoney()
{
	if(k<3&&money>takeMoney&&takeMoney!=0){
		money-=takeMoney;
		cout<<name<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<money<<endl; 
	}
	else if(k<3&&getMoney!=0){
		money+=getMoney;
		cout<<name<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<money<<endl; 
	}
	else{
		cout<<name<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<money<<endl; 
	}
}

int  main()
{
    Account  tom;
    tom.init("32020320011001876X", "Tom Black",  "��",  19,  2000.89);
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
    tom.deposit(89.471);//�����������Ľ��Ϸ�
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
    tom.deposit(10000);
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89
    tom.withdraw(10001);
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
    tom.withdraw(10000.123);//�����������Ľ��Ϸ�
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
    tom.withdraw(10000.9);//��������Ĵ�����
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
    tom.withdraw(100.220);//�����������Ľ��Ϸ� 
    Account  jerry;
    jerry.init("320203200910116569",  "Jerry Black",  "Ů",  11,  100.956);//�����������Ľ��Ϸ�
    jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00
}
