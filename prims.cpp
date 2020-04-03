#include<iostream>
#include<vector>
#include<queue>
#include<list>
struct Node
{
	int dest;
	int weight;
	Node(int a,int b)
	{
		dest=a;
		weight=b;
	}
};
class compare
{
	public:
	bool operator()(Node &x,Node &y)
	{
		return x.weight>y.weight;
	}
};


class graph
{
	private:
	std::list<Node> *adj;
	int size;
	public:
	graph(int s)
	{
		this->size=s;
		adj=new std::list<Node>[size];
	}
	
	void insert(int src, int dst, int cost)
	{
		Node newnode=Node(0,0);
		newnode.dest = dst;
		newnode.weight = cost;
		adj[src].push_front(newnode);
		Node newNode2=Node(0,0);
		newNode2.dest=src;
		newNode2.weight=cost;
		adj[dst].push_front(newNode2);
	}
	
	int getSize() const
	{
		return size;
	}
	
	void createPrims()
	{
		std::priority_queue<Node, std::vector<Node>,compare> q;
		bool *visited= new bool[size];
		int *parent=new int[size];
		int *distance=new int[size];
		for(int i=0;i<size;i++)
		{
			visited[i]=false;
			parent[i]=-1;
			distance[i]=100000;
		}
		
		distance[1]=0;
		parent[1]=1;
		q.push(Node(1,0));
		while(!q.empty())
		{
			Node temp=q.top();
			//std::cout<<temp.dest<<" adfad "<<temp.weight<<std::endl;
			q.pop();
			visited[temp.dest]=true;
			for(auto x: adj[temp.dest])
			{
				std::cout<<x.dest<<" weight: "<<x.weight<<std::endl;
				if(!visited[x.dest])
				{
					if(distance[x.dest]>x.weight)
					{
					q.push(x);
					distance[x.dest]=x.weight;
					parent[x.dest]=temp.dest;
				}
				}
			}
		}
		 for (int i = 0; i < size; ++i) 
        std::cout<<"i: "<<i<<" Parent "<<parent[i]<<" distace "<<distance[i]<<std::endl;
			
		 //for (int i = 0; i < size; ++i) 
        //std::cout<<"i: "<<i<<" distace "<<distance[i]<<std::endl;
        delete[] visited;
        delete [] parent;
        delete [] distance;
	
}
	void print()
    {
      using namespace std;
      for (int v = 0; v < size; ++v) 
    { 
        cout << "\nAdjacency list of vertex "
             << v << "\n"; 
        for (auto x : adj[v])
        {
           std::cout<<"Dest: "<<x.dest<<" Cost "<<x.weight;
           std::cout<<std::endl;
        } 
        std::cout<<std::endl<<" ";
    } 
}
};

int main()
{
std::cout<<"hello world\n";
graph g= graph(10);
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
    g.insert(7,8,5);
    g.print();
    std::cout<<"\nPrims Algorithm: \n";
    g.createPrims();
    
    return 0;
}
