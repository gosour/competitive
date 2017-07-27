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
struct BlackPole{
	int x, y;
};
struct RedPole{
	int x, y;
};
BlackPole blackpoles[100];
RedPole redPoles[100];
int dist[100];
int main(){
	int n,p,k; scanf("%d\n",&n);
	while(n--){
		int redCount=0,blackCount=0;
		scanf("\n");
		scanf("%d %d",&p,&k);
		REP(i,p){
			int x, y; string color;
			cin>>x>>y>>color;
			cout<<x<<" "<<y<<" "<<color<<endl; 
			if(color == "red") {redPoles[redCount].x = x; redPoles[redCount].y = y; redCount++;}
			else {blackpoles[blackCount].x = x; blackpoles[blackCount].y = y; blackCount++;}
		}

		if(redCount<k || blackCount<k){cout<<"Impossible"<<endl; continue;}
		REP(i,blackCount) cout<<blackpoles[i].x<<" "<<blackpoles[i].y<<" ";
		cout<<endl;
		REP(i,redCount) cout<<redPoles[i].x<<" "<<redPoles[i].y<<" ";
		cout<<endl;
		int t=0;
		REP(i,redCount){
			REP(j,blackCount){
				dist[t++] = SQR(redPoles[i].x-blackpoles[j].x) + SQR(redPoles[i].y - blackpoles[j].y);
			}
		}

		sort(dist, dist+t);
		REP(i,t) cout<<dist[i]<<" ";
		cout<<endl;
		cout<<(float)sqrt(dist[k-1])<<endl;

	}
}