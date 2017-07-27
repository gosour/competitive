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

int garment[21][21];
int garment_no[21];
int table[21][201];
bool isPossible;
void build_dp_table(int m, int c){
	memset(table, 0, sizeof(table));
	REP2(i,1,m){
		int currentBudget = i;
		REP(j,garment_no[0])
			if( garment[0][j] > table[0][i] && garment[0][j] <=currentBudget )
				table[0][i] = garment[0][j];
	}
	REP2(i,1,c-1){
		int count = 0;
		REP2(j,1,m){
			int currentBudget = j;
			int maxBudget = 0;
			int leastDifference = 99999999;
			REP(k,garment_no[i]){
				if(garment[i][k] > currentBudget) continue;
				if(leastDifference > (currentBudget - (table[i-1][currentBudget-garment[i][k]] + garment[i][k])) ) {
					if(table[i-1][currentBudget-garment[i][k]])
						maxBudget = (table[i-1][currentBudget-garment[i][k]] + garment[i][k]);
					else 
						continue;
					leastDifference = currentBudget - maxBudget;
				}
			}
			// if(maxBudget ==  0 || maxBudget < table[i-1][j]) maxBudget = table[i-1][j];
			if(maxBudget == 0) count++;
			table[i][j] = maxBudget;
		}
	}
}

int main(){
	int n; scanf("%d",&n);
	while(n--){
		int m, c; scanf("%d %d",&m,&c);
		REP(i,c){
			int k; scanf("%d",&k);
			garment_no[i] = k;
			REP(j,k)
				scanf("%d",&garment[i][j]);
		}
		isPossible = true;
		build_dp_table(m,c);
		// REP(i,c){
		// 	REP2(j,1,m){
		// 		cout<<table[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		if(table[c-1][m]) cout<<table[c-1][m]<<endl;
		else cout<<"no solution"<<endl;
	}
}