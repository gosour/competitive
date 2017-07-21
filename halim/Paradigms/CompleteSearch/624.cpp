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
int n,t;
vi tracks,ans;
int minDiff;
void Consider(int idx,int sum_till_now,vi &elements){
	if(idx == t){
		if(sum_till_now<=n && n-sum_till_now <= minDiff){
			minDiff = n-sum_till_now;
			ans.clear();
			REP(i,elements.size()){
				ans.pb(elements[i]);
			}
		}
	}else{
		if(sum_till_now > n) Consider(idx+1,sum_till_now,elements);
		else{
			Consider(idx+1,sum_till_now,elements);
			elements.pb(tracks[idx]);
			Consider(idx+1,sum_till_now+tracks[idx],elements);
			elements.pop_back();
		}
	}
}

int main(){
	while(scanf("%d %d",&n,&t) != EOF){
		tracks.clear();
		ans.clear();
		REP(i,t){
			int temp; scanf("%d",&temp);
			tracks.pb(temp); 
		}

		minDiff = n;
		vi elements;
		Consider(0,0,elements);

		REP(i,ans.size()){
			cout<<ans[i]<<" ";
		}
		cout<<"sum:"<<n-minDiff<<endl;
	}
}