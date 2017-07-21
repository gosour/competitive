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
int itemWeight[1005];
int itemValue[1005];
int dp[10005][35];
int main(){
	int tests; scanf("%d",&tests);
	while(tests--){
		int n; scanf("%d",&n);
		REP(i,n) scanf("%d %d",&itemValue[i+1],&itemWeight[i+1]);
		int totalValue = 0;
		int g; scanf("%d",&g);
		memset(dp,0,sizeof(dp));
	
		for(int i=1;i<=n;i++){
			for(int j=1;j<35;j++){
				// cout<<"dp[2][0]: "<<dp[2][0]<<endl;
				if(j>=itemWeight[i]){
					// cout<<"i: "<<i<<" j:"<<j<<" "<<dp[i-1][j-itemWeight[i]];
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-itemWeight[i]] + itemValue[i]);
				}
				else{
					// cout<<"i: "<<i<<" j:"<<j;
					dp[i][j] = dp[i-1][j];
				}
				// cout<<" current: "<<dp[i][j]<<endl;
			}
			// cout<<endl;
		}

		REP(i,g) {
			int personMax;
			scanf("%d",&personMax);
			// cout<<personMax<<" "<< dp[n][personMax]<<endl;
			totalValue += dp[n][personMax];
		}
		cout<<totalValue<<endl;
	}	
}