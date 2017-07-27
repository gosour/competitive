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
vi pset;
void initSet(int n){pset.resize(n);}
char findSet(char u){if(pset[(int)(u-'A')] == (int)(u-'A')) return u; else return findSet( (char)(pset[(int)u-'A'] + 'A'));}
void unionSet(char u, char v){pset[(int)(u-'A')] = (int)(v-'A');}

int main(){
	int t; cin>>t;
	char temp[4];
	
	scanf("\n"); bool first;
	char c; cin>>c;
	int nodes = (int)(c-'A') + 1;
	initSet(nodes);
	REP(i,nodes){pset[i] = i;}
	
	char u,v; char s[4];
	while(scanf("%s",&s) !=EOF){
		u = s[0]; v = s[1];
		DEBUG(u); DEBUG(v); 
		if(findSet(u) != findSet(v)) {DEBUG("YAY");unionSet(u,v);}
	}
	set<int> connectedComponents;
	REP(i,nodes){
		DEBUG(pset[i]);
		connectedComponents.insert(findSet((char)(pset[i]+'A')));
	}
	if(first) first = false;
	else printf("\n");
	printf("%d\n",connectedComponents.size());
}