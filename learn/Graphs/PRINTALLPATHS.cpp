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
bool visited[1005];
vector< vector<int> > adjList;
vector<int> path;

void dfs(int u, int s, int d){
	path.pb(u);
	// DEBUG(u);
	// DEBUG(d);
	if(u == d) {
		REP(i,path.size()){
			cout<<path[i]<<" ";
		}		
		cout<<endl;
	}
	visited[u] = true;
	REP(i,adjList[u].size()){
		int v = adjList[u][i];
		if(!visited[v])
			dfs(v,s,d);
	}
	visited[u] = false;
	path.pop_back();
}

int main(){
	int n; cin>>n; int m; cin>>m;
	int s,d;
	cin>>s>>d;
	adjList.resize(n+1);
	memset(visited,0,sizeof(visited));
	REP(i,m){
		int a,b; cin>>a>>b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}

	dfs(s,s,d);

}