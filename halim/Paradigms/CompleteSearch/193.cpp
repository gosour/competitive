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
int visited[101];
int answer[101];
int graph[101][101];
int maxLen;
int n,k;

bool check(int node){
	/*Can I color this node black*/
	cout<<"Can I color "<<node<<" black"<<endl;
	REP2(i,1,n){
		cout<<"graph[n][i]: "<<graph[n][i]<<" visited[i]: "<<visited[i]<<endl;
		if(graph[n][i] && (visited[i]==1)){
			cout<<node<<" "<<i<<endl;
			return false;
		}
	}
	return true;
}

void colorFill(int node){
	if(node > n){
		int len = 0;
		REP2(i,1,n){
			if(visited[i] == 1)  len++;
			cout<<visited[i]<<" ";
		}
		cout<<endl;

		if(len>maxLen){
			maxLen = len;
			memcpy(answer, visited, n*sizeof(int));
		}
	}else{
		visited[node] = 2; //Set white;
		colorFill(node+1);
		if(check(node)){
			visited[node] = 1;
			colorFill(node+1);
		}
		visited[node] = 0;
	}


}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>k;
		memset(visited,0,101*sizeof(int));
		memset(graph,0,101*101*sizeof(int));

		REP(i,k){
			int x,y; cin>>x>>y;
			graph[x][y] = 1;
			graph[y][x] = 1;
		}
		
		DEBUG(graph[3][5]);
		maxLen = 0;
		colorFill(1);
		cout<<maxLen<<endl;
		REP2(i,1,n){
			if(answer[i] == 1) cout<<i<<" ";
		}
		cout<<endl;
	}	
}