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
typedef long long ll;

const int N = 100005;
int MOD = 1000000007;
vector< vector<int> > edges;
int dp[N][2];

int solve(int v, int p, int isAlly){
	// DEBUG(v);
	if(dp[v][isAlly] >= 0) return dp[v][isAlly];
	int totalWays = 1, allDiff = 1, numChild = 0;
	for(int i=0;i<edges[v].size();i++){
		int w = edges[v][i];
		// DEBUG(u); DEBUG(p);
		if(w == p) {
			continue;
		}
		numChild++;
		totalWays = (int)((totalWays * (ll)(solve(w, v, 1) + solve(w, v, 0))) % MOD);
    	allDiff = (int)((allDiff * (ll)(solve(w, v, 0))) % MOD);
    }
	if(numChild == 0 && isAlly==0){
		dp[v][isAlly] = 0; //A leaf that does not have an ally! 0 ways man!
	}
	else if(isAlly == 0){
		//There has to be atleast one child alley
		dp[v][isAlly] = (totalWays-allDiff +  MOD) %MOD;
	}else{
		dp[v][isAlly] = totalWays; //Can be zero as well;
	}
	return dp[v][isAlly];

}

int main(){
	int n;
	cin>>n;
	edges.resize(n+2);
	REP2(i,1,n-1){
		int a,b; cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
		dp[i][0] = dp[i][1] = -1;
	}
	// REP2(i,1,n){
	// 	cout<<i<<" : ";
	// 	for(int j=0;j<edges[i].size();j++) cout<<edges[i][j]<<" ";
	// 	cout<<endl;
	// }
	dp[n][0] = dp[n][1] = -1;
	cout<<(2*solve(1,-1,0))%MOD<<endl;
}