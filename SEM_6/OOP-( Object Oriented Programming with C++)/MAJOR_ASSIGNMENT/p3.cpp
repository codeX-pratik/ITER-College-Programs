#include <iostream>
#include <string>
using namespace std;

class ShoppingList {
    struct Item {
        int code;
        string name;
        double price;
        int quantity;
    };
    
    Item items[100];
    int count;
    
public:
    ShoppingList() : count(0) {}
    
    void addItem(int code, string name, double price, int quantity) {
        if (count < 100) {
            items[count] = {code, name, price, quantity};
            count++;
            cout << "Item added successfully!" << endl;
        } else {
            cout << "Shopping list is full!" << endl;
        }
    }
    
    void deleteItem(int code) {
        for (int i = 0; i < count; i++) {
            if (items[i].code == code) {
                for (int j = i; j < count-1; j++) {
                    items[j] = items[j+1];
                }
                count--;
                cout << "Item deleted successfully!" << endl;
                return;
            }
        }
        cout << "Item not found!" << endl;
    }
    
    void printTotal() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += items[i].price * items[i].quantity;
        }
        cout << "Total order value: " << total << endl;
    }
    
    void displayItems() {
        if (count == 0) {
            cout << "No items in the list!" << endl;
            return;
        }
        
        cout << "Shopping List:" << endl;
        cout << "Code\tName\tPrice\tQuantity" << endl;
        for (int i = 0; i < count; i++) {
            cout << items[i].code << "\t" << items[i].name << "\t" 
                 << items[i].price << "\t" << items[i].quantity << endl;
        }
    }
};

int main() {
    ShoppingList list;
    
    list.addItem(101, "Laptop", 50000, 1);
    list.addItem(102, "Mouse", 500, 2);
    list.addItem(103, "Keyboard", 1200, 1);
    
    list.displayItems();
    list.printTotal();
    
    list.deleteItem(102);
    list.displayItems();
    list.printTotal();
    
    return 0;
}

/*

Item added successfully!
Item added successfully!
Item added successfully!
Shopping List:
Code    Name    Price   Quantity
101     Laptop  50000   1
102     Mouse   500     2
103     Keyboard        1200    1
Total order value: 52200
Item deleted successfully!
Shopping List:
Code    Name    Price   Quantity
101     Laptop  50000   1
103     Keyboard        1200    1
Total order value: 51200

*/