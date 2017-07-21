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
	int arr[10005];
	while(t--){
		int n; cin>>n;
		REP(i,n){ 
			cin>>arr[i];
		}
		sort(arr, arr+n);
		int l=-1,b=-1;
		for(int i=n-1;i-1>=0;i--){
			if(arr[i] == arr[i-1]){
				
				if(l==-1) l = i-1;
				else if(b==-1 && l!=i){ 
					b=i;
					break;
				}
			}
		}
		// DEBUG(l);
		// DEBUG(b);
		if(l==-1 || b==-1 ) cout<<-1<<endl;
		else cout<<arr[l]*arr[b]<<endl;
	}
}