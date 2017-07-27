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
	getchar();
	getchar();
	bool first = true;
	char str[100];
	// DEBUG(tests);
	while(tests--){
		vi heights;
		bool end = false;
		while(gets(str)){
			if(str[0] == '\0') {
				break;
				end = true;
			}
			int temp;
			sscanf(str,"%d",&temp);
			heights.pb(temp);
		}
		if(end) break;
		int len = heights.size();
		// DEBUG(len);
		vi table; table.resize(len,1);
		vi parent; parent.resize(len,-1);
		int ans = 1;
		int last = 0;
		for(int i=1;i<len;i++){
			for(int j=0;j<i;j++){
				if(heights[i] > heights[j] && table[j] + 1 > table[i]){
					// cout<<heights[i]<<" "<<heights[j]<<" "<<table[i]<<endl;
					table[i] = table[j] + 1;
					parent[i] = j;
					if(table[i] > ans){
						last = i;
						ans = table[i];
					}
				}
			}
		}
		if(first) first = false;
		else cout<<endl;
		printf("Max hits: %d\n",ans);
		vi solution;
		while(parent[last]!=-1){
			solution.pb(heights[last]);
			last = parent[last];
		}
		solution.pb(heights[last]);
		reverse(solution.begin(),solution.end());
		REP(i,solution.size())
			cout<<solution[i]<<endl;

	}	
}