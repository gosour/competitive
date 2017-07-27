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
		double h,c,t; cin>>h>>c>>t;
		bool hard = false, carbon = false, strength = false;
		if(h>50) hard = true;
		if(c<0.7) carbon = true;
		if(t> 5600) strength = true;

		if(hard && carbon && strength){
			cout<<"10"<<endl;
			continue;
		}
		if(hard && carbon){
			cout<<"9"<<endl;
			continue;
		}
		if(carbon && strength){
			cout<<"8"<<endl;
			continue;
		}
		if(hard && strength){
			cout<<"7"<<endl;
			continue;
		}
		if(hard || carbon || strength){
			cout<<"6"<<endl;
		}
		else{
			cout<<"5"<<endl;
		}

	}
}