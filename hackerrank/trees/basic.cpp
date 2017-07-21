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

//Preorder traversal

struct node{
	int data;
	node *left;
	node *right;
};

void preOrder(node * root){
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node *root){
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void inOrder(node *root){
	if(root==NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
	
}

int height(node *root){
	if (root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 0;

	return 1 + max(height(root->left), height(root->right));
}

node* insert(node * root, int value){
	if(root==NULL){
		root = new node();
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	}
	else if(root->data > value)
		root->left = insert(root->left, value);
	else
		root->right = insert(root->right, value);

	return root;
}

int main(){
	node *tree = new node();
	tree->data = 3;
	tree->left = new node();
	tree->left->data = 5;
	tree->left->right = NULL;
	tree->left->left = NULL;
	tree->right = new node();
	tree->right->data = 2;
	tree->right->right = NULL;
	tree->right->left = NULL;

	preOrder(tree);
}