#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

float *prefixAverage(int *arr, int n){
	float *new_arr = (float *)malloc(n*sizeof(float));	
	for(int i=0;i<n;i++){
		int t=0;
		for(int j=0;j<=i;j++){
			t = t + *(arr+j);
		}
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
	float *new_arr = prefixAverage(arr,n),x;
	for(int i=0;i<n;i++){
		x = *(new_arr+i); 
		cout << x << "\t";
	}
	cout << endl;
	return 0;
}
