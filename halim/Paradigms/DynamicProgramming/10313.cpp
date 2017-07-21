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
#include<sstream>
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

long long dp[301][301][1002];

int main(){

		memset(dp,0,sizeof(dp));
		for(int i=0;i<301;i++)
			for(int j=0;j<1002;j++)
				dp[0][i][j] = 1;

		for(int i=1;i<301;i++){
			for(int j=1;j<301;j++){
				for(int k=1;k<1002;k++){
					long long x = (i-j >=0 && k-1>=0)? dp[i-j][j][k-1] : 0;
					long long y = (j-1>=0)? dp[i][j-1][k] : 0;
					dp[i][j][k] = x+y;
				}
			}
		}


		string s;
		int count = 0;
		int n,l1,l2;
		while(getline(cin,s)){
			count = l1 = l2 = 0;
			stringstream stream(s);
			while(1){
				int temp;
				stream >> temp;
				if(!stream) break;
				switch(count){
					case 0: n = temp; break;
					case 1: l1 = temp; break;
					case 2: l2 = temp; break;
				}
				count++;
			}

			if(count == 1){
				cout<<dp[n][n][n]<<endl;
			}
			if(count == 2){
				cout<<dp[n][n][l1]<<endl;
			}
			if(count == 3){
				if(n == 0 && l1==0) cout<<1<<endl;
				else if(l1!=0)
					cout<<dp[n][n][l2] - dp[n][n][l1-1]<<endl;
				else
					cout<<dp[n][n][l2] - dp[n][n][l1]<<endl;
			}
		}

}