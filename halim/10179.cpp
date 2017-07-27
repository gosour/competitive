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
#define SQR(n)                ( n * n )
const int INF = 1<<29;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back
typedef vector<int> vi;

const unsigned int max_size = 1 << 15;

bitset<max_size+1> sieve;
vi primes;

void generate_primes(){
	sieve.reset(); sieve.flip();
	sieve.set(0,false); 
	sieve.set(1, false);
	for(int i=2; i<max_size;i++){
		if(sieve.test(i)){
			for(int j=i*i;j<max_size;j+=i){
				sieve.set(j,false);
			}
			primes.push_back(i);
		}
	}
}

bool isPrime(unsigned int n){
	if(n<=max_size) {if(sieve.test(n)) return true; else return false;}
	else{
		for(int i=0;i<primes.size();i++){
			if(n%i == 0) return false;
		}
	}
	return true;
}

vi primeFactors(int n){
	int PF_IDX = 0, PF = primes[PF_IDX];
	vi factors;
	while(n>1 && PF*PF <= n){
		while(n%PF == 0){ n/=PF; factors.pb(PF);}
		PF = primes[++PF_IDX];
	}
	if(n!=1) factors.pb(n);
	return factors;
}

int eulerTotient(int n){
	vi factors = primeFactors(n);
	vi::iterator new_end = unique(factors.begin(),factors.end()); //new_end points to next to last element
	int result = n;
	for(vi::iterator i = factors.begin(); i!= new_end;i++){
		result = result - result/ *i;
	}
	return result;
}

int main(){
	int n; generate_primes();
	while((scanf("%d", &n) == 1) && n != 0){
		if(n==1)printf("%d\n",0);
		else printf("%d\n", eulerTotient(n));
	}
}