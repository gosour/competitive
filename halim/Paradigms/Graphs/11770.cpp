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
#define CLR(a) memset((a),0,sizeof(a))
typedef vector<int> vi;
int n,m;
vector< vector<int> > adjacencyList;
stack<int> topological;
int visited[10005];

void dfs(int node){
	visited[node] = 1;
	for(int i=0;i<adjacencyList[node].size();i++){
		int v = adjacencyList[node][i];
		if(!visited[v]) dfs(v);
	}
	topological.push(node);
}

int main(){
	int T; scanf("%d",&T);
	REP2(t,1,T){
		scanf("%d %d",&n,&m);
		adjacencyList.clear(); adjacencyList.resize(n+1);
		REP(i,m){
			int x, y;
			scanf("%d %d",&x,&y);
			adjacencyList[x].pb(y);
		}

		CLR(visited); 
		while(!topological.empty()) topological.pop();

		REP2(i,1,n){
			if(!visited[i]) dfs(i);
		}
		CLR(visited);
		int counter = 0;
		while(!topological.empty()){
			int x = topological.top(); topological.pop();
			if(!visited[x]){
				dfs(x);
				counter++;
			}
		}
		cout<<"Case "<<t<<": "<<counter<<endl;
	}	
}