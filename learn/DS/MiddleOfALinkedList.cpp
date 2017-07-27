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
typedef struct Node_t{
	int val;
	struct Node_t *next;
} Node;

void addToFront(Node **h, int val){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	if(*h == NULL){
		/*Create node and make h point to it*/
		*h = newNode;
	}else{
		newNode->next = *h;
		*h = newNode;
	}
	return;
}

void printLL(Node *h){
	while(h){
		cout<<h->val<<" ";
		h = h->next;
	}
}

Node * MiddleElement(Node *h){
	if(h==NULL) return h;
	Node *fast,*slow; fast = slow = h;
	if(fast) fast = fast->next;
	while(fast && fast->next){
		fast = fast->next;
		if(fast){
			fast = fast->next;
			slow = slow->next;
		}
	}

	return slow;
}

Node *removeDuplicates(Node *root)
{
	// your code goes here
	if(root==NULL || root->next == NULL ) return NULL;
	Node *prev,*curr,*next;
	prev = root;
	curr = root->next;
	while(curr!=NULL){
	 next = curr->next;
	 if(prev->val == curr->val){
	     //remove curr
	     prev->next = next;
	     free(curr);
	     curr = next;
	}else{
	     prev = curr;
	     curr = next;
	}
}
 
 return root;
}

int main(){
	Node * head = NULL;
	addToFront(&head,10);
	addToFront(&head,10);
	addToFront(&head,8);addToFront(&head,8);
	addToFront(&head,7);
	addToFront(&head,7);
	addToFront(&head,6);
	addToFront(&head,6);
	addToFront(&head,4);

	printLL(head);
	removeDuplicates(head);
	cout<<endl;
	printLL(head);
	// cout<<endl<<MiddleElement(head)->val<<endl;
}