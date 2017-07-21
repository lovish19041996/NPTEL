#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int *stack;
int top = -1;
int n;
bool isEmpty(){
	return (top<0);
}

void push(int d){
	if(top == n-1){
		cout << "Stack overflow.\n";
		return;
	}
	stack[++top] = d;
	return ;
}

int pop(){
	if(top == -1){
		cout << "Stack underflow.\n";
		return -1;  
	}
	int x = stack[top--];
	return x;
}

int * computeSpan(int *arr, int n){
	int *new_arr = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		int h=0;bool done = false;
		while(!(isEmpty() || done)){
			if(arr[i] >= arr[stack[top]]){
				pop();
			}
			else{
				done = true;
			}
		}
		if(isEmpty()){
			h = -1;
		}
		else{
			h = stack[top];
		}
		new_arr[i] = i-h;
		push(i);
	}
	return new_arr;
}

int main(){
	cin >> n;
	stack = (int *)malloc(n*sizeof(int));
	int *arr = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int *new_arr = computeSpan(arr,n);
	for(int i=0;i<n;i++){
		cout << new_arr[i] << "\t";
	}
	cout << endl;
	return 0;
}
