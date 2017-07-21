#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;


struct node *head;
struct node *tail;
int size;
struct node{
	int data;
	struct node *next;
};

struct node *newNode(int d){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = d;
	n->next = NULL;
	return n;
}

void enqueue(int n){
	if(head == NULL){
		head = tail = newNode(n);
		size++;
		return ;
	}
	tail->next = newNode(n);
	size++;
	tail = tail->next;
	return ;
}

void dequeue(){
	if(head == NULL){
		cout << "Queue is Empty.\n";
		return ;
	}
	struct node *temp = head;
	head = head->next;
	size--;
	free(temp);
	return ;
}

void printQueue(){
	struct node *temp = head;	
	while(temp != tail){
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << temp->data << "\n";
	cout << "Size of Queue " << size << endl;
	return ;
}
int main(){
	head = tail = NULL;
	enqueue(3);
	enqueue(4);
	enqueue(5);
	dequeue();
	printQueue();
	dequeue();
	enqueue(6);
	enqueue(7);
	enqueue(8);
	printQueue();
	return 0;		
}
