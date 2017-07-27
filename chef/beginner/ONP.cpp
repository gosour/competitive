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
#include<sstream>
#include<iomanip>

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

int precedence(char c){
	switch(c){
		case '+' : 
		case '-' : return 1;
		case '*' : 
		case '/' : return 2;
		case '^' : return 3;
		default: return -1;
	}
}

int main(){
	int t; cin>>t;
	getchar();
	while(t--){
		string s;
		getline(cin,s);
		istringstream ss(s);
		stack<char> st;
		char ch;
		while(ss>>ch){
			if(ch == '('){
				st.push(ch); continue;
			}
			if(ch == ')'){
				while(!st.empty() && st.top() != '('){
					cout<<st.top(); st.pop();
				}
				st.pop();
				continue;
			}
			if(precedence(ch) == -1){
				cout<<ch;
			}
			else{
				while(!st.empty() && precedence(st.top()) > precedence(ch)){
					cout<<st.top(); st.pop();
				} 
				st.push(ch);
			}
		}

		while(!st.empty()){
			cout<<st.top(); st.pop();
		}
		cout<<endl;
	}
}