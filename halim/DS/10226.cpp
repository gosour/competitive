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

map<string,int> forest;
int main(){
	int t; cin>>t;
	scanf("\n");
	bool first = true;
	while(t-->0){
		forest.clear();
		char buffer[40]; int count = 0;
		while(gets(buffer)&&buffer[0]){
			string s(buffer);
			map<string,int>::iterator it = forest.find(s);
			if(it == forest.end()){forest[s] = 1;}
			else it->second++;
			count++;
		}
		if(first) first = false;
		else printf("\n");
		for(map<string,int>::iterator it = forest.begin();it!=forest.end();it++){
			// DEBUG(it->first); DEBUG(it->second);
			string f = it->first; float freq = it->second/(float)count * 100.00;
			printf("%s %0.4f\n",f.c_str(),freq);
		}
	}
}