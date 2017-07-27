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
	int routes; scanf("%d",&routes);
	for(int b=1;b<=routes;b++){
		int stops; scanf("%d",&stops);
		int best, current, start = 1, end = 1,bestStart=1,bestEnd = 1;
		for(int i=0;i<stops-1;i++){
			int value;
			scanf("%d",&value);
			if(i==0) {
				best = value;
				current = value;
				continue;
			}
			// cout<<"Current: "<<current<<" and element is: "<<value<<endl;
			if(value+current < value){
				current = value;
				start = i+1; end = i+1;
			}
			else{
				current = value+current;
				end = i+1;
			}

			if(current > best){
				best = current;
				bestStart = start;
				bestEnd = end;
			}
			if(current == best){
				if((end-start) <= (bestEnd-bestStart)){
					/*do nothing*/
				}
				else if((end-start) > (bestEnd-bestStart)){
					best = current;
					bestStart = start;
					bestEnd = end;
				}
			}
		}
		// DEBUG(best); 
		if(best<0) cout<<"Route "<<b<<" has no nice parts"<<endl;
		else{
			cout<<"The nicest part of route "<<b<<" is between stops "<<bestStart <<" and "<<bestEnd+1 <<endl;
		}
	}
}