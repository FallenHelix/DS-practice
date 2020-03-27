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
		std::cout << "Constructor called";
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
	void makeHeap()
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


void maxHeap::makeHeap()
{
	int i = count / 2;
	while (i != 1)
	{
		
	}

}
	int main()
	{
		maxHeap h(8);
		h.insertKey(3);
		h.insertKey(2);
		//h.deleteKey(1);
		h.insertKey(15);
		h.insertKey(5);
		h.insertKey(4);
		h.insertKey(45);
		h.insertKey(1);
		std::cout << "print";
		maxHeap a(6);
		a.in(6);
		a.makeHeap();
		h.print();
		std::cin.get();
		//std::cout << h.extractMin() << " ";
		//cout << h.getMin() << " ";
		//h.decreaseKey(2, 1);
		//cout << h.getMin();
		return 0;
	}