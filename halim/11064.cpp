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

const unsigned int max_size = 1<<8+1;
bitset<max_size> sieve;
vi primes;

void generate_primes(){
	sieve.reset(); sieve.flip();
	sieve.set(0,false); 
	sieve.set(1, false);
	for(int i=2; i<max_size;i++){
		if(sieve.test(i)){
			for(int j=i+i;j<max_size;j+=i){
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
			if(n%primes[i] == 0){return false;}
		}
	}
	return true;
}

long primeCombinations = 1;

vi primeFactors(int n){
	primeCombinations = 1;
	int PF_IDX = 0, PF = primes[PF_IDX];
	vi factors;
	bool result = isPrime(n);
	while(!result && n>1 && PF*PF <= n){
		int c = 0;
		while(n%PF == 0){ n/=PF; factors.pb(PF);c++;}
		PF = primes[++PF_IDX];
		primeCombinations *=(c+1);
	}
	if(n!=1) {factors.pb(n); primeCombinations *= 2;}
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
	int n;
	generate_primes();
	while(scanf("%d",&n)!=EOF){
		int result = n -  eulerTotient(n) - primeCombinations + 1; //Since 1 counted twice
		// cout<<primeCombinations<<endl;
		printf("%d\n",result);
	}
}