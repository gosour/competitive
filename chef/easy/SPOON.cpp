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
	char arr[105][105];
	while(t--){
		int r,c; cin>>r>>c;
		REP(i,r){
			string s; cin>>s;
			REP(j,c) arr[i][j] = tolower(s[j]);
		}
		string key = "spoonX";
		int tofind = 0;
		bool found = false;
		REP(i,r){
			if(found) break;
			REP(j,c){
				tofind = 0;
				if(arr[i][j] == key[tofind]){
					int p = i,q = j;
					while(arr[p][q] == key[tofind] && key[tofind]!='X' && p<r){
						
						p++; tofind++;
					}
					if(key[tofind] == 'X') {
						found = false;
					}else{
						p = i;q = j;
						tofind = 0;
						while(arr[p][q] == key[tofind] && key[tofind]!='X' && q<c){
								// DEBUG(arr[i][j]);
								// DEBUG(key[tofind]);
								q++; tofind++;
							}
					}

					if(key[tofind] == 'X') {
						found = true;
					}
				}
			}
		}
		if(found) cout<<"There is a spoon!"<<endl;
		else cout<<"There is indeed no spoon!"<<endl;
	}
}	