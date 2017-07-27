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

struct Node{
	int val;
	Node * next;
};

void push(Node **h, int val){
	Node *node = (Node *) malloc(sizeof(node));
	node->val = val;
	node->next = NULL;

	Node *hp = *h;

	if(*h == NULL) {
		*h = node;
		return;
	}
	while(hp->next != NULL) hp = hp->next;
	hp->next = node;

}

bool del(Node **head, int val){
	if(*head == NULL) return false;
	Node * ptr = *head;
	Node * prev = NULL;
	while(ptr){
		if(ptr->val == val){
			if(prev == NULL){
				*head = ptr->next;
			}
			else{
				prev->next = ptr->next;
			}
			free(ptr);
			return true;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	return false;
}

void print(Node *h){
	bool printed = false;
	while(h != NULL){
		cout<<h->val<<" ";
		h = h->next;
		printed = true;
	}
	if(printed) cout<<endl;
}

int getCount(Node *h){
	if(h==NULL) return 0;
	else return 1 + getCount(h->next);
}

int NthFromEnd(Node *h, int n){
	Node *first  = h;
	Node *second = h;
	while(n-- && first){
		first = first->next;
	}
	while(first){
		first = first->next;
		second = second->next;
	}
	if(second)
		return second->val;
	else 
		return -1;
}

int middleElement(Node *h){
	Node *fast, *slow;
	fast = slow = h;

	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	if(slow)
		return slow->val;
	else 
		return -1;
}

void reverseRecursive(Node *curr, Node *prev, Node **head){
	if(!curr->next){
		*head = curr;
		curr->next = prev;
		return;
	}
	Node *next = curr->next;
	curr->next = prev;
	reverseRecursive(next, curr, head);
}

int main(){
	Node *head = NULL;
	REP(i,16) push(&head, i);
	print(head);
	cout<<getCount(head)<<endl;
	cout<<NthFromEnd(head, 1)<<endl;
	cout<<middleElement(head)<<endl;
	reverseRecursive(head, NULL, &head);
	print(head);
}