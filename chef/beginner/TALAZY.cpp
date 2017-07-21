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
	while(t--){
		long long n,b,m; cin>>n>>b>>m;
		long long ans = 0;
		while(n){
			long long time;
			if(n%2){
				time = m*((n+1)/2) + ((n==1)? 0:b);
				n = (n-1)/2;
			}
			else {
				time = m*((n)/2) + b;
				n = n/2;
			}
			ans += time;
			m = 2*m;
		}
		cout<<ans<<endl;
	}
}