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

int prec(char ch){
	switch(ch){
		case '+' : 
		case '-' : return 0;
		case '*' : 
		case '/' : return 1;
		default: return -1;
	}
}

int main(){
	string infix = "A*(B+C*D)+E";
	string postfix = "";
	stack<char> ops;
	for(int i=0;i<infix.length();i++){
		if(infix[i] == '(') {
			ops.push(infix[i]);
			continue;
		}
		if(infix[i] == ')'){
			while(!ops.empty() && ops.top()!='('){
				postfix += ops.top();
				ops.pop();
			}
			ops.pop();
			continue;
		}

		if(prec(infix[i]) == -1){
			postfix += infix[i];
		}else{
			while(!ops.empty() && prec(ops.top()) > prec(infix[i])){
				postfix += ops.top();
				ops.pop();
			}
			ops.push(infix[i]);
		}
	}
	while(!ops.empty()){
		postfix += ops.top();
		ops.pop();
	}

	cout<<"Postfix notation of "<< infix<< " is "<<postfix<<endl;
}

