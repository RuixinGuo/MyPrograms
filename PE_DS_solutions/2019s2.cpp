#include <iostream>

using namespace std;

class String
{
public:
	String();
	String(const char*);
	String(const String &);
	~String();
	void Swap(String &);
	String & operator=(const String &);
	String operator+(const String &) const;
	void print();

private:
	char *str;
	int len;
};

String::String()
{
	str = NULL;
}

String::String(const char *a)
{
	len = 0;
	while(a[len] != '\0') len++;
	len++;
	str = new char[len];
	for(int i = 0; i < len; i++) str[i] = a[i];
}

String::String(const String &a)
{
	len = a.len;
	str = new char[len];
	for(int i = 0; i < len; i++) str[i] = a.str[i];
}

String::~String()
{
	delete [] str;
}

void String::Swap(String &b)
{
	char *p;
	p = str;
	str = b.str;
	b.str = p;
}

String & String::operator=(const String &a)
{
	len = a.len;
	str = new char[len];
	for(int i = 0; i < len; i++) str[i] = a.str[i];
	return *this;
}

String String::operator+(const String &a) const
{
	String s;
	s.len = len + a.len - 1;
	s.str = new char[s.len];
	for(int i = 0; i < len - 1; i++) s.str[i] = str[i];
	for(int i = 0; i < s.len; i++) s.str[i + len - 1] = a.str[i];
	return s;
}

void String::print()
{
	for(int i = 0; i < len; i++)
		cout << str[i];
	cout<<endl;
	cout<< "length:" << len << endl;
}

int main()
{
	const char *a = "abcdefg";
	const char *b = "1234567";
	String s1(a);
	String s2(b);
	String s3 = s2;
	s1.Swap(s2);
	String s4;
	s4 = s1 + s3;
	s4.print();
	//cout << s4.len << endl;
	//for(int i = 0; i < s4.len; i++) cout << s4.str[i];
	//cout << endl;
	return 0;
}
