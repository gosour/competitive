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

class RepeatNumberCompare{
	public:
		string compare(int x1, int k1, int x2, int k2);
		int numlen(int a);
};

int RepeatNumberCompare::numlen(int a){
	int count = 0;
	while(a){
		count++;
		a = a/10;
	}
	return count;
}

string RepeatNumberCompare::compare(int x1, int k1, int x2, int k2){
	int c1 = this->numlen(x1);
	int c2 = this->numlen(x2);

	if(c1*k1 > c2*k2) return "Greater";
	if(c2*k2 > c1*k1) return "Less";

	if(c1 > c2){
		int diff = (c1 - c2);
		// DEBUG(diff);
		int p = pow(10,diff);
		int temp = x2 * p;
		if(p > x2){
			while(p){
				p = p/10;
				temp += x2 * p;
			}
			x2 = temp;
		}
		else{
			x2 = temp + x2;
			x2 = x2/p;
		}

	}

	if(c2 > c1){
		int diff = (c2 - c1);
		// DEBUG(diff);
		int p = pow(10,diff);
		int temp = x1 * p;
		if(p > x1){
			while(p){
				p = p/10;
				temp += x1 * p;
			}
			x1 = temp;
		}
		else{
			x1 = x1/p;
			x1 = temp + x1;
		}

		// DEBUG(temp);
		
		// DEBUG(x1);
		// DEBUG(x2);
	}

	if(x1 > x2) return "Greater";
	else if(x2 > x1) return "Less";
	else return "Equal";
} 

int main(){
	RepeatNumberCompare o;
	cout<<o.compare(1234,3,70,4)<<endl;
	cout<<o.compare(1010,3,101010,2)<<endl;
	cout<<o.compare(1234,10,456,20)<<endl;
	cout<<o.compare(5,9,555555555,1)<<endl;
	cout<<o.compare(5,9,555555554,1)<<endl;
	cout<<o.compare(5,9,555555556,1)<<endl;
	cout<<o.compare(1000000000,10,1000000000,10)<<endl;
}	