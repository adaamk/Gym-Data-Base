#include <iostream>
#include "GDB.h"
#include <string>

using namespace std;

GymMember list[10];
int count = 0;

bool GDB_IsFull() {
    if (count == 10) {
        cout << "The Data base is now FULL\n";
        return true;
    } else {
        cout << "The Data base is NOT full yet\n";
        return false;
    }
}

unsigned char GDB_GetUsedSize() {
    return count;
}

bool GDB_AddEntry() {
    if (count < 10) {
        cout << "Please Enter Member ID:\n";
        cin >> list[count].Member_ID;
        cout << "Please Enter the Member gender:\n";
        cin >> list[count].Member_Gender;
        cout << "Please Enter Member Age:\n";
        cin >> list[count].Member_Age;
        cout << "Please Enter Member Phone number:\n";
        cin >> list[count].Member_Phone_no;
        count++;
        cout << "----------------------\n";
        return true;
    } else {
        cout << "Failed to add entry!\n Please check your inputs and try again\n";
        return false;
    }
}

void GDB_DeletEntry(unsigned int id) {

    int i, delete_index = -1;

    for (i = 0; i < count; i++) {
        if (id == list[i].Member_ID) {
            delete_index = i;
            break;
        }
    }

    if (delete_index != -1) {
        for (i = delete_index; i < count - 1; i++) {
            list[i] = list[i + 1];
        }

        // Clear the data of the last element
        list[count - 1].Member_ID = 0;
        list[count - 1].Member_Gender = "";
        list[count - 1].Member_Age = 0;
        list[count - 1].Member_Phone_no = 0;

        count--;

        cout << "Entry with ID " << id << " Deleted\n";
    } else {
        cout << "ID" << id << " Not found\n";
    }
}

bool GDB_ReadEntry(unsigned int id) {

    short i, flag = 0;

    for (i = 0; i < 10; i++) {
        if (id == list[i].Member_ID) {
            cout << "Member ID is: [" << list[i].Member_ID << "]" << endl;
            cout << "Member Gender is: [" << list[i].Member_Gender << "]" << endl;
            cout << "Member Age is: [" << list[i].Member_Age << "]" << endl;
            cout << "Member Phone number is: ["<<0 << list[i].Member_Phone_no << "]" << endl;

            flag = 1;
            return true;
        }
    }
    if (flag == 0) {
        cout << "Member does NOT exist!!\n";
        return false;
    }
}

void GDB_GetList() {

    cout << "Number of Members in list = [" << count << "]" << endl;
    int i;
    for (i = 0; i < count; i++) {
        cout << "[" << list[i].Member_ID << "]" << endl;
    }
}

bool GDB_IsIdExist(unsigned int id) {

    int i;

    for (i = 0; i < count; i++) {
        if (id == list[i].Member_ID) {
            cout << "Member Exist\n";
            return true;
        }
    }
    cout << "Member does NOT exist\n";
    return false;
}
