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

bool detectLoop(Node *h){
	Node *fast, *slow;
	fast = slow = h;
	bool loopFound = false;
	Node *meetingPoint = NULL;

	while(fast && !loopFound){
		fast = fast->next;
		if(fast){

			if(fast->next == slow->next){
				loopFound = true;
				meetingPoint = fast->next;
			}
			fast = fast->next;
			slow = slow->next;
		}
	}
	if(loopFound){
		slow = h;
		fast = meetingPoint;
		while(slow->next!=fast->next){
			slow = slow->next;
			fast = fast->next;
		}
		cout<<"Loop in "<<fast->val<<endl;

	}
	return loopFound;
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

	Node *last = head1;
	while(last->next) last = last->next;
	last->next = head1->next->next->next;
	DEBUG(detectLoop(head1));
}