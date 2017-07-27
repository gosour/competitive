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
vector<vi> adjacencyList;
int visited[205];
int color[205];
int v,e; 
int bfs(int p){
	memset(color,0xff,sizeof(color));
	int total = 0;
	int countBlack = 1;
	queue<int> q;
	q.push(p);
	visited[p] = 1;
	color[p] = 1;
	while(!q.empty()){
		int parent = q.front(); q.pop();
		total++;
		REP(i,adjacencyList[parent].size()){
			int u = adjacencyList[parent][i];
			if(!visited[u]){
				visited[u] = 1;
				color[u] = 1 - color[parent];
				if(color[u]) countBlack++;
				q.push(u);
			}
			else if(color[parent] == color[u]){
				return -1;
			}
		}
	}
	if(total == 1) return 1;
	return min(total-countBlack , countBlack);
}
int main(){
	int tests; scanf("%d",&tests);
	while(tests--){
		scanf("%d %d",&v,&e);
		adjacencyList.clear(); adjacencyList.resize(v);
		REP(i,e){
			int a,b; scanf("%d %d",&a,&b);
			adjacencyList[a].pb(b);
			adjacencyList[b].pb(a);
		}
		memset(visited,0,sizeof(visited));
		int ans = 0;
		REP(i,v){
			if(!visited[i]){
				int temp = bfs(i);
				if(temp < 0) {ans = -1; break;}
				else ans += temp;
			}
		}
		cout<<ans<<endl;
	}	
}