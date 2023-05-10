#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

class MinHeap
{
public:
	int *harr;
	int capacity;
	int heap_size;

	MinHeap(int capacity);
	void MinHeapify(int );
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }
	void deletion();
	void insertion(int k);
};

MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insertion(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] > harr[i])
	{
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
	}
}

void MinHeap::deletion()
{
    swap(&harr[0],&harr[heap_size-1]);
    heap_size--;
    MinHeapify(0);
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

MinHeap Buildheap(MinHeap h,int A[],int n){
    for(int i = 0;i<n;i++){
        h.insertion(A[i]);
    }
    return h;
}

int main()
{
	int n = 7;
	int arr[n] = {31,20,11,5,9,13,7};

	MinHeap hp(n);
	MinHeap h= Buildheap(hp,arr,7);

	for(int i = 0;i<h.heap_size;i++){
        cout<<h.harr[i]<<" ";
	}
    cout<<endl;

    h.deletion();


    for(int i = 0;i<h.heap_size;i++){
        cout<<h.harr[i]<<" ";
	}
	return 0;
}
