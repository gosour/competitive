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
int dp[105][105];
int main(){
	int n1,n2; int t=1;
	while(scanf("%d %d",&n1,&n2) && n1!=0 && n2!=0){
		vi tower1, tower2;
		REP(i,n1){
			int temp;
			scanf("%d",&temp);
			tower1.pb(temp);
		}
		REP(i,n2){
			int temp;
			scanf("%d",&temp);
			tower2.pb(temp);
		}
		memset(dp,0,sizeof(dp));

		for(int i=1;i<=n1;i++){
			for(int j=1;j<=n2;j++){
				if(tower1[i-1] == tower2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}

		cout<<"Twin Towers #"<<t++<<endl;
		cout<<"Number of Tiles : "<<dp[n1][n2]<<endl;
		cout<<endl;

	}
}