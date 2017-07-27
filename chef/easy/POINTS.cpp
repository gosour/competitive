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
#include<iomanip>

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

bool mysort(pair<int,int> a, pair<int,int> b){
	if(a.first < b.first) return true;
	else if(a.first == b.second){
		if(a.second > b.second) return true;
	}
	return false;
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<pair<int,int> > vp;
		REP(i,n){
			int x,y; cin>>x>>y; 
			vp.pb(make_pair(x,y));
		} 
		sort(vp.begin(), vp.end(),mysort);
		double dist = 0;
		
		REP2(i,1,n-1){
			dist += (double)sqrt(SQR(vp[i].first - vp[i-1].first) + SQR(vp[i].second - vp[i-1].second));
		}
		cout<<setprecision(2)<<std::fixed<<dist<<endl;
	}
}