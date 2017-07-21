#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int *stack;
int n;
int top = -1;
void resizeStack(){
	int *new_stack = (int *)malloc((n+2)*sizeof(int));
	for(int i=0;i<n;i++){
		new_stack[i] = stack[i];
	}
	stack = new_stack;
	n = n+2;
	return;
}

void printStack(){
	for(int i=0;i<n;i++){
		cout << stack[i] << "\t";
	}
	cout << "\n";
	return ;
}

void growthStack(){
	int *new_stack = (int *)malloc((2*n)*sizeof(int));
	for(int i=0;i<n;i++){
		new_stack[i] = stack[i];
	}
	stack = new_stack;
	n = 2*n;
	return;
}

void push(int d){
	stack[++top] = d;
	return ;
}
int main(){
	cin >> n;
	stack = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin >> stack[i];
		top++;
	}
	resizeStack();
	push(3);	
	printStack();
	growthStack();
	push(4);
	push(5);
	push(6);
	printStack();
	return 0;	
}
