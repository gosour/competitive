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
	int n; cin>>n;
	int arr[10005];
	REP2(i,1,n){
		cin>>arr[i];
	}
	vector<vector<int> > answers;
	REP2(i,1,n){
		if(arr[i] != -1){
			int t = i;
			vector<int> temp;
			while(1){
				temp.pb(t);	
				int j = t;
				t = arr[t];
				arr[j] = -1;
				if(arr[t] == -1){
					temp.pb(t);
					answers.pb(temp);
					break;
				}
			}
		}
	}
	cout<<answers.size()<<endl;
	REP(i,answers.size()){
		REP(j,answers[i].size()){
			cout<<answers[i][j]<<" ";
		}
		cout<<endl;
	}

}