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

int partition(int *arr, int l, int r){
	int i=l-1;
	int k = arr[r];
	for(int j=l;j<r;j++){
		if(arr[j] < k){
			swap(arr[j], arr[i+1]);
			i++;
		}
	}
	swap(arr[i+1],arr[r]);
	i++;
	return i;
}

void quicksort(int *arr, int l, int r){
	if(l < r ){
		int q = partition(arr,l,r);
		DEBUG(q); DEBUG(arr[q]);
		quicksort(arr, l, q-1);
		quicksort(arr, q+1, r);
	}
}

int main(){
	int arr[] = {12,4,56,54,3,10,44};
	quicksort(arr,0,sizeof(arr)/sizeof(int)-1);
	REP(i,sizeof(arr)/sizeof(int)){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}