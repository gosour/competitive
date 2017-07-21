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

struct Node_t{
	int data; 
	struct Node_t *left;
	struct Node_t *right;
};

typedef struct Node_t Node;

Node * createNode(int v){
	Node * n = (Node *) malloc(sizeof(Node));
	n->data = v;
	n->left = n->right = NULL;
}

Node * insertBST(Node *tree, int v){
	if(tree == NULL){
		Node *node = createNode(v);
		return node;
	}else{
		if(tree->data > v)
			tree->left = insertBST(tree->left, v);
		else 
			tree->right = insertBST(tree->right, v);
	}
}

Node * deleteFromTree(Node *tree, int v){
	if(tree == NULL) return tree;
	if(v>tree->data) tree->right = deleteFromTree(tree->right,v);
	else if(v<tree->data) tree->left = deleteFromTree(tree->left,v);
	else{
		if(tree->left == NULL || tree->right == NULL){
			//Is a one child internal node or leaf
			Node *ptr = NULL;
			if(tree->left != NULL) ptr = tree->left;
			if(tree->right != NULL) ptr =  tree->right;
			free(tree);
			return ptr;
		}else{
			//Has two children 
			Node *rightMostOfLeft = tree->left;
			while(rightMostOfLeft->right != NULL){
				rightMostOfLeft = rightMostOfLeft->right;
			}
			int t = tree->data;
			tree->data = rightMostOfLeft->data;
			rightMostOfLeft->data = t;
			tree->left = deleteFromTree(tree->left,t);
		}
	}

}
void inorder(Node *tree){
	if(tree != NULL){
		inorder(tree->left);
		cout<<tree->data<<" ";
		inorder(tree->right);
	}
}

int main(){
	Node *tree = NULL;
	// tree = insertBST(tree, 10);
	// tree = insertBST(tree, 20);
	// tree = insertBST(tree, 50);
	// tree = insertBST(tree, 25);
	// tree = insertBST(tree, 27);
	// tree = insertBST(tree, 15);
	// tree = insertBST(tree, 19);

	// inorder(tree);
	// cout<<endl;

	// DEBUG("DELETING 27 15 10");
	// tree = deleteFromTree(tree, 27);
	// tree = deleteFromTree(tree, 15);
	// tree = deleteFromTree(tree, 10);

	// inorder(tree);
	float a = 0.333;
	float b = 0.1;
	cout<<(1.0/3) + (1.0/3) + (1.0/3)<<endl;

}