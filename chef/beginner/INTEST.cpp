#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	int count = 0;
	int tmp;
	while(n--){
		cin>>tmp; if(tmp%k==0) count++;
	}
	cout<<count<<endl;
}