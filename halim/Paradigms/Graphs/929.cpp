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
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;

#define pb push_back
typedef vector<int> vi;
int maze[1000][1000];
int dist[1000][1000];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int n,m;

bool isValid(int x, int y){
	if(x < 0 || y < 0 || x>=n || y>=m) return false;
	else return true;
}

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		 scanf("%d %d",&n,&m);
		REP(i,n){
			REP(j,m){
				scanf("%d",&maze[i][j]);
				dist[i][j] = INF;
			}
		}

		priority_queue<iii, vector<iii>, greater<iii> > EdgeList;
		EdgeList.push(make_pair(maze[0][0],make_pair(0,0)));
		dist[0][0] = maze[0][0];
		while(!EdgeList.empty()){
			pair<int, pair<int,int> > top = EdgeList.top(); EdgeList.pop();
			if(dist[top.second.first][top.second.second] != top.first) continue;
			REP(i,4){
				int x = top.second.first + dx[i];
				int y = top.second.second + dy[i];
				if(isValid(x,y)){
					// cout<<x<<" "<<y<<endl;
					if(dist[x][y] > dist[top.second.first][top.second.second] + maze[x][y]){
						dist[x][y] = dist[top.second.first][top.second.second] + maze[x][y];
						EdgeList.push(make_pair(dist[x][y],make_pair(x,y)));
					}
				}
			}
			if(top.second.first == n-1 && top.second.second == m-1) break;
		}
		printf("%d\n",dist[n-1][m-1]);	
	}	
}