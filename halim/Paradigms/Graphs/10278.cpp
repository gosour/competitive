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
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int f,intersections;
vector<vector<ii> >AdjacencyList;
vi firestations;
int dist[501];
void dijkstra(){
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	REP2(i,1,intersections){
		pq.push(make_pair(dist[i],i));
		// cout<<dist[i]<<" "<<i<<endl;
	}

	while(!pq.empty()){
		pair<int,int> node = pq.top(); pq.pop();
		int u = node.second, d = node.first;
		// DEBUG(u);
		if(dist[u] != d) continue; //Ignore redundant
		REP(i,AdjacencyList[u].size()){
			int v = AdjacencyList[u][i].second;
			int w = AdjacencyList[u][i].first;
			// cout<<": "<<v<<" "<<w<<endl;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
	int maxStep = -1;
	int u = 1;
	REP2(i,1,intersections){
		// cout<<i<<" "<<dist[i]<<endl;
		if(maxStep < dist[i]){
			maxStep = dist[i];
			u = i;
		}
	}
	cout<<u<<endl;
}

int main(){
	int tests; scanf("%d",&tests);
	int t = 0;
	while(tests--){
		scanf("%d %d",&f,&intersections);
		firestations.clear();
		REP2(i,1,intersections) dist[i] = INF;
		DEBUG(f); DEBUG()
		REP(i,f){
			int temp; scanf("%d",&temp); firestations.pb(temp);
			dist[temp] = 0;
		}
		AdjacencyList.clear(); AdjacencyList.resize(intersections+1);
		REP(i,intersections){
			int x,y,c;
			scanf("%d %d %d",&x,&y,&c);
			AdjacencyList[x].pb(ii(c,y));
			AdjacencyList[y].pb(ii(c,x));
		}
		if(t++ != 0) cout<<endl;
		dijkstra();
	}	
}