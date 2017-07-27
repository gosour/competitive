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
#define S 100000
#define MAX 200005

vi segment_tree;
int arr[MAX];
int countArr[MAX];
int start[MAX];

void build_segment_tree(int node, int b, int e){
	if(e == b + 1){
		segment_tree[node] = countArr[arr[b]];
	}
	else{
		int left_idx = 2*node+1, right_idx = 2*node+2;
		build_segment_tree(left_idx,b,(b+e)/2);
		build_segment_tree(right_idx,(b+e)/2,e);
		segment_tree[node] = (segment_tree[left_idx] > segment_tree[right_idx])? segment_tree[left_idx] : segment_tree[right_idx];
	}
}

void init_segment_tree(int n){
	int length = (int)(2 * pow(2.0,floor( (log((double)n) / log(2.0) ) + 1)));
	segment_tree.resize(length,0);
	build_segment_tree(0,0,n);
}



int query_tree(int node, int l, int h, int ql, int qh){
	// cout<<"IN tree "<<node<<" "<<l<<" "<<h<<" "<<ql<<" "<<qh<<endl;
	if(ql<=l && qh>=h) return segment_tree[node];
	if(qh<=l || ql>=h) return -1; /*Equality used because equal to h or qh is moot since they are not the actual range*/

	int lval = query_tree(2*node+1, l, (l+h)/2, ql, qh);
	int rval = query_tree(2*node+2, (l+h)/2, h, ql, qh);
	return (lval>rval)? lval : rval;
}

int query(int b, int e, int n){
	// cout<<b<<" "<<e<<endl;
	/*Check if partial query from beginning*/
	if(b != start[b]){
		/*Separate first partial query*/
		int freq_left = countArr[arr[b]] - (b-start[b]);
		int k = freq_left + b  - 1;
		if(k>=e) return (e-b+1);
		else{
			int freq_right = query(k+1,e,n); 
			return (freq_left>freq_right)? freq_left: freq_right;
		}
	}
	else if(start[e]+countArr[arr[e]]-1>e){
		/*Seperate last partial query*/
		// cout<<"HERE"<<endl;
		int freq_right = e - start[e] + 1;
		if(b == start[e]) return (e-b+1);
		else{
			int freq_left = query(b,start[e] - 1,n);
			return (freq_left>freq_right)? freq_left: freq_right;
		}
	}
	else{
		return query_tree(0,0,n,b,e+1);
	}
}

int main(){
	int n,q;
	
	while(1){
		scanf("%d",&n); if(n == 0) break;
		else scanf("%d",&q);
		REP(i,n) {
			scanf("%d",&arr[i]);
			arr[i] += S;
			countArr[arr[i]]++;
			// if(countArr[arr[i]] == 1) start[arr[i]] = i;
		}

		/*Populate countArr and start*/
		bool isNew = true; int last_id = 0;
		for(int i=0;i<n;i++){

			if(arr[i] == arr[last_id]) start[i] = last_id;
			else{
				start[i] = i; last_id = i;
			}
		}

		init_segment_tree(n);

		REP(i,q){
			int b,e; scanf("%d %d",&b,&e);
			cout<<query(b-1,e-1,n)<<endl;
		}

	}
}