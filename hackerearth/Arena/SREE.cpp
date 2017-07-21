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

bitset<300> bs;
vi primes;

void init(){
	bs.flip(); bs[0] = bs[1] = false;
	for(int i=2;i<300;i++){
		if(bs[i]){
			primes.pb(i);
			for(int j = i*i;j<300;j+=i) bs[j] = false;
		}
	}
}
bool isALPHA(char c){
	if(c >='A' && c<='Z') return true;
	if(c>='a' && c<='z') return true;
	return false;
}
int main(){
	int t; cin>>t;
	init();
	while(t--){
		int n; cin>>n;
		string s; cin>>s;
		for(int i=0;i<s.length();i++){
			if(!isALPHA(s[i])){
				if(s[i]<'A') cout<<"C";
				else if(s[i] >'z') cout<<"q";
				else if(s[i] - 'Z' > 'a' -s[i] ) cout<<"Y";
				else cout<<"a";
				continue;
			}
			if(bs[(int)s[i]]) cout<<s[i]; //if prime
			else{
				REP(j,primes.size()){
					if(primes[j] < s[i] && primes[j+1] > s[i]){
						int l = primes[j];
						int u = primes[j+1];
						// DEBUG((int)s[i]);
						// DEBUG(l);
						// DEBUG(u);
						if(s[i] -l <= u-s[i]) {
							if(l<'a' && l>'Z') cout<<(char)u;
							if(l<'A') cout<<(char) u;
							else cout<<(char)l;
						}
						else {
							if(u>'Z' && u<'a') cout<<(char)l;
							if(u>'z') cout<<(char) l;
							else
							cout<<(char)u;
						}
					}

				}
			}
		}
		cout<<endl;
	}
}	