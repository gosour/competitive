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
	while(t--){
		int n; cin>>n;
		int zero_count = 0, one_count = 0, neg_one_count = 0, other_count = 0;
		REP(i,n){
			int temp; cin>>temp;
			switch(temp){
				case 0 : zero_count++; break;
				case -1 :  neg_one_count++; break;
				case 1 : one_count++; break;
				default: other_count++;
			}
		}
		if(other_count > 1) cout<<"no"<<endl;
		else if(neg_one_count && other_count) cout<<"no"<<endl;
		else if(neg_one_count>1 && !one_count) cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
}