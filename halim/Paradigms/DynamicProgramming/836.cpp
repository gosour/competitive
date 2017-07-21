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
using namespace std;
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define SQR(n)                ( n * n )
const int INF = 1<<29;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back
typedef vector<int> vi;

int arr[26][26];
int columns[26][26];

int main(){
	int tests; cin>>tests;
	string empty,s;

	getline(cin,empty);
	bool first = true;
	while(tests--){
		getline(cin,empty);
		getline(cin,s);
		int n = s.length();
		int c = 0;
		
		for(int i=0;i<n;i++){
			if(s[i] == '0') arr[0][i] = 0;
			else arr[0][i] = 1;
			columns[0][i] = arr[0][i];
		}

		for(int i=1;i<n;i++){
			getline(cin,s);
			for(int j=0;j<n;j++){
				if(s[j] == '0') arr[i][j] = 0;
				else arr[i][j] = 1;

				columns[i][j] = columns[i-1][j] + arr[i][j]; 
			}
		}

		// REP(i,n){REP(j,n) cout<<arr[i][j]<<" "; cout<<endl;}
		// cout<<"---"<<endl;
		REP(i,n){
			REP(j,n){
				if(i>0) arr[i][j] += arr[i-1][j];
				if(j>0) arr[i][j] += arr[i][j-1];
				if(i>0 && j>0) arr[i][j] -= arr[i-1][j-1];
				// cout<<arr[i][j]<<" ";
			}
			// cout<<endl;
		}

		int maxRect = 0;

		REP(i,n) REP(j,n) REP2(k,i,n-1) REP2(l,j,n-1){
			int subRect = arr[k][l]; // this is sum of all items from (0, 0) to (k, l): O(1)
			if (i > 0) subRect -= arr[i - 1][l]; // O(1)
			if (j > 0) subRect -= arr[k][j - 1]; // O(1)
			if (i > 0 && j > 0) subRect += arr[i - 1][j - 1]; // inclusion-exclusion: O(1)
			int sizeSubRect = (1+(k-i))*(1+(l-j));
			if(subRect == sizeSubRect )
				maxRect = max(maxRect, subRect);
		}

		if(first) first = false;
		else cout<<endl;
		cout<<maxRect<<endl;



	}
}