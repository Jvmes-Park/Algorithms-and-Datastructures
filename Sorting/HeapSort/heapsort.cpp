#include <iostream>
using namespace std;

//On average constant time
//Worst case is when the bottom level of the tree is half full.
// O(h) where h = height.
void maxHeapify(int arr[], int size, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < size && arr[l] > arr[largest]) 
		largest = l;
	if (r < size && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, size, largest);
	}
}

//Build Max Heap makes O(n) calls
//Overall running time is O(n) 
void buildMaxHeap(int arr[], int size) {
	for (int i = size/2 - 1; i >= 0; i--)
		maxHeapify(arr, size, i); //Each call to Max Heapify is O(lg n)
}

//Running time = O(n lg n)
void heapSort(int arr[], int size) {
	buildMaxHeap(arr, size); //O(n)
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0); //O(lg n)
	}
}

//Iteration is O(n)
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout <<arr[i]<<endl;
	}
}

int main() {
	int arr[5];
	cout<<"Enter 5 numbers:"<<endl;
	for (int i = 0; i < 5; i++) 
		cin >> arr[i];
	int size = sizeof(arr)/sizeof(arr[0]);
	heapSort(arr, size);
	cout<<"Sorted Array:"<<endl;
	printArray(arr, size);
}















































