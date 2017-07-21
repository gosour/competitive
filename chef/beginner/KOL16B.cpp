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
	int t; cin>>t; int cases = 1;
	int a[100005],b[100005];
	while(t--){
		int n; cin>>n;
		REP(i,n){
			int temp; cin>>temp;
			b[i] = temp>>16;
			a[i] = temp % (1<<16);
		}
		cout<<"Case "<<cases++<<":"<<endl;
		REP(i,n) cout<<a[i]<<" ";
		cout<<endl;
		REP(i,n) cout<<b[i]<<" ";		
		cout<<endl;
	}
}