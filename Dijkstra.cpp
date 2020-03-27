//Dijkstra algorithm using heap(min heap)
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>

#define _CRT_INT_MAX 10000
class graph 
{
protected:
	struct node
	{
		int dst;
		int weight;
	};


private:
	std::list<node> *adj;
	int size;
public:
	graph(int n)
	{
		size = n;
		adj = new std::list<node>[n];
	}
	void insert(int src, int dst, int cost)
	{
		node newnode;
		newnode.dst = dst;
		newnode.weight = cost;
		adj[src].push_front(newnode);
	}
	void BFS(int);
	void dij(int);
};
/*void graph::dij(int head)
{
	int *path = new int[this->size];
	int *dist = new int[this->size];
	for (int i=0;i<this->size;i++)
	{
		dist[i] = _CRT_INT_MAX;
		path[i] = -1;
	}
	std::queue<int> q;
	dist[head] = 0;
	path[head] = head;
	q.push(head);
	int temp;
	while (!q.empty())
	{
		std::list<node>::iterator i;
		temp = q.front();
		q.pop();
		for (i = adj[temp].begin(); i != adj[temp].end(); i++)
		{
			if ((*i).weight+dist[temp] < dist[(*i).dst])
			{
				dist[(*i).dst] = (*i).weight+dist[temp];
				path[(*i).dst] = temp;
				q.push(i->dst);
			}
		}
	}
	for (int i = 0; i < this->size; i++)
	{
		if(path[i]!=-1)
		std::cout << i << " "<<dist[i] << std::endl;
	}
	for (int i = 0; i < this->size; i++)
	{
		if (path[i] != -1)
			std::cout << "To reach "<<i<<"use "<<path[i] << std::endl;
	}
}*/

void graph::BFS(int head)
{
		bool *visited = new bool[this->size];
		for(int i=0;i<this->size;i++)
		{
			visited[i] = false;
		}
		std::queue<int> q;
		q.push(head);
		int temp;
		while (!q.empty())
		{
			temp = q.front();
			q.pop();
			std::cout << temp << " ";
			std::list<node> ::iterator i;
			for (i = adj[temp].begin(); i != adj[temp].end(); i++)
			{
				if (visited[(*i).dst] == false)
				{
					q.push((*i).dst);
					visited[(*i).dst] = true;
				}
			}
	}
}

	struct Hnode
{
	int key;
	int distance;
};

class minHeap
{

private:
	Hnode *heap;
	int size;
	int  capacity;
	int leftChild(int i) const
	{
		int l = 2 * i + 1;
		if (l > size-1)
			return -1;
		else
			return l;
	}
	int rightChild(int i) const
	{
		int r = 2 * i + 2;
		if (r > size - 1)
			return -1;
		else
			return r;
	}
	int parent(int i) const
	{
		return (i - 1) / 2;
	}
	bool isleaf(int i)
	{
		if (i > size / 2)
			return true;
		else
			return false;
	}
	void swap(int src, int dst)
	{
		Hnode temp;
		temp = heap[src];
		heap[src] = heap[dst];
		heap[dst] = temp;
	}
public:
	int *pos;
	minHeap(int n)
	{
		size = 0;
		capacity = n;
		heap = new Hnode[n];
		pos = new int [n];
	}
	void minHeapify(int i)
	{
		if (!isleaf(i)) {
			int l = leftChild(i);
			int r = rightChild(i);
			int smallest;
	
			if (l != -1 && heap[l].distance < heap[i].distance)
			{
				smallest = l;
			}
			else
				smallest = i;
			if (r != -1 && heap[r].distance < heap[smallest].distance)
			{
				smallest = r;
			}

			if (smallest != i)//swap smallest and i;
			{
				pos[heap[smallest].key] = i;
				pos[heap[i].key] = smallest;
				swap(i, smallest);
				minHeapify(smallest);
			}
		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << heap[i].key << " " << heap[i].distance << std::endl;
		}
	}
	void insertHeap(int dst, int cost)
	{

		if (size == capacity)
			return;
		Hnode newnode;
		newnode.distance = cost;
		newnode.key = dst;
		heap[size] = newnode;
		pos[dst] = size;
		size++;
		int current = size - 1;
		while (heap[current].distance < heap[parent(dst)].distance)
		{
			int temp;
			temp = current;
			pos[temp] = parent(current);
			current = parent(current);
			swap(current, dst);
			current = parent(current);
		}
	}
	Hnode extractMin()  //extract the minimum off the heap and put the rightmost leaf in the root and then 
	{                 // perform operations ass needed      
		Hnode poped= heap[0];
		
		//std::cout << std::endl << <<poped.key << std::endl;
		swap(0, size - 1);
		size--;
		minHeapify(0);
		return poped;
	}
	bool isempty() const
	{
		return size == 0;
	}
	void decreaseKey(int v, int dst)
	{
		int i = pos[v];           //get index of the node
		heap[i].distance = dst;   //set the new distance;
		int p= parent(i);
		while (heap[i].distance < heap[p].distance)  //correct the heap and the position array;
		{
			pos[heap[i].key] = p;
			pos[heap[p].key] = i;
			swap(i, p);
			i = p;
			p = parent(i);
		}
	}
	bool isInMinHeap(int v)
	{
		
		if (pos[v] < size+1)
		{
			return true;

		}
		return false;
	}
};


