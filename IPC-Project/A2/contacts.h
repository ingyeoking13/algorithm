// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

// Structure type Name declaration
typedef struct{
	char firstName[31], middleName[7], lastName[36];
} Name; 

// Structure type Address declaration
typedef struct{
	int streetNumber;
	char street[41]; 
	int apartmentNumber;
	char postalCode[8], city[41];
}Address;

// Structure type Numbers declaration
typedef struct{
	char cell[11], home[11], business[11];
}Numbers;

// Structure type Contact declaration
typedef struct{
	Name name;
	Address address;
	Numbers numbers;
}Contact;

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// getName:
void getName(Name *);

// getAddress:
void getAddress(Address *);

// getNumbers:
void getNumbers(Numbers *);

// getContact:
void getContact(Contact *);
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_
