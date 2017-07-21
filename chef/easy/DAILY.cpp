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
int fact[] = {1,1,2,6,24,120,720};
int select(int n, int r){
 	return fact[n]/(fact[n-r]*fact[r]);
}

int main(){
	int x,n; cin>>x>>n;
	int ans = 0;
	int i,j;
	REP(t,n){
		string s; cin>>s; s = "0" + s;
		for(int c = 1;c<=9;c++){
			i = (c-1)*4 + 1;
			j = 54 - (c-1)*2;
			int count = 0,p = 0;
			p = 0;
			while(p<4) {
				if(s[i+p] == '0') count++;
				p++;
			}
			p = 0;
			while(p<2) {
				if(s[j-p] == '0') count++;
				p++;
			}
			if(count>=x)
				ans += select(count,x);
		}
	}
	cout<<ans<<endl;

}