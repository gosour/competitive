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
	int arr[1005];
	while(t--){
		int n,k; cin>>n>>k;
		int total = 0;
		REP(i,n) {
			cin>>arr[i];
			total += arr[i];
		}
		sort(arr,arr+n);
		int sum1 = 0;
		REP2(i,0,k-1){
			sum1 += arr[i];
		}
		int sum2 = 0;
		for(int i = n-1; i>(n-1-k);i--){
			sum2 += arr[i];
		}

		if(total-sum1 > sum2){
			cout<<(total-sum1) - sum1<<endl;
		}
		else{
			cout<<(sum2) - (total-sum2)<<endl;	
		}
	}
}