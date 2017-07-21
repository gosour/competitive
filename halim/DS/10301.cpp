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

struct Circle{
	float x, y, r;
};
bool intersects(Circle c1, Circle c2){
	float dist = SQR(c1.x - c2.x) + SQR(c1.y - c2.y);
	float diff = SQR(c1.r - c2.r);
	float sum  = SQR(c1.r + c2.r);
	if(dist>diff && dist<sum) return true;
	if(c1.x == c2.x && c1.y == c2.y && c1.r ==  c2.r) return true;
	else return false;
}
vi pset;
void init_set(int n){
	pset.resize(n);
	REP(i,n) pset[i] = i;
}
int find_set(int j){
	return (pset[j] == j)? j : pset[j] = find_set(pset[j]);
}

void union_set(int i, int j){
	if(pset[i] == pset[j]) return;
	else pset[i] = find_set(j);
}

int main(){
	int n;
	while(scanf("%d",&n) && n!=-1){
		init_set(n); vector<Circle> vc;
		REP(i,n){
			float x,y,r; scanf("%f %f %f",&x,&y,&r); Circle c = {x,y,r};
			vc.pb(c);
		}

		REP(i,n){
			REP2(j,i+1,n-1){
				if(intersects(vc[i],vc[j])) union_set(i,j);
			}
		}

		vi freqCount; freqCount.resize(n,0);
		REP(i,n){
			freqCount[pset[i]]++;
		}
		int max = 0;
		REP(i,n){
			if(freqCount[i] > max) max = freqCount[i];
		}

		if(max > 1) printf("The largest component contains %d rings.\n",max);
		else printf("The largest component contains 1 ring.\n");
	}	
}