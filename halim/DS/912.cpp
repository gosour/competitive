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

struct Node{
	int p;
	char val;
};

Node pset[10];

int find(int a){
	if(pset[a].p == a){
		return a;
	}
	else{
		int idx = find(pset[a].p);
		pset[a].p = idx;
		pset[a].val = pset[idx].val;
		return idx;
	}
}

bool join(int a, int b){
	// cout<<"Joining "<<a <<" "<<b<<endl;
	int a_p = find(pset[a].p);
	int b_p = find(pset[b].p);
	// DEBUG(a_p); DEBUG(b_p);
	if(pset[a_p].val == pset[b_p].val){
		pset[a_p].p = pset[b_p].p;
		return true;
	}
	else{
		if(!pset[a_p].val){
			pset[a_p].p = pset[b_p].p;
			pset[a_p].val = pset[b_p].val;
			return true;
		}
		else if(!pset[b_p].val){
			pset[a_p].p = pset[b_p].p;
			pset[b_p].val = pset[a_p].val;
			return true;
		}
		else
			return false;
	}
}

bool isNormal(char c){
	return (c=='A' || c=='B' || c=='C' || c=='D');
}


int main(){
	int n; bool first = true;
	while(1){
		bool flag = true;
		REP(i,10){
			pset[i].p = i;
			pset[i].val = 0;
		}
		cin>>n; if(cin.eof()) break;
		bool isPossible = true;
		char t; int sum = 0;
		vector<char> gene1,gene2;
		REP(i,n) {cin>>t; gene1.pb(t);}
		REP(i,n) {cin>>t; gene2.pb(t);}
		REP(i,n){
			if(isNormal(gene1[i]) && isNormal(gene2[i])){
				if(gene1[i] == gene2[i]) continue;
				else {flag = false;break;}
			}

			else if(isNormal(gene1[i]) && !isNormal(gene2[i])){
				int idx = (int)gene2[i] - (int)'0'; 
				idx = find(idx);
				if(!pset[idx].val) pset[idx].val = gene1[i];
				else if(pset[idx].val != gene1[i]){
					flag = false;
					break;
				}
			}
			else if(isNormal(gene2[i]) && !isNormal(gene1[i])){
				int idx = (int)gene1[i] - (int)'0'; 
				idx = find(idx);
				if(!pset[idx].val) pset[idx].val = gene2[i];
				else if(pset[idx].val != gene2[i]){
					flag = false;
					break;
				}
			}
			else{
				int i1 = (int)gene1[i] - (int)'0', i2 = (int)gene2[i] - (int)'0';
				bool ans = join(i1,i2);
				if(!ans){
					flag = false; break;
				}
			}
		}
		if(first) first = false;
		else cout<<endl;
		if(!flag) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			int arr[10] = {};
			REP(i,10) {
				int id = find(i);
				if(pset[i].val && !arr[i]) {
					cout<<i<<" "<<pset[i].val<<endl;
					arr[i]++;
				}
			}
		}

	}
}