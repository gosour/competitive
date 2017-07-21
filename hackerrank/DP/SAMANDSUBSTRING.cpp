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
const int MOD = 1000000007;

vi digits;
int digitCount(string s){
	int count = 0;
	digits.clear();
	REP(i,s.length()){
		digits.pb((int)s[i]-'0');
	}
	return s.length();
}
int dp[200005] = {};

int main(){
	string s; cin>>s;
	int len = digitCount(s);
	dp[0] = digits[0];
	long long ans = dp[0];
	for(int i=1;i<len;i++){
		dp[i] = ((dp[i-1]*(long long)10)%MOD + ((long long)digits[i]*(i+1))%MOD)%MOD;
		ans = ((long long)ans+dp[i])%MOD;
	}
	cout<<ans<<endl;
}