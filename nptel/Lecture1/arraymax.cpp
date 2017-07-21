#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int arrayMax(int *arr, int n){
	int arrmax;
	arrmax = *(arr+0);
	for(int i=1;i<n;i++){
		if(*(arr+i) > arrmax){
			arrmax = *(arr+i);
		}
	}
	return arrmax;
}
int main(){
	int n;
	cin >> n;
	int *arr = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin >> *(arr+i);
	}
	int arrmax = arrayMax(arr,n);
	cout << arrmax << endl;
	return 0;
}
