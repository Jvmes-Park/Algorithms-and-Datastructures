#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BucketSort(float A[], int size) {
	vector<float>B[size];
	for (int i = 0; i < size; i++) {
		int Bi = size * A[i];
		B[Bi].push_back(A[i]);
	}
	for (int i = 0; i < size - 1; i++)
		sort(B[i].begin(), B[i].end());
	int index = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < B[i].size(); j++) {
			A[index++] = B[i][j];
		}
	}

}

void printArray(float A[], int size) {
	for (int i = 0; i < size; i++) 
		cout << A[i]<<endl;
}

int main() {
	float A[5];
	cout<<"Enter 5 numbers:"<<endl;
	for (int i = 0; i < 5; i++)
		cin >> A[i];
	int size = sizeof(A)/sizeof(A[0]);
	BucketSort(A, size);
	cout<<"Sorted Array: "<<endl;
	printArray(A, size);
}
