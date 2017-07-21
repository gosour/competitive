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
	int negativeArr[50001];
	int leftArr[50001];
	vi ans;
	int m;
	vector<pair<int,int> > vertices;
	int tests; bool first = true;
	scanf("%d",&tests);
	while(tests--){
		scanf("\n");
		scanf("%d",&m);
		memset(leftArr,0,sizeof(leftArr));
		memset(negativeArr,0,sizeof(negativeArr));
		int x,y;
		while(scanf("%d %d",&x,&y) && !(x==0 && y==0)){
			if(x<0 && y>0) {
				negativeArr[y] = x;
				x = 0;
			}
			vertices.pb(make_pair(x,y));
			if(leftArr[x]<y) leftArr[x] = y;
		}
		bool flag = true;
		x = 0;

		if(!leftArr[0]) flag = false;
		ans.clear();
		while(flag){
			y = leftArr[x];
			ans.pb(x);
			if(y>=m) break;
			int nexty = y;
			int nextx = x;
			for(int i=y;i>=x+1;i--){
				if(leftArr[i] >= nexty ) {
					// cout<<i<<" "<<nextx<<" "<<nexty<<endl;
					nexty = leftArr[i]; nextx = i;
				}
			}
			if(nexty == y){
				flag = false;
			}
			x = nextx;
		}
		if(first) first = false;
		else cout<<endl;
		if(!flag) cout<<"0"<<endl;
		else{
			cout<<ans.size()<<endl;
			REP(i,ans.size()){
				int negval = negativeArr[leftArr[ans[i]]];
				if(negval==0)	cout<<ans[i]<<" "<<leftArr[ans[i]]<<endl;
				else cout<<negval<<" "<<leftArr[ans[i]]<<endl;
			}
		}
	}	
}