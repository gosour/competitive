#include<iostream>
#include<bitset>
#include<vector>
#include<cstdio>
#include<utility>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<long,long> pl;

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


ll divCount(ll n){

}

pl maxDivisors(ll L, ll U){
	pl result;
	ll max = 0;
	ll number = 0
	for(ll i=U;i>=L;i--) if(max < divCount(i) ) {max = divCount; number = i;}
	result.make_pair(number, max);	
	return result;
}

int main(){
	int t; cin>>t;
	printf("Done\n");
	while(t--){
		ll L, U; cin>>L>>U;
		pl P;
		P = maxDivisors(L,U);
		printf("Between %d and %d, %d has the maximum of %d divisors.", L, U, P.first, P.second);
	}
}