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
	int tests = 1;
	while(1){
		int temp;
		vector<int> heights;
		scanf("%d",&temp); if(temp == -1) break;
		heights.pb(temp);
		while(scanf("%d",&temp)!=EOF && temp!=-1){
			heights.pb(temp);
		}

		int n = heights.size();
		int ans = 1;
		int lds[n];
		REP(i,n) lds[i] = 1;
		lds[0] = 1;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(heights[i] <= heights[j]){
					if(lds[i] < lds[j] + 1){
						lds[i] = lds[j] + 1;
						ans = max(ans,lds[i]);
					}
				}
			}
		}
		if(tests != 1) cout<<endl;
		cout<<"Test #"<<tests++<<":"<<endl;
		cout<<"  "<<"maximum possible interceptions: "<<ans<<endl;
	}	
}