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
int r,c;
char mazeMap[305][305];
int distColor[305][305][4];
int gi[4]  = {0,1,0,-1};
int gj[4] = {-1,0,1,0};
struct Node{
	int x, y, dist, move;
};

bool valid(int si, int sj, int fi,int fj,int moveCount){
	if(fi<0 || fj<0 || fi>=r || fj>=c) return false;
	bool isValid = true;
	if(si==fi){
		REP2(i,min(sj,fj),max(sj,fj)) if(mazeMap[si][i] == '#') isValid = false;
	}
	else{
		REP2(i,min(si,fi),max(si,fi)) if(mazeMap[i][sj] == '#') isValid = false;
	}

	if(distColor[fi][fj][moveCount]) isValid = false;

	return isValid;
}

bool bfs(int si, int sj, int di, int dj){
	queue<Node> q;
	Node first; first.x = si; first.y = sj; first.dist = 0; first.move = 1;
	q.push(first);
	distColor[si][sj][first.move] = true; //Mark as visited with this move

	while(!q.empty()) {
		Node u = q.front(); q.pop();
		int moves = u.move;
		// cout<<"Visiting "<<u.x<<":"<<u.y<<" and will find "<<moves<<" thereafter"<<endl;
		distColor[u.x][u.y][moves] = true;
		if(u.x == di && u.y == dj){
				cout<<u.dist+1<<endl;
				return true;
		}
		REP(i,4){
			int vi = (u.x+moves*gi[i]);
			int vj = (u.y+moves*gj[i]);
			int vmove = ((moves+1)%4 == 0 )? 1 : moves+1;
			if(valid(u.x,u.y,vi,vj,vmove)){
				//count as not visited and is eligble to visit
				Node temp; temp.x = vi; temp.y = vj; temp.dist = u.dist+1;
				temp.move = vmove;
				q.push(temp);
			}
		}

	}
	return false;
}

int main(){
	int T; scanf("%d",&T);
	REP(t,T){
		scanf("%d %d",&r,&c); getchar();
		int si,sj,di,dj;
		REP(i,r){
			REP(j,c){
				char p = getchar();
				mazeMap[i][j] = p;
				if(p == 'S') {si = i; sj = j;}
				if(p == 'E') {di = i; dj = j;}
			}
			getchar();
		}

		memset(distColor,0,sizeof(distColor));
		int ans = bfs(si,sj,di,dj);
		if(!ans) cout<<"NO"<<endl;		
	}	
}