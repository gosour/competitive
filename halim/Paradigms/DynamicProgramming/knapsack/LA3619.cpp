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

vi primes;
bitset<1500> bitmask;

void generatePrimes(){
	primes.pb(0);
	bitmask.flip(); bitmask[0] = false; bitmask[1] = false;
	for(int i=2;i<1500;i++){
		if(bitmask[i] == true){
			for(int j = i+i;j<1500;j+=i) bitmask[j] = false;
			primes.pb(i);
		}
	}
}

long long dp[1500][15][250 ];

int main(){
	int n,k;
	generatePrimes();
	memset(dp,0,sizeof(dp));
	for(int i=1;i<primes.size();i++){
		dp[primes[i]][1][i] = 1;
	}

	for(int i=1;i<1500;i++){
		for(int j=1;j<15;j++){
			for(int p = 1;p<primes.size();p++){
				if(i>=primes[p])
					dp[i][j][p] = max(dp[i][j][p],dp[i-primes[p]][j-1][p-1] + dp[i][j][p-1]);
				else
					dp[i][j][p] = max(dp[i][j][p],dp[i][j][p-1]);
			}
		}
	}

	
	while(scanf("%d %d",&n,&k) && (n!=0 && k!=0)){
		cout<<dp[n][k][primes.size()-1]<<endl;
	}	
}