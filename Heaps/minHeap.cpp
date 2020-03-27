#include<iostream>
#include<array>
#include<vector>

class minHeap
{
private:
	
	std::vector<int> arr;
	int capacity;
public:
	minHeap(int n)
	{
		arr.resize(n);
		capacity = n;
	}
	int extract_min()
	{
		int data = arr.at(0);
		arr.at(0) = arr.at(capacity - 1);
		capacity--;
		min_heapify(0);
		return data;
	}

	int left(int i)
	{
		int l = (2 * i )+ 1;
		if (l >= capacity)
			return -1;
		else return l;
	}


	int right(int i)
	{
		int r = (2 * i) + 2;
		if (r >=capacity)
			return -1;
		else return r;
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}
	 void heapSort();
	void input();

	void print();
	void convt_heap();
	void min_heapify(int i);
	void decreaseKey(int i, int j);
};


void minHeap::decreaseKey(int pos, int key)
{
	arr.at(pos) = key;
	//convt_heap();
	std::cout << "\nparent: " << parent(pos);
	min_heapify(parent(pos));
}
	void minHeap::input()
	{
		int n = capacity;
		for (int i = 0; i < n; i++)
		{
			arr.at(i)=(7-i);
		}
		
	}

void minHeap::convt_heap()
{
	for (int j =capacity/2; j >= 0; j--)
		min_heapify(j);

}
void minHeap::min_heapify(int i)
{
	int r = right(i);
	int l = left(i);
	int smallest;
	if (l != -1 && arr[l] < arr[i])
		smallest = l;
	else
	{
		smallest = i;
	}
	if (r != -1 && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i)
	{
		std::swap(arr[smallest], arr[i]);
		min_heapify(smallest);
	}
}

void minHeap::heapSort()
{
	  
}
void minHeap::print()
{
	while(capacity>0)
	{
		std::cout << extract_min()<< " ";

	}
}


int main()
{
	minHeap h(7);
	h.input();
	
	std::cout << "print";
	h.convt_heap();
	h.print();
	h.heapSort();
	std::cin.get();
	return 0;
}