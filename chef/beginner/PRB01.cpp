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

const long long upperbound = 1000010;
bitset<upperbound> bs;
vi primes;

void sieve(){
	bs.reset(); bs.flip(); //set all numbers to 1
	bs.set(0,false); bs.set(1,false);
	for(long long i = 2; i<upperbound;i++){
		if(bs[i] == true){
			for(long long j = i*i; j<upperbound;j+=i){
				bs[j] = false;
			}
		primes.pb(i);
		}
	}
}

bool isPrime(long long n){
	if(n < upperbound) return bs[n];
	REP2(i,0,primes.size() - 1) if(n % primes[i]) return false;
	return true; //works upto n<=primes[last]*primes[last]
}

int main(){
	sieve();
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string out  = (isPrime(n))? "yes" : "no";
		cout<<out<<endl;
	}
}