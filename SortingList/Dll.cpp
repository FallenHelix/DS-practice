#include "Dll.h"
#include<iostream>

Dll::Dll()
{
	tail=head = nullptr;
	size = 0;
}

void Dll::swap(node*l, node*r)
{
	node *tempR, *tempL;
	tempL = l->prev;
	tempR = l->next;
	l->next = r->next;
	l->prev = r->prev;
	r->prev->next = l;
	r->next->prev = l;
	r->next = tempR;
	r->prev = tempL;
	tempR->prev = r;
	tempL->next = r;
}

void Dll :: insert_front(int k)
{
	size++;
	node* newNode = new node(k, head, nullptr);
	if (head != nullptr)
	{
		head->prev = newNode;
		head = newNode;
		return;
	}
	tail = newNode;
	head = newNode;
}

void Dll::printR()
{
	auto x = tail;
	while (x!=nullptr)
	{
		std::cout << x->key << " ";
		x = x->prev;
	}
}
void Dll::print()
{
	auto x = head;
	while (x != nullptr)
	{
		std::cout << x->key << " ";
		x = x->next;
	}
}
Dll::node::node(int n):key(n), next(nullptr), prev(nullptr)
{

}

Dll::node::node(int k, node * n, node * p):key(k),next(n),prev(p)
{
}

void Dll::ty()
{
	auto x = head->next;
	auto y = head->next->next->next;
	std::cout << std::endl;
	std::cout << x->key<< " " << y->key;
	std::cout << std::endl;

	swap(x, y);
	printR();
}


void Dll::ShellSort_value()
{
	if (size == 1 || size == 0)
		return;
	for (int i = size / 2; i > 0; i = i / 2)
	{
		auto temp = nextR(head, i);
		std::cout << "\ni: " << i<< std::endl;
		while (temp)
	    {
			int key = temp->key;
			node*temp2 = prevR(temp, i);
			int k = temp2->key;
			while (temp2 != nullptr && k > key)
			{
				nextR(temp2,i)->key = k;
				
				if (!prevR(temp2,i))
					break;
				temp2 = prevR(temp2,i);
				k = temp2->key;
			}
			if (temp2->key > key)
				temp2->key = key;
			else
				nextR(temp2,i)->key = key;
			temp = nextR(temp);
	    }
			std::cout << "\n\n";
			print();
	}
}

void Dll::InsertionSort_value()
{
	if (size == 1 || size == 0)
		return;
	auto temp = head->next;
	while (temp)
	{
		int key = temp->key;//current key
		node* temp2 = prevR(temp);//temp key to check every time
		int k = temp2->key;  //key for previous node
		while (temp2!=nullptr&& k > key)   //swap make 
		{
			nextR(temp2)->key = k ;    //copy key from behind to front 
			if (temp2->prev==nullptr)
				break;
			temp2 = prevR(temp2);
			k = temp2->key;
		}
		//if (temp2->prev == nullptr)
			//temp2->key = key;
		if (temp2->key > key)
			temp2->key = key;
		else
			nextR(temp2)->key = key;
		temp = nextR(temp);
		std::cout << "\n\n";
		print();
	}
}

Dll::node* Dll::nextR(node * n,int k)
{
	if (k == 0)
		return n;
	if (n == nullptr)
		return nullptr;
	else
		return nextR(n->next, --k);
}

Dll::node * Dll::prevR(node * n, int k)
{
	if (k == 0)
		return n;
	else if (n == nullptr)
		return n;
	else
		return prevR(n->prev, --k);
}
