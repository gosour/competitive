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
int n,m;
struct Point{
	int x, y;
};

Point points[760];
int pset[760];
bool alreadyPresent[1005];

void initSet(){
	REP2(i,1,n) pset[i] = i;
}

int findSet(int a){
	return (pset[a] == a)? a : (pset[a] = findSet(pset[a]));
}

bool isSameSet(int a, int b){
	return findSet(a) == findSet(b);
}

void UnionSet(int a, int b){
	pset[findSet(a)] = findSet(b);
}

bool myCompare(pair<int,pair<int,int> > a, pair<int, pair<int,int> > b){
	return (-a.first) < (-b.first);
}

int main(){
	int tests; scanf("%d",&tests);
	REP(t,tests){
		scanf("%d",&n);
		REP(i,n){
			scanf("%d %d",&points[i+1].x,&points[i+1].y);
		}
		scanf("%d",&m);
		memset(alreadyPresent,0,sizeof(alreadyPresent));
		initSet();

		REP(i,m){
			int city1, city2;
			scanf("%d %d",&city1, &city2);
			alreadyPresent[city1] = alreadyPresent[city2] = true;
			UnionSet(city1,city2);
		}

		priority_queue<pair<double, pair<int,int> > > EdgeList;

		REP2(i,1,n-1){
			REP2(j,i+1,n){
				double d = SQR(points[i].x - points[j].x)  + SQR(points[i].y - points[j].y);
				EdgeList.push(make_pair(-d,make_pair(i,j)));
			}
		}

		bool isPossible = false;
		if(t > 1 ) cout<<endl;
		while(!EdgeList.empty()){
			pair<double, pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
			if( !isSameSet(edge.second.first,edge.second.second)){
				isPossible = true;
				UnionSet(edge.second.first,edge.second.second);
				cout<<edge.second.first<<" "<<edge.second.second<<endl;
			}
		}

		if(!isPossible) cout<<"No new highways need."<<endl;

	}	
}