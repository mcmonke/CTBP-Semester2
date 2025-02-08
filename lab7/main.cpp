#include "vectorx/myvector.h"
#include "virtual/virtual.h"
#include <iostream>
using namespace std;

void print(const MyVector<Goods*>& a) {
    for (int i = 0; i < a.get_size(); i++) {
        cout << "Index " << i << endl;
        a[i]->show();
        cout << endl;
    }
}

void remove(int index, MyVector<Goods*>& a) {
    delete a[index]; 
    a.delete_element(index);
}

void clear(MyVector<Goods*>& a) {
    for (int i = a.get_size() - 1; i >= 0; i--) {
        delete a[i];
        a.delete_element(i);
    }
}

int menu() {
    std::cout << "======== MAIN MENU ========\n";
    std::cout << "|1 - Add Goods            |\n";
    std::cout << "|2 - Delete Goods by Index|\n";
    std::cout << "|3 - Clear data           |\n";
    std::cout << "|4 - Print                |\n";
    std::cout << "|5 - End Program          |\n";
    std::cout << "===========================\n\n";
    std::cout << "Choose number from 1 to 5:" << std::endl;
    int resp;
    std::cin >> resp;
    std::cin.clear();
    std::cin.ignore(10, '\n');
    std::cout << "\n";
    return resp;
}

int main() {
    cout << "Choose Mode: \n 1 - Interactive  2 - Demo\n";
    MyVector<Goods*> v;
    int mode;
    cin >> mode;
    cin.ignore(); 

    if (mode == 2) {
        v.add_element(new Product("Milk", "Dairy Farm", 7));
        v.add_element(new Toy("Teddy Bear", "Brown"));
        v.add_element(new Dairy_Product("Cheese", "Cheese Factory", 15, 25.0));

        print(v);
        cout << "==============\n";
        remove(2, v);
        print(v);
        cout << "==============\n";
        clear(v);
        print(v);
        return 0;
    }

    while (true) {
        switch (menu()) {
            case 1: {
                cout << "Choose Goods Type: \n 1 - Toy  2 - Product  3 - Dairy Product\n";
                int type;
                cin >> type;
                cin.ignore();

                if (type == 1) {
                    char name[50];
                    char color[50];

                    cout << "Enter Toy Name: ";
                    cin.getline(name, 50);
                    cout << "Enter Toy Color: ";
                    cin.getline(color, 50);

                    v.add_element(new Toy(name, color));

                } else if (type == 2) {
                    char name[50];
                    char origin[50];
                    int shelf_life;

                    cout << "Enter Product Name: ";
                    cin.getline(name, 50);
                    cout << "Enter Origin: ";
                    cin.getline(origin, 50);
                    cout << "Enter Shelf Life (days): ";
                    cin >> shelf_life;
                    cin.ignore();

                    v.add_element(new Product(name, origin, shelf_life));

                } else if (type == 3) {
                    char name[50];
                    char origin[50];
                    int shelf_life;
                    double fat_content;

                    cout << "Enter Dairy Product Name: ";
                    cin.getline(name, 50);
                    cout << "Enter Origin: ";
                    cin.getline(origin, 50);
                    cout << "Enter Shelf Life (days): ";
                    cin >> shelf_life;
                    cout << "Enter Fat Content (%): ";
                    cin >> fat_content;
                    cin.ignore();

                    v.add_element(new Dairy_Product(name, origin, shelf_life, fat_content));

                } else {
                    cout << "Invalid goods type!\n";
                }
                break;
            }
            case 2: {
                int temp;
                cout << "Enter index of the element you want to delete:\n";
                cin >> temp;
                remove(temp, v);
                break;
            }
            case 3:
                clear(v);
                break;
            case 4:
                print(v);
                break;
            case 5:
                clear(v);
                return 0;
            default:
                std::cout << "Invalid operation number!" << std::endl;
                break;
        }
    }

    return 0;
}