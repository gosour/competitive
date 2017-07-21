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
int m,n;
int pset[200005];
void initSet(){
	REP(i,m) pset[i] = i; 
}

int findSet(int a){
	return (pset[a] == a)? a : (pset[a] = findSet(pset[a]));
}

bool isSameSet(int a, int b){
	return findSet(a) == findSet(b);
}

void unionSet(int a, int b){
	pset[findSet(a)] = findSet(b);
}

priority_queue<pair<int,pair<int,int> > > EdgeList;
int main(){
	while(scanf("%d %d",&m,&n) && m!=0 && n!=0){
		int totalCost = 0;
		REP(i,n){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			totalCost += z;
			EdgeList.push(make_pair(-z,make_pair(x,y)));
		}

		int minCost = 0;
		initSet();
		while(!EdgeList.empty()){
			pair<int, pair<int, int> > edge = EdgeList.top(); EdgeList.pop();
			if(!isSameSet(edge.second.first,edge.second.second)){
				minCost += (-edge.first);
				unionSet(edge.second.first,edge.second.second);
			}
		}
		cout<<totalCost - minCost<<endl;	
	}
}