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
int last_node;
int DropBall(int depth, int number_of_balls, int node){
	int left = node*2, right = node*2+1;
	if(left <= last_node && right <=last_node){
		if(number_of_balls%2 == 0) return DropBall(depth,number_of_balls/2,right);
		else return DropBall(depth,number_of_balls/2 + 1, left);
	}
	else return node;
}

int main(){
	int t,D,I; scanf("%d",&t);
	while(t--){
		scanf("%d %d",&D,&I);
		last_node = pow(2,D)-1;
		cout<<DropBall(D,I,1)<<endl;
	}
	scanf("-1");	
}