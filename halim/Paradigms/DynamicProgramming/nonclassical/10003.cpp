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
int cuts[60];
int dp[1005][60];
int main(){
	int l; int n;
	while(scanf("%d",&l) && l!=0){
		scanf("%d",&n);
		cuts[0] = 0;
		REP(i,n){
			scanf("%d",&cuts[i+1]);
		}
		cuts[n+1] = l;

		for(int i=0;i<n+1;i++){
			dp[i][i+1] = 0;
		}

		for(int l=2;l<=n+1;l++){
			for(int i=0;i<=(n+1)-l;i++){
				int j = i+l;
				dp[i][j] = INF;
				for(int k=i+1;k<j;k++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (cuts[j]- cuts[i]));
				}
			}
		}

		cout<<"The minimum cutting is "<<dp[0][n+1]<<"."<<endl;
	}	
}