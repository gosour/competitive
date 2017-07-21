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

int main(){
	int t; cin>>t;
	double mx = -1;
	double mn = -1;
	int mxi = 1, mni = 1;
	int i = 1;
	while(t--){
		int x1,y1,x2,y2,x3,y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
		double area = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0;
		if(mx == -1)
			mx = area;
		if(mn == -1)
			mn = area;
		if(mx != -1 && mn != -1){
			if(area > mx){
				mx = area;
				mxi = i;
			}
			if(area < mn){
				mn = area;
				mni = i;
			}
		}
		i++;
	}
	cout<<mni<<" "<<mxi<<endl;
}