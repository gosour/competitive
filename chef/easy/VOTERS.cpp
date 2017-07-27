#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<bitset>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<utility>
#include<iterator>

using namespace std;
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define SQR(n)                ( (n) * (n) )
const int INF = 1<<29;


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back

typedef vector<int> vi;

int main(){
	int arr1[50005] = {};
	int arr2[50005] = {};
	int arr3[50005] = {};
	int n1,n2,n3; cin>>n1>>n2>>n3;
	vector<int> ans;
	REP(i,n1){
		cin>>arr1[i];
	}
	sort(arr1,arr1+n1);
	REP(i,n2){
		cin>>arr2[i];
	}
	sort(arr2,arr2+n2);
	REP(i,n3){
		cin>>arr3[i];
	}
	sort(arr3,arr3+n3);

	int i=0,j=0,k=0;
	while(i<n1 && j<n2 && k<n3){
		int mn = min(arr1[i],min(arr2[j],arr3[k]));
	
		if(mn == arr1[i] && mn == arr2[j] && mn == arr3[k]){
			ans.pb(arr1[i]);
			i++;j++;k++;
		}
		else if(mn == arr1[i] && mn ==arr2[j]){
			ans.pb(arr1[i]);
			i++;j++;
		}
		else if(mn == arr2[j] && mn == arr3[k]){
			ans.pb(arr2[j]);
			j++; k++;
		}else if(mn == arr1[i] && mn==arr3[k]){
			ans.pb(arr1[i]);
			i++; k++;
		}else{
			if(mn == arr1[i]) i++;
			if(mn == arr2[j]) j++;
			if(mn == arr3[k]) k++;
		}

	}
	while(i<n1 && j<n2){
		if(arr1[i] == arr2[j]){
			ans.pb(arr1[i]); i++; j++; 
		}
		if(arr1[i] < arr2[j]) i++;
		if(arr1[i] > arr2[j]) j++;
	}
	while(i<n1 && k<n3){
		if(arr1[i] == arr3[k]){
			ans.pb(arr1[i]); i++; k++; 
		}
		if(arr1[i] < arr3[k]) i++;
		if(arr1[i] > arr3[k]) k++;
	}
	while(j<n2 && k<n3){
		if(arr2[j] == arr3[k]){
			ans.pb(arr2[j]); j++; k++; 
		}
		if(arr2[i] < arr3[k]) j++;
		if(arr2[i] > arr3[k]) k++;
	}

	cout<<ans.size()<<endl;
	REP(i,ans.size()){
		cout<<ans[i]<<endl;
	}
}