#include<iostream>
#include<stack>
#include<queue>

struct node
{
	int key;
	node*left, *right;
	node(int i, node*l=nullptr, node*r=nullptr) :key(i), left(l), right(r)  {};

};

void preorder(node* root)
{
	if (!root)
		return;
	std::cout << root->key << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root)
{
	if (!root)
		return;
	inorder(root->left);
	std::cout << root->key << " ";
	inorder(root->right);
}

void preorder_nonrecursive(node*root)
{
	std::stack<node*> s;
	while (1)
	{
		while (root)
		{
			std::cout << root->key << " ";
			s.push(root);
			root=root->left;
		}
		if (s.empty())
			return;

		root = s.top();
		s.pop();
		root = root->right;
	}
}

void inoder_nonrecursive(node* root)
{
	std::stack<node*> s;
	while (1)
	{
		while (root)
		{
			s.push(root);
			root=root->left;
		}
		if (s.empty())
			return;
		root= s.top();
		s.pop();
		std::cout << root->key << " ";
		root = root->right;
	}
}
void postorder(node* root)
{
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	std::cout << root->key << " ";
}

void postorder_nonrecursive(node*root)
{
	node * prev=nullptr;
	std::stack<node*> s;
	while (1)
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
		if (s.empty())
			return;
		root = s.top();
		if (root->right == nullptr || root->right == prev)
		{
			std::cout << root->key << " ";
			prev = root;
			s.pop();
			root = nullptr;
		}
		else {
			root = root->right;
		}
	}
}

void levelorder(node* root)
{
	std::queue<node*>q;
	q.push(root);
	while (!q.empty())
	{
		root = q.front();
		std::cout << root->key << " ";
		q.pop();
		if(root->left)
			q.push(root->left);
		if (root->right)
			q.push(root->right);

	}
}

int main() {
	node *root = new node(1);
	root->left = new node(2);
	root->right= new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->left->right->left = new node(8);
	root->left->right->right = new node(9);
	preorder(root);
	std::cout << std::endl;
	preorder_nonrecursive(root);
	
	std::cout << "Inorder printing of tree";
	inorder(root);
	std::cout << "\nRecursion :";
	inoder_nonrecursive(root);
	std::cout << "\nPorst order traversal: ";
	postorder(root);
	std::cout << "\nPostorder usin stack: ";
	postorder_nonrecursive(root);
	std::cout << "\nlevelorder Traversal: ";
	levelorder(root);
	std::cin.get();

}