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
vector<int> pset;
vector<int> pcount;
int setCount = 0;
const int MOD = 1000000007;

void init(int n){
	pset.resize(n+1);
	pcount.resize(n+1);
	REP2(i,1,n) {
		pset[i] = i; pcount[i] = 1;
	}
	setCount = n;
}

int findset(int n){
	return (pset[n] == n)? n : (pset[n] = findset(pset[n]));
}

bool isSameSet(int a, int b){
	return findset(a) == findset(b);
}

void unionSet(int a, int b){
	if(!isSameSet(a,b)){
		pcount[findset(b)] += pcount[findset(a)];
		pcount[findset(a)] = 0;
		pset[findset(a)] = findset(b);
		setCount--;
	}
}


int main(){
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		init(n);
		long long ans = 1;
		REP(i,k){
			int a,b; cin>>a>>b;
			unionSet(a,b);
		}
		REP2(i,1,n){
			if(pcount[i]>1)
				ans = (ans*pcount[i])%MOD;
		}
		cout<<setCount<<" "<<ans<<endl;
	}
}