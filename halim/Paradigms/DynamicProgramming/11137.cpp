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
int denoms[21];
long long dp[22][10001];
int main(){
	REP(i,21) denoms[i] = (i+1)*(i+1)*(i+1);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<22;i++) dp[i][0] = 1;

	for(int i=1;i<10001;i++){
		for(int j=1;j<22;j++){
			long long x = (i-denoms[j-1]>=0)? dp[j][i-denoms[j-1]]:0;
			long long y = dp[j-1][i];
			dp[j][i] = x+y;
		}
	}

	int x;
	while(scanf("%d",&x)!=EOF){
		cout<<dp[21][x]<<endl;
	}

}