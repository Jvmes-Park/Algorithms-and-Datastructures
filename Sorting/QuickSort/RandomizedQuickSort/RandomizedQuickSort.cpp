#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//O(n)
int Partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i + 1;
}

//Make swap before partition with random index
int RandomizedPartition(int arr[], int low, int high) {
	srand(time(NULL));
	int i = low + rand() % (high - low);
	swap(arr[i], arr[high]);
	return Partition(arr, low, high);
}

//theta(n lg n), O(n^2)
void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int q = RandomizedPartition(arr, low, high);
		QuickSort(arr, low, q - 1);
		QuickSort(arr, q + 1, high);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout <<arr[i]<<endl;
}

int main() {
	cout<<"Enter 5 numbers:"<<endl;
	int arr[5];
	for (int i = 0; i < 5; i++) {
		cin>>arr[i];
	}
	int size = sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr, 0, size - 1);
	cout<<"Sorted:"<<endl;
	printArray(arr, size);
}
