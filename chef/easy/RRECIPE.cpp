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
#define MOD 10000009
typedef vector<int> vi;

int main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		int res=1;
		int l = s.length();
        for(int i=0;i<(l+1)/2;i++)
        {
            if(s[i]==s[l-1-i])
            {
                if(s[i]=='?')
                res=(res*26)%MOD;
                
            }
            else
            {
                if(s[i]!='?'&&s[l-1-i]!='?')
                {
                    res=0;
                break;
                }
                
            }
        }
        cout<<res<<endl;
	}
}