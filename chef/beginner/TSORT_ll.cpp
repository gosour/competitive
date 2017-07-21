#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

struct Node{
	int value;
	Node *next;
};

int main(){
	int t;
	int count = 0;
	Node *list = new Node();
	list->next == NULL;
	list->value = -1;
	cin>>t;
	while(t--){
		int temp; cin>>temp;
		Node *newNode = new Node(); 
		newNode->value = temp; newNode->next = NULL;
		Node *p = list;
		while(p->next!=NULL && p->next->value < temp) p = p->next;
		if(p->next ==NULL) p->next = newNode;
		else{
			newNode->next = p->next;
			p->next = newNode;
		}
	}

	while(list!=NULL){
		if(list->value!=-1){
			cout<<list->value<<endl;
		}
		list = list->next;
	}

}