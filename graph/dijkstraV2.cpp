#include <iostream>
#include <queue>
#include <list>

struct Node
{
    int vertex;
    int weight;
    Node(int v, int w)
    {
        vertex = v;
        weight = w;
    }
};

class compare
{
public:
    bool operator()(Node &x, Node &y)
    {
        return x.weight > y.weight;
    }
};
class graph
{
private:
    int size;
    std::list<Node> *adj;

public:
    graph(int n)
    {
        adj = new std::list<Node>[n];
        size = n;
    }
    void insert(int src, int dest, int weight)
    {
        Node newNode = Node(dest, weight);
        //newNode.vertex=dest;
        //newNode.weight=weight;
        adj[src].push_back(newNode);
    }
    void diijsktras(int);
};

void graph::diijsktras(int src)
{
    std::priority_queue<Node, std::vector<Node>, compare> q;
    bool *visited = new bool[this->size];
    int *parent = new int
    [this->size];
    int *distance = new int[this->size];

    for (int i = 0; i < size; i++)
    {
        parent[i] = -1;
        visited[i] = false;
        distance[i] = 100000000;
    }
    q.push(Node(src, 0));
    distance[src] = 0;
    while (!q.empty())
    {
        auto temp = q.top();
        // std::cout << "temp: " << temp.vertex << "temp distance: " << temp.weight << std::endl;
        q.pop();
        visited[temp.vertex] = true;
        for (Node x : adj[temp.vertex])
        {
            // std::cout << "vertex: " << x.vertex << " distance: " << x.weight << std::endl;
            if (!visited[x.vertex])
            {
                // std::cout<<"distance to parent: "<<distance[temp.vertex]<<std::endl;
                q.push(x);
                if (distance[x.vertex] > distance[temp.vertex] + x.weight)
                {
                    // std::cout << "Inside if condition\n";

                    distance[x.vertex] = distance[temp.vertex] + x.weight;
                    parent[x.vertex] = temp.vertex;
                }
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        std::cout <<"Vertex: "<<i << " parent: " << parent[i] << " Distance: " << distance[i];
        std::cout << std::endl;
    }
}

int main()
{

    // std::cout << "Program starting \n";
    graph g = graph(11);
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
    g.diijsktras(1);

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
    // g.diijsktras(0);
    return 0;
}
