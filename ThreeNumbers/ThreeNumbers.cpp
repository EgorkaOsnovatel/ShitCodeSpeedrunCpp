#include <iostream>
#include <string>
#include <map>

using namespace std;

void first()
{
	string number;
	char starter;
	cin >> number;
	cin >> starter;
	int sum_b = 0;
	int sum_c = 0;
	switch (starter)
	{
	case 'a':
		cout << "Numbers: " << number.length() << endl;
		break;
	case 'b':
		for (int i = 0; i < number.length(); i++)
		{
			sum_b += (int)number[i];
		}
		cout << "Sum numbers: " << sum_b << endl;
		break;
	case 'c':
		for (int i = 0; i < number.length(); i++)
		{
			sum_c += (int)number[i];
		}
		sum_c = sum_c / number.length();
		cout << "Middle: " << sum_c << endl;
		break;
	}
}

struct Cafe
{
	int people = 0;
	int allPrice = 0;
	bool neededOrder = false;
	map<string, int> priceMenu = {
		{"pepsi", 100},
		{"pizza", 500},
		{"potato", 70},
		{"chief-burger", 150},
		{"coffee", 130}
	};

	void printMenu()
	{
		cout << "pepsi " << priceMenu["pepsi"] << endl << "pizza " << priceMenu["pizza"] << endl
			<< "potato " << priceMenu["potato"] << endl << "chief-burger " << priceMenu["chief-burger"] << endl
			<< "coffee " << priceMenu["coffee"];
	}

	void addOrder(char numberMenu)
	{
		switch (numberMenu)
		{
		case '1':
			allPrice += priceMenu["pepsi"];
			break;
		case '2':
			allPrice += priceMenu["pizza"];
			break;
		case '3':
			allPrice += priceMenu["potato"];
			break;
		case '4':
			allPrice += priceMenu["chief-burger"];
			break;
		case '5':
			allPrice += priceMenu["coffee"];
			break;
		default:
			neededOrder = false;
			break;
		}
	}
};

int main()
{
	Cafe cafe;
	cout << "How many guests? ";
	cin >> cafe.people;
	for (int i = 0; i < cafe.people; i++)
	{
		char numberMenu;
		cafe.printMenu();
		cout << endl;
		cafe.neededOrder = true;
		while (cafe.neededOrder)
		{
			cin >> numberMenu;
			cafe.addOrder(numberMenu);
		}
	}
	cout << cafe.allPrice;
}