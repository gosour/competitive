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
struct Point{
	int x,y;
};
int X,Y,start_x, start_y, beeper_count;
int grid[21][21];
Point beepers[12];
int visited[12];
int min_len;
int dist(int beeper1, int beeper2){
	return abs(beepers[beeper1].x-beepers[beeper2].x) + abs(beepers[beeper1].y-beepers[beeper2].y);
}

void start(int current,int count,int path_len){
	visited[current] = 1;
	if(count==beeper_count-1){
		path_len += dist(current, 1);
		if(path_len < min_len) min_len = path_len;
	}else{
		REP2(i,2,beeper_count){
			if(visited[i] == 0) {
				start(i,count+1,path_len+dist(current,i));
			}
		}
	}
	visited[current] = 0;
}

int main(){
	int t; scanf("%d",&t);
	while(t--){
		cin>>X>>Y;
		cin>>start_x>>start_y;
		scanf("%d",&beeper_count);
		beeper_count++;
		beepers[1].x = start_x; beepers[1].y = start_y;
		REP2(i,2,beeper_count) scanf("%d %d",&beepers[i].x,&beepers[i].y);
		min_len = 1<<30;
		memset(visited,0,sizeof(visited));
		start(1,0,0);
		cout<<"The shortest path has length "<<min_len<<endl;
	}
}