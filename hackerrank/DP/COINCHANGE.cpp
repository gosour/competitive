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


long getWays(long n, vector < long > c){
    long long dp[55][255] = {};
	for(int i=0;i<=c.size();i++)
		dp[i][0] = 1;
	for(int i = 0;i < c.size();i++){
		for(int j=1;j<=n;j++){
			long long x = (i>=1)? dp[i-1][j] : 0;
			long long y = (j >= c[i])? dp[i][j-c[i]] : 0;
			dp[i][j] = x+y ;
		}
	}
	// for(int i=0;i<c.size();i++){
	// 	for(int j=0;j<=n;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return dp[c.size()-1][n];    
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout<<ways<<endl;
    return 0;
}