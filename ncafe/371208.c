#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[30], ID_num[30], major[30];
	struct student *next;
}student;

void ADD();          //prototype
void DELETE();
void EDIT();
void PRINT_ALL();
void SEARCH();
void pause();
void clrBuf();

student* first=0;
student* last=0;

int main (void) {

	FILE* fp = fopen("student.txt", "a+");          //파일에서 데이터 읽어옴  

	char name[30], ID[30], major[30];
	while(~fscanf(fp, "%s %s %s", name, ID, major)){
		student* new = (student*) malloc(sizeof(student));

		strcpy(new->name, name);
		strcpy(new->ID_num, ID);
		strcpy(new->major, major);
		new->next=0;

		if(first == NULL) last = first = new;
		else last->next=new, last=new;
	}
	fclose(fp);

	int select = 0;
	printf(">> Student Management System <<\n\n");
	for( ; ; ) {

  printf("========Menu========\n");           //메뉴 선택  
  printf("1. Add\n"
      	 "2. Delete\n"
      	 "3. Modify\n"
      	 "4. Search\n"
      	 "5. Display all\n"
      	 "6. End program\n");
  printf("====================\n");

  printf("Select a function >> ");
  scanf("%d", &select); clrBuf();

  switch (select) {
   case 1: ADD(); break;
   case 2: DELETE(); break;
   case 3: EDIT(); break;
   case 4: SEARCH(); break;
   case 5: PRINT_ALL(); break;
   case 6: return 0;
   default : printf("incorrect input"); break;
  }
	pause();
 }
 return 0;
}

void clrBuf(){
	while(getchar()!='\n');
}

void pause(){
	printf("(Please press Enter ....)\n");
	clrBuf();

}

/*   함수 정의  */ 
void ADD(void) {

	FILE* fp = fopen("student.txt", "a");
	student* new = (struct student*) malloc(sizeof(struct student));
	if(first == NULL) last=first = new;
	else last->next=new, last=new;

	printf("Enter name: ");
	scanf("%s", new->name); clrBuf();
	fprintf(fp, "%s ", new->name);

	printf("Enter ID number: ");
	scanf("%s", new->ID_num); clrBuf();
	fprintf(fp, "%s ", new->ID_num);

	printf("Enter major: ");
	scanf("%s", new->major); clrBuf();
	fprintf(fp, "%s\n", new->major);

	new->next = NULL;

	fclose(fp);
	printf("Add completed!\n");
}

void DELETE(void) {

	char name_del[30];
	printf("Enter the name of the student you want to delete: ");
	scanf("%s", name_del); clrBuf();

	student* current = first,* previous=0;
	while(current != NULL){

		if(strcmp(name_del,current->name) == 0){
			if(previous == NULL) first = current->next;
			else {

				if (current == last) last = previous;
				previous->next = current->next;
				free(current);
			}

			if (first==NULL) last=0;
		}
		else previous = current;
		current = current->next;
	}

	FILE* fp = fopen("student.txt", "w");
	current = first;
	while(current != NULL) { 

		fprintf(fp, "%s %s %s\n", current->name, current->ID_num, current->major);
		current = current->next;

	}

	fclose(fp);
	printf("Delete completed!\n");

}

void EDIT(void) {

  char name_edit[30];
  printf("Enter the name of the student you want to modify: ");
	scanf("%s", name_edit); clrBuf();

	student* current = first;
	
	while(current) {

		if(strcmp(name_edit, current->name) == 0) {
			printf("Enter new name: ");
			scanf("%s", current->name);  clrBuf();

			printf("Enter new ID number: ");
			scanf("%s", current->ID_num); clrBuf();

			printf("Enter new major: ");
			scanf("%s", current->major); clrBuf();
		}

		current = current->next;
	}

	FILE* fp = fopen("student.txt", "w");
	current = first;

	while(current) { 

		fprintf(fp, "%s %s %s\n", current->name, current->ID_num, current->major);
		current = current->next;

	}

	fclose(fp);
}

void SEARCH(void) {

	char name_search[30];
	printf("Enter the name of student you want to search: ");
	scanf("%s", name_search); clrBuf();

	student* current = first;
	while(current != NULL) {

		if(strcmp(name_search, current->name) == 0) {
			printf("%s %s %s\n", current->name, current->ID_num, current->major);
		}

		current = current->next;
	}
}

void PRINT_ALL(void) { 
	student* current = first;
	while(current != NULL) {

		printf("%s %s %s\n", current->name, current->ID_num, current->major);
		current = current->next;
	}
}
