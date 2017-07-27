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

//A tree is given. Each node has certain value denoted in array C
//Find set of nodes that donot share an edge and sum of values of all nodes is maximized
const int N 100;
vi adj[N];
int dp1[N], dp2[N];
int c[N];

void dfs(int V, int pV){
	int sum1 = 0, sum2 = 0;
	for(auto v: adj[V]){
		if(p==pV) continue;
		dfs(v,V);
		sum1 += dp2[v]; //don't include child
		sum2 += max(dp1[v],dp2[v]);
	}
	dp1[v] = c[v]  + sum1;
	dp2[v] = sum2;
}

int main(){
	int n;
	cin>>n;

	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1,0);
	cout<<max(dp1[1],dp2[1])<<endl;
}