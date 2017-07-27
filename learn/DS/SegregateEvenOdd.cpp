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

void segregate(Node ** headref){
	Node *evenEnd = NULL;
	Node *traverse = *headref;
	Node *prev = NULL;
	while(traverse != NULL){
		Node *p = traverse;
		DEBUG(p->val);
		if(p->val % 2 == 0){
			if(evenEnd == NULL){
				evenEnd = p;
				prev->next = p->next;
				*headref = p;

			}
			Node *temp = evenEnd->next;
			temp->next = p->next;
			prev->next = temp;

			p->next = evenEnd->next->next;
			evenEnd->next = p;
			evenEnd = p;

		}
		prev = traverse;
		traverse = traverse->next;
	}
}

int main(){
	int t; cin>>t;
	int n;
	while(t--){
		int n; cin>>n;
		Node *LL = NULL;
		REP(i,n){
			int temp; cin>>temp;
			push(&LL,temp);
		}

		segregate(&LL);
		print(LL);
	}

}