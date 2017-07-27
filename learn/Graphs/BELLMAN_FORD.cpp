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


int main(){
	vector<int> dist(V,INF); dist[s] = 0;
	vector<int> parent(V,-1);

	REP(i,V){ //Relax all edges V-1 times O(VE)
		REP(u,0,V){
			REP(j, adjList[u].size()){
				int v = adjList[u][j].first;
				int w = adjList[u][j].second;
				//Relax(u,v,w)
				if(dist[v] < dist[u] + w){
					dist[v] = dist[u] + w;
					parent[v] = u;
				}
			}
		}
	}

	//Check negative edge cycles
	bool negativeCycles = false;
	REP(u,V){
		REP(j,adjList[u].size()){
			int v = adjList[u][j].first;
			int w = adjList[u][j].second;
			if(dist[v] > dist[u] + w) negativeCycles = true;
		}
	}
}