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
int dp[100005] = {};
int main(){
	int n; cin>>n;	
	int prev = 0;
	long long count = 0;
	REP(i,n){
		int temp;
		cin>>temp;
		if(i==0) {
			prev = temp;
			dp[i] = 1;
		}
		else{
			if(temp<=prev) {
				dp[i] = dp[i-1] + 1;
			}
			else {
				dp[i] = 1;
				
			}
		}
	}
	count = 0;
	int temp = 0;
	REP(i,n){
		if(dp[i] >= dp[i-1] && dp[i] != 1) count+= dp[i];
		if(dp[i] != dp[i-1] && dp[i] == 1){ 
			count++;
			temp = 1;
		}
		if(dp[i] == dp[i-1] && dp[i] == 1){
			count += (++temp);
		}
	}
	cout<<count<<endl;
}