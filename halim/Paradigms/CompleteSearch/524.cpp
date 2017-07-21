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

int arr[17];
int visited[17];
int n;

bool isPrime(int n){
	static int primelist[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	REP(i,sizeof(primelist)/sizeof(primelist[0])){
		if(n==primelist[i]) return true;
	}
	return false;
}


void Place(int place, int number){
	// cout<<place<<" "<<number<<endl;
	arr[place] = number;
	visited[number] = 1;
	if(place == n-1 && isPrime(number+1)){
		REP(i,n){
			cout<<arr[i];
			if(i!=n-1) cout<<" ";
		}
		cout<<endl;
	}
	
	else{
		REP2(i,1,n){
			if(visited[i] != 0) continue;
			if(isPrime(number + i)){
				Place(place+1, i);
			}
		}
	}
	visited[number] = 0;
}
int main(){
	int t = 1;
	while(scanf("%d",&n) !=EOF){
		memset(visited,0,sizeof(visited));
		if(t!=1) cout<<endl;
		cout<<"Case "<<t++<<":"<<endl;
		Place(0,1);
	}
}