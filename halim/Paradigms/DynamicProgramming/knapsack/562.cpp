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
int coins[105];
int dp[105][50001];
int main(){
	int n; scanf("%d",&n);
	while(n--){
		int m; scanf("%d",&m);
		int total = 0;
		coins[0] = 0;
 		REP(i,m) {
 			scanf("%d",&coins[i+1]);
 			total += coins[i+1];
		}

		int target = total/2;
		// cout<<"total: "<<total<<" "<<"target: "<<target<<endl;
		memset(dp,0,sizeof(dp));

		for(int i=1;i<=m;i++){
			for(int j=1;j<=target;j++){
				if(j>=coins[i]){
					dp[i][j] = max (dp[i-1][j-coins[i]] + coins[i], dp[i-1][j]);
				}
				else 
					dp[i][j] = dp[i-1][j];
			}
		}

		// cout<<"Person 1 gets "<<dp[m][target]<<endl;
		// cout<<"Person 2 gets "<<total - dp[m][target]<<endl;
		cout<<total-2*dp[m][target]<<endl;
	}
}