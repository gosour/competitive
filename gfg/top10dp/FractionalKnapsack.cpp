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

struct Item{
	int value,weight;
};

bool cmp(Item a, Item b){
	double x = (double)a.value/a.weight;
	double y = (double)b.value/b.weight;
	return x > y;
}

Item items[100006];

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n; int W; cin>>W;
		REP(i,n) {
			cin>>items[i].value;
			cin>>items[i].weight;
		}
		sort(items, items+n, cmp);
		int currWeight = 0; double value = 0.0;

		REP(i,n){
			if(currWeight + items[i].weight <= W){
				currWeight += items[i].weight;
				value += items[i].value;
			}else{
				if(W-currWeight > 0){
					value += (double)items[i].value*(W-currWeight)/items[i].weight;
					break;
				}
			}

		}
		cout<<value<<endl;
	}	
}