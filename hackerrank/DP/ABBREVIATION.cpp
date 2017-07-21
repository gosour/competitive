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
bool dp[1005][10005];
int main(){
	int t; cin>>t;
	while(t--){
		string a,b; cin>>a>>b;
		memset(dp,0,sizeof(dp));
		dp[0][0] = true;
		
		for(int i=0;i<=a.length();i++){
			for(int j=0;j<=b.length();j++){
				if(j==0 && i!=0 && toupper(a[i-1]) != a[i-1]){
					//a small letter can be delted
					dp[i][0] = true;
				}
				if(i!=0 && j!=0){
					bool x = (toupper(a[i-1]) == b[j-1])? dp[i-1][j-1] : false;
					bool y = (toupper(a[i-1]) !=a[i-1] && a[i-1] != b[j-1])? dp[i-1][j]: false;
					dp[i][j] = x || y || false; 
				}

			}
		}
		// REP(i,a.length()+1){
		// 	REP(j,b.length()+1){
		// 		cout<<i<<" "<<j << " : "<<dp[i][j]<<endl;
		// 	}
		// }
		if(dp[a.length()][b.length()]){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
}