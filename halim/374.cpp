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

long modular_pow(long b, long p, long m){
	if(m == 1) return 0;
	long result = 1;
	long base = b%m;
	long exponent = p;
	while(exponent > 0){
		if(exponent%2 == 1){
			result = (result*base) % m;
		}
		exponent = exponent>>1;
		base = (base*base) % m;
	}
	return result;

}

int main(){
	long b,p,m;
	while(scanf("%ld %ld %ld", &b, &p, &m) == 3){
		printf("%ld\n",modular_pow(b,p,m));
	}
}