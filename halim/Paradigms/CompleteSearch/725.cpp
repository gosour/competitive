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

int to_int(string s){
	int result = 0;
	for(int i = 0;i<s.length();i++){
		result = result*10 + (int)(s[i]-'0');
	}
	return result;
}

int main(){
	int n; bool first = true, flag = false, lastline = false;
	while(scanf("%d",&n) != EOF && n!=0){
		if(first == true) first = false;
		else{printf("\n");}
		string s = "0123456789";
		// cout<<to_int("01234")<<" "<<to_int("10120")<<endl;
		do{
			int denom = to_int(s.substr(0,5));
			int num = to_int(s.substr(5));
			if(denom > num) break;
			else if(EQ( (double)num/denom, (double)n) ){
				cout<<s.substr(5) <<" / "<<s.substr(0,5)<<" = "<<n<<endl;
				flag = true; lastline = true;
			}
		}while(next_permutation(s.begin(),s.end()));
		if(!flag){
			cout<<"There are no solutions for "<<n<<"."<<endl;
			lastline = false;
		}

	}
}