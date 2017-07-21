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
char arr[105][105];
int visited[105][105];

void dfs(int a, int b){
	visited[a][b] = 1;
	int di[8] = {-1,-1,-1,0,1,1, 1, 0};
	int dj[8] = {-1, 0, 1,1,1,0,-1,-1};

	for(int i=0;i<8;i++){
		int x = a + di[i];
		int y = b + dj[i];
		if(!visited[x][y] && arr[x][y]=='@'){
			dfs(x,y);
		}
	}
}

int main(){
	int m,n;
	while(scanf("%d %d",&m,&n) && m!=0 && n!=0){
		getchar();
		char str[105];
		REP(i,m){
			gets(str);
			// cout<<str<<endl;
			REP(j,n) sscanf(str+j,"%c",&arr[i][j]);
		}

		memset(visited,0,sizeof(visited));
		int ans = 0;
		REP(i,m){
			REP(j,n){
				if(!visited[i][j] && arr[i][j] == '@'){
					dfs(i,j);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}	
}