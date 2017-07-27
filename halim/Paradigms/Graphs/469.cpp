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

char arr[110][110],used[110][110];
int ans;

void dfs(int x, int y){
	if(x<0 || y<0 || arr[x][y] == 0)
		return;
	if(used[x][y]!=0 || arr[x][y] !='W')
		return;
	used[x][y] = 1;

	ans++;

	int i,j;

	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++)
			dfs(x+i,y+j);
}

int main(){
	int T;
	scanf("%d",&T); getchar(); getchar();
	while(T--){
		char str[110];
		int n = 0;
		int row = 0;
		while(gets(str)){
			int i,j;
			if(str[0] == '\0') break;
			if(str[0]!='W' && str[0]!='L'){
				sscanf(str,"%d %d",&i,&j);
				memset(used, 0, sizeof(used));
				ans = 0;
				dfs(i-1,j-1);
				printf("%d\n", ans);
			}else{
				sscanf(str,"%s", arr[n]);
				n++;
			}
		}
		if(T)
			puts("");
	}
	return 0;	
}