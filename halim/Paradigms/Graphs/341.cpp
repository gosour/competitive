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
bool visited[100];
int dist[100];
int parent[100];
vector< vector<pair<int,int> > > adjacencyList;

int main(){
	int n,t=1;
	while(scanf("%d",&n) && n!=0){
		adjacencyList.clear(); adjacencyList.resize(n+1);
		REP2(i,1,n){
			visited[i] = false;
			dist[i] = INF;
			parent[i] = INF;
			int no; scanf("%d",&no);
			REP(j,no){
				int intersection, dist;
				scanf("%d %d",&intersection,&dist);
				adjacencyList[i].pb(make_pair(dist,intersection));
			}
		}
		int source,dest; scanf("%d %d",&source, &dest);
		dist[source] = 0;
		priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
		q.push(make_pair(0,source));

		// REP2(i,1,n){
		// 	cout<<i<<" : ";
		// 	REP(j,adjacencyList[i].size()){
		// 		cout<<adjacencyList[i][j].second<<"("<<adjacencyList[i][j].first<<") ";
		// 	}
		// 	cout<<endl;
		// }

		while(!q.empty()){
			pair<int,int> top = q.top(); q.pop();
			// cout<<"Queue: "<<top.second<<" "<<top.first<<endl;
			if(top.first != dist[top.second]) continue;
			REP(i,adjacencyList[top.second].size()){
				pair<int,int> neighbor = adjacencyList[top.second][i];
				if(dist[neighbor.second] > neighbor.first + top.first){
					dist[neighbor.second] = neighbor.first + top.first;
					parent[neighbor.second] = top.second;
					q.push(make_pair(dist[neighbor.second],neighbor.second));
				}
			}
		}
		cout<<"Case "<<t++<<": Path =";
		int sum = dist[dest];
		vi ans;
		while(parent[dest] != INF){
			ans.pb(dest);
			dest = parent[dest];
		}
		ans.pb(source);
		for(int i=ans.size()-1;i>=0;i--){
			cout<<" "<<ans[i]; 
		}
		cout<<"; "<<sum<<" second delay"<<endl;
	}	
}