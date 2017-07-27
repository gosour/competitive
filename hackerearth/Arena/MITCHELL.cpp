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
char arr[25][25];
int main(){
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		REP2(i,1,n) REP2(j,1,m) cin>>arr[i][j];

		int count = 0;
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(arr[i][j] == '0'){
					count++;
					REP2(p,1,i){
						REP2(q,1,j) {arr[p][q] = ((arr[p][q] == '0')? '1': '0');}
					}
				}
			}
		}
		// REP2(i,1,n){
		// 	REP2(j,1,m){
		//  		cout<<arr[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		cout<<count<<endl;
	}
}