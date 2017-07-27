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
bool isGood(char c){
	if(c == 'a' | c== 'e' | c== 'i' | c=='o' | c== 'u') return true;
	return false;
}
int main(){
	string s; cin>>s;
	int c=0,t=0;
	int i=0;
	while(i<s.length()){
		t = 0;
		while(i<s.length() && isGood(s[i])){
			t++; i++;
		}
		i++;
		c = max(c,t);
	}
	cout<<c<<endl;
}