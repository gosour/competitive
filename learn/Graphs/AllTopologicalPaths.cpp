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
int indegree[1005];
vector< vector<int> > adjList;
vector<int> path;
int n;

void dfs(){
	bool toPrint = true;
	REP(i,n){
		if(!visited[i] && indegree[i] == 0){
			//This is a source
			path.pb(i);
			visited[i] = true;
			REP(j,adjList[i].size()){
				int v = adjList[i][j];
				indegree[v]--;
			}
			dfs();
			REP(j,adjList[i].size()){
				int v = adjList[i][j];
				indegree[v]++;
			}
			visited[i] = false;
			toPrint = false;
			path.pop_back();
		}
	}
	if(toPrint){
		REP(i,path.size()) cout<<path[i]<<" ";
		cout<<endl;
	}

}

int main(){
	cin>>n; int m; cin>>m;
	adjList.resize(n+1);
	memset(visited,0,sizeof(visited));
	memset(indegree,0,sizeof(indegree));
	REP(i,m){
		int a,b; cin>>a>>b;
		adjList[a].pb(b);
		indegree[b]++;
	}

	dfs();

}