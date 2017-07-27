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
int square[105][105];
int visited[105][105];
int regions[10005];
int n,Count;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x, int y, int region){
	if(x>=n || y>= n || x<0 || y<0) return;
	visited[x][y] = 1;
	Count++;
	for(int i=0;i<4;i++){
		int a = dx[i] + x;
		int b = dy[i] + y;
		if(!visited[a][b] && square[a][b] == region)
			dfs(a,b,region);
	}
}

int main(){
	while(scanf("%d",&n) && n!=0){
		getchar();
		int region = 1;
		memset(regions,0,sizeof(regions));
		memset(square, 0, sizeof(square));
		memset(visited, 0 , sizeof(visited));
		REP2(i,1,n-1){
			char s[250];
			gets(s);
			int len = strlen(s) ;
			for(int j = 0; j<len;j+=4){
				int x, y;
				sscanf(s+j,"%d %d",&x,&y);
				square[x-1][y-1] = region;
			}
			region++;
		}
		DEBUG("ALL DONE");
		bool possible = true;
		// REP(i,n){
		// 	REP(j,n){
		// 		Count = 0;
		// 		if(!visited[i][j] && regions[square[i][j]]){
		// 			possible = false;
		// 			break;
		// 		}
		// 		if(!visited[i][j]){
		// 			dfs(i,j,square[i][j]);
		// 			regions[square[i][j]] = Count;
		// 		}
		// 	} 	
		// }

		if(possible) cout<<"good"<<endl;
		else cout<<"wrong"<<endl;

	}		
}