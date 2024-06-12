#include <iostream>
#include "GDB.h"
#include <string>

using namespace std;

void GDB_APP() {

    int choice = 1;

    while (choice != 0) {
        cout << "To add Member, enter 1\n";
        cout << "To get used size in database, enter 2\n";
        cout << "To read Member's data, enter 3\n";
        cout << "To get the list of all Members IDs, enter 4\n";
        cout << "To check if Member exists, enter 5\n";
        cout << "To delete a Member, enter 6\n";
        cout << "To check if database is full, enter 7\n";
        cout << "To exit enter 0\n";
        cout << "----------------------------------------------------------\n";
        cin >> choice;


            GDB_action(choice);
    }
}

/*This is our start up for the program it takes the choice from the user and then
it send it to the function in GDB.cpp to do the action required*/
void GDB_action(unsigned char choice)

{

    unsigned int id = 0;

    if (choice == 1) {
        GDB_AddEntry();
    } else if (choice == 2) {
        unsigned char UsedSize = GDB_GetUsedSize();
        cout << "Number of Members Stored = " << static_cast<int>(UsedSize) << endl;//casting the unsigned char to integer
    } else if (choice == 3) {
        cout << "Please Enter the Member's ID :\n";
        cin >> id;
        GDB_ReadEntry(id);
        cout << "-----------------------\n";
    } else if (choice == 4) {
        GDB_GetList();
    } else if (choice == 5) {
        cout << "Please Enter the ID to Check :\n";
        cin >> id;
        GDB_IsIdExist(id);
    } else if (choice == 6) {
        cout << "Please Enter the ID you want to (DELETE) :\n";
        cin >> id;
        GDB_DeletEntry(id);
    } else if (choice == 7) {
        GDB_IsFull();
    }
}
