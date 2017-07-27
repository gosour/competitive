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
long long dp[100005];
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		long long maxSum,sum,maxNum;
		maxSum = sum = 0; maxNum = 0;
		REP(i,n){
			long long temp;
			cin>>temp;
			sum += temp;

			if(sum < 0) sum = 0 ;

			if(sum > maxSum)
				maxSum = sum;

			if(i == 0) {
				dp[i] = temp;
				maxNum = temp;
			}
			else{
				dp[i] = max(dp[i-1], max(dp[i-1]+temp, temp));
				if(temp > maxNum)
					maxNum = temp;
			}
		}
		if(maxSum == 0) {
			maxSum = maxNum;
		}
		cout<<maxSum<<" "<<dp[n-1]<<endl;

	}
}