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
	int n, m;
	vi dragonHeads;
	vi knightHeights;
	while(scanf("%d %d",&n,&m) && n!=0 && m!=0){
		dragonHeads.clear();
		knightHeights.clear();
		REP(i,n){
			int head; scanf("%d",&head);
			dragonHeads.pb(head);
		}
		REP(i,m){
			int height; scanf("%d",&height);
			knightHeights.pb(height);
		}

		sort(dragonHeads.begin(), dragonHeads.end());
		sort(knightHeights.begin(), knightHeights.end());
		bool possible = true;
		long long cost = 0;
		vi::iterator it = dragonHeads.begin();
		vi::iterator kt = knightHeights.begin();
		while(it!=dragonHeads.end()){
			int head = *it;
			if(kt == knightHeights.end()){
				// DEBUG("here");
				possible = false; break;
			}
			vi::iterator ifound = lower_bound(kt,knightHeights.end(),head);
			if(ifound==knightHeights.end() || *ifound < head){
				// DEBUG("No here");
				possible = false; break;
			}
			else{
				cost += *ifound;
				kt = ifound;
				kt++;
			}
			it++;
		}

		if(possible){
			cout<<cost<<endl;
		}
		else cout<<"Loowater is doomed!"<<endl;

	}	
}