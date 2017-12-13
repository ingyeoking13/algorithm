#ifndef CONTACTS_H_
#define CONTACTS_H_

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

// Function Prototypes
void getName(Name *);
void getAddress(Address *);
void getNumbers(Numbers *);
void getContact(Contact *);

#endif // !CONTACTS_H_
