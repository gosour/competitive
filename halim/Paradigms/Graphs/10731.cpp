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
#define TONUM(a) ((int)(a) - 'A')
#define TOCHAR(a) ((char)((char)(a) + 'A'))
typedef vector<int> vi;
vector< vector<int> > adjacencyList;
int n;
vector<vector<int> > ans;
stack<int> dfs_stack;
int dfs_low[30];
int dfs_num[30];
int dfsCounter;
int visited[30];
int exists[30];
bool stackMember[30];

void dfs(int node){
	visited[node] = 1;
	dfs_low[node] = dfs_num[node] = dfsCounter++;
	dfs_stack.push(node);
	stackMember[node] = true;
	REP(i,adjacencyList[node].size()){
		int v = adjacencyList[node][i];
		if(!visited[v]){
			dfs(v);
			dfs_low[node] = min(dfs_low[node],dfs_low[v]);
		}
		else if(stackMember[v]){
			dfs_low[node] = min(dfs_low[node], dfs_num[v]);
		}
	}
	if(dfs_low[node] == dfs_num[node]){
		vector<int> tempVector;
		while(!dfs_stack.empty() && dfs_stack.top() != node){
			tempVector.pb(dfs_stack.top()); 
			stackMember[dfs_stack.top()] = false;
			dfs_stack.pop();
		}
		tempVector.pb(node);
		sort(tempVector.begin(),tempVector.end());
		ans.pb(tempVector);
		stackMember[node] = false;
		dfs_stack.pop();
	}
}

bool mycompare(vector<int> a, vector<int> b){
	if(a.size() && b.size()){
		return a[0] < b[0];
	}
	else{
		return a.size() < b.size();
	}
}

int main(){
	bool first = true;
	while(scanf("%d",&n) && n!=0){
		memset(exists,0,sizeof(exists));
		getchar();
		adjacencyList.clear();
		adjacencyList.resize(26);
		int size = 0;
		REP(i,n){
			char temp[5];
			REP(j,5){
				temp[j] = getchar(); getchar();
				// DEBUG(TONUM(temp[j]));
				// DEBUG(size);
				if(size	 < (int)TONUM(temp[j])) size = (int)TONUM(temp[j]);
				exists[(int)TONUM(temp[j])] = 1;
			}	
			char f = getchar(); getchar();
			REP(j,5){
				if(f == temp[j]) continue;
				adjacencyList[TONUM(temp[j])].pb(TONUM(f));
			}
		}
		size++;
		// REP(i,size){
		// 	cout<<TOCHAR(i)<<" : ";
		// 	REP(j,adjacencyList[i].size())
		// 		cout<<TOCHAR(adjacencyList[i][j])<<" ";
		// 	cout<<endl;			
		// }

		memset(dfs_num,0,sizeof(dfs_num));
		memset(dfs_low,0,sizeof(dfs_low));
		memset(visited,0,sizeof(visited));
		memset(visited,0,sizeof(stackMember));
		ans.clear();
		dfsCounter = 0;
		REP(i,size){
			if(!visited[i] && exists[i]) dfs(i);
		}

		if(first) first = false;
		else cout<<endl;
		sort(ans.begin(),ans.end(),mycompare);
		REP(i,ans.size()){
			cout<<TOCHAR(ans[i][0]);
			REP2(j,1,ans[i].size()-1)
				cout<<" "<<TOCHAR(ans[i][j]);
			cout<<endl;
		}
	}
}