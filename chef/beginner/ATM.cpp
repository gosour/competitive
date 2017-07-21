#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int required; float balance;
	cin>>required>>balance;
	if(required%5 !=0 || required > (balance-0.5)) {printf("%.2f\n", balance); return 0;}
	else balance = balance - required - 0.5;
	printf("%.2f\n", balance);
}