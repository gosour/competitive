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
	int original_idx;
	vector<int> dimensions;
};
vector<Box> boxes;
int k,n;

bool boxcmpr(Box a,Box b){
	return a.dimensions < b.dimensions;
}

bool canContain(Box a, Box b){
	REP(i,a.dimensions.size()){
		if(a.dimensions[i]<=b.dimensions[i]) return false;
	}
	return true;
}

int main(){
	while(scanf("%d %d",&k,&n)!=EOF){
		boxes.clear();
		REP(i,k){
			vi temp;
			REP(j,n){
				int t;
				scanf("%d",&t);
				temp.pb(t);
			}
			sort(temp.begin(),temp.end());
			Box box;
			box.original_idx = i;
			box.dimensions = temp;
			boxes.pb(box);
		}
		sort(boxes.begin(),boxes.end(),boxcmpr);
		
		//DP part
		int table[k];
		int path[k];
		for(int i=0;i<k;i++) {
			table[i] = 1;
			path[i] = i;
		}
		int ans = 1;
		int last_idx = 0;
		for(int i=1;i<k;i++){
			for(int j=0;j<i;j++){
				if(canContain(boxes[i],boxes[j])){
					if(table[i] < table[j] + 1){
						table[i] = table[j] + 1;
						path[i] = j;
					}
				}
			}
			if(table[i] > ans){
				ans = table[i];
				last_idx = i;
			}

		}
		// REP(i,k) cout<<path[i]<<":";
		// cout<<endl;
		cout<<ans<<endl;
		vi solution;
		while(path[last_idx] != last_idx)	{
			solution.pb(boxes[last_idx].original_idx);
			last_idx = path[last_idx];
		} 	
		solution.pb(boxes[last_idx].original_idx);
		reverse(solution.begin(),solution.end());
		REP(i,solution.size())
			cout<<solution[i]+1<<" ";
		cout<<endl;
	}
}