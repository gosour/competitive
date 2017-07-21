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

vector<vector<pair<int,int > > adjList; //v -> (u,w)
int N;
int pSet[10005];

void initSet(){
	REP(i,N) pSet[i] = i;
}

int findSet(int a){
	return (a==pset[a])? a : pset[a] = findSet(pset[a]);
}

void MakeSet(int a, int b){
	pset[findSet(a)] = findSet(b);
}

bool isSameSet(int a, int b){
	return findSet(a) == findSet(b);
}

vector<pair<int,int> > MST;

void kruskals(){
	priority_queue<int, pair<int,int> > Q;
	REP(i,N){
		REP(j,adjList[i].size()){
			int v = adjList[i][j];
			Q.push(make_pair(-v.second, make_pair(i,v.first)));
		}
	}
	int mst_cost = 0;
	initSet();
	while(!Q.empty()){
		pair<int,pair<int,int> > edge = Q.front(); Q.pop();
		if(!findSet(edge.second.first, edge.second.second)){
			MakeSet(edge.second.first, edge.second.second);
			mst_cost += edge.first;
			MST.pb(edge.second);
		}
	}
}

int main(){
	
}