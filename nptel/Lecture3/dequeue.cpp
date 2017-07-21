#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *header,*trailer;
int size;

struct node *newNode(int d){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = d;
	n->prev = n->next = NULL;
	return n;
}

void enqueuefirst(int d){
	struct node *n = newNode(d);
	if(header->next == NULL){
		header->next = n;
		n->prev = header;
		n->next = trailer;
		trailer->prev = n;
		size++;
		return ;
	}
	n->next = header->next;
	n->prev = header;
	n->next->prev = n;
	header->next = n;
	size++;
	return ; 
}

void dequeuefirst(){
	if(header->next == NULL){
		cout << "Queue is Empty\n";
		return ;
	}
	struct node *temp = header->next;
	header->next = temp->next;
	temp->next->prev = header;
	free(temp);
	size--;
	return ;
}

void enqueuelast(int d){
	struct node *n = newNode(d);
	if(header->next == NULL){
		n->next = trailer;
		n->prev = header;
		header->next = n;
		trailer->prev = n;
		size++;
		return ;
	}
	n->next = trailer;
	n->prev = trailer->prev;
	trailer->prev = n;
	n->prev->next = n;
	size++;
	return ; 
}

void dequeuelast(){
	if(header->next == NULL){
		cout << "Queue is Empty\n";
		return ;
	}
	struct node *temp = trailer->prev;
	temp->prev->next = trailer;
	trailer->prev = temp->prev;
	free(temp);
	size--;
	return ;
}

void printQueue(){
	struct node *temp = header->next;
	while(temp->next != trailer){
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << temp->data << endl;
	return ;
}

int main(){
	header = newNode(-1); 	// data value doesn't matter
	trailer = newNode(-1);	// data value doesn't matter
	enqueuefirst(1);
	enqueuefirst(2);
	enqueuefirst(3);
	enqueuefirst(4);
	dequeuefirst();
	enqueuefirst(5);
	printQueue();
	enqueuelast(6);
	enqueuelast(7);
	printQueue();
	dequeuelast();
	dequeuelast();
	dequeuelast();
	printQueue();
	dequeuefirst();
	dequeuefirst();
	printQueue();
	return 0;
}
