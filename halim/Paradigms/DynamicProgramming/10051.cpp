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
struct Box{
	int color[6];
};
struct Parent{
	int idx;
	int face;
};

int oppositeFace(int face){
	switch(face){
		case 0: return 1;
		case 1: return 0;
		case 2: return 3;
		case 3: return 2;
		case 4: return 5;
		case 5: return 4;
	}
}


int table[6][501];
string printColor(int face){
	switch(face){
		case 0: return "front";
		case 1: return "back";
		case 2: return "left";
		case 3: return "right";
		case 4: return "top";
		case 5: return "bottom";
	}
}

int main(){
	int n; int t = 1;
	while(scanf("%d",&n) && n!=0){
		vector<Box> boxes;
		REP(i,n){
			Box b;
			scanf("%d %d %d %d %d %d",&b.color[0],&b.color[1],&b.color[2],&b.color[3],&b.color[4],&b.color[5]);
			boxes.pb(b);
		}
		REP(i,n)
			REP(j,6)
				table[j][i] = 1;
		int ans = 1;
		vector< vector<Parent> >parents; parents.resize(6);
		REP(i,6){
			parents[i].resize(n);
			REP(j,n){
				parents[i][j].idx = -1;
				parents[i][j].face = 0;
			}
		}
		Parent last;
		last.idx = 0;
		last.face = 0;
		for(int i=1;i<n;i++){
			for(int k=0;k<6;k++){
				for(int j=0;j<i;j++){
					for(int l=0;l<6;l++){
						if(boxes[j].color[l] == boxes[i].color[k]){
							if(table[oppositeFace(l)][j]  + 1 > table[k][i]){
								table[k][i] = table[oppositeFace(l)][j] + 1;
								parents[k][i].idx = j;
								parents[k][i].face = oppositeFace(l);
								if(ans < table[k][i]){
									ans = table[k][i];
									last.idx = i;
									last.face = k;
								}
							}
						}
					}
				}
			}
		}
		if(t!=1) cout<<endl;
		cout<<"Case #"<<t++<<endl;
		cout<<ans<<endl;
		vector<Parent> solution;
		while(last.idx!= -1){
			solution.pb(last);
			last = parents[last.face][last.idx];
		}
		reverse(solution.begin(),solution.end());
		REP(i,solution.size()){
			cout<<solution[i].idx+1<<" "<<printColor(solution[i].face)<<endl;
		}

	}		
}