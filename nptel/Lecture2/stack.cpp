#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int top = -1;

bool isEmpty(){
	return (top < 0);
}

void push(int *arr, int n, int element){
	if(top == (n-1)){
		cout << "Stack Overflow." << endl;
		return ;
	}
	*(arr+(++top)) = element;
	return ;
}

void pop(int *arr,int n){
	if(top == -1){
		cout << "Stack Underflow." << endl;
	}
	*(arr+(top--)) = -1;
	return ;
}

int top_element(int *arr){
	return *(arr+top);
}

int size(){
	
	return (top+1);
}

void printStack(int *arr,int n){
	cout << "Stack is: " << endl;
	for(int i=0;i<n;i++){
		cout << *(arr+i) << "\t";
	}
	cout << endl;
	return ;
}
int main(){
	int n;
	cin >> n;
	int *arr= (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		*(arr+i) = -1;
	}
	push(arr,n,1);
	push(arr,n,2);
	push(arr,n,3);
	printStack(arr,n);
	cout << "Is stack Empty?" << endl;
	cout << (isEmpty()?cout << "Stack is Empty.":cout <<"Stack is not Empty.") << endl;
	cout <<	"Size of stack:\t" << size() << "\ntop element is:\t" << top_element(arr) << endl;
	pop(arr,n);
	printStack(arr,n);
	cout << (isEmpty()?cout << "Stack is Empty.":cout <<"Stack is not Empty.") << endl;
	cout <<	"Size of stack:\t" << size() << "\ntop element is:\t" << top_element(arr) << endl;
	return 0;
}
