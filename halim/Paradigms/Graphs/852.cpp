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
char board[10][10];
int visited[10][10];

int blackCount, whiteCount;
int tempCount;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

enum Neighbor{
	BLACK,
	WHITE,
	UNKNOWN
};
bool noCount;
Neighbor hasNeighbor;

void dfs(int x, int y){
	if(x<0 || y<0 || x>=9 || y>=9) return;
	if(board[x][y] == 'X'){
		if(hasNeighbor == WHITE )
			noCount = true;
		else
			hasNeighbor = BLACK;
		return;
	}
	if(board[x][y] == 'O'){
		if(hasNeighbor == BLACK)
			noCount = true;
		else
			hasNeighbor = WHITE;
		return;
	}
	visited[x][y] = 1;
	tempCount++;
	for(int i=0;i<4;i++){
		int a = x + dx[i];
		int b = y + dy[i];
		if(!visited[a][b])
			dfs(a,b);
	}

	visited[x][y] = 1;

}

int main(){
	int n; scanf("%d",&n); getchar();
	while(n--){
		blackCount = 0;
		whiteCount = 0;
		REP(i,9){
			char s[10];
			gets(s); 
			REP(j,9){
				sscanf(s+j,"%c",&board[i][j]);
				if(board[i][j] == 'O') whiteCount++;
				if(board[i][j] == 'X') blackCount++;
			}
		}
		memset(visited, 0,sizeof(visited));
		
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				tempCount = 0;
				noCount = false;
				hasNeighbor = UNKNOWN;
				if(!visited[i][j] && board[i][j] == '.'){
					dfs(i,j);
					if(!noCount && hasNeighbor == BLACK) blackCount += tempCount;
					if(!noCount && hasNeighbor == WHITE) whiteCount += tempCount;
				}
			}
		}
		cout<<"Black "<<blackCount<<" White "<<whiteCount<<endl;
	}
}