#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"
#include "contactHelpers.h"

#define MAXCONTACTS 5

void clearKeyboard(){
  while(getchar()!='\n');
}

// pause:
void pause(){
  printf("(Press Enter to Continue)\n");
  clearKeyboard();
}

// getInt:
int getInt(){
  char c='x'; int n;

  while(c!='\n'){
    scanf("%d%c", &n, &c);
    if(c!='\n') {
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
      clearKeyboard();
    }
  }
  return n;
}

// getIntInRange:
int getIntInRange(int a, int b){
  int n= getInt();
  while(n>b || n<a){
    printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", a, b);
    n=getInt();
  }
  return n;
}

// yes:
int yes(){
  char c='x', c2='x';
  while(c2!='\n' || (c!='n' && c!='N' && c!='y' && c!='Y')){
    scanf("%c%c", &c, &c2);
    if (c2!='\n' || (c!='n' && c!='N' && c!='y' && c!='Y')){
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			if (c2!='\n') clearKeyboard();
    }
  }
  return (c=='y' || c=='Y')?1:0;
}

// menu:
int menu(){
  int n=99; char c='x';
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");
  while(c!='\n' || n<0 || n>6){
    scanf("%d%c", &n, &c);
    if (c!='\n' || n<0 || n>6){
      printf("*** INVALIDE ENTRY *** <Only 0~6 numbers are acceptable>: ");
      if (c!='\n') clearKeyboard();
    }
  }
  return n;
}

// ContactManagerSystem:
void ContactManagerSystem(){
	int n=1;
	Contact c[MAXCONTACTS]= { 
		{ 
			{ "Rick", {'\0'}, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" } 
		},
		{ 
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" } 
		},
		{ 
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } 
		},
		{ 
			{ "Sasha", {'\0'}, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } 
		},
	};

  while(n){
    n = menu();
    if (n==0) { 
      printf("Exit the program? (Y)es/(N)o: "); 
      n=!yes();
    }  
    else if (n==1) displayContacts(c, MAXCONTACTS);
    else if (n==2) addContact(c, MAXCONTACTS);
    else if (n==3) updateContact(c, MAXCONTACTS);
    else if (n==4) deleteContact(c, MAXCONTACTS);
    else if (n==5) searchContacts(c, MAXCONTACTS);
    else if (n==6) sortContacts(c, MAXCONTACTS);
		if (n) pause();
  }
  printf("Contact Management System: terminated\n");
}

// getTenDigitPhone:
void getTenDigitPhone(char telNum[11]){
  int chk=1;
  char temp[15];

  while(chk){
    chk=0;
    scanf("%15[^\n]", temp);
    clearKeyboard();
    if (temp[10]=='\0'){
      for (int i=0; i<10; i++){
        if (temp[i]-'0'>9 || temp[i]-'0'<0) chk=1;
      }
    }
    else chk=1;
    if (chk) printf("Enter a 10-digit phone number: ");
  }
  for (int i=0; i<11; i++) telNum[i]=temp[i];
}

// findContactIndex:
int findContactIndex(const Contact c[], int n, const char cell[]){
  int idx=0;
  while(strcmp(c[idx].numbers.cell, cell)){
    idx++;
		if (idx==n) return -1;
  }
  return idx;
}

// displayContactHeader
void displayContactHeader(){
  printf("+-----------------------------------------------------------------------------+\n");
  printf("|                              Contacts Listing                               |\n");
  printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int n){
	printf("+");
	for (int i=0; i<77; i++) printf("-");
	printf("+\n");
	printf("Total contacts: ");
	printf("%d\n", n);
}

// displayContact:
void displayContact(const Contact* c){
  if (c->name.middleName[0] !='\0') 
    printf("\n %s %s %s\n", c->name.firstName, c->name.middleName, c->name.lastName);
  else printf(" %s %s\n", c->name.firstName, c->name.lastName);
  printf("    C: %-10s    H: %-10s    B: %-10s\n", 
         c->numbers.cell, c->numbers.home, c->numbers.business);
	printf("       %d %s, ", c->address.streetNumber, c->address.street);
	if(c->address.apartmentNumber>0){
		printf("Apt# %d, ", c->address.apartmentNumber);
	}
	printf("%s, %s\n\n", c->address.city, c->address.postalCode);
}

// displayContacts:
void displayContacts(const Contact c[], int n){
	int man=0;
	displayContactHeader();
	for (int i=0; i<n; i++) 
		if (c[i].numbers.cell[0]) displayContact(&c[i]), man++;
	displayContactFooter(man);
}

// searchContacts:
void searchContacts(const Contact c[], int n){
	char input[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(input);
	int idx=findContactIndex(c, n, input);
	if (idx<0) printf("*** Contact NOT FOUND ***\n");
	else displayContact(&c[idx]);
}

// addContact:
void addContact(Contact c[], int n){
	int idx=-1;
	for (int i=0; i<n; i++){
		if (c[i].numbers.cell[0]=='\0') {
			idx=i;
			break;
		}
	}
	if (idx<0) printf("*** ERROR: The contact list is full! ***\n");
	else { 
		getContact(&c[idx]); 
		printf("--- New contact added! ---\n");
	}
}

// updateContact:
void updateContact(Contact c[], int n){
	char input[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(input);
	int idx=findContactIndex(c, n, input);
	if (idx<0) printf("*** Contact NOT FOUND ***\n");
	else{
		printf("Contact found:");
		displayContact(&c[idx]);
		printf("Do you want to update the name? (y or n): ");
		if(yes()) getName(&c[idx].name);
		printf("Do you want to update the address? (y or n): ");
		if(yes()) getAddress(&c[idx].address);
		printf("Do you want to update the numbers? (y or n): ");
		if(yes()) getNumbers(&c[idx].numbers);
		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact(Contact c[], int n){
	char input[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(input);
	int idx=findContactIndex(c, n, input);
	if (idx<0) printf("*** Contact NOT FOUND ***\n");
	else{
		printf("Contact found:\n");
		displayContact(&c[idx]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes()) {
			c[idx].numbers.cell[0]=0;
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
int mycmp(const void* a, const void* b){
	return strcmp((*(Contact *)a).numbers.cell, 
								(*(Contact *)b).numbers.cell);
}
void sortContacts(Contact c[], int n){
	qsort(c, n, sizeof(Contact), mycmp);
	printf("--- Contacts sorted! ---\n");
}
