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
	string s = "GeeksforGeeks A computer Science portal for Geeks";
	int p = 0;
	int li,lj,si,sj;
	int mw,sw;
	li = lj = si = sj = mw = 0;
	sw = INF;

	for(int i=1;i<s.length();i++){
		if(s[i] == ' ' || i+1==s.length()){
			if(i-p > mw){
				li = p;
				lj = i;
				mw = (i-p);
			}
			if(i-p < sw){
				si = p;
				sj = i;
				sw = (i-p);
			}
			if(i+1 != s.length()) p = i+1;
		}
	}
	REP2(i,li,lj) cout<<s[i];
	cout<<endl;
	REP2(i,si,sj) cout<<s[i];
	cout<<endl;
}