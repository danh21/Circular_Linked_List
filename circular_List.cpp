#include <iostream>
#include "circular_List.h"

using namespace std;



int main() {
    cirList *list = NULL;
    int n, pos, data, opt;

    while (1) {
        cout << "\n\n" << " ---------------------------- MENU --------------------------- " << endl;
        cout << "0. Quit" << endl;
        cout << "1. Create list" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Insert node" << endl;
        cout << "4. Delete node" << endl;
        cout << "Enter your option: ";
        cin >> opt;

        switch (opt)
        {
            case 0:
                return 0;
            case 1:
                cout << "Enter the number of nodes: ";
                cin >> n;
                cout << "Add element at the head/tail of the list (0/1): ";
                cin >> opt;
                createList(list, n, opt);
                break;
            case 2:
                cout << "Enter the start position: ";
                cin >> pos;
                printList(list, pos);
                break;
            case 3:
                cout << "Enter the position: ";
                cin >> pos;
                cout << "Enter data: ";
                cin >> data;
                insertAt(list, pos, data);
                break;
            case 4:
                cout << "Enter the position: ";
                cin >> pos;
                deleteAt(list, pos);
                break;
            default:
                cout << "Invalid option !" << endl;
                break;
        }
    }
    
    delete list;
    return 0;
}