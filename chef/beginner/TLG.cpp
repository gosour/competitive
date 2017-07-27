#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int t; cin>>t;
	int lead_person=1, lead_count=0;
	int sumA =0, sumB = 0;
	while(t--){
		int a, b;
		cin>>a>>b; 
		sumA += a;
		sumB += b;
		int lead = abs(sumA-sumB);
		if(lead > lead_count){
			lead_count = lead;
			lead_person = (sumA > sumB)? 1: 2;
		}
	}
	cout<<lead_person<<" "<<lead_count<<endl;
	return 0;
}