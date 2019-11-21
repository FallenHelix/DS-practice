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

void Dll::InsertionSort_value()
{
	if (size == 1 || size == 0)
		return;
	auto temp = head->next;
	int i = 1;
	while (i < size)
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
		if (temp2->prev == nullptr)
			temp2->key = key;
		else
			nextR(temp2)->key = key;
		i++;
		temp = nextR(temp);
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
