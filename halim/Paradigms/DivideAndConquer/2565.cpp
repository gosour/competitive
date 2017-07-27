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

bitset<100000> sieve;
vi primes;
vi prime_factors;

int m, a, b;
int height,width;
void generate_primes(){
	sieve.reset(); sieve.flip();
	sieve[0] = 0; sieve[1] = 0;
	for(int i=2;i<100000;i++){
		if(sieve[i] == 1){
			for(int j=i+i;j<100000;j+=i)
				sieve[j] = 0;
			primes.pb(i);
		}
	}
}

void generate_prime_factors(int num){
	prime_factors.clear();
	int prime_idx = 0; 
	while(1){
		int current_prime= primes[prime_idx];
		if(prime_idx >= primes.size()) {prime_factors.pb(num); break;}
		if(num == 1) break;
		while(num%current_prime == 0){
			prime_factors.pb(current_prime);
			num /= current_prime;
		}
		prime_idx++;
	}
}

int find_rightmost_prime(int n,int left_idx, int right_idx){
	int mid = (left_idx+right_idx)/2;
	if(primes[mid] == n) {return mid;}
	if(left_idx +1 == right_idx) {return left_idx;}

	if(primes[mid] < n) left_idx = mid;
	else right_idx = mid;

	find_rightmost_prime(n,left_idx,right_idx);

}

void maximize_area(int lower_idx, int breadth_idx){
	if(breadth_idx<lower_idx) {return;}
	int max_height_idx = find_rightmost_prime(b*primes[breadth_idx]/a,0,primes.size());
	int min_height_idx = breadth_idx;
	int MaxArea = primes[max_height_idx] * primes[breadth_idx];
	int MinArea = primes[min_height_idx] * primes[breadth_idx];
	int mid_idx = (lower_idx+breadth_idx)/2;
	
	if(MaxArea > m && MinArea <= m){
		for(int i=min_height_idx;primes[i]*primes[breadth_idx]<=m;i++){
			if( (primes[i]*primes[breadth_idx]) > height*width){
				height = primes[i]; width = primes[breadth_idx];
			}
		}
		maximize_area(lower_idx,breadth_idx-1);
	}else{
		if(MaxArea >= height*width) {height = primes[max_height_idx]; width = primes[breadth_idx];}
	}

}

int main(){
	generate_primes();
	while(scanf("%d %d %d",&m,&a,&b) && a!=0){
		height = 0; width = 0;
		maximize_area(0,find_rightmost_prime(sqrt(m),0,primes.size()));
		cout<<width<<" "<<height<<endl;
	}	
	
}