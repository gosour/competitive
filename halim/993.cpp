#include<string>
#include<bitset>
#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

const int prime[] = {2,5,7,9};

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		if(n<10){ cout<<n<<endl; continue;}
		string result = "";
		bool flag = false;
		while(n>1){
			flag = false;
			for(int i=2;i<=9;i++){
				if(n%i==0){result = result + to_string(i); n /= i; flag = true;}
			}
			if(flag == false && result=="") {cout<<-1<<endl; break;}
		}
	}
}

