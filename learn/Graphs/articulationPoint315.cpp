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
int N;
vector< vector<int> > adjacencyList;
int dfs_num[105];
int dfs_low[105];
bool isChokePoint[105];
int chokepoints = 0;
int bridges = 0;
int dfsCounter = 1;

void dfs(int v,int p){
	dfs_num[v] = dfs_low[v]= dfsCounter++;
	int childCount = 0;
	REP(i,adjacencyList[v].size()){
		int u = adjacencyList[v][i];
		if(u == p) continue; //don't consider the parent again!
		childCount++;
		if(dfs_num[u] != 0){
			dfs_low[v] = min(dfs_low[v], dfs_num[u]);
		}
		else{
			dfs(u,v);
			dfs_low[v] = min(dfs_low[v], dfs_low[u]);
		}
		if(dfs_low[u] >= dfs_num[v]) isChokePoint[v] = true;
		if(dfs_low[u] >  dfs_num[v]) bridges++;
		// DEBUG(v);
		// DEBUG(u);
		// DEBUG(dfs_num[v]);
		// DEBUG(dfs_num[u]);
		// DEBUG(dfs_low[v]);
		// DEBUG(dfs_low[u]);
	}
	if(p == 0) {
		isChokePoint[v] = (childCount > 1);
	}
}

int main(){
	while(scanf("%d",&N) && N!=0){
		getchar();
		adjacencyList.clear();
		adjacencyList.resize(N+1);
		char s[10000];
		while(1){
			gets(s); 
			// puts(s);
			if(s[0] == '0') break;
			char *f = strtok(s," ");
			int k = atoi(f);
			f = strtok(NULL," ");
			while(f!=NULL){
				int temp = atoi(f);
				adjacencyList[k].pb(temp);
				adjacencyList[temp].pb(k);
				f = strtok(NULL," ");
			}
		}

		memset(dfs_num,0,sizeof(dfs_num));
		memset(dfs_low,0,sizeof(dfs_low));
		memset(isChokePoint,0,sizeof(isChokePoint));
		chokepoints = bridges = 0;
		dfsCounter = 1;
		dfs(1,0);

		REP2(i,1,N) if(isChokePoint[i]) {
			chokepoints++;
		}
		cout<<chokepoints<<endl;
		DEBUG(bridges);
	}
}