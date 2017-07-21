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
int a[15];
// int main(){
// 	int n; bool first = true;
// 	while(1){
// 		cin>>n;
// 		if(n==0) break;
// 		REP(i,n){
// 			cin>>a[i];
// 		}
// 		if(first) first = false;
// 		else cout<<endl;
// 		for(int i1=0;i1<n;i1++){
// 			for(int i2=i1+1;i2<n;i2++){
// 				for(int i3=i2+1;i3<n;i3++){
// 					for(int i4=i3+1;i4<n;i4++){
// 						for(int i5=i4+1;i5<n;i5++){
// 							for(int i6=i5+1;i6<n;i6++){
// 								cout<<a[i1]<<" "<<a[i2]<<" "<<a[i3]<<" "<<a[i4]<<" "<<a[i5]<<" "<<a[i6]<<endl;
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// }
int result[15];
int combCount;
void allNumbers(int total, int required, int current){
	// cout<<current<<endl;
	if(current == required){
		// REP(i,required){
		// 	cout<<result[i]<<" ";
		// }
		combCount++;
		// cout<<endl;
		return;
	}

	REP(i,total){
		result[current] = a[i];
		allNumbers(total, required, current+1); 
	}

}

void allCombinations(int total, int required, int current, int start_index){
	if(required == 0){
		REP(i,2){
			cout<<result[i]<<" ";
		}
		combCount++;
		cout<<endl;
		return;
	}
	// cout<<"current: "<<current<<" required: "<<required<<endl;

	for(int i = start_index; i< (total-required) + 1; i++){
		// cout<<"Pivot index: "<<i<<" value"<<a[i]<<endl;
		result[current] = a[i];
		allCombinations(total, required-1, current+1,i+1); 
	}

}



int main(){
	int n; bool first = true;
	while(1){
		cin>>n;
		if(n==0) break;
		REP(i,n){
			cin>>a[i];
		}
		combCount = 0;
		// allNumbers(n,6,0); //Start from 0
		// cout<<combCount<<endl;
		allCombinations(n,2,0,0);
	}
}