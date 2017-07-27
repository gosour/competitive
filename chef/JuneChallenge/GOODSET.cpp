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
#include<assert.h>

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

int main(){
	int t; cin>>t;
	int n = 0; 
	while(t--){
		// n++;
		cin>>n;
		vector<long long> p;
		REP(i,n){
			int next = i*2 + 1;
			p.pb(next);
			cout<<next<<" ";
		}
		cout<<endl;
		//Unit test case
		REP(i,n){
			REP2(j,i+1,n){
				REP2(k,j+1,n){
					assert(p[i] + p[j] != p[k]);
				}
			}
		}
	}
}