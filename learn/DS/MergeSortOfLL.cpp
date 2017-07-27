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

void print(Node *h){
	bool printed = false;
	while(h != NULL){
		cout<<h->val<<" ";
		h = h->next;
		printed = true;
	}
	if(printed) cout<<endl;
}

void mergeSort(Node **headRef){
	if(*head == NULL || *head->next == NULL) return; //0 and 1 node handled;

	Node *a, *b, *head;
	head = *headRef;

	FrontBackSplit(head, &a, &b); //not only updates a and b but actually splits. cannot go from a -> b
	mergeSort(&a);
	mergeSort(&b);

	*headRef = merge(a,b);
}

Node * merge(Node *a, Node *b){
	Node *result = NULL;

	if(a == NULL) return b;
	if(b == NULL) return a;

	if(a->val <=b->val){
		result = a;
		result->next = merge(a->next,b);
	}else{
		result = b;
		result->next = merge(a,b->next);
	}
	return result;
}

void FrontBackSplit(Node *head, Node **a, Node **b){
	Node *fast, *slow;
	fast = slow = head;

	if(head == NULL || head->next == NULL ){
		*a = head;
		*b = NULL;

	}
	else{
		fast = fast->next; //fast is one ahead before starting, so that slow is before mid point
		while(fast != NULL){
			fast = fast->next;
			if(fast!=NULL){
				slow = slow->next;
				fast = fast->next;
			}
		}

		*a = head;
		*b = slow->next;
		slow->next = NULL;
	}
}

int main(){
	
}