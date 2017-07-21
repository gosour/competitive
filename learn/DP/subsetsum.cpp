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
bool dp[101][101]; //i,sum
int subsetCount[101]; //wil keep subsetCount of the number of subsets with the given sum;
int main(){
	int arr[] = {6,6,8,4,12,9,8,8}; //{6,-6,8,4,-12,9,8,-8};
	int len = sizeof(arr)/sizeof(int);
	memset(subsetCount,0,sizeof(subsetCount));

	int maxSum = 25;
	dp[0][0] = true;

	for(int i=0;i<=len;i++){
		dp[i][0] = true; //Any subset from empty(i=0) to (i=1 to i=len) can have a subset sum = 0;
	}

	for(int sum=1;sum<=maxSum;sum++){
		dp[0][sum] = false; //Any empty subset(i=0, cannot have sum >0)
	}

	for(int i=1;i<=len;i++){
		for(int sum = 1; sum<=maxSum;sum++){
			dp[i][sum] = dp[i-1][sum]; //Don't include the current element
			if(sum >= arr[i-1]){
				dp[i][sum] = dp[i-1][sum] || dp[i-1][sum-arr[i-1]];
				if(dp[i-1][sum-arr[i-1]]) {
					cout<<arr[i-1]<<" included in "<<sum<<endl;
					subsetCount[sum]++;
				}
			}

			// cout<<dp[i][sum]<<" ";
		}
		// cout<<endl;
	}
	REP2(i,0,maxSum){
		cout<<"Sum of "<<i<<" possible? "<<dp[len][i]<<" ";
		if(dp[len][i]){
			cout<<subsetCount[i];
		}
		cout<<endl;
	}
}