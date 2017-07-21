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
struct Agencies
{
	char name[20];
	int minCost;
};

int Solve(int n, int m, int a, int b){
	int cost = 0;
	while(1){
		if(n/2 < m || (a*(n-m) < b)) {
			cost += a*(n-m);
			break;
		}
		else{
			cost += min(b,a*(n/2));
		}
		n/=2;
	}
	return cost;
}
bool compare(Agencies a1, Agencies a2){
	string s1(a1.name), s2(a2.name);
	if(a1.minCost != a2.minCost){
		return a1.minCost < a2.minCost;
	}
	else return (s1.compare(s2) < 0 );
}
int main(){
	int tests,n,m,l;	
	scanf("%d",&tests);
	REP2(t,1,tests){
		scanf("%d %d %d",&n,&m,&l);
		vector<Agencies> agencies;
		REP(i,l){
			Agencies ag;
			char ch,s[20];int a, b; 
			getchar();
            int k = 0;
            while (ch = getchar(), ch != ':' )
                s[k++] = ch;
            s[k] = '\0';
            strcpy(ag.name, s);
			scanf("%d, %d", &a, &b);
			int minCost = Solve(n,m,a,b);
			ag.minCost = minCost;
			agencies.pb(ag);
		}
		sort(agencies.begin(), agencies.end(),compare);
		printf("Case %d\n",t);
		REP(i,agencies.size()){
			cout<<agencies[i].name<<" "<<agencies[i].minCost<<endl;
		}
	}
}