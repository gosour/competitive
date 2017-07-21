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
int depth[35];
int value[35];
int dp[35][1005];

vector<int> node[35][1005];

int main(){
	int t, w;
	bool first = true;
	while(scanf("%d %d",&t,&w)!=EOF){
		int k; scanf("%d",&k);
		depth[0] = value[0] = 0;
		REP(i,k) {
			scanf("%d %d",&depth[i+1],&value[i+1]);
			depth[i+1] = 3*w*depth[i+1];
		}

		memset(dp,0,sizeof(dp));
		REP(i,k) REP(j,t) node[i][j].clear();

		for(int i=1;i<=k;i++){
			for(int j=1;j<=t;j++){
				if(j>=depth[i] && dp[i-1][j-depth[i]] + value[i] > dp[i-1][j]){
					dp[i][j] = dp[i-1][j-depth[i]] + value[i] ;
					node[i][j] = node[i-1][j-depth[i]];
					node[i][j].pb(i);
				}
				else{
					dp[i][j] = dp[i-1][j];
					node[i][j] = node[i-1][j];
				}
			}
		}
		if(first) first = false;
		else cout<<endl;
		cout<<dp[k][t]<<endl;
		cout<<node[k][t].size()<<endl;
		for(int i=0;i<node[k][t].size();i++){
			int idx = node[k][t][i];
			if(idx!=0){
				cout<<depth[idx]/(3*w)<<" "<<value[idx]<<endl;
			}
		}
	}
}
