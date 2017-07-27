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
int dp[1005][1005];
int main(){
	int tests; scanf("%d",&tests);
	string empt;
	getline(cin,empt);
	while(tests--){
		string s1,s2;
		getline(cin,s1);
		int len = s1.length();
		s2 = s1;
		reverse(s2.begin(),s2.end());

		memset(dp,0,sizeof(dp));

		for(int i=1;i<=len;i++){
			for(int j=1;j<=len;j++){
				if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[len][len]<<endl;
	}
}