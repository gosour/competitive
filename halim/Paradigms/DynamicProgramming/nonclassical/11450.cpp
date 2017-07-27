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
int garmentCount[25];
int garments[25][25];
int dp[25][205];
int main(){
	int n; scanf("%d",&n);
	while(n--){
		int m, c; scanf("%d %d",&m,&c);
		REP(i,c){
			int k; scanf("%d",&k);
			garmentCount[i] = k;
			REP(j,k){
				scanf("%d",&garments[i][j]);
			}
		}

		memset(dp,0,sizeof(dp));
		for(int i=0;i<=m;i++){
			
		}
		for(int i=0;i<c;i++){
			for(int j=1;j<=m;j++){
				for(int k = 0; k<garmentCount[i];k++){
					if(j>=garments[i][k])
						dp[i][j] = dp[i-1][j-garments[i][k]];

				}
			}
		}


	}	
}