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
int n;
vector< vector<int> > adjacencyList;
vector<pair<int,int> > answer;
int dfs_num[10005];
int dfs_low[10005];
int parent[10005];
int visited[10005];
int dfsCount;

void dfs(int node){
	// cout<<"node: "<<node<<endl;
	visited[node] = 1;
	dfs_num[node] = dfs_low[node] = dfsCount++;
	for(int i=0;i<adjacencyList[node].size();i++){
		int v = adjacencyList[node][i];
		if(!visited[v]){
			parent[v] = node;
			dfs(v);
			if(dfs_num[node] < dfs_low[v]) {
				answer.pb(make_pair(min(node,v), max(node,v)));
			}
			dfs_low[node] = min(dfs_low[node],dfs_low[v]);
		}else if(v != parent[node]){
			dfs_low[node] = min(dfs_low[node],dfs_num[v]);
		}	
	}

}

bool myCompare(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0){ cout<<"0 critical links"<<endl<<endl; continue;}
		adjacencyList.clear();
		adjacencyList.resize(n);
		REP(i,n){
			int k;
			scanf("%d",&k);
			int count;
			char s1[5], s2[5];
			scanf("%[^(](%d)",s1,&count,s2);
			// cout<<"count: "<<count<<endl;
			REP(j,count){
				int temp;
				scanf("%d",&temp);
				// DEBUG(temp);
				adjacencyList[k].pb(temp);
			}
		}
		answer.clear();
		memset(dfs_num,0,sizeof(dfs_num));
		memset(dfs_low,0,sizeof(dfs_low));
		memset(parent,0,sizeof(parent));
		memset(visited,0,sizeof(visited));
		dfsCount = 0;
		REP(i,n){
			if(!visited[i]) 
				dfs(i);
		}
		cout<<answer.size()<<" critical links"<<endl;
		sort(answer.begin(),answer.end(),myCompare);
		for(int i=0;i<answer.size();i++){
			cout<<answer[i].first << " - "<<answer[i].second<<endl;
		}
		cout<<endl;

	}	
}