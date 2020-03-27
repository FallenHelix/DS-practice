//priority queue or min heap
#include<iostream>

class minHeap
{
private:
	int *heap;
	int size;
	int capacity;
	int left(int i)
	{
		int l = 2 * i + 1;
		if (l > size-1)
			return -1;
		else
			return l;
	}
	int right(int i)
	{
		int r = 2 * i + 2;
		if (r > size-1)
		{
			return -1;
		}
		else {
			return r;
		}
	}
	int parent(int i)
	{
		return (i-1) / 2;
	}
	void swap(int src, int dest)
	{
		int temp = heap[src];
		heap[src] = heap[dest];
		heap[dest] = temp;
	}
	bool isleaf(int i)
	{
		if (i > size / 2)
			return true;
		else
			return false;
	}
public:
	minHeap(int n)
	{
		size = 0;
		capacity = n;
		heap = new int[n];
	}
	void minHeapify(int i)
	{
		//std::cout << "I is: " << i << std::endl;
		if (!isleaf(i)) {
			int l = left(i);
			int r = right(i);
			int smallest;
			if (l != -1&&heap[l] < heap[i])
			{
				smallest = l;
			}
			else
				smallest = i;
			if (r != -1&&heap[r] < heap[smallest])
			{
				smallest = r;
			}
			
			if (smallest != i)
			{
				swap(i, smallest);
				minHeapify(smallest);
			}
		}

	}
	void insert(int key)
	{
		if (size == capacity)
			return;
		else
		{
			heap[size] = key;
			size++;
			int current = size-1;
			while (heap[current] < heap[parent(current)])
			{
				swap(current, parent(current));
				current = parent(current);
			}
		}
	}
	void print()
	{
		for (int i = 0; i < size / 2; i++) {
			std::cout << " PARENT : " << heap[i];
			std::cout << " LEFT CHILD : " << heap[2 * i+1];
			std::cout<< " RIGHT CHILD :" <<heap[2 * i + 2];
			std::cout << std::endl;
		}
	}
	void toMinHeap(int *arr, int n)  //convert an array to min Heap;
	{
		//std::cout << "printing inside function\n\n";
		//print();
		for (int i=0;i<n;i++)
		{
			insert(arr[i]);
		}
	}
	int extractMin()  //extract the minimum off the heap and put the rightmost leaf in the root and then 
	{                 // perform operations ass needed      
		int poped = heap[0];
		std::cout << std::endl << heap[0] << std::endl;
		swap(0, size-1);
		size--;
		minHeapify(0);
		return poped;
	}
};

int main()
{

	
	std::cout << "The Min Heap is\n ";
		/*minHeap heap = minHeap(15);
		heap.insert(5);
		heap.insert(3);
		heap.insert(17);
		heap.insert(10);
		heap.insert(84);
		heap.insert(19);
		heap.insert(6);
		heap.insert(22);
		heap.insert(9);
		//minHeap.minHeap();
		heap.print();
		*/
		int arr[] = { 26,28,1,14,16,18,31,17,12 };
		minHeap h2 = minHeap(sizeof(arr)/sizeof(int));
		/*for (auto x : arr)
		{
			h2.insert(x);
		}*/
		h2.toMinHeap(arr, sizeof(arr)/sizeof(int));
		
		h2.print();
		std::cout << "Smallest element in the array is: " << h2.extractMin() << std::endl;
		h2.print();
		std::cin.get();
	
}