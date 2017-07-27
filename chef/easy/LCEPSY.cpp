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
		string a,b; cin>>a>>b;
		int count = 0;

		int alpha[26] = {};
		int Calpha[26] = {};

		REP(i,a.length()){
			if(a[i] == tolower(a[i])) alpha[a[i]-'a']++;
			else Calpha[a[i]-'A']++;
		}
		REP(i,b.length()){
			if(b[i] == tolower(b[i])){
				int idx = (int)b[i]-'a'; 
				if(alpha[idx]!=0){
					count++; alpha[idx]--;
				} 
			}else{
				int idx = (int)b[i]-'A'; 
				if(Calpha[idx]!=0){
					count++; Calpha[idx]--;
				} 
			}
		}
		cout<<count<<endl;
	}
}	