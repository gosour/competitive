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
	int n, arr[2005];
	while(1){
		cin>>n; if(n==0) break;
		REP2(i,1,n) cin>>arr[i];
		int count = 0;
		sort(arr+1, arr+1+n);
		for(int i=n;i>=3;i--){
			int j=1;
			int k = i-1;
			while(j<k){
				if(arr[j] + arr[k]< arr[i]) {
					count += (k-j);
					j++;
				}
				else{
					k--;
				}
			}
		}
		cout<<count<<endl;
	}
}