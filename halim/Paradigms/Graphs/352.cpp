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
int N;
char arr[28][28];
int visited[28][28];

void dfs(int p, int q){
	// cout<<p<<" "<<q<<endl;
	visited[p][q] = 1;
	int di[8] = {-1,-1,-1,0,1,1, 1, 0};
	int dj[8] = {-1, 0, 1,1,1,0,-1,-1};

	for(int i=0;i<8;i++){
		int x = p + di[i];
		int y = q + dj[i];
		if(x>=0 && y>=0 && x<N && y<N && arr[x][y] == '1' && !visited[x][y]){
			// cout<<"i: "<<i<<endl;
			// cout<<"Going to "<<x<< " "<<y<<endl;
			dfs(x,y);
		}
	}

}	

int main(){
	int tests = 1;
	while(scanf("%d",&N)!=EOF){
		getchar();
		REP(i,N){
			char s[30];
			gets(s);
			REP(j,N) {
				sscanf(s+j,"%c",&arr[i][j]);
			}
		}

		memset(visited,0, sizeof(visited));
		int count = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j] == '1' && !visited[i][j]){
					count++;
					dfs(i,j);
					// cout<<"----"<<endl;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n",tests++,count);
	}
}