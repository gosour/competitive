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
struct Q{
	int t,v;
};	
Q qarr[100005];
long sum[100006] = {};
bool cmp(Q a, Q b){
	if(a.v > b.v) return true;
	if(a.v == b.v) return a.t < b.t;
	return false;
}
int main(){
	int n,q; cin>>n>>q;
	REP2(i,1,n) cin>>qarr[i].t;
	REP2(i,1,n) cin>>qarr[i].v;
	sort(qarr+1, qarr+n+1, cmp);

	// REP2(i,1,n) cout<<qarr[i].v<<" ";
	// DEBUG("df");
	sum[1] = qarr[1].t;
	for(int i=2;i<=n;i++){
		sum[i] = sum[i-1] + qarr[i].t;
	}
	REP(i,q){
		int l; cin>>l;
		cout<<sum[l]<<endl;
	}
}	