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

vector<int> tree;

void populateTree(int arr[],int node, int l, int h){
	if(l+1==h) tree[node] = arr[l];
	else{
		int mid = (l+h)/2;
		int left_child = 2*node + 1;
		int right_child = 2*node + 2;
		populateTree(arr,left_child,l,mid);
		populateTree(arr,right_child,mid,h);
		if(tree[left_child] > tree[right_child] ) tree[node] = tree[left_child];
		else tree[node] = tree[right_child];
	}
}

int query(int node, int l, int h, int ql, int qh){
	cout<<"node: "<<node<<" l: "<<l<<" h: "<<h<<" ql: "<<ql<<" qh: "<<qh<<endl;
	//1. Is current tree range inside qrange
	if(ql<=l && qh>=h) return tree[node];

	//2. qrange doesnot overlap with tree range at all
	// If it goes then return a minimum value ( a token value to distinguish that the node returned nothing)
	if(qh<=l || ql >= h) return -1;

	//3. qrange overlaps with tree range
	int lval = query(2*node+1, l, (l+h)/2, ql, qh);
	int rval = query(2*node+2, (l+h)/2, h, ql, qh);
	return (lval>rval)? lval : rval;
}
void create_tree(int n, int arr[]){
	int h = ceil(log(n)/log(2));
	int length = 2*(pow(2,h+1));
	tree.resize(length,-1);
	populateTree(arr,0,0,n);
}

void inorder(int node){
	if(tree[node] == -1) return;
	else{
		cout<< tree[node]<<"=";
		inorder(2*node+1);
		inorder(2*node+2);
	}
}

int main(){
	int array[7] = {1,2,3,4,3,2,1};
	create_tree(7,array);
	/*Traversing a tree inorder*/
	REP(i,tree.size()){
		cout<<tree[i]<<"=";
	}
	cout<<endl;
	inorder(0); cout<<endl;
	cout<<"0 and 7: "<<query(0,0,7,0,7)<<endl;
	cout<<"0 and 6: "<<query(0,0,7,0,6)<<endl;
	cout<<"0 and 3: "<<query(0,0,7,0,3)<<endl;
	cout<<"4 and 6: "<<query(0,0,7,4,6)<<endl;
	cout<<"5 and 7: "<<query(0,0,7,5,7)<<endl;
	DEBUG(tree.size());
}