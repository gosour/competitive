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
int N;
double dist[25][25], memo[1<<16+2];

double matching(int bit_mask){
	if(memo[bit_mask] > -0.5) return memo[bit_mask];
	if(bit_mask == (1<<2*N) - 1) return memo[bit_mask] = 0;

	double matching_value = 3267*3267;
	for(int p1 = 0;p1 < 2*N;p1++){
		if(!(bit_mask && (1<<p1))){
			for(int p2 = p1+1;p2<2*N;p2++){
				if(!(bit_mask && (1<<p2)))
					matching_value = min(matching_value, dist[p1][p2] + matching(bit_mask | (1<<p1) | (1<<p2)));
			}
		}
		break;
	}
	return memo[bit_mask] = matching_value;
}

int countOnes(int bitmap, int *start, int *end, int *isMax){
	*start = 0; *end = 0; *isMax = 0;
	int b = 0,count = 0;
	while(bitmap){
		b++;
		if(bitmap % 2 != 0){
			if(*start == 0) {
				*start = b;
			}
			*end = b;
			count++;
		}
		bitmap /= 2;	
	}
	if(count == b) *isMax = 1;
	return count;
}

int bitCount(int bitmap){
	int count = 0;
	while(bitmap){
		count++;
		bitmap /= 2;
	}
	return count;
}

int main(){
	char line[1000], name[1000];
	// int i,j, caseNo = 1;
	int x[20], y[20], t = 1;
	int start = 0, end = 0 , isMax = 0;

	while(sscanf(gets(line),"%d",&N),N){
		for(int i=0; i<2*N;i++){
			sscanf(gets(line), "%s %d %d",&name, &x[i],&y[i]);
		}

		for(int i = 0;i<2*N;i++){
			for(int j=0;j<2*N;j++){
				dist[i+1][j+1] = sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				// cout<<dist[i+1][j+1]<<" ";
			}
			// cout<<endl;
		}

		for(int bitmap=0;bitmap<2*N;bitmap++) memo[bitmap] = INF;

		for(int bitmap=3;bitmap<(1<<2*N);bitmap++){
			// cout<<"Bitmap: "<<bitmap<<endl;
			int end, start, isMax;
			int count = countOnes(bitmap,&start,&end,&isMax);
			end = bitCount(bitmap);
			// cout<<"Count: "<<count<<" isMax: "<<isMax<<endl;
			if(count == 2){ //if only two bits are set
				memo[bitmap] = dist[end][start];
				// cout<<bitmap<<" : ";
				// DEBUG(memo[bitmap]);
			}else if(count!=2 && count%2 == 0){
				double maxVal = INF;
				for(int i=1;i<=end;i++){
					for(int j=1;j<=end;j++){
						if(i==j) continue;
						if( !(bitmap & (1<<(i-1)))  || !(bitmap & (1<<(j-1)))) continue;
						// cout<<"unsetting "<<i<<" and "<<j<<endl;
						// cout<<"indexes: "<<i<<" "<<j<<endl;
						int mask = bitmap ^ (1<<(i-1));
						mask = mask & (bitmap ^ (1<<(j-1)));
						// cout<<"mask: "<<mask<<" dist[i][j]: "<<dist[i][j]<<" memo[mask]: "<<memo[mask]<<endl;
						maxVal = min(maxVal,dist[i][j] + memo[mask]);
					}
				}
				// cout<<"bitmap : "<<bitmap<<" "<<maxVal<<endl;
				memo[bitmap] = maxVal;
			}
			else{
				// cout<<"continued"<<endl;
				continue;
			}
		}
		printf("Case %d: %0.2lf\n",t++,memo[(1<<2*N)-1]);

	}	
}