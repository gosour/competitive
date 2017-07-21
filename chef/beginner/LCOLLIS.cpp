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
	int arr[15][15];
	while(t--){
		int n,m; cin>>n>>m;
		REP(i,n)
			REP(j,m){
				char ch; cin>>ch;
				if(ch == '0') arr[i][j] = 0;
				else arr[i][j] = 1;
			}
		int colls = 0;
		REP(j,m){
			int c = 0;
			REP(i,n){
				c += arr[i][j];
			}
			if(c > 2)
				colls += c*(c-1)/2;
			else if(c==2)
				colls += 1;
			else 
				colls += 0;
		}
		cout<<colls<<endl;
	}
}