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
int N, maxVal, maxTask;
vector<vector<int> > adjacencyList;
int visited[110];
int dependencyCount;

void dfs(int node){
	// DEBUG(node);
	visited[node] = 1;
	for(int i=0;i<adjacencyList[node].size();i++){
		if(!visited[adjacencyList[node][i]]){
			dfs(adjacencyList[node][i]);
			dependencyCount++;
		}
	}
}

int main(){
	while(scanf("%d",&N) && N!=0){
		adjacencyList.clear();
		adjacencyList.resize(N);
		REP(i,N){
			int k; scanf("%d",&k);
			REP(j,k){
				int temp; scanf("%d",&temp);
				adjacencyList[i].pb(temp-1);
			}
		}
		memset(visited,0, sizeof(visited));
		maxVal = 0; maxTask = 0;
		REP(i,N){
			dependencyCount = 0;
			if(!visited[i]) {
				dfs(i);
				if(dependencyCount > maxVal) {
					maxVal = dependencyCount;
					maxTask = i;
				}
			}
		}
		cout<<maxTask+1<<endl;
	}
}