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
#define forit(i, a) for ( __typeof( (a).begin() ) i = (a).begin(); i != (a).end(); i++ )
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back
typedef vector<int> vi;

string line;
map< <string, set<string> > project;
map< string, int > cnt;
vector< pair< int, string > > ans;

bool cmp(pair<int,string>A, pair<int, string>B){
	return A.first > B.first  || (A.first == B.first && A.second < B.second);
}

int main(){
	while(getline(cin,line), line!="0"){
		string lastP = "";
		project.clear();
		while(line != "1"){
			if(isupper(line[0])){
				project[line] = set<string>();
				lastP = line;
			}
			else{
				project[lastP].insert(line);
			}
			getline(cin.line);
		}
		cnt.clear();
		forit(it1,project){
			forit(it2,it1->second){
				cnt[*it2]++;
			}
		}
		ans.clear();
		forit(it1;project){
			int a = 0;
			forit(it2,it1->second){
				if(cnt[*it2] > 1) continue;
				a++;
			}
			ans.pb(make_pair(a,it1->first));
		}
		sort(ans.begin(),ans.end(),cmp);
		forit(it,ans) cout<<it->second << " " <<it->first << endl;
	}
}