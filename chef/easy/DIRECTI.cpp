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

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		stack<string> st;
		getchar();
		REP(i,n){
			string s;
			getline(cin,s);
			st.push(s);
		}

		string s = st.top();
		string dir = s.substr(0, s.find(' '));
		string road = s.substr(s.find("on ") + 3);
		st.pop();
		cout<<"Begin on "<<road<<endl;
		while(!st.empty()){
			string s = st.top();
			st.pop();
			road = s.substr(s.find("on ") + 3);
			if(dir == "Left") dir = "Right";
			else dir = "Left";
			cout<<dir<<" on "<< road<<endl;
			dir = s.substr(0, s.find(' '));
		}
		if(t) cout<<endl;

	}
}	