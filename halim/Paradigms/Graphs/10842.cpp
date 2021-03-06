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
	REP(i,n) pset[i] = i;
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
	REP2(t,1,tests){
		int n,m;
		scanf("%d %d",&n,&m);
		priority_queue<pair<int,pair<int,int> > > EdgeList;
		initSet(n);
		REP(i,m){
			int u,v,d;
			scanf("%d %d %d",&u,&v,&d);
			EdgeList.push(make_pair(d,make_pair(u,v)));
		}
		int count = 0;
		bool answer = false;
		while(!EdgeList.empty()){
			pair<int,pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
			if(!isSameSet(edge.second.first, edge.second.second)){
				count++;
				if(count == n-1){
					cout<<"Case #"<<t<<": "<<edge.first<<endl;
					answer = true;
				}
				unionSet(edge.second.first, edge.second.second);
			}
		}
		if(!answer)
			cout<<"Case #"<<t<<": "<<2147383647<<endl;
	}
}