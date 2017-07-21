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
int c, s;
vi specimens;
vector<double> weights;
double totalWeight = 0;
int main(){
	int set = 1;
	while(scanf("%d %d",&c,&s)!= EOF){
		specimens.clear(); weights.clear(); totalWeight = 0;
		REP(i,s){
			int temp;
			scanf("%d",&temp);
			specimens.pb(temp);
			totalWeight += temp; 
		}
		REP2(i,1,2*c-s){
			specimens.pb(0);
		}
		sort(specimens.begin(),specimens.end());
		int i = 0, j = specimens.size()-1,container = 0;
		if(set != 1) cout<<endl;
		printf("Set #%d\n", set++);
		while(i<j){
			printf(" %d:",container++);
			if(specimens[i] == 0 && specimens[j]!=0) printf(" %d\n",specimens[j]);
			else if(specimens[j] == 0) printf("\n");
			else printf(" %d %d\n",specimens[i],specimens[j]);
			weights.pb(specimens[i]+specimens[j]); 
			i++; j--;
		}

		totalWeight /= c;
		double imbalance = 0;
		REP(i,weights.size()){
			imbalance = imbalance + fabs(totalWeight - weights[i]);
		}
		printf("IMBALANCE = %0.5lf\n",(double)imbalance);
	}
}