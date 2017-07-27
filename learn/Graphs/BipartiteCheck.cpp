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

int color[10005]; //0 no color, 1 red 2 black
vector< vector<int> > adjList;

bool isBipartite(int s){
	queue<int> st;
	st.push(s);
	color[s] = 1;
	bool ans = true;
	while(!st.empty()){
		int u = st.front();
		int c = (color[u] == 1)? 2: 1;
		st.pop();
		REP(i,adjList[u].size()){
			int v = adjList[u][i];
			if(color[v] == 0){
				st.push(v);
				color[v] = c;
			}
			else if(color[v] == c) continue;
			else {
				ans = false;
			}
		}
	}
	return ans;
}

int main(){
	//Bipartite if two colorable
	int n,m; cin>>n>>m; 
	adjList.resize(n+1);
	memset(color,0,sizeof(color));
	REP(i,m){
		int a, b; cin>>a>>b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	cout<<isBipartite(1);
}