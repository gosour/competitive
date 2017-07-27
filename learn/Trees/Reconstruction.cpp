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

struct node{
	//char data;
	int data;
	struct node * left;
	struct node * right;
};
struct node * createNode(char d){
	node * n = (node *)malloc(sizeof(node));
	n->data = d;
	n->left = n->right = NULL;
}

int currPreorder = 0;
string inorder, preorder;

struct node * buildTree(string instring){
	DEBUG(preorder[currPreorder]);
	DEBUG(instring);
	int len = instring.length();
	if(len == 0 || currPreorder > preorder.length()) return NULL;

	int idx = instring.find(preorder[currPreorder++]);
	DEBUG(idx);
	struct node * tree = createNode(instring[idx]);
	DEBUG(instring.substr(0,idx));
	DEBUG(instring.substr(idx+1));
	tree->left = buildTree(instring.substr(0,idx));
	tree->right = buildTree(instring.substr(idx+1));
	return tree;
	
}
void printLevelOrder(struct node * T){
	queue<node *> Q;
	int level = 1;
	Q.push(T);
	bool lr = true;
	vector<int> levelNodes;

	while(!Q.empty()){
		if(level == 0) {
			level = Q.size();
			if(!lr) 
				reverse(levelNodes.begin(), levelNodes.end());
			// lr = !lr;

			REP(i,levelNodes.size()){
				cout<<levelNodes[i]<<" ";
			}
			cout<<endl;
			levelNodes.clear();
		}
		struct node * temp = Q.front();
		DEBUG(temp->data);
		levelNodes.pb(temp->data);
		if(temp->left != NULL) Q.push(temp->left);
		if(temp->right != NULL) Q.push(temp->right);
		Q.pop();
		level--;
	}
	//Last level will not get printed
	if(levelNodes.size()){
		if(!lr) 
				reverse(levelNodes.begin(), levelNodes.end());
			lr = !lr;

			REP(i,levelNodes.size()){
				cout<<levelNodes[i]<<" ";
			}
			cout<<endl;
	}
}

void printAllRootToLeaves(){

}

int isSumProperty(struct node *T){
	if(T == NULL) return 0;
	int ls = isSumProperty(T->left);
	int rs = isSumProperty(T->right);
	if(ls == rs && ls == 0) return T->data;
	if(ls + rs == T->data && ls!=-1 && rs!=-1) return T->data;
	else {
		DEBUG(T->data);
		DEBUG(ls);
		DEBUG(rs);
		return -1;
	}
}

int main(){
	inorder = "DBEAFC";
	preorder = "ABDECF";
	currPreorder = 0;
	// struct node* tree = buildTree(inorder);
	// struct node *tree = createNode('A');
	// tree->left = createNode('B');
	// tree->right = createNode('C');
	// tree->right->left = createNode('D');
	// tree->right->right = createNode('E');
	struct node *root  = createNode(11);
	root->left         = createNode(8);
	root->right        = createNode(2);
	root->left->left   = createNode(3);
	root->left->right  = createNode(5);
	root->right->right = createNode(2);
  	if(isSumProperty(root) > 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}