void graph::dij(int src)
{
	bool *visited = new bool[this->size];
	int *path = new int[this->size];
	int *dist = new int[this->size];
	minHeap h = minHeap(this->size);
	for (int i = 0; i < this->size; i++)
	{
		path[i] = -1;
		dist[i] = _CRT_INT_MAX;
		h.insertHeap(i, _CRT_INT_MAX);
		h.pos[i] = i;
	}
	dist[src] = 0;
	h.decreaseKey(src, dist[src]);
	while (!h.isempty())
	{
		//std::cout << "\n\nNew LOOP\n\n";
		//h.print();
		Hnode curr = h.extractMin();
		//std::cout << "\n\nStandings after extract  min function\n\n";
		//h.print();
		int u = curr.key;
		std::list<node>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); i++)
		{
			int v = i->dst;
			if (h.isInMinHeap(v) && dist[u] != _CRT_INT_MAX && i->weight + dist[u] < dist[v])
			{
				path[v] = u;
				dist[v] = i->weight + dist[u];
				h.decreaseKey(v, dist[v]);
			}

		}

	}
	// for (int i = 0; i < this->size; i++)
	// {
	// 	if (path[i] != -1)
	// 		std::cout<<"NODE: " << i << " Shortest Distance: " << dist[i] << std::endl;
	// }
	// for (int i = 0; i < this->size; i++)
	// {
	// 	if (path[i] != -1)
	// 		std::cout << "To reach  " << i << " use  " << path[i] << std::endl;
	// }
	for (int i = 0; i < size; i++)
    {
        std::cout <<"Vertex: "<<i << " parent: " << path[i] << " Distance: " << dist[i];
        std::cout << std::endl;
    }
}


int main()
{
	
	graph g = graph(11);

	// g.insert(0, 6, 4);
	// g.insert(0, 2, 3);
	// g.insert(2, 3,2);
	// g.insert(3, 7, 2);
	// g.insert(7, 0, 1);
	// g.insert(0, 7, 1);

	// g.insert(6, 7, 10);
	// g.insert(6, 1, 1);
	// g.insert(6, 4, 4);
	// g.insert(1, 5, 8);
	// g.insert(5, 4, 2);
	// g.insert(4, 5, 1);
	// g.insert(4, 2, 6);
	// g.dij(0);

	 g.insert(1, 2, 2);

    g.insert(1, 3, 5);
    g.insert(2, 3, 4);
    g.insert(2, 4, 3);
    g.insert(3, 5, 7);
    g.insert(4, 5, 6);
    g.insert(4, 6, 2);
    g.insert(5, 6, 5);
    g.insert(5, 7, 8);
    g.insert(6, 7, 9);
    g.insert(6, 8, 10);
    g.insert(7, 8, 5);
    std::cout<<"Dij: \n";
    g.dij(1);
	std::cin.get();
}
