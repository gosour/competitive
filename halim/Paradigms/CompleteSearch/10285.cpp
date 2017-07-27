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
int t,r,c,maxPath; string name;
int arr[100][100];

bool check(int r1, int c1, int r2, int c2){
	if(arr[r1][c1] > arr[r2][c2]) return true;
	else return false;
}

void calculate_longest(int row,int column, vi &path){
	bool isEnd = true;
	if(row >= r || column >= c ) return;
	path.pb(arr[row][column]);
	if(row>=1 && check(row,column, row-1, column)) {calculate_longest(row-1,column, path); isEnd = false;}
	if(column >=1 && check(row, column, row, column-1)) {calculate_longest(row, column-1, path); isEnd = false;}
	if(row<r-1 && check(row,column,row+1,column)) {calculate_longest(row+1, column, path); isEnd = false;}
	if(column<c-1 && check(row,column,row,column+1)) {calculate_longest(row, column+1, path); isEnd = false;}
	if(isEnd){
		if(path.size() > maxPath) maxPath = path.size();
	}
	path.pop_back();
}

int main(){
	
	scanf("%d",&t);	
	while(t--){
		cin>>name;
		scanf("%d %d",&r,&c);
		REP(i,r){
			REP(j,c){
				scanf("%d",&arr[i][j]);
			}
		}

		maxPath = 0;
		REP(i,r){
			REP(j,c){
				vi path;
				calculate_longest(i,j,path);
			}
		}

		cout<<name<<": "<<maxPath<<endl;
	}
}