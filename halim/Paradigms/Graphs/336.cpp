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
int connectionCount;
int source, ttl;
map<int,int> nodeMap;
map<int,int> oppNodeMap;
vector< vector<int> > adjacencyList;
int dist[31];

int bfs(){
	queue<int> q;
	q.push(source);
	int ttlCount = 1;
	dist[source] = 0;
	bool noneed = false;
	while(!q.empty() && !noneed){
		int v = q.front();
		q.pop();
		REP(i,adjacencyList[v].size()){
			int u = adjacencyList[v][i];
			if(dist[u] < 0){
				dist[u] = dist[v] + 1;
				if(dist[u] > ttl){
					noneed = true;
					break;
				}
				else ttlCount++;
				q.push(u);
			}
		}
	}
	return nodeMap.size() - ttlCount;
}

int main(){
	int tests = 1;
	while(scanf("%d",&connectionCount) && connectionCount!=0){
		nodeMap.clear();
		adjacencyList.clear();
		adjacencyList.resize(31);
		int count = 0;
		REP(i,connectionCount){
			int a, b;
			scanf("%d %d",&a,&b);
			if(nodeMap.find(a) == nodeMap.end()){
				nodeMap[a] = count;
				oppNodeMap[count++] = a;
			}
			if(nodeMap.find(b) == nodeMap.end()){
				nodeMap[b] = count;
				oppNodeMap[count++] = b;
			}
			adjacencyList[nodeMap[a]].pb(nodeMap[b]);
			adjacencyList[nodeMap[b]].pb(nodeMap[a]);
		}
		// for(map<int,int>::iterator it = nodeMap.begin(); it!=nodeMap.end();it++){
		// 	cout<<it->first<<" : "<<it->second<<endl;
		// }
		while(scanf("%d %d",&source,&ttl) && (source != 0 || ttl != 0)){
			int sourceTemp = source;
			memset(dist,0xff,sizeof(dist));
			int ans;
			if(nodeMap.find(source) != nodeMap.end()){
				source = nodeMap[source];
				ans = bfs();
			}
			else{
				ans = nodeMap.size();
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", tests++,ans,sourceTemp,ttl);
		}	
	}
}