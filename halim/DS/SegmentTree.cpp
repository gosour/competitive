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

#define RANGE_SUM  0
#define RANGE_MIN 1
#define RANGE_MAX 2
vi segment_tree; //Segment tree is stored like a heap array

void init_segment_tree(int N){
	//if original array size is N
	//then segment_tree has 2*2^(floor(log2(N)) + 1) nodes
	int length = (int)(2 * pow(2.0, floor((log((double) N) / log(2.0)) + 1)));
	segment_tree.resize(length,0);
}

void build_segment_tree(int code, int A[], int node, int b, int e){
	if(b==e){
		if(code == RANGE_SUM)	segment_tree[node] = A[b]; //store value of this cell
		else					segment_tree[node] = b; //if RANGE_MIN/MAX, store index
	}
	else{ //recursively compute values in the left and right subtrees
		int leftIdx = 2*node, rightIdx = 2*node+1;
		build_segment_tree(code, A, leftIdx, b, (b+e)/2);
		build_segment_tree(code, A, rightIdx, (b+e)/2+1, e);

		int lContent = segment_tree[leftIdx], rContent = segment_tree[rightIdx];

		if(code == RANGE_SUM)
			segment_tree[node] = lContent + rContent;
		else{
			int lValue = A[lContent], rValue = A[rContent];
			if(code == RANGE_MIN) segment_tree[node] = (lValue <= rValue)? lContent :rContent;
			else segment_tree[node] = (lValue >= rValue)? lContent :rContent;
		}
	}
}

int query(int code, int A[], int node, int b, int e, int i,int j){
	if(i>e || j < b) return -1; 
	if(b>=i && e<=j) return segment_tree[node]; //if the current interval is inside query interval

	//compute minimum position in the left and right part of the interval
	int p1 = query(code, A, 2*node, b, (b+e)/2, i, j);
	int p2 = query(code, A, 2*node+1, (b+e)/2 + 1, e, i,j);

	if(p1 == -1) return p2;
	if(p2 == -1) return p1;

	if(code == RANGE_SUM) return p1+p2;
	else if(code == RANGE_MIN) return (A[p1] <= A[p2]) ? p1 : p2;
	else return (A[p1] <= A[p2]) ? p2 : p1;
}


int main(){
		
}