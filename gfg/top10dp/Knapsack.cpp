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
int varr[10005];
int warr[10005];

int dp[1005][1005];

int main(){
	int t; cin>>t;
	while(t--){
		int n, W; cin>>n>>W;
		REP(i,n) cin>>varr[i];
		REP(i,n) cin>>warr[i];

		for(int i=0;i<n;i++){
			for(int w = 0;w <=W;w++){
				if(i==0 || w==0) dp[i][w] = 0;
				else{
					dp[i][w] = max(varr[i]+dp[i-1][w-warr[i]], dp[i-1][w]);
				}
			}

		}
		cout<<dp[n-1][W]<<endl;
	}
}