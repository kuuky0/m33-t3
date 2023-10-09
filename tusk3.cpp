#include <iostream>
#include <vector>

using namespace std;

template<typename T1, typename T2>
class govna {
public:
	T1 a;
	T2 b;

	govna(T1 _a, T2 _b) : a(_a), b(_b) {};
};

template<typename T1, typename T2>
void add(vector<govna<T1, T2>>& vec, T1 a, T2 b)
{
	govna<T1, T2> pa(a, b);
	vec.push_back(pa);
}

template<typename T1, typename T2>
void remove(vector<govna<T1, T2>>& vec, T1 c)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].a == c)
		{
			vec.erase(vec.begin() + i);
			i--;
		}
	}
}

template<typename T1, typename T2>
void print(vector<govna<T1, T2>>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "Key: " << vec[i].a << "Meaning: " << vec[i].b << endl;
	}
}

template<typename T1, typename T2>
void find(vector<govna<T1, T2>>& vec, T1 key)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].a == key)
		{
			cout << "Key: " << vec[i].a << "Meaning: " << vec[i].b << endl;
		}
	}
}

int main()
{
	vector<govna<string, int>> vec;

	string command;
	do {
		if (command == "add")
		{
			string key;
			int meaning;
			cout << "Input key and meaning: ";
			cin >> key >> meaning;
			add(vec,key,meaning);
		}
		else if (command == "remove")
		{
			string key;
			cout << "Remove key: ";
			cin >> key;
			remove(vec, key);
		}
		else if (command == "find")
		{
			string key;
			cout << "Find by key: ";
			cin >> key;
			find(vec, key);
		}
		else if (command == "print")
		{
			print(vec);
		}

		cout << "Input command: ";
		cin >> command;
	} while (command != "exit");
}