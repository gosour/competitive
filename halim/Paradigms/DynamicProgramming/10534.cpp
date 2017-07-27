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
int arr1[10001];
int arr2[10001];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		REP(i,n) scanf("%d",&arr1[i]);
		REP(i,n) arr2[n-i-1] = arr1[i];

		int tail1[10001] = {0};
		int lcs1[10001] = {0};
		int lcs2[10001] = {0};
		int tail2[10002] = {0};
		tail1[0] = arr1[0];
		tail2[0] = arr2[0];
		int end1 = 1,end2 = 1;
		for(int i=0;i<n;i++){
			lcs1[i] = lcs2[i] = 1;
			if(arr1[i]<=tail1[0]) tail1[0] = arr1[i];
			else if(arr1[i] > tail1[end1-1]){
				lcs1[i] = end1;
				tail1[end1++] = arr1[i];
			}
			else{
				int *p = lower_bound(tail1,tail1+end1,arr1[i]);
				*p = arr1[i];
				lcs1[i] = end1; 
			}

			if(arr2[i]<tail2[0]) tail2[0] = arr2[i];
			else if(arr2[i] > tail2[end2-1]){
				tail2[end2++] = arr2[i];
				lcs2[i] = end2;
			}
			else{
				int *p = lower_bound(tail2,tail2+end2,arr2[i]);
				*p = arr2[i];
				lcs2[i] = end2;
			}
		}
		REP(i,n)
			cout<<lcs1[i]<<"+";
		cout<<endl;
		REP(i,n)
			cout<<lcs2[i]<<"+";
		cout<<endl;
		int len =0;
		for(int i=min(end1-1,end2-1);i>=0;i--){
			len = max(len,min(tail1[i],tail2[i]));
		}
		cout<<2*len-1<<endl;
	}
}