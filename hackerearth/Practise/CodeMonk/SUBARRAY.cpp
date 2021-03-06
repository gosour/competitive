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
int arr[20];
bool dp[15000001];
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int sum = 0,N = 0;
		REP(i,n) {
			cin>>arr[i];
			sum+= arr[i];
		}
		cin>>N;
		DEBUG(N);
		REP(i,N+2) {
			dp[i] = false;
			cout<<dp[i]<<" ";
		}
		cout<<endl;
		REP(i,n) cout<<arr[i]<<" ";
		cout<<endl;
		
		dp[0] = true;

		REP(i,n){
			for(int j=N+1-arr[i];j>=0;j--){
				if(dp[j]) {
					dp[j+arr[i]] = true;
				}
			}
		}
		REP2(i,0,N) cout<<dp[i]<<" ";
		cout<<endl;
		if(dp[N]) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}