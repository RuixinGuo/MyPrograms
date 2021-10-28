#include <iostream>

using namespace std;

/*typedef struct node
{
	int v;
	struct node *left = NULL;
	struct node *right = NULL;
}Node;*/  // Define Node as a struct.

class Node
{
public:
	Node()
	{
		left = NULL;
		right = NULL;
	}

	Node *left;
	Node *right;
	int v;
};  // Define Node as a class.

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &);
	void Insert(const int);
	void InOrderPrint();
	void bst_remove(const int); //Remove a node from BST. This function is a little bit more complex than the others.
	Node* bst_max(Node *);
private:
	Node *root;
};

void assign(Node *n, const int val)
{
	if(val <= n->v)
	{
		if(n->left == NULL)
		{
			n->left = new Node;
			n->left->v = val;
		}
		else assign(n->left, val);
	}
	else
	{
		if(n->right == NULL)
		{
			n->right = new Node;
			n->right->v = val;
		}
		else assign(n->right, val);
	}
}

void destroy(Node *n)
{
	if(n != NULL)
	{
		destroy(n->left);
		destroy(n->right);
		delete n;
	}
}

Node* copy(Node *n)
{
	if(n != NULL)
	{
		Node *t = new Node;
		t->v = n->v;
		t->left = copy(n->left);
		t->right = copy(n->right);
		return t;
	}
	else return NULL;
}

void print(Node *t)
{
	if(t != NULL)
	{
		print(t->left);
		cout << t->v << endl;
		print(t->right);
	}
}

Node* search(Node *n, const int val)
{
	if(n->v == val) return n;
	else if(n == NULL) return NULL;
	else
	{
/*		Node *t1 = search(n->left);
		Node *t2 = search(n->right);
		if(t1 != NULL) return t1;
		else if(t2 != NULL) return t2;
		else return NULL;*/ // O(n) solution
		if(n->v >= val) return search(n->left, val);
		else return search(n->right, val); //O(log n) solution
	}
}

Node* parent(Node *n, const int val)
{
	if((n->left != NULL && n->left->v == val) || (n->right != NULL && n->right->v == val)) return n;
	else if(n == NULL) return NULL;
	else
    {
/*      Node *t1 = parent(n->left);
        Node *t2 = parent(n->right);
        if(t1 != NULL) return t1;
        else if(t2 != NULL) return t2;
        else return NULL;*/  //O(n) solution.
		if(n->v >= val) return parent(n->left, val); 
		else return parent(n->right, val); // O(log n) solution
    }
}

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    destroy(root);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &obj)
{
    root = copy(obj.root);
}

void BinarySearchTree::Insert(const int val)
{
	if(root == NULL)
	{
		root = new Node;
		root->v = val;
	}
    else assign(root, val);
}

void BinarySearchTree::InOrderPrint()
{
    print(root);
}

void BinarySearchTree::bst_remove(const int val)
{
	Node *t = search(root, val);
	if(t == NULL) cout << "This value is not in the tree!" << endl;
	else
	{
		if(t->left != NULL)
		{
			Node *t1 = bst_max(t->left);
			Node *t2 = parent(t->left, t1->v);
			if(t1->left != NULL) t2->right = t1->left;
			else t2->right = NULL;
			t->v = t1->v;
			delete t1;
		}
		else if(t->right != NULL)
		{
			Node *t1 = parent(root, val);
			if(val > t1->v) t1->right = t->right;
			else t1->left = t->right;
			delete t;
		}
		else
		{
			Node *t1 = parent(root, val);
			//cout << "--" << t1->v << endl;
			if(val > t1->v) t1->right = NULL;
			else t1->left = NULL;
			delete t;
		} 
	}
	//cout << t->v << endl;
}

Node* BinarySearchTree::bst_max(Node *n)
{
	if(n->right != NULL) return bst_max(n->right);
	else return n;
}

int main()
{
	BinarySearchTree b;
	b.Insert(7);
	b.Insert(3);
	b.Insert(6);
	b.Insert(2);
	b.Insert(9);
	b.Insert(12);
	b.Insert(10);
	b.Insert(11);
	BinarySearchTree c(b);
	c.InOrderPrint();
	c.bst_remove(12);
	c.InOrderPrint();
	return 0;
}
