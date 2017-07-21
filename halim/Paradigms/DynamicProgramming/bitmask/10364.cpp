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
int lengths[25];
int maskStickLengths[1<<20];

int main(){
	int tests; scanf("%d",&tests);
	while(tests--){
		int n, sum = 0;
		scanf("%d",&n);
		for(int i=0;i<(1<<n);i++){
			maskStickLengths[i] = -1;
		}
		REP(i,n) {
			scanf("%d",&lengths[i]);
			sum += lengths[i];
			maskStickLengths[1<<i] = lengths[i];
		}	
		if(sum%4 != 0){printf("no\n"); continue;}
		int L = sum/4;
		for(int mask = 0; mask<(1<<n); mask++){
			if(maskStickLengths[mask] != -1) continue;
			int msb = b & (-b);
        	maskStickLengths[b] = maskStickLengths[msb] + maskStickLengths[b ^ msb];
		}
		for(int mask = 0; mask<(1<<n); mask++){
			
		}

	}
}