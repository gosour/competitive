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
int arr[10005];

int main(){
	int t; cin>>t;
	while(t--){
		int dp[5][1005] = {};
		int n; cin>>n;
		int mn = INF,mx = -INF;
		REP(i,n) {
			cin>>arr[i];
			mn = min(mn,arr[i]);
			mx = max(mx,arr[i]);
		}
		REP(i,5)
			dp[i][mn-i] = 0;

		for(int j=0;j<5;j++){
			for(int i=mn-j+1;i<=mx;i++){
				int s = i;
				long long x,y,z;
				x = (s-1 >= mn-j)? 1 + dp[j][s-1] : INF;
				y = (s-2>=mn-j)? 1 + dp[j][s-2] : INF;
				z = (s-5>=mn-j)? 1+ dp[j][s-5] : INF;
				dp[j][s] = min(x,min(y,z));
				// cout<<j<<":"<<s<<" = "<<dp[j][s]<<endl;
			}
		}
		long long count[5] = {};
		REP(i,n){
			REP(j,5){
				count[j]+=dp[j][arr[i]];
			}
		}
		long long ans = INF;
		REP(i,5) ans = min(ans,count[i]);
		cout<<ans<<endl;

	}
}