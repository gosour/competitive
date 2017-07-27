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
	int tests; scanf("%d",&tests);
	int n;
	while(tests--){
		scanf("%d",&n);
		if(n==0) {cout<<0<<endl; continue;}
		vi cars;
		REP(i,n){
			int temp; scanf("%d",&temp);
			cars.pb(temp);
		}
		vi lis,lds;
		lis.resize(n,1); lds.resize(n,1);
		int ans = 1;
		for(int i=n-2;i>=0;i--){
			for(int j = i+1; j<n;j++){
				//lis calculation
				if(cars[i] < cars[j] && lis[i] < lis[j] + 1)
					lis[i] = lis[j]+1;
				//lds calculation
				if(cars[i] > cars[j] && lds[i] < lds[j] + 1)
					lds[i] = lds[j]+1;

				ans = max(ans, lis[i]+lds[i] -1); 
			}
		}
		cout<<ans<<endl;
	}
}