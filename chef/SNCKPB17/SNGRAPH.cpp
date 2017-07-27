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
int n,m;
int degrees[100005];
int visited[100005];
int degCount[100005];

int cc = 0;
vector< vector<int> > adjList;

void dfs(int node){
	visited[node] = true;

	REP(i,adjList[node].size()){
		int u = adjList[node][i];
		if(!visited[u]) dfs(u);
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>m;
		adjList.clear();
		adjList.resize(n+1);
		memset(visited,0,sizeof(visited));
		memset(degrees,0,sizeof(degrees));
		memset(degCount,0,sizeof(degCount));

		REP(i,m){
			int a,b; cin>>a>>b;
			degrees[a]++;
			degrees[b]++;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}

		//Calculate connected components
		cc = 0;
		REP2(i,1,n){
			if(!visited[i]) {
				dfs(i);
				cc++;
			}
		}

		REP2(i,1,n){
			// DEBUG(degrees[i]);
			degCount[degrees[i]]++;
		}
		int initialEdges = cc-1;
		//0 -> cc-1
		//1 -> 
		int prev = cc-1;
		REP(i,n){
			// cout<<"Degree "<<i<<" "<<degCount[i]<<endl;
			if(i==0 || degCount[i] == 0){
				cout<<prev<<" ";
			}
			else{
				// DEBUG(i*degCount[i]);
				// DEBUG(m);
				int edges =  degCount[i];
				if(prev + edges < n)
					prev += edges;

				cout<<prev<<" ";
			}
		}
		cout<<endl;
	}
}