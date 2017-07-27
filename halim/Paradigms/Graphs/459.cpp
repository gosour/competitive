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
vector<vector<int> > graph;
int visited[30];
int totalCount;
void dfs(int node){
	visited[node] = 1;
	for(int i = 0; i< graph[node].size();i++){
		if(!visited[graph[node][i]])
			dfs(graph[node][i]);
	}
}

int main(){
	int N;
	scanf("%d",&N); getchar(); getchar();
	while(N--){
		char c = getchar();
		getchar();
		totalCount = (int)c-(int)'A' + 1;
		graph.clear();
		graph.resize(totalCount);
		char s[3];
		while(gets(s)){
			if(strlen(s) == 0) break;
			// DEBUG(s);
			int a =  (int)s[0] - (int)'A';
			// DEBUG(a);
			int b = (int)s[1] - (int)'A';
			// DEBUG(b);
			graph[a].pb(b);
			graph[b].pb(a);
		}

		// for(int i=0;i<totalCount;i++){
		// 	cout<<"i:: ";
		// 	for(int j=0;j<graph[i].size();j++){
		// 		cout<<graph[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }


		memset(visited, 0, sizeof(visited));
		int connectedComponents = 0;
		for(int i=0;i<totalCount;i++){
			if(!visited[i]){
				connectedComponents++;
				dfs(i);
			}	
		}
		cout<<connectedComponents<<endl;
		if(N>=1) cout<<endl;
	}	
}