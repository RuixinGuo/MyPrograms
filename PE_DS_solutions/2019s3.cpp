#include <iostream>

using namespace std;

typedef struct node
{
	int v;
	node *left = NULL;
	node *middle = NULL;
	node *right = NULL;
}Node;

class ternary
{
public:
	ternary();
	ternary(Node *);
	~ternary();
	ternary(const ternary &);
	void preorder(Node *);
	void postorder(Node *);
	void recursive_delete(Node *);
	void recursive_copy(Node *, Node *);

	Node *root;
};

ternary::ternary()
{
	root = new Node;
}

ternary::ternary(Node *a)
{
	root = a;
}

void ternary::recursive_delete(Node *n)
{
	if(n->left != NULL) recursive_delete(n->left);
	if(n->middle != NULL) recursive_delete(n->middle);
	if(n->right != NULL) recursive_delete(n->right);
	delete n;
}

ternary::~ternary()
{
	recursive_delete(root);
}

void ternary::recursive_copy(Node *n, Node *a)
{
	if(n != NULL)
	{
		n->v = a->v;
		if(a->left != NULL)
		{
			Node *t = new Node;
			n->left = t;
			recursive_copy(t, a->left);
		}
        if(a->middle != NULL)
        {
            Node *t = new Node;
			n->middle = t;
            recursive_copy(t, a->middle);
        }
        if(a->right != NULL)
        {
            Node *t = new Node;
			n->right = t;
            recursive_copy(t, a->right);
        }
	}
}

ternary::ternary(const ternary &a)
{
	root = new Node;
	recursive_copy(root, a.root);
}

void ternary::preorder(Node *n)
{
	if(n == NULL) return;
	else
	{
		printf("%d ", n->v);
		preorder(n->left);
		preorder(n->middle);
		preorder(n->right);
	}
}

void ternary::postorder(Node *n)
{
    if(n == NULL) return;
    else
    {
        postorder(n->left);
        postorder(n->middle);	
		postorder(n->right);
    	printf("%d ", n->v);
	}
}

int main()
{
	Node *t1[6];
	for(int i = 0; i < 6; i++) t1[i] = new Node;
	for(int i = 1; i <= 6; i++) t1[i-1]->v = i;
	t1[0]->left = t1[1];
	t1[0]->middle = t1[2];
	t1[0]->right = t1[3];
	t1[1]->left = t1[4];
	t1[2]->middle = t1[5];
//	cout << t1[5]->v << endl;
	ternary t(t1[0]);
	ternary q(t);
	q.preorder(q.root);
	cout << endl;
	q.postorder(q.root);
	cout << endl;
//	for(int i = 0; i < 6; i++) delete t1[i];
	return 0;
}
