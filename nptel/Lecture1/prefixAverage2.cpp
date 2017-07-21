#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

float * prefixAverage(int *arr, int n){
	float *new_arr = (float *)malloc(n*sizeof(float));
	int t = 0;	
	for(int i=0;i<n;i++){
		t = t + *(arr+i);
		*(new_arr+i) = (float)t/(i+1);
	}
	return new_arr;
}

int main(){
	int n;
	cin >> n;
	int *arr = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin >> *(arr+i);
	}
	float * new_arr = prefixAverage(arr,n);
	for(int i=0;i<n;i++){
		cout << *(new_arr+i) << "\t";
	}
	cout << endl;
	return 0;
}
