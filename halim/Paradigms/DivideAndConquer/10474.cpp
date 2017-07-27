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
int n, q;
vi marbles;
int main(){
	int t = 1;
	while(scanf("%d %d",&n,&q)!=EOF){
		if(n==0 && q==0) break;
		marbles.clear();
		// DEBUG(n); DEBUG(q);
		REP(i,n){
			int temp; scanf("%d",&temp);
			marbles.pb(temp);
		}
		sort(marbles.begin(), marbles.end());
		printf("CASE# %d:\n",t++);
		REP(i,q){
			int temp; scanf("%d",&temp);
			vector<int>::iterator l = lower_bound(marbles.begin(),marbles.end(),temp);
			// cout<<*l<<endl;
			if(l==marbles.end() || *l != temp) printf("%d not found\n",temp);
			else printf("%d found at %d\n",temp,(l-marbles.begin()+1));
		}
	}
}