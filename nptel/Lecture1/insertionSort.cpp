#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void insertionSort(int *arr,int n){
	int temp,j;
	for(int i=1;i<n;i++){
		temp = *(arr+i);
		j = i-1;
		while(j>=0 && arr[j]>temp){
			*(arr+(j+1)) = *(arr+j);
			j--;
		}
		*(arr+(j+1)) = temp; // when it exits it will be arr[j] <= temp so arr[j+1] = temp
	}
	return ;
}
int main(){
	int n;
	cin >> n;
	int *arr = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin >> *(arr+i);
	}
	insertionSort(arr,n);
	for(int i=0;i<n;i++){
		cout << *(arr+i) << "\t";
	}
	cout << endl;
	return 0;
}
