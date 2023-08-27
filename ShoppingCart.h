#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H


#include <string>
#include "ItemToPurchase.h"
#include <vector>
using namespace std;


class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string customerName, string Date);
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase item);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase item);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();


private:
    string CustomerName;
    string CurrentDate;
    vector <ItemToPurchase> cartItems;
};




#endif
