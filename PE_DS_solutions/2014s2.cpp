#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	Node()
	{
		next = NULL;
	}
	T item;
	Node *next;
};

template <typename T>
class List
{
public:
	List();
	~List();
	List(List<T> &);
	List<T> & operator=(List<T> &);
	int length();
	T &operator[](int);
	void AddToBack(T item);
	T RemoveFromFront();
	void removeDumplicates();
	void print();
	
private:
	Node<T> *begining;
	Node<T> *ending;
};

template <typename T>
List<T>::List()
{
	begining = NULL;
	ending = NULL;
}

template <typename T>
List<T>::~List()
{
	Node<T> *t = begining;
	while(begining != ending)
	{
		begining = begining -> next;
		delete t;
		t = begining;
	}
	delete begining;
}

template <typename T>
List<T>::List(List<T>& l)
{
	Node<T> *t1, *t2;
	t1 = l.begining;
	while(t1 != NULL)
	{
		t2 = new Node<T>;
		t2 -> item = t1 -> item;
		if(begining == NULL)
		{
			begining = t2;
			ending = t2;
		}
		else
		{
			ending -> next = t2;
			ending = ending -> next;
		}
		t1 = t1 -> next;
	}
}

template <typename T>
List<T> & List<T>::operator=(List<T> &b)
{
	this -> List(b);
	return *this;
}

template <typename T>
int List<T>::length()
{
	int count = 0;
	Node<T> *t = begining;
	while(t != NULL)
	{
		t = t->next;
		count++;
	}
	return count;
}

template <typename T>
T &List<T>::operator[](int i)
{
	Node<T> *t = begining;
	for(int k = 0; k < i; k++) t = t -> next;
	return t -> item;
}

template <typename T>
void List<T>::AddToBack(T item)
{
	Node<T> *t = new Node<T>;
	t -> item = item;
	if(begining == NULL)
	{
		begining = t;
		ending = t;
	}
	else
	{
		ending -> next = t;
		ending = ending -> next;
	}
}

template <typename T>
T List<T>::RemoveFromFront()
{
	Node<T> *t = begining;
	begining = begining -> next;
	T item = t -> item;
	delete t;
	return item;
}

template <typename T>
bool compare(T item1, T item2)
{
	if(item1 == item2) return true;
	else return false;
}

template <typename T>
void List<T>::removeDumplicates()
{
	Node<T> *t1, *t2;
	t1 = begining;
	while(t1 -> next != NULL)
	{
		t2 = t1;
		while(t2 -> next != NULL)
		{
			if(compare(t2 -> next -> item, t1 -> item))
			{
				Node<T> *t3 = t2 -> next;
				t2 -> next = t2 -> next -> next;
				delete t3;
			}
			else t2 = t2 -> next;
		}
		t1 = t1 -> next;
	}
	ending = t1;
}

template <typename T>
void List<T>::print()
{
	Node<T> *t = begining;
	while(t != NULL)
	{
		cout << t -> item << " ";
		t = t -> next;
	}
	cout << endl;
}

int main()
{
	List<int> l;
	l.AddToBack(2);
	l.AddToBack(1);
	l.AddToBack(2);
	l.AddToBack(3);
	l.AddToBack(4);
	l.AddToBack(2);
	l.AddToBack(3);
	l.AddToBack(3);
	l.print();
	cout << "length: " << l.length() << endl;
	l.RemoveFromFront();
	l.print();
	List<int> l1 = l;
	l1.print();
	l1.removeDumplicates();
	l1.print();
	return 0;
}
