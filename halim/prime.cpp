#include<bitset>
#include<vector>
#include<cstdio>
using namespace std;

typedef long long ll;
typedef vector<int> vi;



ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.reset(); bs.flip(); //Set all numbers to 1;
	bs.set(0,false); bs.set(1, false);
	for(ll i=2;i<=_sieve_size;i++) if(bs.test((size_t)i)){
		for(ll j=i*i;j<=_sieve_size; j+=i) bs.set((size_t)j, false);
		primes.push_back((int)i);
	}
}

bool isPrime(ll N){
	if(N < _sieve_size) return bs.test(N); //for small primes
	for(int i=0; i<primes.size()-1;i++) if(N%primes[i] == 0) return false;
	return true;
}

vi primeFactors(int N){
	vi factors;
	int PF_idx = 0, PF = primes[PF_idx];
	while(N != 1 && (PF*PF <=N)){
		while(N%PF ==0) { N /= PF; factors.push_back(PF);}
		PF = primes[++PF_idx];
	}
}

int main(){
	sieve(10000000);
	printf("%d\n", isPrime(4));
}