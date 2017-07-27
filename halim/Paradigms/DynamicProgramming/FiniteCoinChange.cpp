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



int main(){
    long long t,n,k,x,kase=0;
 
	scanf("%Ld",&t);
 	vi A,C;
	while(t--){
 
		printf("Case %d: ",++kase);
 
		scanf("%Ld",&n);
		scanf("%Ld",&k);
 
		A.clear();C.clear();
 
		for(int i=0;i<n;i++){
			scanf("%Ld",&x);
			A.push_back(x);
		}
 
		for(int i=0;i<n;i++){
			scanf("%Ld",&x);
			C.push_back(x);
		}
 
		
	}
	return 0;	
}