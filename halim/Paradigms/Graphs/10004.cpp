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
int main(){
	while(1){
		int n; scanf("%d",&n); 
		if(!n) break;
		adjacencyList.clear(); adjacencyList.resize(n+1);
		int l; scanf("%d",&l);
		REP(i,l){
			int u,v; scanf("%d %d",&u,&v);
			adjacencyList[u].pb(v);
			adjacencyList[v].pb(u);
		}
		vector<bool> visited; visited.resize(n+1,false);
		vector<int> color; color.resize(n+1,-1);
		queue<int> q;
		q.push(0);
		visited[0] = true;
		color[0] = 1;
		bool nonbipartite = false;
		while(!q.empty() && !nonbipartite){
			int u = q.front(); q.pop();
			REP(i,adjacencyList[u].size()){
				int v = adjacencyList[u][i];
				if(!visited[v]){
					visited[v] = true;
					color[v] = 1 - color[u];
					q.push(v);
				}
				else if(color[v] == color[u]){
					nonbipartite = true;
					break;
				}
			}
		}

		if(nonbipartite) cout<<"NOT BICOLORABLE."<<endl;
		else cout<<"BICOLORABLE."<<endl;
	}
}