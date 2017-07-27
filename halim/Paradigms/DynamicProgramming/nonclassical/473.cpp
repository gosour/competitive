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
#define SQR(n)                ( n * n )
const int INF = 1<<29;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back
typedef vector<int> vi;
int dp[800][800][100];
int main(){
	int tests; cin>>tests;
	bool first = true;
	while(tests--){
		int n,t,m;
		cin>>n>>t>>m;		
		vi times;
		int temp; char comma;
		cin>>temp; times.pb(temp);
		REP(i,n-1){
			cin>>comma>>temp; times.pb(temp);
		}
		memset(dp,0,sizeof(dp));

		for(int i=0;i<n;i++){
			for(int j=0;j<=m;j++){
				for(int k=0;k<=t;k++){
					if(k<times[i])
						dp[i+1][j][k] = dp[i][j][k];
					else
						dp[i+1][j][k] = max(dp[i][j][k], 1 + dp[i][j][k-times[i]]);
					if(j>0)
						dp[i+1][j][k] = max(dp[i+1][j][k], 1 + dp[i][j-1][t-times[i]]);
				}
			}
			// cout<<dp[i+1][m][t]<<endl;
		}
		int r = 0;
		for (int i=0; i<=n; i++) {
            r=max(r, dp[i][m][0]);
        }
		if(first) first = false;
		else cout<<endl;
		cout<<r<<endl;

	}
}