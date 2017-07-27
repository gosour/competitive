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
#define SQR(n)                ( n * n )
const int INF = 1<<29;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<=(b);i++)
#define REPD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
#define pb push_back
typedef vector<int> vi;
int main(){
	vi arr;
	int temp;
	while(scanf("%d",&temp)!=EOF){
		arr.pb(temp);
	}
	int length = arr.size();
	vi sequenceEnds; sequenceEnds.resize(length,0);
	vi endIndices ; endIndices.resize(length,0);
	vi parent; parent.resize(length,-1);
	sequenceEnds[0] = arr[0];
	int end = 1;

	REP2(i,1,length-1){
		int current = arr[i];
		if(current < sequenceEnds[0]) {
			//If current is the smallest element out of all searched
			sequenceEnds[0] = current;
			endIndices[0] = i;
		}
		else if(current > sequenceEnds[end-1]){
			//Current is the larger than the last element of the largest active list
			sequenceEnds[end] = current;
			endIndices[end] = i;
			parent[i] = endIndices[end-1];
			end++;
		}
		else{
			vi::iterator it = lower_bound(sequenceEnds.begin(),sequenceEnds.begin()+end,current);
			int idx = (it-sequenceEnds.begin());
			endIndices[idx] = i;
			*it = current;
			parent[i] = endIndices[idx-1];
		}
	}

	cout<<end<<endl;
	cout<<"-"<<endl;
	vi solution;
	int p = endIndices[end-1];
	while(parent[p]!=-1){
		solution.pb(arr[p]);
		p = parent[p];
	}
	solution.pb(arr[p]);
	reverse(solution.begin(),solution.end());
	// REP(i,length) cout<<parent[i]<<endl;
	REP(i,solution.size()) cout<<solution[i]<<endl;
}