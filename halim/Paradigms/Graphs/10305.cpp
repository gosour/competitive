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
int n,m;
int visited[105];
vector< vector<int> > adjacencyList;
stack<int> dfs_stack;
bool instack[105];

void dfs(int node){
	visited[node] = 1;
	for(int i=0;i<adjacencyList[node].size();i++){
		if(!visited[adjacencyList[node][i]])
			dfs(adjacencyList[node][i]);
	}
	dfs_stack.push(node);
}

int main(){
	while(scanf("%d %d",&n,&m) && n!=0 && m!=0){
		adjacencyList.clear();
		adjacencyList.resize(n+1);
		REP(i,m){
			int a, b;
			scanf("%d %d",&a,&b);
			adjacencyList[a].pb(b);
		}

		memset(visited,0,sizeof(visited));
		memset(instack,0,sizeof(instack));
		REP2(i,1,n){
			if(!visited[i]){
				dfs(i);
			}
		}

		while(!dfs_stack.empty()){
			int v = dfs_stack.top(); dfs_stack.pop();
			if(dfs_stack.empty()) cout<<v;
			else cout<<v<<" ";
		}
		cout<<endl;
	}
}