#include<iostream>
#include<array>

class maxHeap
{
public:
	int *arr;
	int count;
	int m_size;
	maxHeap(int n)
	{
		arr = new int[n];
		count = 0;
		m_size = n;
	}
	int left(int i)
	{
		int l = (2 * i) + 1;
		if (l >= m_size)
			return -1;
		else
			return l;
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int extract_min();
	int getMin() const
	{
		return arr[0];
	}
	int right(int i)
	{
		int r = (2 * i) + 2;
		if (r >= m_size)
			return -1;
		else
			return r;
	}
	void insertKey(int k);
	void print();
	void in(int n);
	void makeHeap();
	void heapify(int i);
	int extractMax()
	{
		if (count == 0)
			return -1;
		int data;
		data = arr[0];
		arr[0] = arr[count - 1];
		count--;
		heapify(0);
		print();
		return data;
	}
};

void maxHeap::print()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << arr[i] << " ";
	}
}
void maxHeap::insertKey(int k)
{
	if (count == m_size)
	{
		std::cout << "The heap is full";
		return;
	}
	count++;
	int i;
	i = count - 1;
	arr[i] = k;
	while (i != 0 && arr[parent(i)] < arr[i])
	{
		std::swap(arr[parent(i)], arr[i]);
		i = parent(i);
	}
}
void maxHeap::in(int n)
{
	count = n;
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
}

void maxHeap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l!=-1 &&arr[l] > arr[i])
		smallest = l;
	if (r!=-1 &&arr[r] > arr[smallest])
		smallest = r;
	if (smallest != i)
	{
		std::swap(arr[i], arr[smallest]);
		heapify(smallest);
	}
}

void maxHeap::makeHeap()
{
	int n = count;
	for (int k = n/2; k >= 0; k--) {
		heapify(k);
	}

}


int main()
{
	
	maxHeap a(10);
	a.in(10);
	a.makeHeap();
	std::cout << std::endl;
	a.print();
	std::cout<<std::endl;
	std::cout << "Max extracted is: " << a.extractMax();
	std::cin.get();
	return 0;
}