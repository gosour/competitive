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

void calculate(int n){
	int a, b;
	int sign = (n>0) ? 1: -1;
	n *= sign;

	if(n == 0){printf("0 0\n"); return;}

	if(n%4 == 2){printf("Bachelor Number.\n"); return;}
	if(n%2 == 0){
		a = (n>>2) + 1;
		b = (n>>2) - 1;
	}
	else{
		b = (n-1)>>1;
		a = b+1;
	}

	if(sign > 0) printf("%d %d\n",a,b);
	else printf("%d %d\n",b,a);

}

void calculate(int n1,int n2){
	int r = 0;
	while(n1<=n2){
		if(n1%4 == 2) r++;
		n1++;
	}
	printf("%d\n",r);
}

int main(){
	static char s[1024];
	int t, n1, n2 = 0;
	while(gets(s)){
		if(sscanf(s,"%d %d", &n1,&n2) == 1){
			calculate(n1);
		}
		else calculate(n1, n2);
		n2 = 0; 
	}	
}