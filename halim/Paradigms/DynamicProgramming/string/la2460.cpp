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
int dp[505][505];
int main(){
	string s1,s2, name;
	getline(cin,name);
	getline(cin,s1);
	int len1 = s1.length();
	int t = 0; int maxScore = -INF;
	vector<string> queryStrings;
	vi scores;
	while(getline(cin,name)){
		if(!getline(cin,name)) break;
		getline(cin,s2);
		int len2 = s2.length();
		memset(dp,0,sizeof(dp));

		for(int i=0;i<=len1;i++) dp[i][0] = i*(-7);
		for(int i=0;i<=len2;i++) dp[0][i] = i*(-7);

		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				int score = 0;
				if(s1[i-1] == s2[j-1]) score = 5;
				dp[i][j] = max(dp[i-1][j] -7, max(dp[i][j-1] - 7, dp[i-1][j-1]  + (score? score: -4) ) );
			}
		}
		cout<<s2<<" "<<dp[len1][len2]<<endl;
		queryStrings.pb(s2);
		scores.pb(dp[len1][len2]);
		if(dp[len1][len2] > maxScore) maxScore = dp[len1][len2];
	}
	cout<<"The query sequence is:"<<endl;
	cout<<s1<<endl;
	cout<<endl;
	cout<<"The most similar sequences are:"<<endl;
	cout<<endl;
	bool first = true;
	for(int i=0;i<queryStrings.size();i++){
		if(scores[i] == maxScore){
			if(first) first = false;
			else cout<<endl;
			cout<<queryStrings[i]<<endl;
			cout<<"The similarity score is: "<<maxScore<<endl;	
		} 
	}
}