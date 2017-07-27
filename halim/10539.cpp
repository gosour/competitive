#include<string>
#include<bitset>
#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

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

int main(){
	int t; cin>>t;
	while(t--){
		long long L, U; scanf("%lld %lld", &L, &U);

	}
}