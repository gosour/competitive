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
int pset[755];
void initSet(int n){
	REP2(i,1,n) pset[i] = i;
}

int findSet(int a){
	return (a == pset[a])? a : (pset[a] = findSet(pset[a]));
}

bool isSameSet(int a, int b){
	return findSet(a) == findSet(b);
}

void unionSet(int a, int b){
	pset[findSet(a)] = findSet(b);
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		priority_queue<pair<int,pair<int,int> > > EdgeList1, EdgeList2;
		REP(i,m){
			int x, y, d;
			scanf("%d %d %d",&x,&y,&d);
			EdgeList1.push(make_pair(-d,make_pair(x,y)));
			EdgeList2.push(make_pair(-d,make_pair(x,y)));
		}
		initSet(n);
		int best = 0,secondBest = 0;

		int count = 0;
		vector<pair<int,int> >bestEdges;
		while(!EdgeList1.empty()){
			pair<int, pair<int,int> > edge = EdgeList1.top(); EdgeList1.pop();
			if(!isSameSet(edge.second.first, edge.second.second)){
				count++;
				unionSet(edge.second.first, edge.second.second);
				best += (-edge.first);
				bestEdges.pb(edge.second);
			}
		}
		
		secondBest = INF;

		REP(i,bestEdges.size()){
			initSet(n);
			priority_queue<pair<int,pair<int,int> > > EdgeList(EdgeList2);
			int currentBest = 0;
			count = 0;
			while(!EdgeList.empty()){
				pair<int, pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
				if(edge.second.first == bestEdges[i].first && edge.second.second == bestEdges[i].second) continue;
				if(!isSameSet(edge.second.first, edge.second.second)){
					unionSet(edge.second.first, edge.second.second);
					currentBest += (-edge.first);
					count++;
				}
			}
			if(count == n-1){
				secondBest = min(currentBest,secondBest);
			}
		}
		if(secondBest == INF)
			secondBest = best;
		cout<<best<<" "<<secondBest<<endl;
	}	
}