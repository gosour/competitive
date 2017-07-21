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
int main(){
	int c,n,t,m;
	int timeOfArrival[1441];
	scanf("%d",&c);
	while(c--){
		scanf("%d %d %d",&n,&t,&m);
		REP(i,m){
			scanf("%d",&timeOfArrival[i]);
		}
		sort(timeOfArrival, timeOfArrival+m);
		int trips = 0,time = 0;
		int carno = 0;
		while(carno<m){
			int taken = 0;
			while(taken<n && carno+taken<m){
				if(timeOfArrival[carno+taken]>time+2*t) break;
				else if(timeOfArrival[carno+taken] > time){
					time=timeOfArrival[carno+taken];
					taken++;
				}
				else{
					taken++;
				}
			}
			if(taken!=0) trips += 1;			
			carno = carno+taken;
			time = time+2*t;
		}
		cout<<time-t<<" "<<trips<<endl;

	}
}