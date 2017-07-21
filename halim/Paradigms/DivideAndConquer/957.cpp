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

int y,p;
int pope_year[100001];

int main(){
	while(scanf("%d",&y)!=EOF){
		scanf("%d",&p);
		REP(i,p){
			scanf("%d",&pope_year[i]);
		}

		int last_year = pope_year[p-1];
		int max_no_popes = 0;
		int first_pope = 0,last_pope = 0;
		REP(i,p){
			if(pope_year[i]+y-1 > last_year) continue;
			else{
				int *ret = upper_bound(pope_year+i,pope_year+p,pope_year[i]+y-1);
				if(ret == pope_year + p) continue;
				else{
					int years = ret-(pope_year+i);
					if(years > max_no_popes) {
						max_no_popes = years;
						last_pope = (ret-1)-pope_year;
						first_pope = i;
					}
				}
			}
		}

		cout<<max_no_popes<<" "<<pope_year[first_pope] << " "<<pope_year[last_pope]<<endl;

	}
}