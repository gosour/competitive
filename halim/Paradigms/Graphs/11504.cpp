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
int visited[100001];
stack<int> topology;

void dfs(int node){
	visited[node] = 1;
	REP(i,adjacencyList[node].size()){
		int v = adjacencyList[node][i];
		if(!visited[v]) dfs(v);
	}
	topology.push(node);
}

int main(){
	int tests; scanf("%d",&tests);
	REP(i,tests){
		int n,m;
		scanf("%d %d",&n,&m);
		adjacencyList.clear(); adjacencyList.resize(n+1);
		REP(j,m){
			int x,y;
			scanf("%d %d",&x,&y);
			adjacencyList[x].pb(y);
		}

		// REP2(i,1,n){
		// 	cout<<i<<" : ";
		// 	REP(j,adjacencyList[i].size()){
		// 		cout<<adjacencyList[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		int count = 0;
		memset(visited,0,sizeof(visited));
		while(!topology.empty()) topology.pop();

		REP2(i,1,n){
			if(!visited[i]) {
				dfs(i);
			}
		}
		memset(visited,0,sizeof(visited));
		while(!topology.empty()){
			int node = topology.top(); topology.pop();
			if(!visited[node]){
				count++;
				dfs(node); 
			}
		}
		cout<<count<<endl;
	}
}