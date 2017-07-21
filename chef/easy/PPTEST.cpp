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
int carr[105] = {}, parr[105] = {}, tarr[105] = {};
int dp[105][105] = {};
int main(){
	int t; cin>>t;
	while(t--){
		int n,W; cin>>n>>W;
		REP2(i,1,n) cin>>carr[i]>>parr[i]>>tarr[i];
	    for(int i=0;i<=W;i++)
	    {
	    	dp[0][i]=0;
	    }
		REP2(i,1,n){
			REP2(w,0,W){
				int x = (w >= tarr[i])? carr[i]*parr[i] + dp[i-1][w-tarr[i]] : 0;
				int y = dp[i-1][w];
				dp[i][w] = max(x,y);
			}
		}
		cout<<dp[n][W]<<endl;
	}
}