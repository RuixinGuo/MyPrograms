#include <iostream>

using namespace std;

typedef int T;

typedef struct node
{
	T item;
	struct node *next;
}Node;

/*---------Class Queue----------*/

class Queue
{
	
public:
	Queue();
	Queue(const Queue &);
	~Queue();
	void swap(Node *, Node *);
	Queue operator=(const Queue &);
	void enqueue(T);
	T dequeue();
//private:
	Node *front;
	Node *rear;
};

Queue::Queue()
{
	front = new Node;
	rear = front;
}

Queue::Queue(const Queue &obj)
{
	front = new Node;
	front->item = obj.front->item;
	Node *q = obj.front;
	Node *p = front;
	while(q != obj.rear)
	{
		Node *t = new node;
		t->item = q->next->item;
		p->next = t;
		p = p->next;
		q = q->next;
	}
	rear = p;
}

Queue::~Queue()
{
    Node *t = front;
	Node *t1;
	while(t != rear)
	{
		t1 = t;
		t = t->next;
		delete t1;
	}
	delete t;
}

void Queue::swap(Node *a, Node *b)
{
    T item0;
	if(a != NULL && b != NULL)
	{
		item0 = a->item;
		a->item = b->item;
		b->item = item0;
	}
}

Queue Queue::operator=(const Queue &obj)
{
	Queue qu;
    qu.front = new Node;
    qu.front->item = obj.front->item;
    Node *q = obj.front;
    Node *p = qu.front;
    while(q != obj.rear)
    {   
        Node *t = new Node;
        t->item = q->next->item;
        p->next = t;
        p = p->next;
		q = q->next;
    }
    qu.rear = p;
	return qu;
}

void Queue::enqueue(T item0)
{
	rear->item = item0;
	Node *t = new Node;
	rear->next = t;
	rear = rear->next;
}

T Queue::dequeue()
{
	T item0 = front->item;
	Node *t1 = front;
	front = front->next;
	delete t1;
	return item0;
}
	

int main()
{
	Queue q;
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(7);
	q.enqueue(6);
	T v = q.dequeue();
	cout << v << endl;
	Queue r = q;
	cout << r.dequeue() << endl;
	Queue s(r);
	cout << s.dequeue() << endl;
	return 0;
}
