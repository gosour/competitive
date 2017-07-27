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
#include<sstream>
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
vector<vector<int> > adjacencyList; 
int dist[10005];
int parent[10005];
int n;

int bfs(int source, int dest){
	memset(dist,0xff,sizeof(dist));
	memset(parent,0,sizeof(parent));
	if(source == dest) {cout<<source<<endl; return 1;}
	// DEBUG("start");
	queue<int> q;
	q.push(source);
	dist[source] = 0;
	bool found = false;
	while(!q.empty() && !found){
		int u = q.front(); q.pop();
		// DEBUG(u);
		REP(i,adjacencyList[u].size()){
			// DEBUG("HERE?");
			int v = adjacencyList[u][i];
			if(dist[v] < 0){
				parent[v] = u;
				dist[v] = dist[u]+1;
				if( v == dest){
					found = true; break;
				}
				q.push(v);
			}
		}
	}

	if(!found) return -1;
	int p = dest;
	vector<int> ans;
	while(parent[p] > 0){
		ans.pb(p);
		p = parent[p];
	}
	ans.pb(p);
	for(int i=ans.size()-1;i>0;i--) cout<<ans[i]<<" ";
	cout<<ans[0]<<endl;
	return 1;
}

int main(){
	while(1){
		if(!(cin>>n)) break;
		getchar();
		cout<<"-----"<<endl;
		adjacencyList.clear(); adjacencyList.resize(n+1);
		REP2(i,1,n){
			string line; getline(cin,line);
			istringstream ss(line);
			int u,v = 0; char c;
			ss>>u; ss>>c;
			while(ss>>v>>c){
				adjacencyList[u].pb(v);
			}
			if(u!=v && v!=0){
				adjacencyList[u].pb(v);
			}
		}
		int m; cin>>m;
		REP(i,m){
			int source, dest; cin>>source>>dest;
			int ans = bfs(source, dest);
			if(ans == -1) cout<<"connection impossible"<<endl;

		}
		// REP2(i,1,n){
		// 	cout<<i<<" : ";
		// 	REP(j,adjacencyList[i].size()) cout<<adjacencyList[i][j]<<" ";
		// 	cout<<endl;
		// }
	}
}