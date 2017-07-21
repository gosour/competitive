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
int n;vi floors;
vi stopPlan;
bool valid(int guess_time){
	vi stopping_floors;
	for(int i=0;i<floors.size();i++){
		int currentFloor = floors[i];

		//Check if current floor is walkable from ground before guess time
		if( (currentFloor - 1)*20 <=guess_time) continue; //Make the person walk
		if(stopping_floors.empty()){
			stopping_floors.pb(currentFloor); //Stop at the first floor
			//Check if the first floor is reachable by lift in the stipulated time
			if( (currentFloor - 1)*4 > guess_time) return false;
			continue;
		}

		int t1 = abs(stopping_floors[stopping_floors.size()-1] - currentFloor) * 20 + (stopping_floors[stopping_floors.size()-1] - 1) * 4 + (stopping_floors.size() - 1)*10;
		//t1 is the time if we walk to current floor from the last given floor
		if(t1<=guess_time){
			//Then don't stop in the current floor
			continue;
		}
		else{
			stopping_floors.pb(currentFloor);
			//Check if stopping in the currentFloor is not within the stipulated time
			if( (currentFloor-1)*4 + (stopping_floors.size() - 1)*10 > guess_time) return false;
			continue;
		}
	}

	stopPlan = stopping_floors;
	return true;
}

void solve(){
	stopPlan.clear();
	int low = 0, high = 410;
	while(low<high-1){
		int mid = (low+high)/2;
		if(valid(mid)){
			//Means the time-> mid is doable for the given stop plan
			high = mid;
		}
		else{
			low = mid;
		}
	}
	cout<<high<<endl;
	cout<<stopPlan.size()<<" ";
	for(int i=0;i<stopPlan.size();i++)
		cout<<stopPlan[i]<<" ";
	cout<<endl;
}

int main(){
	while(scanf("%d",&n) && n!=0){
		floors.clear();
		REP(i,n){
			int temp; scanf("%d",&temp); 
			floors.pb(temp);
		}
		sort(floors.begin(),floors.end());
		solve();
	}
}