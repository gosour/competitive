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
		int n,k; cin>>n>>k;
		vector< vector<int> > sets(n,vector<int>(k+1,0));

		REP(i,n){
			int len; cin>>len; 
			REP(j,len){
				int elem; cin>>elem;
				sets[i][elem]++;
			}
		}

		int count = 0;
		REP(i,n){
			REP2(j,i+1,n-1){
				bool isSet = true;
				// DEBUG(i); DEBUG(j);
				REP2(p,1,k){
					if(!isSet) break;
					if(sets[i][p] == 0 && sets[j][p] == 0) isSet = false;
				}
				if(isSet) count++;
			}
		}
		cout<<count<<endl;
	}
}