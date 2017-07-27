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
#include<iomanip>
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
long long dp[30001][12];
int denoms[12] = {0,5,10,20,50,100,200,500,1000,2000,5000,10000};
long long table[30001];
int main(){
	double f;
	memset(dp,0,sizeof(dp));
	
	for(int i=0;i<12;i++) dp[0][i] = 1;

	for(int i=1;i<30001;i++){
		for(int j=1;j<12;j++){
			long long x = (i-denoms[j] >= 0)? dp[i-denoms[j]][j] : 0;
			long long y = (j>=1)? dp[i][j-1]:0;
			dp[i][j] = x+y;
		}
	}
	
	
	while(scanf("%lf",&f) && (f-0.00) > 0.001){
		long long amount = f*100 + 0.5;
		// DEBUG(f); DEBUG(amount);
		printf("%6.2f%17lld\n", f, dp[amount][11]);
		// REP(i,12)
		// 	cout<<dp[amount][i]<<" ";
	}	
}