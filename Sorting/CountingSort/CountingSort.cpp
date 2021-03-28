#include <iostream>
#include <algorithm>
using namespace std;

//Counting sort is a linear sort, not a comparison sort.

void CountingSort(int A[], int B[], int A_length, int max) {
	int C[max + 1];
	for (int i = 0; i <= max; i++)
		C[i] = 0;
	for (int j = 1; j <= A_length; j++)
		C[A[j]]++;
	for (int i = 1; i <= max; i++)
		C[i] += C[i - 1];
	for (int j = A_length; j >= 1; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

void printArray(int B[], int size) {
	for (int i = 1; i <= size; i++)
		cout <<B[i]<<endl;
}

int main() {
	int A[5];
	cout << "Enter 5 numbers: "<<endl;
	for (int i = 0; i < 5; i++)
		cin>>A[i];
	int A_length = sizeof(A)/sizeof(A[0]);
	int B[A_length + 1] = {};
	int max = *max_element(A, A + A_length) + 1;
	CountingSort(A, B, A_length, max);
	cout<<"Sorted Array:"<<endl;
	printArray(B, A_length);	
}
