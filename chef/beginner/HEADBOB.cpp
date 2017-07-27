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
char carr[10005];
int main(){
	int t; cin>>t;
	while(t--){
		int len; cin>>len;
		int yc = 0, nc=0, ic = 0;
		REP(i,len){
			cin>>carr[i];
			switch(carr[i]){
				case 'Y': yc++; break;
				case 'N': nc++; break;
				case 'I': ic++; break;
			}
		}
		if(ic) cout<<"INDIAN"<<endl;
		else if(yc) cout<<"NOT INDIAN"<<endl;
		else cout<<"NOT SURE"<<endl;
	}	
}