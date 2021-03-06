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
typedef unsigned long long ull;

int main(){
	int t; cin>>t;
	ull arr[10];
	while(t--){
		ull n,m;
		cin>>n>>m;
		REP(i,n){
			cin>>arr[i];
		}
		sort(arr, arr+n, std::greater<ull>());
		int i = 0;
		ull sum = 0;
		for(i = 0;i<n;i++){
			sum += arr[i];
			if(sum >= m) break;
		}

		if(i == n) cout<<-1<<endl;
		else cout<<i+1<<endl;
	}
}