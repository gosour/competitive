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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int w,h;
int dieCount,dotCount;
vi die;
int visited[55][55];
char arr[55][55];

void subdfs(int a, int b){
	arr[a][b] = '*';
	for(int i=0;i<4;i++){
		int x = dx[i] + a;
		int y = dy[i] + b;
		if(x>=0 && y>=0 && x<h && y<w && arr[x][y]=='X'){
			subdfs(x,y);
		}
	}
}


void superdfs(int a, int b){
	arr[a][b] = '.';
	for(int i=0;i<4;i++){
		int x = dx[i] + a;
		int y = dy[i] + b;
		if(x>=0 && y>=0 && x<h && y<w && arr[x][y]!='.'){
			if(arr[x][y] == 'X') {
				subdfs(x,y);
				dotCount++;
			}
			superdfs(x,y);
		}
	}
}


int main(){
	int th = 1;
	while(scanf("%d %d\n",&w,&h) && w!=0 && h!=0){
		die.clear();
		REP(i,h){
			char str[60];
			gets(str);
			REP(j,w) sscanf(str+j,"%c",&arr[i][j]);
		}

		dieCount = 0;
		memset(visited, 0 , sizeof(visited));
		REP(i,h){
			REP(j,w){
				dotCount = 0;
				if(arr[i][j] == 'X'){
					subdfs(i,j);
					dotCount++;
				}
				if(arr[i][j] == '*'){
					dieCount++;
					superdfs(i,j);
				}
				if(dotCount!=0) die.pb(dotCount);
			}
		}

		cout<<"Throw "<<th++<<endl;
		sort(die.begin(), die.end());
		if(die.size())
			cout<<die[0];
		REP2(i,1,die.size()-1) cout<<" "<<die[i];
		cout<<endl;
		cout<<endl;
	}		
}