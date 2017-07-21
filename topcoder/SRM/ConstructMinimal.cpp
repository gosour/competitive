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

struct AP{
	char ch;
	int count;
};
bool comp(AP a, AP b){
	if(a.count < b.count) return true;
	else return false;
}
class MakePalindrome{
public:
	vector<string> constructMinimal(string card);
};

vector<string> MakePalindrome::constructMinimal(string card){
	AP ap[26];
	REP(i,26){
		ap[i].count = 0;
	}
	REP(i,card.length()) {
		ap[(int)card[i]-(int)'a'].ch = card[i];
		ap[(int)card[i]-(int)'a'].count++;
	}

	sort(ap,ap+26,comp);
	int index = 0;
	vector<string> ans;
	string s = "";
	for(int i=25; i>=0; i--)
		if(!ap[i].count) continue;
		if(ap[i].count % 2 && s == ""){
			REP(j,ap[i].count) s += ap[i].ch;
			continue;
		}
		if(ap[i].)

	} 
	return ans;
}

int main(){
	MakePalindrome o;
	o.constructMinimal("abbaa");
}