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
struct Block{
	int left,middle;
};
Block blocks[10001];
int table[10001];

bool mycompare(Block b1, Block b2){
	if(b1.left == b2.left) return b1.middle > b2.middle;
	else return b1.left > b2.left;
}

int main(){
	int n;
	while(scanf("%d",&n) && n!=0){
		REP(i,n){
			scanf("%d %d",&blocks[i].left,&blocks[i].middle);
			table[i] = 1;
		}
		int ans = 1;
		sort(blocks,blocks+n,mycompare);
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if((blocks[j].left >= blocks[i].left) && (blocks[j].middle >= blocks[i].middle) && table[i] < table[j] + 1){
					table[i] = table[j] + 1;
					ans = max(ans,table[i]);
				}
			}
		}
		cout<<ans<<endl;
	}
	cout<<"*"<<endl;	
}