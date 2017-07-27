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
	int n; cin>>n;
	string balphabet; cin>>balphabet;
	char map[26];
	REP(i,26){
		map[balphabet[i]-'a'] = (char)(i+'a');
	}
	REP(i,n){
		string s; cin>>s;
		REP(i,s.length()){
			char c = s[i];
			char f = tolower(c);
			if(f>='a' && f<='z'){
				if(c==f)
					cout<<balphabet[f-'a']; 
				else
					cout<<(char)toupper(balphabet[c-'A']);
			}else if(c == '_')
				cout<<" ";
			else
				cout<<c;
		}
		cout<<endl;
	}
}