#ifndef GDB_H
#define GDB_H
#include <string>
#include <iostream>
using namespace std;

struct GymMember {
    unsigned int Member_ID;
    string Member_Gender;
    unsigned int Member_Age;
    unsigned int Member_Phone_no;
};

bool GDB_IsFull();
unsigned char GDB_GetUsedSize();
bool GDB_AddEntry();
void GDB_DeletEntry(unsigned int id);
bool GDB_ReadEntry(unsigned int id);
void GDB_GetList();
bool GDB_IsIdExist(unsigned int id);
void GDB_APP();
void GDB_action(unsigned char choice);

#endif // GDB_H
