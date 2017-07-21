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
const int MOD = 1000000007;
int A[100005];
int B[100005];
int C[100005];

int main(){
	int t; cin>>t;
	while(t--){
		int p, q, r; cin>>p>>q>>r;
		REP(i,p) cin>>A[i];
		REP(i,q) cin>>B[i];
		REP(i,r) cin>>C[i];
		int sum = 0;

		REP(i,p){
			int X = A[i];
			int lx;
			lx = (lower_bound(B,B+q, X) - B);
			// DEBUG(X);
			REP2(j,lx,q-1){
				int Y = B[j];
				int uy = (upper_bound(C,C+r,Y) - C);
				// DEBUG(Y); 
				REP2(k,0,uy-1){
					int Z = C[k];
					// DEBUG(Z);
					int prod1,prod2;
					prod1 = ((long long)X+Y)%MOD;
					prod2 = ((long long)Y+Z)%MOD;
					sum += ((long long) prod1 * prod2)%MOD;
					sum = sum%MOD;
				}
			}
		}

		cout<<sum<<endl;
	}
}