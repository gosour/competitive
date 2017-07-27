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

int kadane(int *arr, int *start, int *finish, int n){
	int sum = 0, maxSum = -INF, i;

	*finish = -1; //this will remain - 1if not positive numbers present

	int local_start = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum < 0){
			local_start = i+1;
			sum = 0;
		}
		else if(sum > maxSum){
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if(*finish != -1) return maxSum;

	//If all the numbers are negative
	//find max number 
	maxSum = arr[0];
	*start = *finish = 0;
	for(int i=1;i<n;i++){
		if(arr[i] > maxSum){
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}
int temp[1005];

void findMaxSum(int M[][], int row, int column){
	int maxSum = -INF, finalLeft, finalRight, finalTop, finalBottom;
	int left,right,i;
	int sum, start, finish;
	for(left = 0;left<column;left++){
		memset(temp,0,sizeof(temp));
		for(right = left;right<column;right++){
			for(i=0;i<row;i++) temp[i] += M[i][right];

			sum = kadane(temp,&start,&finish,row);
			if(sum > maxSum){
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}

	}
}

int main(){
	
}