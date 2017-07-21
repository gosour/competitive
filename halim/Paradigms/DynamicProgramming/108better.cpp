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
int arr[101][101];
int columns[101][101];

int main(){
	int n; scanf("%d",&n);
	memset(columns,0,sizeof(columns));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			if(i==0) columns[i][j] = arr[i][j];
			else columns[i][j] = columns[i-1][j] + arr[i][j];
		}
	}

	// REP(i,n) {REP(j,n) cout <<columns[i][j]<<" "; cout<<endl;}

	int best = -INF;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int current_max = columns[j][0] - ((i-1>=0)?columns[i-1][0]:0);
			// DEBUG();
			for(int k=1;k<n;k++){
				int columnSum = columns[j][k] - ((i-1>=0)?columns[i-1][k]:0); 
				// cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<" current_max: "<<current_max<<endl;
				current_max = max(columnSum, current_max+columnSum);
				best = max(current_max,best);
			}
		}
	}
	if(best !=INF)
		cout<<best<<endl;
	else cout<<best<<endl;

}