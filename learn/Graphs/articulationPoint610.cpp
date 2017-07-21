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
int n,m;
vector< vector<int> > adjList;
bool visited[1005];
int dfs_num[1005];
int dfs_low[1005];
int dfsCounter = 1;
vector<pair<int,int> > ans;

void dfs(int u, int p){
	visited[u] = true;
	dfs_num[u] = dfs_low[u] = dfsCounter++;
	REP(i,adjList[u].size()){
		int v = adjList[u][i];
		if(v == p) continue;
		if(!visited[v]){
			dfs(v);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);

		if(dfs_num[u] < dfs_low[v]) {
			ans.pb(make_pair(u,v));
			ans.pb(make_pair(v,u));
		}else{
			ans.pb(make_pair(u,v));
		}
	}

}

int main(){
	while(cin>>n>>m && n!=0){
		adjList.clear();
		adjList.resize(n+1);
		memset(visited,0,sizeof(visited));
		memset(dfs_num,0,sizeof(dfs_num));
		memset(dfs_low,0,sizeof(dfs_low));
		dfsCounter = 1;
		ans.clear();

		REP(i,m){
			int a,b; cin>>a>>b;
			adjList[a].pb(b);
		}

		dfs(1,0);
		sort(ans.begin(),ans.end());
		REP(i,ans.size()){
			cout<<ans[i].first<<" "<<ans.second<<endl;
		}
	}
}
