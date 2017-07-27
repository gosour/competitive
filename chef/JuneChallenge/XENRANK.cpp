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

int main(){
	int t; cin>>t;
	while(t--){
		long long u,v; cin>>u>>v;
		long long u1,v1; u1 = u, v1 = v;
		if(u!=0){
			v = (u+v);
			u = 0;
		}
		long long rank = 1;
		rank = (v%2)? v*((v+1)/2): (v+1)*(v/2);
		rank++;
		// REP(i,v+1){
		// 	rank = rank + i;
		// 	// DEBUG(rank);
		// }
		// cout<<"("<<u<<","<<v<<") "<<rank<<endl;

		rank += u1;
		cout<<rank<<endl;
	}
}