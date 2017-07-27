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
int arr[505][505];
int dist[505][505];
bool visited[505][505];


int dx[] = {-1,-1,-1,0,1,1, 1, 0};
int dy[] = {-1, 0, 1,1,1,0,-1,-1};

int main(){
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		queue<pair<int,int> > Q;
		int mx = 0; 
		memset(dist,0,sizeof(dist));
		memset(visited,0,sizeof(visited));

		REP(i,n){
			REP(j,m){
				cin>>arr[i][j];
				mx = max(arr[i][j],mx);
			}
		}

		REP(i,n){
			REP(j,m){
				if(arr[i][j] == mx) {
					Q.push(make_pair(i,j));
					visited[i][j] = true;
				}
			}
		}
		int maxDist = 0;
		while(!Q.empty()){
			pair<int,int> u = Q.front(); Q.pop();
			REP(i,8){
				int vx,vy;
				vx = u.first + dx[i];
				vy = u.second + dy[i];
				if(vx>=0 && vy>=0 && vx<n && vy<m && !visited[vx][vy]){
					Q.push(make_pair(vx,vy));
					dist[vx][vy] = dist[u.first][u.second] + 1;
					visited[vx][vy] = true;
					maxDist = max(maxDist, dist[vx][vy]);
				}
			}

		}
		cout<<maxDist<<endl;
	}
}