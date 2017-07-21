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

int main(){
	int t; cin>>t;
	int dp[105][105] = {};
	while(t--){
		int n,m; cin>>n>>m;
		string s1, s2; cin>>s1>>s2;
		REP2(i,1,n){
			REP2(j,1,m){
				if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
				else{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout<<dp[n][m]<<endl;
	}
}	