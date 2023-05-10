#include <iostream>
using namespace std;

void swapi(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionind (int arr[], int left, int right)
    {
       // Your code here
        int pivot = arr[right];
        int i = left-1;

        for(int j = left;j<=right-1;j++){
            if(arr[j]<pivot){
                i++;
                swapi(&arr[i],&arr[j]);
            }
        }

        swapi(&arr[i+1],&arr[right]);

        return (i+1);
    }

void quicksort(int arr[],int left,int right){
    if(left<right){
        int p = partitionind(arr,left,right);
        quicksort(arr,left,p-1);
        quicksort(arr,p+1,right);
    }
}

void artrav(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr)/sizeof(arr[0]);

	artrav(arr,n);
	quicksort(arr,0,n-1);
	artrav(arr,n);
	return 0;
}
