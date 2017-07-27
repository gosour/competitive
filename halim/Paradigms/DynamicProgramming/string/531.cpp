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
int dp[105][105];
int pre[105][105];
int main(){
	while(1){
		vector<string> speech1, speech2;
		string s;
		cin>>s;
		if(cin.bad() || cin.eof() || cin.fail()) break;
		speech1.pb(s);
		while(cin>>s){
			if(s=="#") break;
			else speech1.pb(s);
		}
		while(cin>>s){
			if(s=="#") break;
			else speech2.pb(s);
		}

		memset(dp,0,sizeof(dp));
		int l1 = speech1.size(); int l2 = speech2.size();
 		for(int i=1;i<=l1;i++){
 			for(int j=1;j<=l2;j++){
 				if(speech1[i-1] == speech2[j-1]) {
 					dp[i][j] = 1 + dp[i-1][j-1];
 					pre[i][j] = 0; //signifies diagonally up
 				}
 				else{
 					if(dp[i-1][j] < dp[i][j-1]){
 						dp[i][j] = dp[i][j-1];
 						pre[i][j] = 2; //signifies left
 						
 					}
 					else{
 						dp[i][j] = dp[i-1][j];
 						pre[i][j] = 1; //signifies top
 					}
 				}
 			}
 		}

 		int i = l1,j = l2;
 		vector<string> ans;
 		// REP(i,l1+1){REP(j,l2+1) cout<<dp[i][j]<<" "; cout<<endl;}
 		cout<<dp[i][j];

 		while(i>0 && j>0){
 			if(pre[i][j] == 0) {
 				ans.pb(speech1[i-1]);
 				i--;j--;
 			}
 			else if(pre[i][j] == 1){
 				i--;
 			}
 			else
 				j--;
 		}

 		for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
 		cout<<endl;

	}
}