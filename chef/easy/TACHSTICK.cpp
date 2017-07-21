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
	int n,d; cin>>n>>d;
	vector<int> arr;
	REP(i,n){
		int temp; cin>>temp; arr.pb(temp);
	}
	sort(arr.begin(), arr.end());
	int prev = -1;
	int count = 0;
	REP(i,n){
		if(prev != -1){
			if(arr[i] - prev <= d) {
				count++;
				prev = -1;
			}
			else prev = arr[i];
		}
		else{
			prev = arr[i];
		}
	}
	cout<<count<<endl;
}