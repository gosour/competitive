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
char s[35][85];
int slen[35];
int visited[35][85];

bool isValid(int x, int y){
	if(x<0 || y<0) return false;
	if(s[x][y] == ' ' || s[x][y] == '*') return true;
	return false;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x, int y){
	if(!isValid(x,y) || visited[x][y]){
		return;
	}

	visited[x][y] = 1;
	s[x][y] = '#';
	for(int i=0;i<4;i++){
		dfs(x+dx[i],y+dy[i]);
	}
}

int main(){
	int tests; scanf("%d",&tests); getchar();
	int n = 0;
	int startx, starty;
	while(tests--){
		n = 0;
		while(gets(s[n])){
			if(s[n][0] == '_'){
				break;
			}
			slen[n] = strlen(s[n]);
			for(int i=0;i<slen[n];i++){
				if(s[n][i] == '*'){
					startx = n;
					starty = i;
				}
			}
			n++;
		}
		memset(visited,0,sizeof(visited));
		dfs(startx,starty);

		REP(i,n){
			REP(j,slen[i]) cout<<s[i][j];
			cout<<endl;
		}
		puts(s[n]); 
	}
}