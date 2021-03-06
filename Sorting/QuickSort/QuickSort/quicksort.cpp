#include <iostream>
using namespace std;

//Running time: theta(n)
//Values less than the pivot are placed to the left
//Values greater than the pivot are placed to the right

int Partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

//Worst case scenario is when one side of the tree is larger than the other. ie unbalanced. 
//Worst case running time: O(n^2)
//However, the expected running time is O(n lg n)
//This can be more easily achieved with randomized quick sort

void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int q = Partition(arr, low, high);
		QuickSort(arr, low, q - 1);
		QuickSort(arr, q + 1, high);
	}
}

//O(n)
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout<<arr[i]<<endl;
}

int main() {
	cout<<"Enter 5 numbers: "<<endl;
	int arr[5];
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	int size = sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr, 0, size - 1);
	cout <<"Sorted:"<<endl;
	printArray(arr, size);
}
