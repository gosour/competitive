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
int s, c;
map<string,int> stationMap;
priority_queue<pair<int,pair<int,int> > > EdgeList;
int pset[405];
void initSet(){
	REP(i,s) pset[i] = i;
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
	while(true){
		cin>>s>>c;
		if(s==0 && c==0) break;
		stationMap.clear();
		REP(i,s){
			string city; cin>>city;
			stationMap[city] = i;
		}
		REP(i,c){
			string city1, city2; int dist;
			cin>>city1>>city2>>dist;
			// cout<<city1<<" "<<city2<<" "<<dist<<endl;
			EdgeList.push(make_pair(-dist,make_pair(stationMap[city1],stationMap[city2])));
		}
		string source; cin>>source;
		int total = 0;
		initSet();
		while(!EdgeList.empty()){
			pair<int, pair<int,int> > edge = EdgeList.top(); EdgeList.pop();
			if(!isSameSet(edge.second.first,edge.second.second)){
				total += (-edge.first);
				unionSet(edge.second.first,edge.second.second);
			}
		}
		int pcount = 0;
		REP(i,s){
			if(pset[i] == i) pcount++;
		}

		if(pcount == 1) cout<<total<<endl;
		else cout<<"Impossible"<<endl;

	}
}