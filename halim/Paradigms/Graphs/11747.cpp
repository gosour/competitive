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
int n,m;
int pset[1001];
void initSet(){
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
	while(scanf("%d %d",&n,&m) && n){
		priority_queue<pair<int,pair<int,int> > > EdgeList;
		REP(i,m){
			int x,y,w;
			scanf("%d %d %d",&x,&y,&w);
			EdgeList.push(make_pair((-w),make_pair(x,y)));
		}
		initSet();
		vi weights;
		while(!EdgeList.empty()){
			pair<int, pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
			if(!isSameSet(edge.second.first, edge.second.second)){
				unionSet(edge.second.first, edge.second.second);
			}
			else{
				weights.pb(-(edge.first));
			}
		}
		sort(weights.begin(),weights.end());
		if(weights.size()){
			cout<<weights[0];
			REP2(i,1,weights.size()-1) cout<<" "<<weights[i];
			cout<<endl;
		}else{
			cout<<"forest"<<endl;
		}
	}
}