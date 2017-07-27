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
	int t, r, h;
	int TPrice[20],RPrice[20],HPrice[20];
	int TWithR[20][20],RWithH[20][20],HWithT[20][20];
	while(1){
		if(scanf("%d %d %d",&t,&r,&h) == EOF) break;
		REP(i,t){
			scanf("%d",&TPrice[i]);
			REP(j,r){
				scanf("%d",&TWithR[i][j]);
			}
		}
		REP(i,r){
			scanf("%d",&RPrice[i]);
			REP(j,h){
				scanf("%d",&RWithH[i][j]);
			}
		}
		REP(i,h){
			scanf("%d",&HPrice[i]);
			REP(j,r){
				scanf("%d",&HWithT[i][j]);
			}
		}

		int minPrice = 1<<30; bool path = false; int a = 0, b = 0, c = 0;
		REP(i,t){
			int price = 0; 
			price += TPrice[i];
			REP(j,r){
				if(TWithR[i][j] == 0){
					price += RPrice[j];
					REP(k,h){
						if(RWithH[j][k] == 0){
							price += HPrice[k];
							if(HWithT[k][i] == 0) {
								path = true; 
								if(price<minPrice) {
									minPrice = price;
									a = i;
									b = j;
									c = k;
								}
							}
							price -= HPrice[k];
						}
					}
					price -= RPrice[j];
				}
			}
			price -= TPrice[i];
		}

		if(path) cout<<a<<" "<<b<<" "<<c<<":"<<minPrice<<endl;
		else cout<<"Don't get married!"<<endl;
		
	}	
}