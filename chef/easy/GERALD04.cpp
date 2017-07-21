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
#include<iomanip>

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
		int ht1,mt1, ht2,mt2, d;
		char c;
		cin>>ht1>>c>>mt1;
		cin>>ht2>>c>>mt2;
		cin>>d;

		double diff1 = ((ht1-ht2)*60 + mt1) - mt2;
		double diff2;
		if(diff1 > d) {
			if((diff1-d) > d){
				diff2  = 0;
			}else{
				diff2 = (double)(d - (diff1-d))/2;
			}			
		}
		else{
			diff2 = (double)(diff1)/2;
		}
		cout<<setprecision(1)<<std::fixed<<diff1+d<<" "<<diff1+ diff2 <<endl;
	}
}