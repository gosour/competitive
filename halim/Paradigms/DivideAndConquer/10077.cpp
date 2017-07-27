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
int m,n;

void represent(int lm,int ln,int rm, int rn){
	// cout<<lm<<"/"<<ln<<"&"<<rm<<"/"<<rn<<endl;
	int mid_m = lm+rm, mid_n = ln+rn;
	if(mid_m == m && mid_n == n){cout<<endl; return;}
	if(m*mid_n > mid_m*n){
		cout<<"R";
		represent(mid_m,mid_n,rm,rn);
	}else{
		cout<<"L";
		represent(lm,ln,mid_m,mid_n);
	}
}

int main(){
	while(scanf("%d %d",&m,&n) && (m!=1 || n!=1)){
		represent(0,1,1,0);
	}	
}