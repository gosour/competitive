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
int p,q,r,s,t,u;

void solve(double l, double h){
	double e = 2.7182818284;
	double l_val = p*exp(-l) + q*sin(l) + r*cos(l) + s*tan(l) + t*l*l + u; 
	double h_val = p*exp(-h) + q*sin(h) + r*cos(h) + s*tan(h) + t*h*h + u; 
	if(l_val*h_val > 0 ) {cout<<"No solution"<<endl; return;}
	else{
		double x = (l+h)/2;
		double x_val = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u; 
		if(l+0.00000001>=h) {printf("%.4lf\n",x); return;}
		else if(x_val * l_val < 0) solve(l,x);
		else solve(x,h); 
	}
}

int main(){
	while(scanf("%d %d %d %d %d %d", &p,&q,&r,&s,&t,&u)!=EOF){
		solve(0,1);
	}
}