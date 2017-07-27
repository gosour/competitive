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
int i, n, caseNo = 1, order[8];
double a[8], b[8], timeGap, maxTimeGap; // timeGap is the variable L mentioned in text

double greedyLanding(){
	double lastLanding = a[order[0]];
	for(i=1;i<n;i++){
		double targetLandingTime = lastLanding + timeGap;
		if(targetLandingTime <= b[order[i]])
			lastLanding = max(a[order[i]],targetLandingTime);
		else
			return 1;
	}
	//Always returns a negative value
	return lastLanding - b[order[n-1]];
}

int main(){
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){
			scanf("%lf %lf",&a[i],&b[i]);
			a[i]*=60; b[i]*=60; //Convert to seconds
			order[i] = i;
		}
		maxTimeGap = -1;
		do{ //Permute plane landing
			double lowVal = 0, highVal = 86400;
			timeGap = -1; //Start with the infeasible solution
			while(fabs(lowVal - highVal) >= 1e-3){
				timeGap = (lowVal+highVal)/2.0;
				double retVal = greedyLanding();
				if(retVal <= 1e-2) lowVal = timeGap; //must increase timeGap
				else highVal = timeGap;
			}
			maxTimeGap = max(maxTimeGap,timeGap);
		} while(next_permutation(order,order+n));
		maxTimeGap = (int)(maxTimeGap + 0.5); // round to nearest second
		printf("Case %d: %d:%0.2d\n", caseNo++, (int)(maxTimeGap / 60), (int)maxTimeGap % 60);
	}
}