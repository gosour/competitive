#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int t; cin>>t;
	vector<int>arr; arr.reserve(t);
	while(t--){
		int temp; cin>>temp; arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for(int i=0;i<arr.size();i++) cout<<arr[i]<<endl;
}