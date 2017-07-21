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
struct Post{
	int id;
	int p;
	string s;
};

Post posts[100001];
Post ans[100001];
bool cmp(Post p1, Post p2){
	if(p1.p > p2.p) return true;
	else return false;
}
int main(){
	int n,m;
	cin>>n>>m;
	int specials[100001] = {};
	REP(i,n){
		int s; cin>>s; 
		specials[s] = 1;
	}
	int idx1=0,idx2 = 0;
	REP(i,m){
		int id,p; string s;
		cin>>id>>p>>s;
		if(specials[id]){
			ans[idx1].id = id;
			ans[idx1].p = p;
			ans[idx1].s = s;
			idx1++;
		}
		else{
			posts[idx2].id = id;
			posts[idx2].p = p;
			posts[idx2].s = s;
			idx2++;
		}
	}
	sort(posts, posts+idx2,cmp);
	sort(ans, ans+idx1,cmp);
	REP(i,idx1) cout<<ans[i].s<<endl;
	REP(i,idx2) cout<<posts[i].s<<endl;
}