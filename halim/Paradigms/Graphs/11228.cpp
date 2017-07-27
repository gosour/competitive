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
int n, r;
int pset[1005];
struct Point{
	int x, y;
};

priority_queue< pair<double,pair<int,int> > > EdgeList;

void initSet(){
	REP(i,n) pset[i] = i;
}

int findSet(int a){
	return (pset[a] == a)? a : (pset[a] = findSet(pset[a]));
}

bool isSameSet(int a, int b){
	return findSet(a) == findSet(b);
}

void unionSet(int a , int b){
	pset[findSet(a)] = findSet(b);
}

Point points[1005];
int main(){
	int tests; scanf("%d",&tests);
	REP(t,tests){
		scanf("%d %d",&n,&r);
		REP(i,n){
			scanf("%d %d",&points[i].x,&points[i].y);
		}

		initSet();
		REP(i,n-1){
			REP2(j,i+1,n-1){
				double d = sqrt(SQR(points[i].x - points[j].x) + SQR(points[i].y - points[j].y));
				if(d <= r){
					unionSet(i,j);
				}
				EdgeList.push(make_pair(-d,make_pair(i,j)));
			}
		}
		int stateCount = 0;
		REP(i,n) if(pset[i] == i) stateCount++;
		initSet();
		double roadDist = 0, railDist = 0;
		while(!EdgeList.empty()){
			pair<double, pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
			if(!isSameSet(edge.second.first,edge.second.second)){
				if((-edge.first) <= r) roadDist += (-edge.first);
				else railDist += (-edge.first);
				unionSet(edge.second.first,edge.second.second);
			}	
		}

		cout<<"Case #"<<t+1<<": "<<stateCount<<" "<<(int)(roadDist+0.5)<<" "<<(int)(railDist+0.5)<<endl;
	}	
}