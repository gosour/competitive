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

vector<int> dist(V,INF); dist[s] = 0;
vector<int> parent(V,-1); 

int main(){

	int s;
	priority_queue<pair<int,int> , vector<int,int>, greater<pair<int,int> > pq; //min heap
	pq.push(make_pair(0,s)); 

	while(!pq.empty()){
		pair<int,int> top = pq.top(); pq.pop();
		int d = top.first, u = top.second;
		if(d == dist[u]){
			for(int i=0;i<adjList[u].size();i++){
				int v = adjList[u][i].first;
				int w = adjList[u][i].second;
				if(dist[u] + w < dist[w]){
					dist[v] = dist[u] + w;
					pq.push(make_pair(dist[v],v));
					parent[v] = u;
				}
			}
		}
	}
}