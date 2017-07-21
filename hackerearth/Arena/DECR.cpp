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
	int n; cin>>n;
	if(n==0) {
		cout<<"NO"<<endl;
		return 0;
	}
	int arr[10005];
	REP(i,n) cin>>arr[i];
	bool possible = true;
	int i = 0;
	while(i<n){
		// cout<<i<<" "<<arr[i]<<endl;
		if(arr[i] && i<n-1 && arr[i] != arr[i+1]){
			 possible = false;
			 break;
		}
		if(arr[i]) i+=2;
		else i++;
	}
	if(i == n+1) possible = false;

	if(possible) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}