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

int arr[205];

int main(){
	int t; cin>>t;
	while(t--){
		int n,x; cin>>n>>x;
		REP(i,n) cin>>arr[i];
		sort(arr, arr+n);
		int i = 0, j= n-1;
		bool ans = false;
		while(i<j){
			if(arr[i] + arr[j] == x) {
				ans = true;
				break;
			}else if(arr[i] + arr[j] > x){
				j--;
			}else{
				i++;
			}
		}

		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}