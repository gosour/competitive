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
	int f,r;
	int fteeth[10];
	int rteeth[10];
	double result[101];
	while(1){
		scanf("%d",&f); if(f==0) break;
		scanf("%d",&r);
		REP(i,f){
			scanf("%d",&fteeth[i]);
		}
		REP(j,r){
			scanf("%d",&rteeth[j]);
		}

		int count = 0;
		REP(i,f){
			REP(j,r){
				result[count++] = (double)rteeth[j]/fteeth[i];
			}
		}
		// REP(i,count){
		// 	cout<<result[i]<<"-";
		// }
		// cout<<endl;
		sort(result,result+count);
		// REP(i,count){
		// 	cout<<result[i]<<"-";
		// }
		double max = 0;
		REP(i,count-1){
			double drive = (result[i+1]/result[i]);
			if(drive - max> 0.00000001)  max = drive;
		}

		printf("%.2lf\n", max);
	}
}