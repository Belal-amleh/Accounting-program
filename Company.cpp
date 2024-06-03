#include<iostream>
#include<string>
#include<iomanip>
const int SIZE = 100;
using namespace std;
void cin_check(int& size);
void Separator()
{
    cout << "================================" << endl;
}
int main()
{
   
    int count = 0, Index = 0;
    int Quantity[SIZE] = { 0 };
    int Price[SIZE] = { 0 };
    int n, no, choice;
    int size;
    int TotalPrice = 0;
    string Items[SIZE];
    string item;
   
    
   
    cout << "Enter Numbers of items ";
    cin_check(size);
    cout << "Enter an Item Name , Quantity and Price for it \n";
    for (int i = 0; i < size; ++i)
    {
        cin >> Items[i] >> Quantity[i] >> Price[i];
        
    }
    system("pause");
    system("cls");
    do {
        cout << "[1] View All Items"         << endl;
        cout << "[2] Update Items Quantity " << endl;
        cout << "[3] Update item  Price "    << endl;
        cout << "[4] Add an Item "           << endl;
        cout << "[5] Print The total price " << endl;
        cout << "[6] Clear Screen "          << endl;
        cout << "[7] Exit"                   << endl;


        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {

        case 1://view all items   
            cout << "Item" << setw(30) << "Quantity"
                << setw(20) << "Price" << setw(20) << "Final Price" << endl;
            for (int i = 0; i < size; ++i)
                cout << Items[i] << "\t\t\t   "
                << Quantity[i] << "\t\t\t " << Price[i]
                << "\t\t" << Price[i] * Quantity[i] << endl;
            break;
        case 2://update items Quantity
            cout << "Enter Number of items you want to update : "; cin >> n;
            if (n == 1)
            {
                cout << "Enter The Item's Name : ";
                cin >> item;
                cout << "Enter The New value : ";
                for (int i = 0; i < SIZE; ++i)
                    if (item == Items[i])
                        cin >> Quantity[i];
            }
            else if (n > 1 && n <= size)
            {
                for (int i = 0; i < n; ++i)
                {
                    cout << "Enter The Item's Name  : "; cin >> item;
                    cout << "Enter The New value : ";
                    for (int j = 0; j < SIZE; ++j)
                        if (item == Items[j])
                            cin >> Quantity[j];
                }
            }
            else
                cout << "The Number you Entered was out of range " << endl;
            cout << "Updated Successfully" << endl;
            break;
        case 3://Update price 
            cout << "Enter Number of items you want to update : ";
            cin >> n;
            if (n == 1)
            {
                cout << "Enter The Item's Name : ";
                cin >> item;
                cout << "Enter The New value : ";
                for (int i = 0; i < SIZE; ++i)
                    if (item == Items[i])
                        cin >> Price[i];
            }
            else if (n > 1 && n <= size)
            {
                for (int i = 0; i < n; ++i)
                {
                    cout << "Enter The Item's Name  : "; 
                    cin >> item;
                    cout << "Enter The New value : ";
                    for (int j = 0; j < SIZE; ++j)
                        if (item == Items[j])
                            cin >> Price[j];
                }
            }
            else
                cout << "The Number you Entered was out of range " << endl;
            cout << "Updated Successfully" << endl;
            break;
        case 4: //add items
            cout << "Enter Number of items you want to enter : ";
            cin >> no;
            for (int i = size; i < size + no; i++)
            {
                cout << "Enter item # " << i + 1 << " :  ";
                cin >> Items[i];
                cout << "Enter " << Items[i] << " Quantity :  ";
                cin >> Quantity[i];
                cout << "Enter the " << Items[i] << "\'s Price : ";
                cin >> Price[i];
                count++;
            }
            size = size + count;
            cout << "Added Successfully" << endl;
            break;
        case 5://total price 
            for (int i = 0; i < size; ++i)
                TotalPrice += (Price[i] * Quantity[i]);
            cout << "The Total Price is : " << TotalPrice << endl;
            break;
        case 6 : // cleer screen
            system("pause");
            system("cls");
            break;
        case 7 :
            cout << "Thanks for visiting our Company :) " << endl;
            system("pause");
        default:
            cout << "Invalid choice , Try again " << endl;
            break;

        }

        Separator();

    } while (choice != 7);

    return 0;
}
void cin_check(int &size)
{
    
    cin >> size;
    if (!cin)
    {
       cout << "Wrong input please enter again : ";
       cin.clear(); 
       cin.ignore();
       cin_check(size);
    }
    return;
}