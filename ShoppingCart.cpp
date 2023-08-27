#include <iostream>
using namespace std;


#include "ShoppingCart.h"


ShoppingCart::ShoppingCart() {
    CustomerName = "none";
    CurrentDate = "January 1, 2016";
}


ShoppingCart::ShoppingCart(string customerName, string Date) {
    CustomerName = customerName;
    CurrentDate = Date;
}


string ShoppingCart::GetCustomerName() {
    return CustomerName;
}


string ShoppingCart::GetDate() {
    return CurrentDate;
}


void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}
void ShoppingCart::RemoveItem(string itemName){
    int i;
    int index = -1;
    for (i = 0; i < cartItems.size(); ++i) {
        if (itemName== cartItems.at(i).GetName()) {
            index = i;
        }
    }
    if (index != -1) {
        cartItems.erase(cartItems.begin() + index);
    }
    else {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}


void ShoppingCart::ModifyItem(ItemToPurchase item){
    int i;
    int index = -1;
    for (i = 0; i < cartItems.size(); ++i) {
        if (item.GetName() == cartItems.at(i).GetName()) {
            index = i;
        }
    }
    if (index != -1) {
        cartItems.at(index).SetQuantity(item.GetQuantity());
    }
    else {
        cout << "Item not found in cart. Nothing modified." << endl;
    }


}


int ShoppingCart::GetNumItemsInCart(){
    return cartItems.size();
}


int ShoppingCart::GetCostOfCart(){
    int i = 0, total = 0;
    for (i = 0; i < cartItems.size(); ++i) {
        total += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
    }
    return total;
}


void ShoppingCart::PrintTotal(){
    int i;
    int total = 0;
    int numItems = 0;
    for (i = 0; i < cartItems.size(); ++i) {
        numItems += cartItems.at(i).GetQuantity();
    }
        cout << CustomerName << "'s Shopping Cart - " << CurrentDate << endl;
        cout << "Number of Items: " << numItems << endl << endl;
        if (cartItems.size() == 0) {
            cout << "SHOPPING CART IS EMPTY" << endl;
        }
        else {
            for (i = 0; i < cartItems.size(); ++i) {
                cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice() << " = $" << cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice() << endl;
                total += cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice();
            }
        }
            cout << endl << "Total: $" << total << endl;
       
}


void ShoppingCart::PrintDescriptions(){
    int i;
    cout << CustomerName << "'s Shopping Cart - " << CurrentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for (i = 0; i < cartItems.size(); ++i) {
        cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
    }
}
