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

map< pair<int,int>,bool> dict; //map[<i,sum>] = true; if 0->i has a subset of sum = sum

int main(){
	int arr[] = {6,-6,8,4,-12,9,8,-8}; //{6,-6,8,4,-12,9,8,-8};
	int len = sizeof(arr)/sizeof(int);
	int A,B; A = -26; B = 35;

	for(int sum=A;sum<=B;sum++){
		dict[make_pair(0,sum)] = false;
	}

	int maxSum = 15;
	for(int i=1;i<=len;i++){
		for(int sum=A;sum<=B;sum++){
			bool curr = (arr[i-1] == sum);
			bool prevExclude = (dict.find(make_pair(i-1,sum)) != dict.end())? dict[make_pair(i-1,sum)] : false;
			bool prevInclude = (sum-arr[i-1] >= A && sum-arr[i-1] <=B && dict.find(make_pair(i-1,sum-arr[i-1])) != dict.end() )? dict[make_pair(i-1,sum-arr[i-1])] : false ;
			dict[make_pair(i,sum)] = curr || prevExclude || prevInclude;
		}			
	}

	DEBUG(dict[make_pair(len,0)]);
	DEBUG(dict[make_pair(len,6)]);
	DEBUG(dict[make_pair(len,-6)]);
	DEBUG(dict[make_pair(len,7)]);
	DEBUG(dict[make_pair(len,3)]);
	DEBUG(dict[make_pair(len,1)]);
}
