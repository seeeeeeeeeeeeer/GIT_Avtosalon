#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<map>

using namespace std;

class car
{
	string name;
	int engine_capacity, year, price;
public:
	car()
	{
		name = "NULL";
		engine_capacity = 0;
		year = 0;
		price = 0; 	
	}
	car(string name,int engine_capacity, int year, int price)
	{
		this->name = name;
		this->engine_capacity = engine_capacity;
		this->year = year;
		this->price = price;	
	}
	void set()
	{
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter Engine: ";
		cin >> engine_capacity;
		cout << "Enter Year: ";
		cin >> year;
		cout << "Enter Price: ";
		cin >> price;	
	}
	void print()const
	{		
		cout << "\n" << string(50, '=') << "\n";
		cout << "Name: " << name << "\n";
		cout << "Engine: " << engine_capacity << "\n";
		cout << "Year: " << year << "\n";
		cout << "Price: " << price << "\n";		
	}
};

class car_avtosalon
{
	map<int, car> c;
	car c1;
	int priority;
public:
	void add_car()
	{
		c1.set();
		cout << "Enter car to add: ";
		cin >> priority;
		c.insert({ priority,c1 });
	}
	void remove_car()
	{
		priority = 0;
		cout << "Enter car to delete: ";
		cin >> priority;
		if (c.find(priority) == c.end())
		{
			cout << "This car not exist\n";
		}
		else
		{
			auto res = c.find(priority);
			c.erase(res);
		}
	}
	void find_car()
	{
		priority = 0;
		cout << "Enter car to find: ";
		cin >> priority;
		if (c.find(priority) == c.end())
		{
			cout << "This car not exist\n";
		}
		else
		{
			auto it = c.find(priority);
			cout << string(50, '=') << "\n";
			cout << it->first << "\n";
			it->second.print();
			cout << string(50, '=') << "\n";
		}
	}
	void print()
	{
		for (auto it = c.begin(); it != c.end(); it++)
		{
			cout << string(50, '=') << "\n";
			cout << it->first << "\n";
			it->second.print();
			cout << string(50, '=') << "\n";
		}
	}
};
int menu()
{
	int choice;
	cout << string(50, '=') << "\n";
	cout << " Enter you choise: \n";
	cout << string(50, '=') << "\n";
	cout << "0 - Exit\n";
	cout << "1 - Print\n";
	cout << "2 - Add new car \n";
	cout << "3 - Find car\n";
	cout << "4 - Remove Car\n";
	cin >> choice;
	return choice;
}

int main()
{

	car_avtosalon c;
	int choice;
	do {
		choice = menu();
		if (!choice)break;
		switch (choice)
		{
		case 1:
			c.print();
			break;
		case 2:
			c.add_car();
			break;
		case 3:
			c.find_car();
			break;
		case 4:
			c.remove_car();
			break;
		}
	} while (true);
	return 0;

}
