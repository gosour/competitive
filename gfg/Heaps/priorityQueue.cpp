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

int parent(int i){
	//zero index
	return (int)(i-1)/2;
}

int left(int i){
	//zero index
	return 2*(i + 1) - 1;
}

int right(int i){
	//zero index
	return 2*(i + 1);
}

void heapify(int *arr, int hlength, int index){
	int l = left(index), r = right(index);
	int max_i = index;
	int largest = arr[index];
	if(l < hlength && arr[l] > arr[index]){
		largest = arr[l];
		max_i = l;
	}

	if(r < hlength && arr[r] > largest){
		largest = arr[r];
		max_i = r;
	}

	if(max_i != index){
		arr[max_i] = arr[index];
		arr[index] = largest;
		heapify(arr,hlength,max_i);
	}
}

void heap(int *arr, int hlength){
	for(int i= hlength/2-1 ; i>=0;i--){
		heapify(arr, hlength, i);
	}
}

int heapMaximum(int *h, int hlength){
	if(hlength > 0)
		return h[0];
	else
		return -INF;
}

int extractHeapMaximum(int *h, int *hlength){
	if(*hlength <= 0)
		return -1;

	int max = h[0];
	h[0] = h[*hlength-1];
	(*hlength)--;
	heapify(h,*hlength, 0);
	return max;
}

void increaseKey(int *h, int hlength, int index, int key){
	h[index] = key;
	int p = parent(index);
	while(p >=0  && h[p] < h[index]){
		int temp = h[index];
		h[index] = h[p];
		h[p] = h[index];
		index = p;
		p = parent(index);
	}
}

void insertKey(int *h, int *hlength, int key){
	
}

int main(){
	int hArr[] = {4,6,3,2,5,7,23,545,25,44};
	int length = sizeof(hArr)/sizeof(int);
	heap(hArr, length);

	REP(i, length)
		cout<<hArr[i]<<" ";
	cout<<endl;

	increaseKey(hArr, length, 2, 100);
	cout<<extractHeapMaximum(hArr,&length)<<endl;
	cout<<extractHeapMaximum(hArr,&length)<<endl;
	// cout<<extractHeapMaximum(hArr,&length)<<endl;
	// cout<<extractHeapMaximum(hArr,&length)<<endl;
	// cout<<extractHeapMaximum(hArr,&length)<<endl;
	// cout<<extractHeapMaximum(hArr,&length)<<endl;



	cout<<endl;
}