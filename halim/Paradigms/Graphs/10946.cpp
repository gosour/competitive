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
char land[55][55];
int alphabet[30];
int visited[55][55];
int x, y; 
int Count;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int a, int b, char c){
	if(a<0 || b<0 || a>=x || b>=y) return;
	// cout<<a<<" "<<b<<" "<<c<<endl;
	visited[a][b] = 1;
	Count++;
	for(int i=0;i<4;i++){
		int p = dx[i] + a;
		int q = dy[i] + b;
		if(!visited[p][q] && land[p][q] == c)
			dfs(p,q,c);
	}
}

bool myCompare(pair<int,int>a, pair<int,int> b){
	if(a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

int main(){
	int t =1;
	while(scanf("%d %d",&x,&y) && x!=0 && y!=0){
		getchar();
		REP(i,x){
			char s[55];
			gets(s);
			REP(j,y){
				sscanf(s+j,"%c",&land[i][j]);
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(alphabet,0, sizeof(alphabet));
		vector<pair<char, int> > vii;
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				Count = 0;
				if(!visited[i][j] && land[i][j]!='.'){
					dfs(i,j,land[i][j]);
					vii.pb(make_pair(land[i][j],Count));
				}
			}
		}

		cout<<"Problem "<<t++<<":"<<endl;
		sort(vii.begin(),vii.end(),myCompare);
		for(int i=0;i<vii.size();i++){
			cout<<(char)(vii[i].first)<<" "<<vii[i].second<<endl;
		}
	}	
}