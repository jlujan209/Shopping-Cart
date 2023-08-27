#include <iostream>
#include <iomanip>
using namespace std;


#include "ShoppingCart.h"


void PrintMenu() {
    cout <<"MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;


}


void ExecuteMenu(char option, ShoppingCart& theCart) {
    ItemToPurchase tempAdd, tempChange;
    string tempName;
    string tempDescription;
    int tempQuantity;
    int tempPrice;


    if (option == 'a') {
        cout << "ADD ITEM TO CART" << endl << "Enter the item's name:" << endl;
        cin.ignore();
        getline(cin, tempName);
        cout << "Enter the item description:" << endl;
        getline(cin, tempDescription);
        cout << "Enter the item price:" << endl;
        cin >> tempPrice;
        cout << "Enter the item quantity:" << endl;
        cin >> tempQuantity;


        tempAdd.SetName(tempName);
        tempAdd.SetDescription(tempDescription);
        tempAdd.SetPrice(tempPrice);
        tempAdd.SetQuantity(tempQuantity);
       
        theCart.AddItem(tempAdd);
        cout << endl;
    }
    else if (option == 'd') {
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove:" << endl;
        cin.ignore();
        getline(cin, tempName);
        theCart.RemoveItem(tempName);
    }
    else if (option == 'c') { //FIX
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline(cin, tempName);
        tempChange.SetName(tempName);
        cout << "Enter the new quantity:" << endl;
        cin >> tempQuantity;
        tempChange.SetQuantity(tempQuantity);
        theCart.ModifyItem(tempChange);


    }
    else if (option == 'i') {
        theCart.PrintDescriptions();
    }
    else if (option == 'o') {
        cout << "OUTPUT SHOPPING CART" << endl;
        theCart.PrintTotal();
    }
   
}


int main() {
    string holdName;
    string currDate;
    char selection;


    cout << "Enter customer's name:"<< endl;
    getline(cin, holdName);
    cout << "Enter today's date:" << endl;
    getline(cin, currDate);


    ShoppingCart cart(holdName, currDate);


    cout << endl<< "Customer name: " << cart.GetCustomerName() << endl;
    cout << "Today's date: " << cart.GetDate() << endl;
    cout << endl;
    PrintMenu();
    cout << endl << "Choose an option:" << endl;
    cin >> selection;


    while (selection != 'a' && selection != 'd' && selection != 'i' && selection != 'c' && selection != 'o' && selection != 'q') {
        cout << "Choose an option:" << endl;
        cin >> selection;
    }
    while (selection != 'q') {
        ExecuteMenu(selection, cart);
        PrintMenu();
        cout << endl << "Choose an option:" << endl;
        cin >> selection;
    }
   


    return 0;
}
