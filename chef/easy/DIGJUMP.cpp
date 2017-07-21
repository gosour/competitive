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
typedef pair<int,int> ii;
vector< vector<int> > occurances;
bool visited[100005];
int d[100005];

string s;

void explore(){
	queue<int> q;
	q.push(0); //queue holds index
	visited[0] = true;
	d[0] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		// DEBUG(s[u.first]);

		if(u == s.length()-1){
			cout<<d[u]<<endl;
			return;
		}

		if(u+1<s.length() && !visited[u+1]){
			q.push(u+1);
			visited[u+1] = true;
			d[u+1] = d[u] + 1;
		}
		if(u>0 && !visited[u-1]){
			q.push(u-1);
			visited[u-1] = true;
			d[u-1] = d[u] + 1;
		}
		REP(i,occurances[s[u]-'0'].size()){
			int v = occurances[s[u]-'0'][i];
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
				d[v] = d[u] + 1;
			}
		} 
	}
}

int main(){
	cin>>s;
	occurances.resize(10);
	memset(visited,0,sizeof(visited));
	REP(i,s.length()){
		int indx = s[i]-'0';
		int len = occurances[indx].size();
		occurances[indx].pb(i);
	}
	// REP(i,10){
	// 	cout<<i<<" : ";
	// 	REP(j,occurances[i].size()) cout<<occurances[i][j]<<" ";
	// 	cout<<endl;
	// }
	explore();
}