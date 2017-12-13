#ifndef CONTACTSH_H_
#define CONTACTSH_H_

#include "contacts.h"

// clearKeyboard:
void clearKeyboard();
// pause:
void pause();
// getInt:
int getInt();
// getIntInRange:
int getIntInRange(int, int);
// yes:
int yes(); 
// menu:
int menu();
// ContactManagerSystem:
void ContactManagerSystem();

// getTenDigitPhone:
void getTenDigitPhone(char[11]);
// findContactIndex:
int findContactIndex(const Contact[], int, const char[]);
// displayContactHeader:
void displayContactHeader();
// displayContactFooter:
void displayContactFooter(int);
// displayContact:
void displayContact(const Contact *);
// displayContacts:
void displayContacts(const Contact[], int);
// searchContacts:
void searchContacts(const Contact[], int);
// addContact:
void addContact(Contact[], int);
// updateContact:
void updateContact(Contact[], int);
// deleteContact:
void deleteContact(Contact[], int);
// sortContacts:
void sortContacts(Contact[], int);

#endif
