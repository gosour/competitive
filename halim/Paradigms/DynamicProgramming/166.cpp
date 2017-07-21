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
const int DENOM = 6;
const int MAX = 501;
int denoms[DENOM] = {5,10,20,50,100,200};
int coins[DENOM];
int minTable[MAX];
int main(){
	REP(i,MAX) minTable[i] = 99999999 ;
	minTable[0] = 0;
	for(int i=1;i<MAX;i++){
		for(int j=0;j<DENOM;j++){
			if(denoms[j] <= i)
				minTable[i] = min(minTable[i],1 + minTable[i-denoms[j]]);
		}
	}

	while(scanf("%d %d %d %d %d %d",&coins[0],&coins[1],&coins[2],&coins[3],&coins[4],&coins[5])){
		int sum = 0;
		REP(i,DENOM) sum += coins[i];
		if(!sum) break;
		double d; long amount;
		scanf("%lf",&d);
		amount = d*100 + 0.5;
		DEBUG(amount);

		REP(i,21){
			cout<<minTable[i]<<" ";
		}
		cout<<endl;
	}
}