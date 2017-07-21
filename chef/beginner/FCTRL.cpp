#include<iostream>
#include<cstdio>

using namespace std;
int main()
{
	int t; cin>>t;
	while(t--){
		long n;cin>>n;
		long i=5,count=0;
		while(n>=i){
			count += n/i;
			i *=5;

		}
		cout<<count<<endl;
	}
}