#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int * computeSpans(int *arr, int n){
	int *new_arr = (int *)malloc(n*sizeof(int));
	int c;
	for(int i=0;i<n;i++){
	        c = 1;
		for(int j=i-1;j>=0;j--){
			if(arr[j] <= arr[i]){
				c++;
			}
			else break;
		}
		new_arr[i] = c;
	}
	return new_arr;
}

int main(){
	int n;
	cin >> n;
	int *arr=  (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin >> *(arr+i);
	}
	int *new_arr = computeSpans(arr,n);
	for(int i=0;i<n;i++){
		cout << *(new_arr+i) << "\t";
	}
	cout << endl;
	return 0;
}
