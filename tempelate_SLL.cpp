#include<iostream>


template<typename object>

class sll
{
protected:
	struct node
	{
		object key;
		node* next;
		node(object& e, node* n = nullptr) :key(e), next(n) {}
	};
private:
	node * head;
	node* tail;
public:
	int size;
	sll()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	int insert_begin(object n)
	{
		node * newptr = new node(n, head);

		if (head == nullptr)
		{
			head = newptr;
			tail = newptr;
			size++;
			return 0;
		}
		head = newptr;
		size++;
		return 0;

	}
	int insert_after(object e, int n);
	int delete_end();
	void display_list();
};

template<typename object>
void sll<object>::display_list()
{
	if (head == nullptr)
	{
		std::cout << "the list is empty !!";
		return;
	}
	node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template<typename object>
int sll<object>::insert_after(object e, int n)
{
	node* temp = head;
	bool f = false;

	while (temp != nullptr)
	{
		if (temp->data == n)
		{
			f = true;
			break;
		}
		temp = temp->next;
	}
	if (f) {

		node* newptr = new node(e);
		newptr->next = temp->next;
		temp->next = newptr;
		size++;
		return 1;
	}
	return 0;
}

template<typename object>
int sll<object>::delete_end()
{
	node*prev = nullptr;;
	node* temp = head;
	while (temp->next != nullptr)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = nullptr;
	delete temp;
	size--;
	return 0;
}

int main()
{
	std::cout << "Enter the number of list: ";
	int m, i;
	std::cin >> m;
	sll<int> *s = new sll<int>[m - 1];
	char ans;
	int choice, element;
	do
	{
		std::cout << "Enter an option to proceed: 1: Insert_begin 2: Insert_End\n3:display List 4:Delete_End : ";
		std::cin >> choice;
		std::cout << "which list to enter data?(1-" << m << "): ";
		std::cin >> i;
		if (i > m)
			std::cout << "wrong option!!";
		break;
		switch (choice)
		{
		case 1:
			std::cout << "Enter an Element: ";
			std::cin >> element;
			s[i - 1].insert_begin(element);
			break;
		case 2:
		{
			std::cout << "Enter an Element: ";
			std::cin >> element;
			int pos;
			std::cout << "Enter the element after which insertion is to be done: ";
			std::cin >> pos;
			if (!s[i - 1].insert_after(element, pos))
				std::cout << "The Element does not exist !!! no Insertion done!" << std::endl;
		}
		break;
		case 3:
			s[i - 1].display_list();
			break;
		case 4:
			s[i - 1].delete_end();
			s[i - 1].display_list();
			break;
		default:
			std::cout << "Wrong choice!!!\n";
		}
		std::cout << "Do you want to continue: ";
		std::cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	/*s.insert_begin(3);
	s.insert_begin(2);
	s.insert_begin(1);
	s.insert_after(4, 1);
	s.insert_after(5, 3);

	s.insert_after(7, 10);
	s.display_list();
	s.delete_end();
	s.display_list();*/
	std::cin.get();
	return 0;
}
