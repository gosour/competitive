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
#include<iomanip>

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
typedef vector<float> vf;

int main(){
	int n; scanf("%d",&n); bool flag = false;
	while(n-->0){
		scanf("\n");
		vi index_arr;
		vector<string> arr;
		vector<string> result_arr;

		string line; getline(cin,line);
		istringstream is(line);
		index_arr = vector<int>(istream_iterator<int>(is), istream_iterator<int>());

		is.clear(); is.str("");
		getline(cin,line); is.str(line);
		arr = vector<string>(istream_iterator<string>(is), istream_iterator<string>());

		result_arr = arr;
		REP(i,index_arr.size()){
			result_arr[index_arr[i] - 1] = arr[i];
		}
		if(!flag) flag = true;
		else cout<<endl;
		REP(i,index_arr.size()) cout<<result_arr[i]<<endl;
	}
}