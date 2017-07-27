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
int dp[25][25];
int main(){
	string s1, s2;
	while(1){
		cin>>s1; if(s1=="#" ) break;
		cin>>s2;

		int l1 = s1.length();
		int l2 = s2.length();
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=l1;i++) dp[i][0] = i;
		for(int j=0;j<=l2;j++) dp[0][j] = j;

		for(int i=1;i<=l1;i++){
			for(int j=1;j<=l2;j++){
				int cost;
				if(s1[i-1] == s2[j-1]) cost = 0; else cost =1;
				dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1]+1, dp[i-1][j-1] + cost));
			}	
		}


		// REP2(i,0,l1){REP2(j,0,l2) cout<<dp[i][j]<<" "; cout<<endl;}

		//Now construct your edited string
		int i=l1,j=l2;
		vector<string> commands;
		char buf[25];
		while(i>0 && j>0){ //We want to go until the first char, (we won't go where i aswell as j == 0, meaning no char)
			if(dp[i-1][j] + 1 == dp[i][j]){  //Meaning we have to 
				sprintf(buf,"D%c%02d",s1[i-1],j+1);
				i--;
			}
			else if(dp[i][j-1] + 1 == dp[i][j]){
				sprintf(buf,"I%c%02d",s2[j-1],j);
				j--;
			}else{
				if(s1[--i] != s2[--j]) sprintf(buf,"C%c%02d",s2[j],j+1);
				else  continue;
			}	
			commands.pb(string(buf));
		}
		while(i>0){
			sprintf(buf,"D%c%02d",s1[--i],1);
			commands.pb(string(buf));
		}
		while(j>0){
			sprintf(buf,"I%c%02d",s2[j-1],j);
			commands.pb(string(buf));
			j--;
		}

		for(i=commands.size()-1;i>=0;i--)
			cout<<commands[i];
		cout<<"E"<<endl;
	}
}