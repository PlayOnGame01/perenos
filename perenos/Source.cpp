#include<iostream>
using namespace std;

class MyString
{
	char* leter;
	int year;
	string str;
public:
	MyString() = default;
	MyString(const char* l, int y)
	{
		cout << "Constructor by 2 params\n";
		leter = new char[strlen(l) + 1];
		strcpy_s(leter, strlen(l) + 1, l);
		str = nullptr; 
		year = y;
	}
	MyString(initializer_list<char> a) ///// ѕоследовательный шаблон класса который имеет минимальный интерфейс 
	{
		cout << "Size ->" << a.size() << endl;
		str.append(a.begin(), a.end());
	}
	MyString(const MyString& obj2) = delete;
	MyString& operator = (const MyString& obj2) = delete;
	MyString(const MyString& obj2) // copy constructor
	{
		cout << "Constructor Copy\n";
		leter = new char[strlen(obj2.leter) + 1];
		strcpy_s(leter, strlen(obj2.leter) + 1, obj2.leter);
		year = obj2.year;
	}
	MyString(const MyString& obj0) = delete;
	MyString& operator = (const MyString& obj0) = delete;
	MyString(const MyString& obj0) // copy constructor
	{
		cout << "Constructor Copy\n";
		leter = new char[strlen(obj0.leter) + 1];
		strcpy_s(leter, strlen(obj0.leter) + 1, obj0.leter);
		year = obj0.year;
	}

	MyString(MyString&& obj2) // move constructor
	{
		cout << "Constructor MOVE\n";
		leter = obj2.leter; // 
		obj2.leter = nullptr;

		year = obj2.year;
		obj2.year = 0;
	}
	MyString& operator =(MyString&& obj2)
	{
		if (leter != nullptr)
		{
			delete[] leter;
		}
		cout << "= MOVE\n";
		leter = obj2.leter; // 
		obj2.leter = nullptr;

		year = obj2.year;

		return *this;
	}

	MyString(MyString&& obj0) // move constructor
	{
		cout << "Constructor MOVE\n";
		leter = obj0.leter; // 
		obj0.leter = nullptr;

		year = obj0.year;
		obj0.year = 0;
	}
	MyString& operator =(MyString&& obj0)
	{
		if (leter != nullptr)
		{
			delete[] leter;
		}
		cout << "= MOVE\n";
		leter = obj0.leter; // 
		obj0.leter = nullptr;

		year = obj0.year;

		return *this;
	}

	~MyString()
	{
		cout << "Destructor\n";
		delete[] leter;
	}
	void Print()
	{
		if (leter == nullptr)
		{
			cout << "Model = NULLPTR\n";
		}
		else
		{
			cout << leter << "\t" << year << endl;
		}

	}
};

MyString ByValue()
{
	MyString obj("BMW", 2022);
	MyString obj{ 'H','e','l','l','o' };
	return obj; 
}


int main()
{
	MyString obj1("Audi", 1999); 
	MyString obj2 = move(obj1); 
	MyString obj{ 'H','e','l','l','o' };
	MyString obj3;
	obj3 = move(obj2);
	obj3.Print();
	obj2.Print();
}