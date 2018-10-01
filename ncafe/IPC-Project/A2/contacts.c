#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(Name *a){
	printf("Please enter the contact's first name: ");
  scanf("%31[^\n]", a->firstName); 
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if(yes()){
		printf("Please enter the contact's middle initial(s): ");
		scanf("%7[^\n]", a->middleName); 
    clearKeyboard();
	}
	else a->middleName[0]='\0';

	printf("Please enter the contact's last name: ");
	scanf("%31[^\n]", a->lastName);
  clearKeyboard();
};

// getAddress:
void getAddress(Address *d){
	printf("Please enter the contact's street number: ");
	d->streetNumber = getInt();

	printf("Please enter the contact's street name: ");
	scanf("%41[^\n]", d->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
  if(yes()){
		printf("Please enter the contact's apartment number: ");
		d->apartmentNumber = getInt();
	}
	else d->apartmentNumber =0;

	printf("Please enter the contact's postal code: ");
	scanf("%8[^\n]", d->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%41[^\n]", d->city);
	clearKeyboard();
}

// getNumbers:
void getNumbers(Numbers *n){
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(n->cell);

  printf("Do you want to enter a home phone number? (y or n): ");
	if (yes()){
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(n->home);
	}
	else n->home[0]=0;

	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes()){
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(n->business);
	}
	else n->business[0]=0;
}

void getContact(Contact *c){
	getName(&c->name);
	getAddress(&c->address);
	getNumbers(&c->numbers);
}
