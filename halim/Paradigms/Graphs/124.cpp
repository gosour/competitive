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
#include<sstream>

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
#define TONUM(a) ((int)(a) - (int)'a')
#define TOCHAR(a) (char)((char)(a) + 'a')
typedef vector<int> vi;

char seq[25];
int visited[30];
int N;
vector< vector<int> > adjacencyList;

bool valid(char node){
	for(int i=0;i<adjacencyList[TONUM(node)].size();i++){
		if(visited[adjacencyList[TONUM(node)][i]]) return false;
	}
	return true;
}


void dfs(string result){
	// DEBUG(result);
	if(result.length() == N) {
		cout<<result<<endl;
	}
	for(int i=0;i<N;i++){
		if(!visited[TONUM(seq[i])]){
			visited[TONUM(seq[i])] = 1;
			if(valid(seq[i])) dfs(result + seq[i]);
			visited[TONUM(seq[i])] = 0;
		}
	}
}

int main(){
	string s1,s2;
	bool first = true;
	while(getline(cin,s1)){
		istringstream ss(s1);
		char a,b; N = 0;
		while(ss>>a){
			seq[N++] = a;
		}
		sort(seq,seq+N);

		getline(cin,s2);
		istringstream ss1(s2);
		adjacencyList.clear(); adjacencyList.resize(30);
		while(ss1>>a>>b){
			adjacencyList[TONUM(a)].pb(TONUM(b));
		}
		memset(visited,0,sizeof(visited));
		if(first) first = false;
		else cout<<endl;
		dfs("");
	}	
}