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
#define SQR(n)                ( (n) * (n) )
const int INF = 1<<29;


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back

typedef vector<int> vi;
const long long upperbound = 1000010;
const int MOD = 1000000007;

bitset<upperbound> bs;
vi primes;

void sieve(){
	bs.reset(); bs.flip(); //set all numbers to 1
	bs.set(0,false); bs.set(1,false);
	for(long long i = 2; i<upperbound;i++){
		if(bs[i] == true){
			for(long long j = i*i; j<upperbound;j+=i){
				bs[j] = false;
			}
		primes.pb(i);
		}
	}
}

bool isPrime(long long n){
	if(n < upperbound) return bs[n];
	REP2(i,0,primes.size() - 1) if(n % primes[i]) return false;
	return true; //works upto n<=primes[last]*primes[last]
}
int N,M;
int matrix[1003][1003];
bool visited[1003][1003]= {};
vector<pair<int,int> > currPath;
vector<pair<int,int> > maxPath;

int pathLength = 0, maxPathLength = 0;
int paths = 0;
int dx[] = {1,0,1};
int dy[] = {0,1,1};
bool greater = true;

bool isLexLarger(){
	// DEBUG(currPath.size());
	// DEBUG(maxPath.size());
	int len = min(currPath.size(),maxPath.size());
	// DEBUG(len);
	REP(i,len){
		// DEBUG(currPath[i].first); DEBUG(maxPath[i].first);
		if(currPath[i] > maxPath[i]) return true;
		if(currPath[i] < maxPath[i]) return false;
	}
	if(currPath.size() > maxPath.size()) return true;
	if(currPath.size() < maxPath.size()) return false;
	return false;
}

void bfs(int x,int y){
	if(x==N-1 && y==M-1){
		paths++;
		paths = paths%MOD;
		//If currPath is Lexicographically larger than maxPath then update maxPath
		if(maxPath.size() == 0 || isLexLarger())
			maxPath = currPath;
		return;
	}
	pair<int,int> prev;
	bool isFirst = true;
	REP(i,3){
		int u = x+dx[i];
		int v = y+dy[i];
		if(u>=0 && v>=0 && u<N && v<M && !visited[u][v] && isPrime(matrix[u][v])){
			visited[u][v] = true;
			currPath.pb(make_pair(u,v));
			bfs(u,v);
			visited[u][v] = false;
			currPath.pop_back();

			if(greater == true)
			prev.x = u
			prev.y = v;

			if(isFirst) isFirst = false;
		}
	}
}

int main(){
	sieve();
	cin>>N>>M;
	REP(i,N) REP(j,M) cin>>matrix[i][j];
	visited[0][0] = true;
	bfs(0,0);
	currPath.pb(make_pair(0,0));
	cout<<paths<<endl;
	if(paths){
		cout<<"1 1"<<endl;
		REP(i,maxPath.size()){
			cout<<maxPath[i].first + 1<<" "<<maxPath[i].second + 1<<endl;
		}
	}
}