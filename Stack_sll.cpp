#include<iostream>


template<typename object>

class stack
{
protected:
	struct node
	{
		object key;
		node* next;
		node(object& e, node* n = nullptr) :key(e), next(n) {}
	};
private:
    int	size;
	node * head;
public:
	stack()
	{
		head= nullptr;
		size = 0;
	}
	bool push(object n)
	{
		node* newptr = new node(n, head);
		if (!newptr)
			return 0;
		
			head = newptr;
			size++;
		
		return 1;
	}
	object pop()
	{
		if (size == 0)
		{
			throw 0;
		}
			object d = head->key;
			node* temp = head;
			head= head->next;
			delete temp;
			size--;
			return d;
	}
	bool isempty() const
	{
		return size == 0;
	}

	object top()
	{
		if (isempty())
			throw - 1;
		else
		{
			return head->key;
		}
	}
};

int main()
{
	stack<int> s;
	int n;
	do
	{
		std::cout << "\n1.Push \t 2. Pop \t 3. Display element at top\n 4. Check if the stack is empty\n5. Exit program  ==>";
		std::cin >> n;
		switch (n)
		{
		case 1:
			std::cout << "\nEnter an Element: ";
			std::cin >> n;
			s.push(n);
			break;
		case 2:
			try
			{
				auto x = s.pop();
			std::cout << "\nElement Poped is : " << x << std::endl;
			}
			catch (...)
			{
				std::cout << "\n\nThe Stack is empty!!" << "\n\n";

			}
			break;
		case 3:
			try
			{
				auto a = s.top();
			std::cout << "\n\nElement at top is : " << s.top() << "\n\n";
			}
			catch (...)
			{
				std::cout << "\n\nException Found Stack Empty!!" << "\n\n\n";
			}
			break;
		case 4:
			if (s.isempty())
				std::cout << "The stack is empty\n\n ";
			else
				std::cout << "The stack is not empty!" << "\n\n";
			break;
		default:
			break;
		}
	} while (n != 5);
	return 0;
}