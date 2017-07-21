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

void reverseAll(Node **h){
	if(*h == NULL || (*h)->next == NULL) return;
	
	Node *toReverse = (*h)->next;
	Node *next = (*h)->next;
	reverseAll(&toReverse);
	next->next = *h;
	(*h)->next = NULL;
	*h = toReverse;

}

void reverseEveryNode(Node **h){
	//Swap the first two and change head pointer
	if(*h == NULL || (*h)->next == NULL) return; //0 and 1 elements

	Node* curr = *h;
	Node *next = curr->next;
	Node *nextnext = next->next; //Can be null

	*h = next;
	next->next = curr;
	//Set curr->next
	reverseEveryNode(&nextnext);
	curr->next = nextnext;
}

void reverseEveryKNode(Node **h, int k){
	if(*h == NULL) return;
	Node *first = *h;
	Node * afterKth = *h;
	Node *kth = NULL;
	int i = 0;
	while(i++<k && afterKth!= NULL){
		kth = afterKth;
		afterKth = afterKth->next;
	}
	if(afterKth == NULL){
		reverseAll(h);
	}else{
		// DEBUG(kth->val);
		// DEBUG(afterKth->val);
		kth->next = NULL;
		reverseAll(h);
		reverseEveryKNode(&afterKth,k);
		first->next = afterKth;
	}
}

int main(){
	Node * head1 = NULL;
	addToFront(&head1,10);
	addToFront(&head1,20);
	addToFront(&head1,8);addToFront(&head1,18);
	addToFront(&head1,7);
	addToFront(&head1,17);
	addToFront(&head1,6);
	addToFront(&head1,16);
	addToFront(&head1,14);
	addToFront(&head1,12);

	printLL(head1);
	// reverseAll(&head1);
	reverseEveryKNode(&head1,4);
	// reverseEveryNode(&head1);
	printLL(head1);


}