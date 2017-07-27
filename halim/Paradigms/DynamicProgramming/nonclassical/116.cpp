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
int arr[12][105];
int dp[12][105];
int main(){
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF){
		REP(i,m) REP(j,n) scanf("%d",&arr[i][j]);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++) dp[i][n-1] = arr[i][n-1];

		for(int i=n-2;i>=0;i--){
			for(int j=0;j<m;j++){
				// cout<<i<<" "<<j<<endl;
				int x = ((j==0)? dp[m-1][i+1] : dp[j-1][i+1] );
				int y = dp[j][i+1];
				int z = ((j==m-1)? dp[0][i+1] : dp[j+1][i+1]);
				dp[j][i] = arr[j][i] + min(x,(min(y,z)));
			}
		}
		int minPath = INF;
		int row = 0;
		for(int i=0;i<m;i++){
			if(minPath > dp[i][0]){
				minPath = dp[i][0];
				row = i;	
			}
		}
		// REP(i,m) {REP(j,n) cout<<dp[i][j]<<" "; cout<<endl;}
		int j = 0;
		vi ans;
		while(j<n-1){
			// cout<<row<<" "<<j<<endl;
			ans.pb(row+1);
			// DEBUG(dp[row][j]);
			// DEBUG(arr[row][j]);
			if(row == m-1 && (dp[row][j] == dp[0][j+1] + arr[row][j])){row = 0; j++; continue;}
			if(row > 0 && dp[row][j] == (arr[row][j] + dp[row-1][j+1])){row--; j++; continue;}

			if(dp[row][j] == (dp[row][j+1]  + arr[row][j]) ){j++; continue;}
			if(row < m-1 && (dp[row][j] == dp[row+1][j+1] + arr[row][j])){row = row+1; j++; continue;}

			if(row == 0 && dp[row][j] == (dp[m-1][j+1] + arr[row][j])){row = m-1; j++; continue;}


		}
		ans.pb(row+1);
		// reverse(ans.begin(),ans.end());
		cout<<ans[0];
		REP2(i,1, ans.size()-1) cout<<" "<<ans[i];
		cout<<endl;
		cout<<minPath<<endl;
	}
}