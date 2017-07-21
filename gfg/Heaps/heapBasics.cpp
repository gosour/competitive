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
//Create heap from an array
//Implement heapsort
//Everything is max heap

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

void heapSort(int *arr, int hlength){
	//sorts in ascending order, to change order, use min heapify
	heap(arr, hlength);
	for(int i = hlength - 1; i>0; i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		hlength--;
		heapify(arr, hlength, 0);
	}
}

int main(){

	int arr1[] = {4,6,3,2,5,7,23,545,25,44};
	int length = sizeof(arr1)/sizeof(int);
	heapSort(arr1, length);
	REP(i, length)
		cout<<arr1[i]<<" ";

	cout<<endl;
}

