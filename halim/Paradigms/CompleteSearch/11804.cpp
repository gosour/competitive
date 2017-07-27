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
struct Player{
	string name;
	int attack, defence;
};

bool mysort(Player A, Player B){
	if(A.attack > B.attack) return true;
	else if(A.attack == B.attack){
		if(A.defence < B.defence) return true;
		else return false;
	}
	else return false;
}

int main(){
	Player P[10];
	int t; scanf("%d",&t);
	while(t--){
		REP(i,10){
			cin>>P[i].name>>P[i].attack>>P[i].defence;
		}

		sort(P, P+10,mysort);
	}
	REP(i,10){
		cout<<P[i].name<<endl;
	}
}