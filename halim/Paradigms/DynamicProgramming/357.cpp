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
int denoms[5] = {1,5,10,25,50};
long long dp[5][30001];
int main(){
	memset(dp,0,sizeof(dp));
	REP(coin,5) dp[coin][0] = 1;

	for(int i=1;i<30001;i++){
		for(int j=0;j<5;j++){
			long long x = (i-denoms[j] >= 0)? dp[j][i-denoms[j]]:0;
			long long y = (j-1 >= 0)? dp[j-1][i]:0;
			dp[j][i] = x+y;
		}
	}

	int n;
	while(scanf("%d",&n)!=EOF){
		long long ans = dp[4][n];
		// if(ans != 1){
		// 	cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change."<<endl;
		// }
		// else{
		// 	cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
		// }
		cout<<ans<<endl;
	}
}