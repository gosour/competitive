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
#define SQR(n)                ( n * n )
const int INF = 1<<29;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back
typedef vector<int> vi;
int order[21];
int idx[21];
int studentOrder[21];
int main(){
	int n; cin>>n;
	REP2(i,1,n){
		scanf("%d",&order[i]);
		idx[order[i]] = i;
	}

	while(1){
		int temp;
		cin>>temp;
		if(cin.fail() || cin.bad() || cin.eof()) break;
		studentOrder[1] = idx[temp]; 
		REP2(i,2,n){
			cin>>temp;
			studentOrder[i] = idx[temp];
		}
		int table[21];
		REP(i,21) table[i] = 1;
		int ans = 1;
		REP2(i,2,n){
			REP2(j,1,i-1){
				if(studentOrder[i] > studentOrder[j]){
					if(table[j] + 1 >  table[i]) {
						table[i] = table[j] + 1;
						ans = max(ans,table[i]);
					}
				}
			}
		}
		cout<<ans<<endl;

	}
}