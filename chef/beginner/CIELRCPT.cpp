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
int twoPowers[12];
int ways(int p){
	if(p == 1 || p == 0)
		return p;

	int closest = 0;
	REP(i,12){
		if(twoPowers[i] <= p ) closest = i;
		else break;
	}

	return 1 + ways(p-twoPowers[closest]);
}
int main(){
	int t; cin>>t;
	REP(i,12){
		twoPowers[i] = pow((int)2, i);
	}

	while(t--){
		int p; cin>>p;
		cout<<ways(p)<<endl;
	}
}	