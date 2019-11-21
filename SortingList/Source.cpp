#include<iostream>
#include"Dll.h"



int main()
{
	Dll l;
	l.insert_front(1);
	l.insert_front(2);
	l.insert_front(3);
	l.insert_front(4);
	l.insert_front(5);
	l.print();
	l.InsertionSort_value();
	std::cout << "After sorting\n";
	l.print();
	std::cin.get();

	return 0;
}