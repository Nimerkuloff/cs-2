//
// Created by nimerkuloff on 17/04/18.
//

#include "menu.h"
void menuFunc(list *&ph){

    string numStr;
    int choice;
    bool flag = true;
    while (flag != false) {
        cout << "*******************************\n";
        cout << " 1 - Add.\n";
        cout << " 2 - Remove.\n";
        cout << " 3 - Find.\n";
        cout << " 4 - Print.\n";
        cout << " 5 - Exit.\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;
        switch (choice) {
            case 1:
                addNumber(ph);
                break;
            case 2:
                removeFirst(ph);
                break;
            case 3:
                cout << "Searching for what?" << endl;
                cin >> numStr;
                search(ph, numStr);
                break;
            case 4:
                print(ph);
                cout << endl;
                break;
            case 5:
                cout << "*******************************\n";
                cout << "End of Program.\n";
                flag = false;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }
    }
}

