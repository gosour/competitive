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
		int alpha[26] = {};
		string p1,p2; cin>>p1>>p2;
		REP(i,p1.length()) alpha[p1[i]-'a']++;
		REP(i,p2.length()) alpha[p2[i]-'a']++;
		int k; cin>>k;
		REP(i,k){
			string s; cin>>s;
			REP(i,s.length()) alpha[s[i]-'a']--;
		}
		bool result = true;
		REP(i,26){
			if(alpha[i]< 0) result = false;
		}
		if(result) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}