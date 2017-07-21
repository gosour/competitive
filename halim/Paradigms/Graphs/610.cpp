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
vector< vector<int> > adjacencyList;
int parent[1005];
int dfs_num[1005];
int dfs_low[1005];
int visited[1005];
int dfsCount;
int n,m;
vector<pair<int,int> > answer;
void dfs(int node){
	visited[node] = 1;
	dfs_low[node] = dfs_num[node] = dfsCount++;
	int children = 0;
	for(int i=0;i<adjacencyList[node].size();i++){
		int v = adjacencyList[node][i];
		if(!visited[v]){
			children++;
			parent[v] = node;
			dfs(v);
			if(dfs_num[node] >= dfs_low[v]) answer.pb(make_pair(node,v));
			if(dfs_num[node] < dfs_low[v]) {
				answer.pb(make_pair(node,v));
				answer.pb(make_pair(v,node));
			}
			dfs_low[node] = min(dfs_low[node],dfs_low[v]);
		}
		else if(v != parent[node]){
			if(dfs_num[v] >= dfs_low[node]) answer.pb(make_pair(v,node));
			dfs_low[node] = min(dfs_low[node],dfs_num[v]);
		}
	}
}

bool myCompare(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main(){
	int num = 1;
	while(scanf("%d %d",&n,&m) && n!=0 && m!=0){
		adjacencyList.clear();
		adjacencyList.resize(n+1);
		REP(i,m){
			int u,v; scanf("%d %d",&u,&v);
			adjacencyList[u].pb(v);
			adjacencyList[v].pb(u);
		}
		memset(parent,0,sizeof(parent));
		memset(dfs_num,0,sizeof(dfs_num));
		memset(dfs_low,0,sizeof(dfs_low));
		memset(visited,0,sizeof(visited));
		dfsCount=1;
		cout<<num++<<endl;
		cout<<endl;
		answer.clear();
		dfs(1);
		sort(answer.begin(),answer.end(),myCompare);
		REP(i,answer.size())
			cout<<answer[i].first<<" "<<answer[i].second<<endl;
		cout<<"#"<<endl;
	}
}