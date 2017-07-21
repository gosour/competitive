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
	int arr[105];
	while(t--){
		int n; cin>>n;
		int b,g; cin>>b>>g;
		bool turn = false;
		arr[0] = 0; g--;
		int i = 0;
		int samecount = 0, diffcount = 0;

		for(i=1;i<n;i++){
			if(b== 0 || g==0) break;
			if(turn && arr[i-1] == 0) arr[i] = 0;
			if(turn && arr[i-1] == 1) arr[i] = 1;
			if(!turn && arr[i-1] == 0) arr[i] = 1;
			if(!turn && arr[i-1] == 1) arr[i] = 0;

			if(arr[i] == 0) g--;
			else b--;
			turn = !turn;
			if(arr[i]!=arr[i-1]) diffcount++;
			else samecount++;

		}
		while(g--) {
			arr[i] = 0;
			if(arr[i] == arr[i-1]) samecount++;
			else diffcount++;
			i++;
		}
		while(b--) {
			arr[i] = 1;
			if(arr[i] == arr[i-1])	samecount++;
			else diffcount++;
			i++;
		}

		// REP(i,n) cout<<arr[i]<<" ";
		// DEBUG(samecount);
		// DEBUG(diffcount);
		if(samecount > diffcount) cout<<"Little Jhool wins!"<<endl;
		else cout<<"The teacher wins!"<<endl;
	}
}