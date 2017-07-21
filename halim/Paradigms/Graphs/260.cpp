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
char board[200][201];
bool visited[200][200];
int N;
bool black(){
	stack< pair<int,int> > S;
	pair<int,int> P;
	int di[] = {-1, -1, 0, 0, 1, 1};
	int dj[] = {-1, 0, -1, 1, 0, 1};
	int I,J;

	for(int i=0;i<N;i++){
		if(board[0][i] == 'b'){
			S.push(make_pair(0,i));
			visited[0][i] = true;
		}
	}

	while(!S.empty()){
		P = S.top();
		S.pop();
		if(P.first == N-1) return true;
		for(int i=0;i<6;i++){
			I = P.first + di[i];
			J = P.second + dj[i];

			if(I>=0 && I<N && J>=0 && J<N && board[I][J]=='b' && !visited[I][J]){
				visited[I][J] = true;
				S.push(make_pair(I,J));
			}

		}
	}

	return false;

}

int main(){
	int n, c = 1;
	while(scanf("%d",&N)!=EOF && N!=0){
		REP(i,N) scanf("%s",board[i]);

		for(int i=0;i<N;i++) fill(visited[i],visited[i]+N, false);
		printf("%d ",c++);
		if(black()) printf("B\n");
		else printf("W\n");
	}
}