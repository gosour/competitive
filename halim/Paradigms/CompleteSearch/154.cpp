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
	map<char, int> colors;
    map<char, int> materials;
    int cities[101][5];
    string s;
    int i,j,k,cnt,dif,minDif,min;
    colors['b'] = 0;
    colors['g'] = 1;
    colors['o'] = 2;
    colors['r'] = 3;
    colors['y'] = 4;
    materials['A'] = 0;
    materials['G'] = 1;
    materials['N'] = 2;
    materials['P'] = 3;
    materials['S'] = 4;

	while(1){
		cnt = 0;
		while(1){
			cin>>s;
			if(s[0] == 'e' || s[0] == '#') break;
			j = 0;
			while(j<s.length()){
				cities[cnt][colors[s[j]]] = materials[s[j+2]];
				j+=4;
			}
			cnt++;
		}

		if(s[0] == '#') break;
		minDif = 100000;
		min = 0;
		
		for(i=0;i<cnt;i++){
			dif = 0;
			for(j=0;j<cnt;j++){
				if(i==j) continue;
				for(k=0;k<5;k++){
					if(cities[i][k]!=cities[j][k]) dif++;
				}
			}
			if(dif<minDif){
				minDif = dif;
				min = i;
			}
		}
		cout<<min+i<<endl;
	}
}