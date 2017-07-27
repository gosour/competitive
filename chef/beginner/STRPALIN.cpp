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
	bitset<26> bs;
	while(t--){
		bs.reset();
		string A,B; cin>>A>>B;
		bool exists = false;
		// REP(i,A.length()){
		// 	int len = 0;
		// 	while(len+i < A.length()){
		// 		string b = A.substr(i,len);
		// 		if()
		// 		reverse(b.begin(),b.end());
		// 		exists = (B.find(b) != string::npos);
		// 		len++;
		// 	}
		// }
		
		REP(i,A.length())
			bs[(int)A[i]-'a'] = true;
		REP(i,B.length())
			if(bs[B[i]-'a']) exists = true;

		if(exists) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

	}
}