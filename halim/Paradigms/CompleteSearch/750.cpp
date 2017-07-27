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
int tc, a,b,linecounter;
int x[9];

bool canplace(int column, int row){
	/*Check for all previous queen placements*/
	/*1. They don't share a row
	2. They don't share a diagonal
	*/
	for(int i=1;i<column;i++){
		if(x[i] == row || abs(x[i] - row) == abs(i-column))
			return false;
	}
	return true;
}

void NQueens(int n){
	for(int i=1;i<=8;i++){
		if(canplace(n,i)){
			x[n] = i; //Place the queen
			//Check if this is a complete solution
			if(n == 8 && x[b] == a){ //Is this also a candidate solution
				printf("%2d %d", ++linecounter, x[1]);
				for (int j = 2; j <= 8; j++) printf(" %d", x[j]);
				printf("\n");
			}else{
				NQueens(n+1);
			}
		}
	}
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&a, &b);
		memset(x,0,sizeof x); linecounter = 0;
		printf("SOLN    COLUMN\n");
		printf(" #    1 2 3 4 5 6 7 8\n\n");
		NQueens(1); //NQueens(n) places the a queen in the nth column
		if(tc) printf("\n");
	}
}