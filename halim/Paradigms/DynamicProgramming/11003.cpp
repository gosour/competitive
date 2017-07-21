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
struct Box{
	int w;
	int l;
};
int main(){
	int n;
	while(scanf("%d",&n) && n!=0){
		vector<Box> boxes;
		REP(i,n){
			int w, l; scanf("%d %d",&w,&l);
			Box box; box.w = w; box.l = l;
			boxes.pb(box);
		}

		vector<int> dp; dp.resize(6001,0);
		int ans = 1;
		for(int i = n-1; i>=0;i--){
			for(int load = boxes[i].l;load>0;load--){
				if(dp[load]){
					dp[load + boxes[i].w] = max(dp[load+boxes[i].w], dp[load]+1);
					ans = max(ans, dp[load+boxes[i].w]);
				}
			}
			if(dp[boxes[i].w] == 0)
				dp[boxes[i].w] = 1;
		}
		cout<<ans<<endl;
	}
}