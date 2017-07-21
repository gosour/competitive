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
typedef unsigned long long ull;
bitset<100002> bs;
vi primes;
void init(){
	bs.flip();
	bs[0] = bs[1] = false;
	for(int i=2;i<10002;i++){
		if(bs[i]){
			primes.pb(i);
			for(int j=i*i;j<100002;j+=i) bs[j] = false;
		}
	}
}

ull gcd(ull a, ull b){
	if(a<b){
		ull temp = a;
		a = b;
		b = temp;
	}
	int r;
	while(r = a%b){
		a = b;
		b = r;
	}
	return b;
}

bool isPrime(ull n){
	if(n <= 100004) return bs[n];
	else {
		bool ans = true;
		int i = 0;
		while(primes[i] < sqrt(n))
			if(n%primes[i] == 0) return false;
	}
	return true;
}
ull primeFactors(ull N){
	ull PF_idx =0, PF = primes[PF_idx];
	ull count = 0;
	while(N!=1 && (PF*PF <=N)){
		ull currcount = 0 ;
		while(N%PF == 0){ N/=PF; currcount++;}
		PF = primes[++PF_idx];
		if(count == 0) count = currcount;
		else count *= currcount;
	}
	if(N!=1) count++;
	return count;
}
int main(){
	init();
	ull a,b; cin>>a>>b;
	int count = 1;
	ull g = gcd(a,b);
	cout<<primeFactors(g)+1<<endl;
}