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
	int k,n; cin>>k>>n;
	vector<string> dict;
	REP(i,k){
		string s; cin>>s;
		dict.pb(s);
	}
	REP(i,n){
		string s; cin>>s;
		bool yes = true;
		bool sub = false;
		REP(i,s.length()){
			if(s[i] != '7' && s[i] != '4'){
				yes = false;
				break;
			}
			REP(j,k){
				bool ismatch = true;
				if(i+dict[j].size() > s.length()) {
					continue;
				}
				REP(l,dict[j].size()){
					if(i+l<s.length() && s[i+l] != dict[j][l]){
						ismatch = false;
						break;
					}
				}
				if(ismatch){
					sub = true;
					break;
				}
			}

			if(sub) break;
		}

		if(yes && sub){
			cout<<"Good"<<endl;
		}
		else if(yes && s.length() >= 47)
			cout<<"Good"<<endl;
		else 
			cout<<"Bad"<<endl;
	}
}