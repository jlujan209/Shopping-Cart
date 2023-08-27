#include <iostream>
using namespace std;


#include "ItemToPurchase.h"


ItemToPurchase::ItemToPurchase() {
    name = "none";
    description = "none";
    quantity = 0;
    price = 0;
}


ItemToPurchase::ItemToPurchase(string Name, string Description, int Price, int Quantity) {
    name = Name;
    description = Description;
    quantity = Quantity;
    price = Price;
}


string ItemToPurchase::GetName() {
    return name;
}


string ItemToPurchase::GetDescription() {
    return description;
}


int ItemToPurchase::GetPrice() {
    return price;
}


int ItemToPurchase::GetQuantity() {
    return quantity;
}


void ItemToPurchase::SetName(string Name) {
    name = Name;
}


void ItemToPurchase::SetPrice(int Price) {
    price = Price;
}


void ItemToPurchase::SetQuantity(int Quantity) {
    quantity = Quantity;
}


void ItemToPurchase::SetDescription(string Description) {
    description = Description;
}


void ItemToPurchase::PrintItemDescription() {
    cout << name << ": " << description << endl;
}


void ItemToPurchase::PrintItemCost() {
    cout << name << " " << quantity << " @ $" << price << " = $" << price * quantity << endl;
}
