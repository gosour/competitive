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
struct Prod{
	int m,l,r,i;
};

bool mycmp(struct Prod p2, struct Prod p1){
	if(p2.m > p1.m) return true;
	if(p2.m == p1.m && p2.r > p1.r) return true;
	if(p2.m == p1.m && p2.r == p1.r && p2.i < p1.i) { return true;}
	return false;
}

int main(){
	int t; cin>>t;
	struct Prod prod[105];
	while(t--){
		int n; cin>>n;
		REP(i,n) {
			cin>>prod[i].l;
		}
		REP(i,n){
			cin>>prod[i].r;
			prod[i].m = prod[i].l * prod[i].r;
			prod[i].i = i;
		}

		sort(prod, prod + n, mycmp);
		// REP(i,n){
		// 	cout<<prod[i].i<<" ";
		// }
		// cout<<endl;
		cout<<prod[0].i+1<<endl;
	}
}