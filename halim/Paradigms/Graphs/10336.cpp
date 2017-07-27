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
int alphabets[30];
char myMap[500][500];
int visited[500][500];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int r,c;
void dfs(int a, int b, char c){
	if(a<0 || b<0 || a>=r || b>=c) return;
	visited[a][b] = 1;
	for(int i=0;i<4;i++){
		int x = a + dx[i];
		int y = b + dy[i];
		if(myMap[x][y] == c && !visited[x][y])
			dfs(x,y,c);
	}
}

bool myCompare(pair<int,int>a, pair<int,int> b){
	if(a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

int main(){
	int n,t=1;
	scanf("%d",&n); getchar();
	while(n--){
		scanf("%d %d",&r,&c); getchar();
		memset(alphabets,0,sizeof(alphabets));
		char s[500];
		REP(i,r){
			gets(s);
			REP(j,c){
				sscanf(s+j,"%c",&myMap[i][j]);
			}
		}

		memset(visited,0,sizeof(visited));
		memset(alphabets,0,sizeof(alphabets));
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(!visited[i][j]){
					dfs(i,j,myMap[i][j]);
					alphabets[myMap[i][j] - 'a']++;
				}
			}
		}
		vector<pair<int,int> > answer;
		REP(i,30){
			if(alphabets[i]!=0){
				answer.pb(make_pair(i,alphabets[i]));
			}
		}
		sort(answer.begin(),answer.end(),myCompare);
		cout<<"World #"<<t++<<endl;
		for(int i=0;i<answer.size();i++){
			cout<<(char)('a' + answer[i].first)<<": "<<answer[i].second<<endl;
		}
	}	
}