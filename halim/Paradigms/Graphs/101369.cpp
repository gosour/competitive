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
int s,p;
struct Point{
	int x,y;
};
Point points[505];
int pset[505];

void initSet(){
	REP2(i,1,p) pset[i] = i;
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
	int tests;
	scanf("%d",&tests);
	REP(t,tests){
		scanf("%d %d",&s,&p);
		REP(i,p){
			scanf("%d %d",&points[i+1].x, &points[i+1].y);
		}

		priority_queue<pair<double, pair<int,int> > > EdgeList;
		REP2(i,1,p-1){
			REP2(j,i+1,p){
				double d = sqrt(SQR(points[i].x - points[j].x) + SQR(points[i].y - points[j].y));
				EdgeList.push(make_pair(-d,make_pair(i,j)));
			}
		}

		initSet();
		int counter = 0;
		while(!EdgeList.empty()){
			pair<double, pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
			if(!isSameSet(edge.second.first, edge.second.second)){
				unionSet(edge.second.first, edge.second.second);
				counter++;
				if(counter >= (p-1) - (s-1)){
					printf("%0.2lf\n",-edge.first);
					break;
				}
			}
		}
	}	
}