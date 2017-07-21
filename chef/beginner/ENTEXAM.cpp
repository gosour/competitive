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
		int n,k,e,m; cin>>n>>k>>e>>m;
		int scores[10004] = {};

		REP(i,n-1){
			REP(i,e){
				int temp; cin>>temp;
				scores[i] += temp;
			} 
		}
		sort(scores,scores+n-1);
		int myscore = 0;
		REP(i,1){
			REP(i,e-1){
				int temp; cin>>temp;
				myscore += temp;
			}
		}

		int ans = -INF;
		while(k>1 && scores[(n-1)-k] + 1 != scores[(n-1)-k+1]){
			if(scores[(n-1)-k] + 1  <= m) {
				ans = scores[(n-1)-k] + 1;
				break;
			}
			k--;
		}

		if(ans < 0) cout<<"Impossible"<<endl;
		else cout<<ans<<endl;
	

	}
}