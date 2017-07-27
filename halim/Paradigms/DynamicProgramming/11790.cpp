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
	int tests; scanf("%d",&tests);
	REP2(t,1,tests){
		int n; scanf("%d",&n);
		vi heights,weights;
		REP(i,n){
			int temp; scanf("%d",&temp); heights.pb(temp);
		}
		REP(i,n){
			int temp; scanf("%d",&temp); weights.pb(temp);
		}

		vi incTable; incTable.resize(n,0);
		vi decTable; decTable.resize(n,0);
		incTable[0] = weights[0];
		decTable[0] = weights[0];
		int maxIncAns = weights[0], maxDecAns = weights[0];
		for(int i=1;i<n;i++){
			incTable[i] = weights[i];
			decTable[i] = weights[i];
			for(int j=0;j<i;j++){
				if(heights[i] > heights[j] && incTable[j] + weights[i] > incTable[i]){
					incTable[i] = incTable[j] + weights[i];
				}
				if(maxIncAns < incTable[i]) maxIncAns = incTable[i];


				if(heights[i] < heights[j] && decTable[j] + weights[i] > decTable[i]){
					decTable[i] = decTable[j] + weights[i];
				}
				if(maxDecAns < decTable[i]) maxDecAns = decTable[i];

			}
		}

		// REP(i,n) cout<<incTable[i]<<" ";
		// cout<<endl;
		// REP(i,n) cout<<decTable[i]<<" ";
		// cout<<endl;
		cout<<"Case "<<t<<". ";
		if(maxDecAns <= maxIncAns){
			cout<<"Increasing ("<<maxIncAns<<"). ";
			cout<<"Decreasing ("<<maxDecAns<<")."<<endl;
		}
		else{
			cout<<"Decreasing ("<<maxDecAns<<"). ";
			cout<<"Increasing ("<<maxIncAns<<")."<<endl;
		}

	}
}