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
	while(t--){
		int n; cin>>n;
		string row1, row2;
		int r1,r2; r1 = 0, r2 = 0;
		int r1Special  = 0 , r2Special = 0;

		int gr = 0;
		cin>>row1>>row2;
		bool onLeftTop = false;
		bool onLeftBottom = false;
		int fences = 0;

		REP(i,n){
			if(row1[i] == '*' && row2[i] == '*'){
				r1++; r2++;
				if(onLeftTop || onLeftBottom){
					fences++;
				}
				onLeftTop = true;
				onLeftBottom = true;
			}
			else if(row1[i] == '*') {
				r1++;
				if(onLeftTop){
					fences++;
					if(onLeftBottom) onLeftBottom = false;
				}
				onLeftTop = true;
			}
			else if(row2[i] == '*') {
				r2++;
				if(onLeftBottom){
					fences++;
					if(onLeftTop) onLeftTop = false;
				}
				onLeftBottom = true;
			}
		}

		if(r1 && r2) fences ++; //one horizontal

		cout<<fences<<endl;
	}
}