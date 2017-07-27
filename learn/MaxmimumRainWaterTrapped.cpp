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
int arr[105];
int left[105];
int right[105];

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		
		left[0] = arr[0];
		right[n-1] = arr[n-1];
		REP2(i,1,n-1){
			left[i] = max(left[i-1], arr[i]);
		}
		for(int i=n-2;i>=0;i--){
			right[i] = max(right[i+1],arr[i]);
		}
		int water = 0;
		REP(i,n){
			water += min(left[i],right[i]) - arr[i];
		}
	}
}