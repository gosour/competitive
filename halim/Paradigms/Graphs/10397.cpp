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
struct Point{
	int x,y;
};
Point points[755];
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
	int n;
	while(scanf("%d",&n) !=EOF){
		REP(i,n){
			scanf("%d %d",&points[i+1].x,&points[i+1].y);
		}	
		priority_queue<pair<double,pair<int,int> > > EdgeList;
		REP2(i,1,n-1){
			REP2(j,i+1,n){	
				double d =  sqrt(SQR(points[i].x - points[j].x) + SQR(points[i].y - points[j].y));
				EdgeList.push(make_pair(-d,make_pair(i,j)));
			}
		}
		int m;
		scanf("%d",&m);
		initSet(n);
		REP(i,m){
			int u,v; scanf("%d %d",&u,&v);
			unionSet(u,v);
		}
		double length = 0;
		while(!EdgeList.empty()){
			pair<double,pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
			if(!isSameSet(edge.second.first,edge.second.second)){
				length += (-edge.first);
				unionSet(edge.second.first, edge.second.second);
			}
		}
		printf("%0.2lf\n",length);
	}
}