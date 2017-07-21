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
typedef vector<int>::iterator it;
struct Node{
	int parent, rank;
	vector<int> enemyList;
} nd[10005];

bool join(int a, int b){
	int a_idx = find(a);
	int b_idx = find(b);

	for(it i = pset[a_idx].enemyList.begin(); i!= pset[a_idx].enemyList.end(); i++){
		if(find(*i) == b_idx) return false;
	}

	

}

int main(){
	
}