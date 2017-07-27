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
		long long n; cin>>n;
		vector<long long> negatives;
		long long neg_sum = 0, pos_sum = 0;
		long long posCount = 0;
		REP(i,n){
			long long temp; cin>>temp;
			if(temp < 0){
				neg_sum += temp;
				negatives.pb(temp);
			}
			else{
				pos_sum += temp;
				posCount++;
			}
		}
		sort(negatives.begin(),negatives.end(),greater<int>());
		// DEBUG(pos_sum);
		// DEBUG(neg_sum);
		int i = 0;
		int prev_sum = pos_sum;
		int tempCount = posCount;

		while(i<negatives.size()){
			if( (prev_sum*tempCount + negatives[i]) < 0) break;
			if( (prev_sum + negatives[i]) * (tempCount+1) > (prev_sum*tempCount + negatives[i])){
				// DEBUG(negatives[i]);
				prev_sum  = (prev_sum + negatives[i]);
				neg_sum -= negatives[i];
				posCount = tempCount+1;
			}
			i++;
			tempCount++;
		}

		pos_sum = prev_sum;
		pos_sum *= posCount;
		// DEBUG(pos_sum);
		// DEBUG(neg_sum);
		cout<<pos_sum+neg_sum<<endl;
	}
}