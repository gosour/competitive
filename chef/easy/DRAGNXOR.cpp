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

int ocount(int a){
	int c = 0;
	while(a){
		if(a%2) c++;
		a = a>>1;
	}
	return c;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n,a,b; cin>>n>>a>>b;
		int ac = ocount(a), bc = ocount(b);
		int ans = 0;
		int ototal = ac+bc;
		if(ototal <= n){
			REP(i,ototal)
				ans += pow(2,i);
			ans = ans<<(n-ototal);
		}else{
			REP(i,2*n-(ototal))
				ans +=pow(2,i);
			ans = ans<<(ototal-n);
		}

		cout<<ans<<endl;
	}
}