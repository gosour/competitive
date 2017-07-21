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
char board[4][4];
int shuffleArr[16];
int boardCount = 0;
int maxCount = 0;
bool checkRookPosition(int n, int p, int q){
	bool seen = false;

	REP(i,n){
		if(!seen && shuffleArr[p*n + i] == 1) {seen = true; continue;}
		if(seen && board[p][i] == 'X') {seen = false; continue;}
		if(seen && shuffleArr[p*n + i] == 1){return false; }
	}
	seen = false;
	REP(i,n){
		if(!seen && shuffleArr[i*n + q] == 1) {seen = true; continue;}
		if(seen && board[i][q] == 'X') {seen = false; continue;}
		if(seen && shuffleArr[i*n + q] == 1) {return false;}
	}

	return true;
}

int checkBoardConfiguration(int n){
	int rooks = 0;
	REP(i,n){
		REP(j,n){
			if(board[i][j] == 'X' && shuffleArr[i*n +j] == 1) return -1;
			if(shuffleArr[i*n + j] == 1){
				// DEBUG(i); DEBUG(j);
				if(!checkRookPosition(n,i,j)) return -1;
				else rooks++;
			} 
		}
	}
	return rooks;
}
void generateBoards(int total, int current){
	if(current >= total){
		// REP(i,sqrt(total)){
		// 	REP(j,sqrt(total)){
		// 		cout<< shuffleArr[i*(int)sqrt(total) + j];
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		int val = checkBoardConfiguration(sqrt(total)) ;
		// cout<<val<<endl;
		if(val != -1 && val>maxCount ) maxCount = val;
		boardCount++;
		return;
	}

	shuffleArr[current] = 0;
	generateBoards(total,current+1);
	shuffleArr[current] = 1;
	generateBoards(total,current+1);
}

int main(){
	int n;
	while(1){
		cin>>n; if(n==0) break;
		REP(i,n){
			REP(j,n){
				cin>>board[i][j];
			}
		}

		boardCount = 0; maxCount = 0;
		generateBoards(n*n,0);
		cout<<maxCount<<endl;
	}
}