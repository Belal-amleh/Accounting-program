#include<iostream>
#include<vector>
#include<string>
#define endl '\n'
using namespace std;
void Line()
{
	cout << "\n----------------------------------------------------------\n";
}
int counter = 1 ;
struct Product_info
{
	string item_name;
	int Quantity;
	double Price;
};
int32_t main()
{
	int n;
	int choice;

	cout << "Enter The number of Initial products You have : ";
	cin >> n;
	string Name;
	int Quantity;
	double Price;
	vector<Product_info> Menu;
	cout << "Enter The Product Name, Quanitiy and Price : " << endl;
	for (auto i = 0; i < n; i++)
	{
		cin >> Name >> Quantity >> Price;
		Menu.push_back(Product_info({ Name , Quantity , Price }));
	}

	system("pause");
	system("cls");
Start:
	cout << "[1] Show All Items " << endl;
	cout << "[2] Add An Item    " << endl;
	cout << "[3] Update An Item Info " << endl;
	cout << "[4] Delete An Item  " << endl;
	cout << "[5] Print The final Price " << endl;
	cout << "[6] Clear Screen " << endl;
	cout << "[7] Exit " << endl;
	cout << endl << "Enter Your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1: // show all items info 
		counter = 1;
		cout << "ID" << "\t" << "P.Name" << "\t\t " << "P.Quantity" << "\t " << "P.Price";
		Line();
		for (auto& i : Menu)
		{
			if (i.item_name == "Deleted")
			{
				cout << "0" << "\t" << i.item_name << "\t\t  " << i.Quantity << "\t\t  " << i.Price;
				Line();
			}
			else
			{
				cout << counter++ << "\t" << i.item_name << "\t\t  " << i.Quantity << "\t\t  " << i.Price;
				Line();
			}
		}
		break;
	case 2: // Add item
		cout << "Enter How many Items you want to add : ";
		int num; cin >> num;
		for (auto i = 1; i <= num; ++i)
		{
			if (i == 1)
			{
				cout << "Enter The " << i << "\'st Product Name : ";
				cin >> Name;
				cout << "Enter The " << i << "\'st Product Quantity : ";
				cin >> Quantity;
				cout << "Enter The " << i << "\'st Product Price : ";;
				cin >> Price;
			}
			else if (i == 2)
			{
				cout << "Enter The " << i << "\'nd Product Name : ";
				cin >> Name;
				cout << "Enter The " << i << "\'nd Product Quantity : ";
				cin >> Quantity;
				cout << "Enter The " << i << "\'nd Product Price : ";;
				cin >> Price;
			}
			else if (i == 3)
			{
				cout << "Enter The " << i << "\'rd Product Name : ";
				cin >> Name;
				cout << "Enter The " << i << "\'rd Product Quantity : ";
				cin >> Quantity;
				cout << "Enter The " << i << "\'rd Product Price : ";;
				cin >> Price;
			}
			else
			{
				cout << "Enter The " << i << "\'th Product Name : ";
				cin >> Name;
				cout << "Enter The " << i << "\'th Product Quantity : ";
				cin >> Quantity;
				cout << "Enter The " << i << "\'th Product Price : ";;
				cin >> Price;
			}
			Line();
			Menu.push_back({ Name,Quantity,Price });
		}
		break;
	case 3: //  Update info
		int choice2;
	Start2:
		cout << "What You Want to update ? " << endl;
		cout << "[1] Product Name" << endl;
		cout << "[2] Product Quantity " << endl;
		cout << "[3] Product Price " << endl;
		cout << "[4] All product info " << endl;
		cout << "[5] Exit" << endl;
		cin >> choice2;
		bool Search;
		Search = false;
		switch (choice2)
		{
		case 1: // Name
			cout << "Enter The OLD Product name : ";
			cin >> Name;
			if (Name == "Deleted")
			{
				cout << "The item not found in the product menu ";
				Line();
				break;
			}
			for (auto& i : Menu)
			{
				if (i.item_name == Name)
				{
					Search = true;
					cout << "Enter The NEW Product Name :";
					cin >> Name;
					i.item_name = Name;
					cout << "Updated Successfully \n" << endl;
				}
			}
			if (Search == false)
			{
				cout << "The item not found in the product menu " << endl;
				Line();
			}

			break;
		case 2:
			if (Name == "Deleted")
			{
				cout << "The item not found in the product menu ";
				Line();
				break;
			}
			cout << "Enter The Product name : ";
			cin >> Name;
			for (auto& i : Menu)
			{
				if (i.item_name == Name)
				{
					Search = true;
					cout << "Enter The NEW Product Quantity :";
					cin >> Quantity;
					i.Quantity = Quantity;
					cout << "Updated Successfully \n" << endl;
				}
			}
			if (Search == false)
			{
				cout << "The item not found in the product menu " << endl;
				Line();
			}
			break;
		case 3:
			if (Name == "Deleted")
			{
				cout << "The item not found in the product menu ";
				Line();
				break;
			}
			cout << "Enter The Product name : ";
			cin >> Name;
			for (auto& i : Menu)
			{
				if (i.item_name == Name)
				{
					Search = true;
					cout << "Enter The NEW Product Price :";
					cin >> Price;
					i.Price = Price;
					cout << "Updated Successfully " << endl;
				}
			}
			if (Search == false)
			{
				cout << "The item not found in the product menu " << endl;
				Line();
			}
			break;
		case 4:
			if (Name == "Deleted")
			{
				cout << "The item not found in the product menu ";
				Line();
				break;
			}
			cout << "Enter The Product name : ";
			cin >> Name;
			for (auto& i : Menu)
			{
				if (i.item_name == Name)
				{
					Search = true;
					cout << "Enter The NEW Product Name :";
					cin >> Name;
					i.item_name = Name;
					cout << "Updated Successfully " << endl;
					Line();
					cout << "Enter The NEW Product Quantity :";
					cin >> Quantity;
					i.Quantity = Quantity;
					cout << "Updated Successfully " << endl;
					Line();
					cout << "Enter The NEW Product Price :";
					cin >> Price;
					i.Price = Price;
					cout << "Updated Successfully " << endl;
					Line();
				}
			}
			if (Search == false)
			{
				cout << "The item not found in the product menu " << endl;
				Line();
			}

			break;
		case 5:
			system("pause");
			break;
		default:
			cout << "INVALID , Please Try again" << endl;
			Line();
			goto Start2;
			break;
		}
		break;

	case 4: // Delete 
		bool S ;
		S = false;
		char ch;
		int Index ;
		cout << "Enter The item Name : ";
		cin >> Name;
		for (int i = 0; i < Menu.size(); ++i)
		{
			if (Menu[i].item_name == Name)
			{
				S = true;
				Index = i;
				cout << "Are you Sure you want to Delete " << Name << " ?" << endl;
				cout << "Yes (Y) / No[N] : "; cin >> ch;
				if (ch == 'Y')
				{
					Menu[i] = { "Deleted" , 0 , 0 };
				}
				else
				{
					cout << "Mission Cancelled " << endl;
					break;
					break;
				}

			}
		}
		if (S == true)
		{
			cout << "Deleted Successully " << endl;
			Line();
		}

		break;
	case 5:
		double sum ;
		sum = 0;
		for (auto& i : Menu)
		{
			sum += (i.Price * i.Quantity);

		}
		cout << "The Total Price is : " << sum << endl;
		Line();
		break;
	case 6:
		system("pause");
		system("cls");
	case 7:
		cout << "Thanks for using my app " << endl;
		break;
	default:
		cout << "IVALID , Try again please ";
		Line();
		break;
	}
	if (choice != 7)
		goto Start;

}