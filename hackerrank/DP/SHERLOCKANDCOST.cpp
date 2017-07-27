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
long long dp[100005][2] = {};
int arr[100005];

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		REP(i,n) cin>>arr[i];
		REP2(i,1,n-1){
			dp[i][0] = max(dp[i-1][0] + 0, (arr[i-1]-1) + dp[i-1][1]);
			dp[i][1] = max(dp[i-1][1] + abs(arr[i-1]-arr[i]), (arr[i]-1) + dp[i-1][0]);
			// cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
	}
}