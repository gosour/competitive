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
int E;
vector<vector<int> > adjacencyList;
int dist[2505];

void bfs(int source){
	memset(dist,0xff,sizeof(dist));
	queue<int> q;
	q.push(source);
	dist[source] = 0;
	int boomCounter = 0;
	int currentDist = 0;
	int tempCounter = 0;
	int first = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(currentDist != dist[u]){
			if(boomCounter < tempCounter){
				boomCounter = tempCounter;
				first = dist[u];
			}
			currentDist = dist[u];
			tempCounter = 0;
		}
		REP(i,adjacencyList[u].size()){
			int v = adjacencyList[u][i];
			if(dist[v] < 0){
				dist[v] = dist[u] + 1;
				tempCounter++;
				q.push(v);
			}
		}
	}

	if(first == 0) cout<<0<<endl;
	else{
		cout<<boomCounter<<" "<<first<<endl;
	}

}

int main(){
	scanf("%d",&E);
	adjacencyList.clear(); adjacencyList.resize(E);
	REP(i,E){
		int k; scanf("%d",&k);
		int u = i;
		REP(j,k){
			int v; scanf("%d",&v);
			adjacencyList[u].pb(v);
		}
	}	

	int T; scanf("%d",&T);
	REP(i,T){
		int source; scanf("%d",&source);
		bfs(source);
	}
}