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
int main(){
	string s, t;
	while(1){
		cin>>s>>t;
		bool found = false;
		if(cin.fail()) break;
		int si=0, ti=0;
		while(ti<t.size()){
			if(si > s.size()-1) {found = true; break;}
			while(ti<t.size()){
				if(s[si] == t[ti++]){
					si++;
					break;
				}
			}
		}
		if(si > s.size()-1) found=true;
		if(found == true) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}	
}