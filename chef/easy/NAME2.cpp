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
int dp[2505][2505] = {};
int main(){
	int t; cin>>t;
	string a, b;
	while(t--){
		cin>>a>>b;
		int alen = a.length(), blen = b.length();
		if(alen > blen){
			string c = a;
			a = b;
			b = c;
		}

		int j = 0;
		bool val = true;
		REP(i,alen){
			if(j >= blen){ 
				val = false;
				break;
			}

			while(j<blen && a[i] != b[j])
				j++;
		}

		if(val)  cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}