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
int arr[105];
int dp[105][105];
int sum(int a,int b){
	int sum = 0;
	for(int i=a;i<=b;i++) sum += arr[i];
	return sum;
}
int main(){
	int n;
	while(scanf("%d",&n) && n!=0){
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i+1]);
		}

		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++){
				if(i==j)
					dp[i][i] = arr[i];
				else
					dp[i][j] = -INF;

			}
		}

		for(int l=1;l<=n;l++){
			for(int i=1;i+l<=n;i++){
				int j = i+l;
				int val;
				for(int k=0;k<j-i;k++){
					// cout<<i<<" to "<<i+k<<" sum is : "<<sum(i,i+k)<<" and ";
					// cout<<"dp["<<i+k+1<<"]["<<j<<"] = "<<dp[i+k+1][j]<<endl;

					// cout<<j-k<<" to "<<j<<" sum is : "<<sum(j-k,j)<<" and ";
					// cout<<"dp["<<i<<"]["<<i + (j-i)-k -1<<"] = "<<dp[i][i + (j-i)-k - 1 ]<<endl;
					dp[i][j]= max(dp[i][j],max(sum(i,i+k) - dp[i+k+1][j] , sum(j-k,j) - dp[i][i + (j-i)-k - 1 ]));
	 			}
	 			dp[i][j] = max(dp[i][j],sum(i,j));
	 			// cout<<"i : "<<i<< " j : "<<j<<" val : "<<dp[i][j]<<endl;
			}
		}

		cout<<dp[1][n]<<endl;
	}
}