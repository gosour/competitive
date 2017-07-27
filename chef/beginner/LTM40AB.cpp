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
		int a,b,c,d; cin>>a>>b>>c>>d;
		long long ans = 0;
		if(a>d ||  a>b || c>d) ans = 0;
		else{
			int diff = (b-c);
			if(diff < 0) ans =  (b-a+1) * (d-c+1);
			else{
				ans = (d-b+1)*(c-a+1) + (b-c+1)*(b-c+1) - (b-c+1) + (c-a)*(b-c) + (d-b)*(b-c);
			}

		}
		cout<<ans<<endl;
	}
}