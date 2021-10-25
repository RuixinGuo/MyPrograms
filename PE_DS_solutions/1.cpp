#include <iostream>

using namespace std;

typedef struct node
{
	int item;
	struct node *next;
}Node;

class Stack
{
	
public:
	Stack();
	~Stack();
	void push(int item);
	int pop();
	int getmin();
private:
	Node *tos;
};

Stack::Stack()
{
	tos = new Node;
}

Stack::~Stack()
{
        Node *t = tos;
	Node *t1;
	while(t->next != NULL)
	{
		t1 = t;
		t = t->next;
		delete t1;
	}
	delete t;
}

void Stack::push(int item)
{
        Node *t = new Node;
	t->item = item;
	t->next = tos->next;
	tos->next = t;
}

int Stack::pop()
{
        int ret = tos->next->item;
	Node *t = tos->next;
	tos->next = tos->next->next;
	delete t;
	return ret; 
}

int Stack::getmin()
{
        int min = 999999;
	Node *tag;
	Node *t = tos->next;
	while(t != NULL)
	{
		if(t->item < tag->item) tag = t;
		t = t->next;
	}
	return tag->item;
}

int main()
{
	Stack s;
	s.push(3);
	s.push(7);
	s.push(2);
	s.push(4);
	printf("min:%d\n", s.getmin());
	printf("pop:%d\n", s.pop());
	printf("pop:%d\n", s.pop());
	return 0;
}
