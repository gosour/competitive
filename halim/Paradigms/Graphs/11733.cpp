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
int n,m,a;
int pset[10001];
void initSet(){
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
	int tests; scanf("%d",&tests);
	REP(t,tests){
		scanf("%d %d %d",&n,&m,&a);
		initSet();
		priority_queue<pair<int, pair<int,int> > > EdgeList;

		REP(i,m){
			int x,y,c; scanf("%d %d %d",&x,&y,&c);
			if(t+1 == 11){
				cout<<x<<" + "<<y<<" + "<<c<<endl;
			}
			EdgeList.push(make_pair(-c,make_pair(x,y)));
		}
		int cost = 0;
		int vCount = 0;
		while(!EdgeList.empty()){
			pair<int, pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
			// cout<<edge.second.first<<" "<<edge.second.second<<" "<<edge.first<<endl;
			if(vCount >= n || ((-edge.first) >= a)) break;
			if(!isSameSet(edge.second.first, edge.second.second)){
				// DEBUG("YAY BSABY!");
				cost += (-edge.first);
				unionSet(edge.second.first,edge.second.second);
				vCount++;
			}
		}
		int airportCount = 0;
		REP2(i,1,n){
			if(i==pset[i]) {
				airportCount++;
				cost += a;
			}
		}

		cout<<"Case #"<<t+1<<": "<<cost<< " "<<airportCount<<endl;
	}
}