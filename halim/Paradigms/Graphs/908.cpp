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
typedef pair<int,int> ii;
typedef vector<int> vi;
vector<vi> adjacencyList;
int n;
priority_queue<pair<int,ii> > EdgeList;
int pset[100001];
void initSet(){
	REP(i,n+1) pset[i] = i;
}

int findSet(int a){
	return ((pset[a] == a)? a : (pset[a] = findSet(pset[a])));
}

bool isSameSet(int a, int b){
	if(findSet(a) == findSet(b)) return true;
	else return false;
}

void unionSet(int a, int b){
	pset[findSet(a)] = findSet(b);
}

void mst(){
	int mst_cost = 0;
	initSet();
	while(!EdgeList.empty()){
		pair<int,ii> front = EdgeList.top(); EdgeList.pop();
		if(!isSameSet(front.second.first,front.second.second)){
			// cout<<front.second.first<<" "<<front.second.second<<" "<<front.first<<endl;
			mst_cost += (-front.first);
			unionSet(front.second.first,front.second.second);
		}
	}
	cout<<mst_cost<<endl;
}

int main(){
	bool first = true;
	while(1){
		if(!(cin>>n)) break;
		int prevTotal = 0;
		int u,v,dist;
		REP(i,n-1){
			cin>>u>>v>>dist;
			prevTotal += dist;
		}
		if(!first) cout<<endl;
		else first = false;

		cout<<prevTotal<<endl;
		int k; cin>>k;
		REP(i,k){
			cin>>u>>v>>dist;
			EdgeList.push(make_pair(-dist,make_pair(u,v)));
		}
		int m; cin>>m;
		REP(i,m){
			cin>>u>>v>>dist;
			EdgeList.push(make_pair(-dist,make_pair(u,v)));
		}
		mst();
	}	
}