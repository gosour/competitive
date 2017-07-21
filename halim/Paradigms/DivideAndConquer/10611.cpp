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

int n,q;
vi heights;

int main(){
	while(scanf("%d",&n)!=EOF){
		heights.clear();
		REP(i,n){
			int temp; scanf("%d",&temp); heights.pb(temp);
		}
		scanf("%d",&q);
		REP(i,q){
			int temp; scanf("%d",&temp);
			bool lower_possible = true, upper_possible = true;
			vector<int>::iterator lower_it = lower_bound(heights.begin(),heights.end(),temp);
			vector<int>::iterator upper_it = upper_bound(heights.begin(), heights.end(),temp);
			if(lower_it == heights.begin()) lower_possible = false;
			if(upper_it == heights.end()) upper_possible = false;
			if(lower_possible) cout<<*(lower_it-1)<<" ";
			else cout<<"X ";
			if(upper_possible) cout<<*upper_it;
			else cout<<"X";
			cout<<endl;
		}
	}
}