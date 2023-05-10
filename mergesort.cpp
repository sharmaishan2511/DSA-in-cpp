#include <iostream>
using namespace std;

void merge(int array[], int left, int mid,int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;


	int* leftArray = new int[n1];
	int* rightArray = new int[n2];

	for (int i = 0; i < n1; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < n2; j++)
		rightArray[j] = array[mid + 1 + j];

	int i= 0;
	int	j= 0;
	int k= left;

	while (i < n1
		&& j < n2) {
		if (leftArray[i]
			<= rightArray[j]) {
			array[k]
				= leftArray[i];
			i++;
		}
		else {
			array[k]
				= rightArray[j];
			j++;
		}
		k++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (i < n1) {
		array[k]
			= leftArray[i];
		i++;
		k++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (j < n2) {
		array[k]
			= rightArray[j];
		j++;
		k++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int begin, int end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}


void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";

    cout<<endl;
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printArray(arr, arr_size);
	return 0;
}
