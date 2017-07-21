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
	cout<<endl;
}

void insertionSort(Node **head){
	if(*head == NULL || (*head)->next == NULL) return;

	Node *currNode = (*head)->next;
	Node *nextCurrNode;
	(*head)->next = NULL; //This is sorted by itself

	while(currNode){
		nextCurrNode = currNode->next;
		Node *h = *head;
		Node *prev = NULL;
		while(h){
			// DEBUG(h->val);
			if(h->val > currNode->val){
				if(prev == NULL){
					currNode->next = *head;
					*head = currNode;
				}else{
					prev->next = currNode;
					currNode->next = h;
				}
				break;//Already placed
			}

			prev = h;
			h = h->next;
		}
		if(h==NULL){
			//Will be placed at end of list
			prev->next = currNode;
			currNode->next = NULL;
		}
		currNode = nextCurrNode;
	}
}

Node *mergedhead(Node *a, Node *b){
	if(a==NULL && b==NULL) return NULL;
	if(a==NULL) return b;
	if(b==NULL) return a;

	int h1 = a->val;
	int h2 = b->val;
	if(h1>h2) {
		b->next = mergedhead(a,b->next);
	}
	else{
		a->next = mergedhead(a->next,b);
	}
}

int main(){
	Node * head1 = NULL;
	// addToFront(&head1,10);
	addToFront(&head1,20);
	addToFront(&head1,8);addToFront(&head1,18);
	// addToFront(&head1,7);
	// addToFront(&head1,17);
	// addToFront(&head1,6);
	// addToFront(&head1,16);
	// addToFront(&head1,14);
	Node *head2 = NULL;
	addToFront(&head2,11);
	addToFront(&head2,10);
	// addToFront(&head2,5);addToFront(&head2,9);
	// addToFront(&head2,7);
	// addToFront(&head2,12);
	// addToFront(&head2,6);
	// addToFront(&head2,1);
	// addToFront(&head2,4);

	insertionSort(&head2);
	insertionSort(&head1);

	Node *mhead = mergedhead(head1,head2);
	printLL(mhead);
}