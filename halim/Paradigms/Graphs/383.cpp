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
int m,n,p;
map<string,int> warehouseMap;
vector< vector<int> > adjacencyList;
int costs[35];

int bfs(string a, string b){
	int target = warehouseMap[b];
	// DEBUG(target);
	queue<int> q;
	q.push(warehouseMap[a]);
	costs[warehouseMap[a]] = 0;
	bool targetFound = false;
	while(!q.empty() && !targetFound){
		int u = q.front(); q.pop();
		// DEBUG(u);
		for(int i=0;i<adjacencyList[u].size();i++){
			int v = adjacencyList[u][i];
			if(costs[v] < 0){
				// cout<<"Neighbor : "<<v<<endl;
				costs[v] = costs[u]  + 1;
				if(v == target){
					// DEBUG("HEY");
					targetFound = true; break;
				}
				q.push(v);
			}
		}
	}
	if(!targetFound) return -1;
	else return costs[target];
}


int main(){
	int T; scanf("%d",&T);
	cout<<"SHIPPING ROUTES OUTPUT"<<endl;
	REP(t,T){
		scanf("%d %d %d",&m,&n,&p);
		string warehouse;
		int count = 0;
		REP(i,m){
			cin>>warehouse;
			warehouseMap[warehouse] = count++;
		}
		adjacencyList.clear(); adjacencyList.resize(m);
		REP(i,n){
			string w1, w2;
			cin>>w1>>w2;
			adjacencyList[warehouseMap[w1]].pb(warehouseMap[w2]);
			adjacencyList[warehouseMap[w2]].pb(warehouseMap[w1]);
		}
		cout<<endl<<"DATA SET  "<<t+1<<endl<<endl;
		REP(i,p){
			int size; string w1, w2;
			cin>>size>>w1>>w2;
			int ans = 0;
			memset(costs,0xff,sizeof(costs));
			ans = bfs(w1,w2);
			if(ans == -1) cout<<"NO SHIPMENT POSSIBLE"<<endl;
			else{
				cout<<"$"<<ans*size*100<<endl;
			}
		}
	}
	cout<<endl<<"END OF OUTPUT"<<endl;
}