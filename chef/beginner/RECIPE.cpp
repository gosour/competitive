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

int hcf(int a, int b){
	int m = max(a,b);
	int n = min(a,b);
	while(m%n){
		int rem = m%n;
		m = n;
		n = rem;
	}
	return n;
}

int hcf(vi v){
	int h = (v.size())? v[0] : 1;
	REP2(i,1,v.size()-1){
		h = hcf(h,v[i]);
	}
	return h;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n;
		vi ingds;
		cin>>n;
		REP(i,n){
			int temp;
			cin>>temp;
			ingds.pb(temp);
		}
		int h = hcf(ingds);
		REP(i,n){
			cout<<ingds[i]/h<<" ";
		}
		cout<<endl;
	}	
}