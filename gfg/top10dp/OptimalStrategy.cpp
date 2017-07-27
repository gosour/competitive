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
#define SQR(n)                ( (n) * (n) )
const int INF = 1<<29;


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back

typedef vector<int> vi;
int arr[1005];
int dp[1005][1005] = {};
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		REP(i,n) cin>>arr[i];
		REP(gap,n){
			for(int i=0,j=gap;j<n;j++,i++){
				int x = ((i+2)<=j)? dp[i+2][j] : 0;
				int y = ((i+1)<=(j-1))? dp[i+1][j-1] : 0;
				int z = (i<=(j-2))? dp[i][j-2] : 0;
				dp[i][j] = max(arr[i]+min(x,y), arr[j]+min(y,z));
			}
		}

		cout<<dp[0][n-1]<<endl;
	}
}