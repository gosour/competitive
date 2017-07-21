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
char arr[1005][1005];
bool dpx[1005][1005];
bool dpy[1005][1005];

int main(){
	int t; cin>>t;
	
	while(t--){
		int n; cin>>n; getchar();
		REP(i,n){
			REP(j,n){
				arr[i][j] = getchar();
			}
			getchar();
		}

		int count = 0;
		for(int i=n-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				dpx[i][j] = false;
				dpy[i][j] = false;
				if(i == n-1 || j == n-1){
					if(i== n-1 && j==n-1 && arr[i][j] == '.') {
						dpx[i][j] = true;
						dpy[i][j] = true;
					}
					if(i!=n-1 && arr[i][j] == '.') {
						dpx[i][j] = dpx[i+1][j] & true;
						dpy[i][j] = true;
					}
					if(j!=n-1 && arr[i][j] == '.') {
						dpy[i][j] = dpy[i][j+1] & true;
						dpx[i][j] = true;
					}
				}else{
					if(arr[i][j] == '.') {
						dpx[i][j] = dpx[i+1][j] & 1;
						dpy[i][j] = dpy[i][j+1] & 1;
					}
				}
				if(dpx[i][j]  && dpy[i][j]) count++;
			}
		}
		cout<<count<<endl;
		// REP(i,n){
		// 	REP(j,n){
		// 		cout<<dpx[i][j]<<':'<<dpy[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

	}
}