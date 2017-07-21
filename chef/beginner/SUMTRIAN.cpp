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

int triangles[105][105];
int dp[105][105] = {};
int lines; 

int main(){
	int t; cin>>t;
	while(t--){
		cin>>lines;
		REP(i,lines){
			REP2(j,0,i){
				cin>>triangles[i][j];
				if(i==0 && j==0) dp[1][1] = triangles[i][j];
				dp[i+1][j+1] = triangles[i][j] + max(dp[i][j+1], dp[i][j]);
			}
		}
		int ans = -INF;
		REP2(i,1,lines){
			ans = max(ans, dp[lines][i]);
		}	
		cout<<ans<<endl;
	}
}	