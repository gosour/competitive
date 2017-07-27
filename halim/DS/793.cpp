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

vi pset;
void init_set(int size){
	pset.resize(size);
	REP(i,size) pset[i] = i;
}

int find(int a){
	return (pset[a] == a)? a : pset[a] = find(pset[a]); //Using path compression as an optimization
}

void join(int a, int b){
	if(pset[a] == pset[b]) return;
	pset[a] = find(b);
}

int main(){
	int T; scanf("%d",&T);
	string s; char c; int x,y,n;
	for(int tc = 1;tc<=T;tc++){
		scanf("\n%d\n",&n);
		init_set(n);

		int success = 0, failure = 0;
		while(1){
			if(!getline(cin,s) || s.empty()) break;
			sscanf(s.c_str(),"%c %d %d",&c,&x,&y);

			if(c == 'c'){join(x,y);}
			else{
				(find(x) == find(y))? success++: failure++;
			}
		}
		if(tc != 1) printf("\n");
		printf("%d,%d\n",success,failure);
	}

}