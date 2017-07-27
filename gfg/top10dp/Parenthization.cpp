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

int countParenth(char symb[], char oper[], int n){
	int F[n][n] = {}, T[n][n] = {};

	REP(i,n){
		if(symb[i] == 'F')
			F[i][i] = 1;
		else 
			T[i][i] = 1;
	}

	for(int gap = 1;gap<n;gap++){
		for(int i=0,j=gap; j<n; i++,j++){
			T[i][j] = F[i][j] = 0;
			for(int g = 0; g<gap; g++){
				int k = i+g;

				int tik = T[i][k] + F[i][k];
				int tkj = T[k+1][j] + F[k+1][j];

				if (oper[k] == '&')
                {
                    T[i][j] += T[i][k]*T[k+1][j];
                    F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]);
                }
                if (oper[k] == '|')
                {
                    F[i][j] += F[i][k]*F[k+1][j];
                    T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]);
                }
                if (oper[k] == '^')
                {
                    T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j];
                    F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
                }
			}
		}
	}
	return T[0][n-1];
}

int main(){
	char symbols[] = "TTFT";
	char operators[] = "|&^";
	int n = strlen(symbols);
	cout<<countParenth(symbols,operators,n);
	return 0;
}