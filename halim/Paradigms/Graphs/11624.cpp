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
char maze[1005][1005];
struct  Point{
	int x, y, dist;	
};
int r,c;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void bfsJoe(){

}

int main(){
	int tests; scanf("%d",&tests);
	REP(t,tests){
		scanf("%d %d",&r,&c); getchar();
		Point joe;
		Vector<Point> fires;
		REP(i,r){
			REP(j,c){
				char c; scanf("%c",&c); maze[i][j] = c;
				if(maze[i][j] == 'J') {joe.x = i; joe.y = j;}
				if(maze[i][j] == 'F') {
					Point fire;
					fire.x = i; fire.y = j;
					fires.pb(fire);
				}
			}
			getchar();
		}

		bfsJoe(joe);
		bfsFire();
		// REP(i,r){
		// 	REP(j,c){
		// 		cout<<maze[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
	}
}