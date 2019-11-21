#pragma once
class Dll
{
protected:
public:

	struct node
	{
		node*next, *prev;
		int key;
		node(int ) ;
		node(int , node*, node*);
	};
	Dll();
	static void swap(node*l,node * r);
	void insert_front(int k);
	void print();
	void printR();
	void ty();
	void InsertionSort_value();
	node* nextR(node *n, int k = 1);
	
	node* prevR(node*n, int k=1);
	//void delete_end();
	//void delete_beg();
	//void insert_end();
	node*head, *tail;

private:
	int size;

};
