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
#define TONUM(a) ((int)(a) - (int)'A')
#define TOCHAR(a) (char)((char)(a) + 'A')
typedef vector<int> vi;
bool exists[30];
int visited[30];
vector< vector<int> > adjacencyList;
stack<int> dfs_stack;

void dfs(int node){
	visited[node] = 1;
	REP(i,adjacencyList[node].size()){
		int v = adjacencyList[node][i];
		if(!visited[v]) dfs(v);
	}
	dfs_stack.push(node);
}

int main(){
	while(1){
		string sprev,s;
		if(!(cin>>sprev)) break;
		adjacencyList.clear();
		adjacencyList.resize(30);
		memset(visited,0,sizeof(visited));
		memset(exists,0,sizeof(exists));
		while(1){
			cin>>s; if(s == "#") break;
			for(int i=0;i<s.length() && i<sprev.length();i++){
				if(s[i]!=sprev[i]){
					exists[TONUM(s[i])] = true;
					exists[TONUM(sprev[i])] = true;
					adjacencyList[TONUM(sprev[i])].pb(TONUM(s[i]));
					break;
				}
			}
			sprev = s;
		}
		REP(i,26){
			if(!visited[i] && exists[i]) dfs(i);
		}

		while(!dfs_stack.empty()){
			cout<<TOCHAR(dfs_stack.top());
			dfs_stack.pop();
		}
		cout<<endl;
	}
}