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

bitset<10001> bs;
vector<int> primes;
void generate(){
	bs.reset(); bs.flip();
	bs[0] = bs[1] = false;
	for(int i=2;i<10001;i++){
		if(bs[i]){
			primes.pb(i);
			for(int j=i*i;j<10001;j=j+i){
				bs[j] = false;
			}
		}
	}
}

int main(){
	int t; cin>>t;
	generate();
	while(t--){
		int x,y; cin>>x>>y;
		int sum = x+y;
		vector<int>::iterator it = upper_bound(primes.begin(),primes.end(),sum);
		cout<<(*it - sum)<<endl;
	}
}