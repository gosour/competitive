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
int n, h;
void combination(int idx, int yet_to_select, vi &elements){
	if(idx == n){
		REP(i,n) cout<<elements[i];
		cout<<endl;
	}
	else{
		if(yet_to_select == n-idx){
			REP2(i,idx,n-1) elements.pb(1);
			combination(n,0,elements);
			REP2(i,idx,n-1) elements.pop_back();
		}else{
			elements.pb(0);
			combination(idx+1,yet_to_select,elements);
			if(yet_to_select != 0){
				elements.pop_back();
				elements.pb(1);
				combination(idx+1,yet_to_select-1,elements);
			}
			elements.pop_back();
		}
	}
}

int main(){
	int t; scanf("%d\n",&t); 
	bool first = true;
	while(t--){
		scanf("\n");
		scanf("%d %d",&n,&h);
		vi empty;
		if(first) first = false;
		else cout<<endl;
		combination(0,h,empty);
	}	
}