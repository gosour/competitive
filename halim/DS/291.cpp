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
typedef vector<vi> vvi;

int matrix[5][5] = {
	{0,1,1,0,1},
	{1,0,1,0,1},
	{1,1,0,1,1},
	{0,0,1,0,1},
	{1,1,1,1,0}
};
int ans[10] = {0};

void backtrack(int start, int count){
	ans[count] = start; 
	if(count == 8){
		REP(i,9) printf("%d",ans[i]+1);
		cout<<endl;
		return;
	}
	for(int i=0;i<5;i++){
		if(matrix[start][i] == 1){
			matrix[start][i] = matrix[i][start] = 0;
			backtrack(i,count+1);
			matrix[start][i] = matrix[i][start] = 1;
		}
	}
}

int main(){
	backtrack(0,0);
}