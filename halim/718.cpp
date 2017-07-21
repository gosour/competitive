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
typedef long long int num;

#define N 102
int e, t;
num ini, fim, r, s, maxi,f;
pair<num,num> x,y;
bool v[N];
vector<int> adj[N];
pair<num,num> ele[N];

bool dfs(int u){
	if(u == e+1) return 1;
	if(v[u]) return 0;

	v[u] = 1;

	for(int i=0;i<adj[u].size();i++){
		if(dfs(adj[u][i])) return 1;
	}
	return 0;
}

num divfloor(num a, num b) {
    if (a < 0 && b < 0) return -divfloor(-a, -b);
    if (b < 0) return divfloor(-a, -b);

    if (a > 0 || a%b == 0) return a/b;
    return a/b-1;
}

num euclid(num a, num *k, num b, num *l){
	if(a<0){
		*k = -*k;
		return euclid(-a,k,b,l);
	}
	if(b<0){
		*l = -*l;
		return euclid(a,k,-b,l);
	}
	if(a%b == 0){
		*k = 0;
		*l = 1;
		return b;
	}
	num d = euclid(b,k,a%b,l);
	num aux = *k;
	*k = *l;
	*l = aux - *l * (a/b);
	return d;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &f, &e, &ini, %fim);
		for(int i=0; i<e+2;i++){
			adj[i].clear();
			v[i] = 0;
		}
		for(int i=0;i<e;i++){
			scanf("%d %d", &ele[i].first, &ele[i].second);
		}

		for(int i=0;i<e;i++){
			x = ele[i];
			if((ini - x.second)%x.first == 0){
				adj[i]
			}
		}

	}
}