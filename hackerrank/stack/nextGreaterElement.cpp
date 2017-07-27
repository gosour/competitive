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

void nextGreaterElement(int a[], int size){
	cout<<size<<endl;
	stack<int> s;
	for(int i=0;i<size;i++){
		if(s.empty())
			s.push(a[i]);
		else{
			while(!s.empty() && s.top() < a[i]){
				cout<<s.top()<< " -> " <<a[i]<<endl;
				s.pop();
			}
			s.push(a[i]);
		}
	}
	while(!s.empty()){
		cout<<s.top() << " -> "<< -1<<endl;
		s.pop();
	}
	cout<<endl;
}

int main(){
	int a1[] = {4,5,2,25};
	int a2[] = {13,7,6,12};

	nextGreaterElement(a1,sizeof(a1)/sizeof(int));
	nextGreaterElement(a2,sizeof(a1)/sizeof(int));
}