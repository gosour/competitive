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
typedef unsigned long long ull;
const int MOD = 1000000009;
ull dp[1000005] = {};

ull exp(ull a, ull n){
	if(n == 0) return 1;
	if(n==1) return a;
	if(n<1000005 && dp[n]) return dp[n];

	ull halfexp = n/2;
	ull power, prod, prod2;

	prod = a;

	for(power = 2; power<=halfexp;power++){
		prod  = (prod*a)%MOD;
	}
	if(n%2 == 0 || n == 1)
		prod2 = prod;
	else
		prod2 = (prod * a)%MOD;
	if(n<1000005)
		return dp[n] = (prod * prod2)%MOD;
	else
		return (prod * prod2)%MOD;
}

int main(){
	int t; cin>>t;
	while(t--){
		ull n; cin>>n;
		ull ans = (n%2)? 26 : 1;
		int k = n/2;
		cout<<(exp(26,k)*ans)%MOD<<endl;
	}
}