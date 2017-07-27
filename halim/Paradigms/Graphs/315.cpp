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
int N;
vector< vector<int> > adjacencyList;

int dfs_num[105];
int dfs_low[105];
int dfs_parent[105];
int visited[105];
int dfsNumberCounter = 0;
int articulation_vertex[105];
int rootChildren;
int dfsRoot;

void dfs(int node){
	visited[node] = 1;
	int children = 0;
	dfs_low[node] = dfs_num[node] = dfsNumberCounter++;
	for(int i=0;i<adjacencyList[node].size();i++){
		int v = adjacencyList[node][i];
		if(!visited[v]){
			children++;
			dfs_parent[v] = node;
			dfs(v);
			if(!dfs_parent[node] && children > 1)
				articulation_vertex[node] = 1;
			if(dfs_parent[node] && dfs_num[node] <= dfs_low[v])
				articulation_vertex[node] = 1;
			dfs_low[node] = min(dfs_low[node],dfs_low[v]);
		}
		else if(v != dfs_parent[node]){ //to not count the child to direct parent back edges
			dfs_low[node] = min(dfs_low[node],dfs_num[v]);
		}
	}
}

int main(){
	while(scanf("%d",&N) && N!=0){
		getchar();
		adjacencyList.clear();
		adjacencyList.resize(N+1);
		char s[10000];
		while(1){
			gets(s); 
			// puts(s);
			if(s[0] == '0') break;
			char *f = strtok(s," ");
			int k = atoi(f);
			f = strtok(NULL," ");
			while(f!=NULL){
				int temp = atoi(f);
				adjacencyList[k].pb(temp);
				adjacencyList[temp].pb(k);
				f = strtok(NULL," ");
			}

		}

		memset(dfs_num,0,sizeof(dfs_num));
		memset(dfs_low,0,sizeof(dfs_low));
		memset(articulation_vertex,0,sizeof(articulation_vertex));
		memset(dfs_parent,0,sizeof(dfs_parent));
		memset(visited,0,sizeof(visited));
		dfsNumberCounter = 1;

		// REP2(i,1,N){
		// 	cout<<i<<" : ";
		// 	REP(j,adjacencyList[i].size())
		// 		cout<<adjacencyList[i][j]<<" ";
		// 	cout<<endl;
		// }

		dfs(1);
		int count = 0;
		REP2(i,1,N){
			// cout<<dfs_num[i]<<" "<<dfs_low[i]<<" "<<articulation_vertex[i]<<endl;
			if(articulation_vertex[i]) {
				// cout<<i<<" ";
				count++;
			}
		}
		cout<<count<<endl;
	}	
}