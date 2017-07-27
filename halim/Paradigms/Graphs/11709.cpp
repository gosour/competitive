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
#define CLR(a) memset((a), 0,sizeof((a)));
typedef vector<int> vi;
int p,t;
map<string,int> nameDict;
map<int, string> oppNameDict;
vector< vector<int> > adjacencyList;

int dfs_num[1001];
int dfs_low[1001];
int visited[1001];
bool instack[1001];
stack<int> dfs_stack;
int dfsCounter;
int sscCounter;

void dfs(int node){
	dfs_low[node] = dfs_num[node] = dfsCounter++;
	dfs_stack.push(node);
	instack[node] = true;
	visited[node] = 1;
	REP(i,adjacencyList[node].size()){
		int v = adjacencyList[node][i];
		if(!visited[v]){
			dfs(v);
			dfs_low[node] = min(dfs_low[node],dfs_low[v]);
		}
		else if(instack[v]){
			dfs_low[node] = min(dfs_low[node], dfs_num[v]);
		}
	}

	if(dfs_num[node] == dfs_low[node]){
		sscCounter++;
		while(!dfs_stack.empty() && dfs_stack.top() != node){
			instack[dfs_stack.top()] = false;
			dfs_stack.pop();
		}
		instack[dfs_stack.top()] = false;
		dfs_stack.pop();
	}
}


int main(){
	while(1){
		cin>>p>>t;
		if(p==0 && t==0) break;
		// DEBUG(p); DEBUG(t);
		getchar();
		nameDict.clear(); oppNameDict.clear();
		REP(i,p){
			string s;
			getline(cin,s);
			nameDict.insert(make_pair(s,i));
			oppNameDict.insert(make_pair(i,s));
		}
		adjacencyList.clear(); adjacencyList.resize(p);
		REP(i,t){
			string s1, s2;
			getline(cin,s1);
			getline(cin,s2);
			adjacencyList[nameDict[s1]].pb(nameDict[s2]);
		}

		// REP(i,p){
		// 	cout<<oppNameDict[i]<<" : ";
		// 	REP(j,adjacencyList[i].size()){
		// 		cout<<oppNameDict[adjacencyList[i][j]]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		dfsCounter = 0;
		sscCounter = 0;
		CLR(dfs_low); CLR(dfs_num); CLR(visited); CLR(instack);
		while(!dfs_stack.empty()) dfs_stack.pop();
		REP(i,p){
			if(!visited[i]) dfs(i);
		}
		cout<<sscCounter<<endl;
	}
}