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

map<string,int> NameMap;
struct node{
	int val, total;
};
vector<node> pset;
void init_set(int n){
	pset.reserve(n);
	REP(i,n){
		pset[i].val = i;
		pset[i].total = 1;
	}
}

int find_friend(int i){
	if(pset[i].val == i) return i;
	else{
		pset[i].val = find_friend(pset[i].val);
		pset[i].total = pset[pset[i].val].total;
		return pset[i].val;
	}
}
int make_friend(int i1, int i2){
	int parent_idx = find_friend(i2);
	int idx = find_friend(i1);
	if(parent_idx != idx){
		pset[idx].val = parent_idx;
		pset[parent_idx].total += pset[idx].total;
	}
	return pset[parent_idx].total;
}

int main(){
	int n; scanf("%d",&n);
	while(n--){
		int f; scanf("%d",&f);
		init_set(200000);
		NameMap.clear ();
		int pool = 0;
		while(f--){
			string s1, s2; cin>>s1>>s2; 
			map<string,int>::iterator it1 = NameMap.find(s1), it2= NameMap.find(s2);
			int i1, i2;
			if(it1 == NameMap.end()) i1 = NameMap[s1] = pool++;
			else i1 = it1->second;
			if(it2 == NameMap.end()) i2 = NameMap[s2] = pool++;
			else i2 = it2->second;

			int r = make_friend(i1,i2);
			printf("%d\n",r);
		}
		// for(map<string,int>::iterator it = NameMap.begin(); it!= NameMap.end(); it++){
		// 	cout<<it->first<<" "<<it->second<<endl;
		// }
	}
}