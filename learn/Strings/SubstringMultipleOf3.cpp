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
	int arr[3] = {3,3,3}; //arr simulating string
	int dp[3][3] = {};
	dp[0][arr[0]%3]++;
	for(int i=1;i<3;i++){
		int curr = arr[i]%3;
		dp[i][curr] = 1;

		dp[i][(curr+0)%3] += dp[i-1][(curr+0)%3] + 1;
		dp[i][(curr+1)%3] += dp[i-1][(curr+1)%3] + 1;
		dp[i][(curr+2)%3] += dp[i-1][(curr+2)%3] + 1;
		cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	}
	cout<<dp[2][0]<<endl;
}