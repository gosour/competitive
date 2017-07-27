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
		string str; cin>>str;
		int m,s; m = s = 0;
		REP(i,str.length()){
			if(str[i] == 'm'){
				m++;
				if(i>0 && str[i-1] == 's'){
					s--;
					str[i] = 'e'; //to denote this mongoose already ate
				}
			}
			if(str[i] == 's'){
				s++;
				if(i>0 && str[i-1] == 'm'){
					s--;
					str[i] = 'e'; //this snake is already eaten
				}
			}
		}
		// DEBUG(s);
		// DEBUG(m);
		if(s > m) cout<<"snakes"<<endl;
		else if(m > s) cout<<"mongooses"<<endl;
		else cout<<"tie"<<endl;
	}
}