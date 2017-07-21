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
#include<ctype.h>

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

map<string,int> ingredient;
vector<pair<string,int> > cakes;

bool cmp(pair<string,int> A, pair<string,int> B){
	return (A.second!=B.second)? A.second<B.second : A.first<B.first;
}

int main(){
	int t; cin>>t; bool first = true;
	while(t-->0){
		string binderName;  cin.ignore(); getline(cin,binderName);
		REP(i,binderName.length()) binderName[i] = toupper(binderName[i]);
		int m,n,b;
		cin>>m>>n>>b;
		ingredient.clear();
		REP(i,m){
			string name; int price; cin>>name>>price;
			ingredient[name] = price;
		}
		cakes.clear();
		REP(i,n){
			string cakeName; int k; cin.ignore();getline(cin,cakeName); cin>>k;
			int total = 0;
			REP(i,k){
				string name; int amount; cin>>name; cin>>amount;
				total += ingredient[name]*amount;
			}
			if(total<=b) {
				cakes.pb(make_pair(cakeName,total));
			}
		}
		if(first) first = false;
		else printf("\n");

		cout<<binderName<<endl;
		if(cakes.size()!=0){
			sort(cakes.begin(),cakes.end(),cmp);
			REP(i,cakes.size())cout<<cakes[i].first<<endl;
		}
		else cout<<"Too expensive!"<<endl;

	}
}