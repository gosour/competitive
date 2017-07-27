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
		int n,m; cin>>n>>m;
		int arr[1005] = {};
		REP(i,m) {
			int temp; cin>>temp; arr[temp] = 1;
		}
		bool take = true;
		vector<int> ass;
		REP2(i,1,n){
			if(take && arr[i]==0){
				cout<<i<<" ";
				take = false;
			}
			else if(!take && arr[i]==0){
				ass.pb(i);
				take = true;
			}

		}
		cout<<endl;
		REP(i,ass.size())
			cout<<ass[i]<<" ";
		cout<<endl;
	}
}