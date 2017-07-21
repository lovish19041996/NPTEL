#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int * queue;
int n;
int front,rear;

int size(){
	return (n-front+rear)%n;
}

bool isEmpty(){
	return (front == rear);
}

int front_ele(){
	if(isEmpty()){
		cout << "Queue is Empty.\n";
		return -1;
	}
	return queue[front];
}

void dequeue(){
	 if(isEmpty()){
		cout << "Queue is Empty.\n";
		return ;
	}
	queue[front] = -1;
	front = (front+1)%n;
	return ;
}

void enqueue(int d){
	if(size() == n-1){
		cout << "Queue is full.\n";
		return ;
	}
	queue[rear] = d;
	rear =(rear+1)%n;
	return ;
}

int main(){
	n = 4;
	queue = (int *)malloc(n*sizeof(int));
	enqueue(3);
	enqueue(4);
	enqueue(5);
	dequeue();
	cout << front << " " << rear << " " << size() << " " << isEmpty() << " " << front_ele() << endl; 
	dequeue();
	enqueue(6);
	enqueue(7);
	enqueue(8);
	cout << front << " " << rear << " " << size() << " " << isEmpty() << " " << front_ele() << endl; 
	return 0;
}
