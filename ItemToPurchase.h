#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H


#include <string>
using namespace std;


class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(string Name, string description, int price, int quantity);
        string GetName();
        int GetQuantity();
        int GetPrice();
        string GetDescription();
        void SetName(string Name);
        void SetPrice(int Price);
        void SetQuantity(int Quantity);
        void SetDescription(string Description);
        void PrintItemCost();
        void PrintItemDescription();
    private:
        string name;
        string description;
        int quantity;
        int price;
};


#endif
