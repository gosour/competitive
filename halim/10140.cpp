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

vi primeFactors(unsigned int n){
	vi factors;
	int PF_idx = 0, PF = primes[PF];
	while(n!=1 && n>PF*PF){
		while(n%PF == 0){ n /= PF; factors.push_back(PF); }
		PF_idx++; PF = primes[PF_idx];
	}
	return factors;
}

int main(){
	generate_primes();
	unsigned int L, U;
	while(scanf("%d %d", &L, &U) !=EOF){
		vi local_primes;
		unsigned int closest=0 , farthest=0;
		int min_distance = 2147483647, max_distance = -2147483647;
		int counter = 0;
		for(unsigned int i=L;i<=U;i++){
			if(isPrime(i)){
				if(counter>0){
					int dist = i-local_primes.back();
					if(dist>max_distance) {max_distance = dist; farthest= counter-1;}
					if(dist<min_distance) {min_distance = dist; closest = counter-1;}
				}
				local_primes.push_back(i); counter++;
			}
		}
		if(local_primes.size() > 1){
			cout<<local_primes[closest]<<","<<local_primes[closest+1]<<" "<<"are closest"<<",";
			cout<<local_primes[farthest]<<","<<local_primes[farthest+1]<<" "<< "are most distant."<<endl;
		}
		else cout<<"There are no adjacent primes."<<endl;
	}
}
