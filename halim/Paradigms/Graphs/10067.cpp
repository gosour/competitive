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
struct Node{
	int a, b, c, d;
	int dist;
};
int startNode; endNode;
Node forbidden[10005];
int fCount;

int bfs(){
	queue<Node> q;
	startNode.dist = 0;
}


int main(){
	int tests; scanf("%d",&tests);
	REP(t,tests){
		cin>>start.a>>start.b>>start.c>>start.d;
		REP(i,4) cin>>end.a>>end.b>>end.c>>end.d;
		cin>>fCount;
		REP(i,fCount){
				cin>>forbidden[i].a>>forbidden[i].b>>forbidden[i].c>>forbidden[i].d;
		}

		cout<<bfs()<<endl;

	}
}