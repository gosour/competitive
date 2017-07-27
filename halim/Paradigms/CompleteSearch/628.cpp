#include<cstdio>
#include<iostream>
#include<sstream>
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
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
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
typedef vector<string> vs;

vs dictionary; int n,m;
string ruleset;

void Enumerate(int index,string till_now){
	if(index == ruleset.size()){
		cout<<till_now<<endl;
	}else{
		if(ruleset[index] == '#'){
			REP(i,dictionary.size()){
				Enumerate(index+1,till_now+dictionary[i]);
			}
		}else{
			REP(i,10){
				Enumerate(index+1,till_now+ SSTR(i) );
			}
		}
	}

}

int main(){
	while(scanf("%d",&n) != EOF){ 
		string s;
		dictionary.clear();
		REP(i,n){
			cin>>s; dictionary.pb(s);
		}
		scanf("%d",&m);
		cout<<"--"<<endl;
		REP(i,m){
			cin>>ruleset;
			Enumerate(0,"");
		}
	}
}