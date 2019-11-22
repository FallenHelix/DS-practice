#include<iostream>
#include"Dll.h"



int main()
{
	Dll l;
	l.insert_front(100);
	l.insert_front(2);
	l.insert_front(3);
	l.insert_front(-1);

	l.insert_front(4);
	l.insert_front(5);
	l.insert_front(1);

	l.print();
	l.InsertionSort_value();
	std::cout << "After sorting\n";

	l.print();
	std::cout << "\n\n\n\n\n\n\n";
	Dll h;
	h.insert_front(55);
	h.insert_front(70);
	h.insert_front(25);
	h.insert_front(10);
	h.insert_front(21);
	h.insert_front(30);
	h.insert_front(9);
	h.insert_front(14);
	h.insert_front(62);
	h.insert_front(77 );

	h.print();
	h.ShellSort_value();
	std::cout << "After Shell sort:  \n";
	h.print();

	std::cin.get();

	return 0;
}