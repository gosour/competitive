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
vector< vector<int> > adjacencyList;
map<string, int> dict;
map<int, string> oppDict;
int dist[1005];
int parent[1005];
int n;

bool bfs(string s, string d){
	memset(dist, 0xff, sizeof(dist));
	memset(parent, 0xff, sizeof(parent));
	if(s == d){ cout<<s<<endl; return true;}
	queue<int> q;
	if(dict.find(s) == dict.end()) return false;
	if(dict.find(d) == dict.end()) return false;
	int s_idx = dict[s];
	int d_idx = dict[d];
	q.push(s_idx);
	dist[s_idx] = 0;
	bool found = false;
	while(!q.empty() && !found){
		int u = q.front(); q.pop();
		// DEBUG(oppDict[u]);
		REP(i,adjacencyList[u].size()){
			int v = adjacencyList[u][i];
			if(dist[v] < 0 ){
				// DEBUG(oppDict[v]);
				dist[v] = dist[u] + 1;
				parent[v] = u;
				if(d_idx == v){
					found = true; break;
				}
				q.push(v);
			}
		}
	}

	if(!found) return false;
	vector<int> ans;
	int v = d_idx;
	while(parent[v] >= 0){
		ans.pb(v);
		v = parent[v];
	}
	ans.pb(v);
	int i=0;
	for(i=ans.size()-1;i>0;i--){
		cout<<oppDict[ans[i]]<<" "<<oppDict[ans[i-1]]<<endl;
		// cout<<oppDict[ans[i]]<<" ";
	}
	// cout<<endl;
	return true;
}

int main(){
	bool first = true;
	while(scanf("%d",&n) != EOF){
		getchar();
		int count = 0;
		adjacencyList.clear();adjacencyList.resize(1005);
		dict.clear(); oppDict.clear();
		REP(i,n){
			string u, v;
			cin>>u>>v;
			if(dict.find(u) == dict.end()) {
				dict[u] = count;
				oppDict[count++] = u;
			}
			if(dict.find(v) == dict.end()) {
				dict[v] = count;
				oppDict[count++] = v; 
			}
			adjacencyList[dict[u]].pb(dict[v]);
			adjacencyList[dict[v]].pb(dict[u]);
		}
		getchar();
		string line;
		if(first) first  = false;
		else cout<<endl;
		while(getline(cin,line) && line.length() > 0){
			string u, v;
			istringstream ss(line);
			ss>>u>>v;
			bool ans = bfs(u,v);
			if(!ans) cout<<"No route"<<endl;
		}
	}	
}