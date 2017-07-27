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
int cityCount = 0;
map<string,int> cityMap;
map<int,string> oppCityMap;
int dist[1005];
int parent[1005];

void bfs(int source, int dest){
	memset(dist,0xff,sizeof(dist));
	memset(parent,0xff,sizeof(parent));
	queue<int> q;
	q.push(source);
	dist[source] = 0;
	bool found = false;
	while(!q.empty() && !found){
		int u = q.front(); q.pop();
		for(int i=0;i<adjacencyList[u].size();i++){
			int v = adjacencyList[u][i];
			if(dist[v] < 0){
				dist[v] = dist[u] + 1;
				parent[v] = u;
				if(dest == v){
					found = true;
					break;
				}
				q.push(v);
			}
		}
	}
	string ans = "";
	while(parent[dest] >=0){
		ans += oppCityMap[dest][0];
		dest = parent[dest];
	}
	ans += oppCityMap[dest][0];
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}

int main(){
	int tests; scanf("%d",&tests);
	REP(t,tests){
		int n,m;
		scanf("%d %d",&n,&m);
		adjacencyList.clear(); adjacencyList.resize(1005);
		cityMap.clear(); oppCityMap.clear();
		cityCount = 0;
		REP(i,n){
			string city1, city2;
			cin>>city1>>city2;
			if(cityMap.find(city1) == cityMap.end()){
				cityMap[city1] = cityCount;
				oppCityMap[cityCount++] = city1;
			}
			if(cityMap.find(city2) == cityMap.end()){
				cityMap[city2] = cityCount;
				oppCityMap[cityCount++] = city2;
			}
			adjacencyList[cityMap[city1]].pb(cityMap[city2]);
			adjacencyList[cityMap[city2]].pb(cityMap[city1]);
		}
		if(t>0) cout<<endl;
		REP(i,m){
			string sourceCity, destCity;
			cin>>sourceCity>>destCity;
			int source = cityMap[sourceCity];
			int dest = cityMap[destCity];
			bfs(source, dest);
		}
		string line; getline(cin,line); getline(cin,line);
	}	
}