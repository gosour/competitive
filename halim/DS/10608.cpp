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
void init_set(int n){
	pset.resize(n);
	REP(i,n) pset[i] = i;
}

int findset(int a){
	return (pset[a] == a)? a : (pset[a] = findset(pset[a]));
}
void unionSet(int a, int b){
	pset[findset(a)] = findset(b);
}

int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n,m; scanf("%d %d",&n,&m); 
		init_set(n);
		REP(i,m){
			int x,y;
			scanf("%d %d",&x,&y);
			unionSet(x-1,y-1);
		}
		vi freqCount; freqCount.resize(n,0);
		REP(i,n){
			freqCount[findset(i)]++;
		}
		int max = 0;
		REP(i,n){
			if(max<freqCount[i]) max = freqCount[i];
		}
		printf("%d\n",max);
	}
}