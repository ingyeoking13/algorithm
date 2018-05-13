#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MX_BUF 100000
#define MX_WSIZE 1000

typedef struct 
{ 
	struct Alphabet* head; 
	struct Alphabet* tail; 
}List; 

typedef struct Alphabet
{
	char al;
	struct Alphabet* next; 
	struct String* head;
	struct String* tail;
} Alphabet;

typedef struct String
{
	int id;
	char word[MX_WSIZE];
	struct String* next;
}String;

String* create_String(char* word, int id)
{
	String* string = (String*)malloc(sizeof(String));
	strcpy(string->word, word);
	string->id =id; 
	string->next = NULL;
	return string;
}

Alphabet* create_Alphabet(char c)
{
	Alphabet* alpha = (Alphabet*) malloc(sizeof(Alphabet));
	alpha->al = c; 
	alpha->next = NULL; 
	alpha->head = alpha->tail = NULL;
	return alpha;
}

List* create_List()
{
	List* list = (List*) malloc(sizeof(List));
	list->head = list->tail= NULL; 
	return list;
}

void push_Alphabet(List* list, char c) // push Alphabet into List
{
	Alphabet* alpha = create_Alphabet(c);

	if ( list->head == NULL)
	{
		list->head = list->tail = alpha;
		return;
	}

	list->tail->next = alpha;
	list->tail = alpha;
};

void push_String_toAlphabet(Alphabet* alpha, char* str, int id)
{
	//push string -> in to Alphabet List 
	String* string = create_String(str, id);

	if (alpha->head == NULL)
	{
		alpha->head = alpha->tail = string;
		return;
	}

	alpha->tail->next = string;
	alpha->tail = string;
}

void push_String_toList(List* list, char* str, int id)
{
	// Find alphabet node before push string to Alphabet list

	Alphabet* alpha = list->head;

	while(alpha != NULL)
	{
		if( alpha->al == str[0] ) // we find match character!
		{
			push_String_toAlphabet(alpha, str, id);
			break;
		}
		else alpha = alpha->next; //index alpha node move
	}
}

void Sch(List* list, char* str)
{
	Alphabet* alpha = list->head;

	while(alpha != NULL)
	{

		if(alpha->al == str[0] ) 
		{
			String* string = alpha->head;

			while(string)
			{
				printf("%d ", string->id);
				if (strcmp(string->word, str) == 0) 
				{
					printf("\n");
					return;
				}
				string = string->next;
			}

		}
		alpha = alpha->next;
	}
	printf("\n");
}

void Del(List* list, char* str)
{
	Alphabet* alpha = list->head;

	while(alpha != NULL)
	{

		if ( alpha->al == str[0])
		{
			String* string = alpha->head;
			String* before=0;

			while(string){

				if(strcmp(string->word, str) == 0){

					if(before) before->next= string->next; // if this string node is not head...
					else       alpha->head = string->next; // if this string node is head

					if(string->next == 0) alpha->tail =before; // if this string node is tail

					free(string);
					return;

				}
				before=string;
				string= string->next;
			}
		}
		alpha = alpha->next;
	}
}

void Sub(List* list, char* from, char* to)
{
	Alphabet* alpha = list->head;

	while(alpha != NULL)
	{

		if ( alpha->al == from[0] )
		{
			String* string = alpha->head;

			while(string)
			{

				if( strcmp(string->word, from) ==0)
				{
					push_String_toList(list,  to, string->id);
					Del(list, from);
					return;
				}

				string = string->next;
			}
		}
		alpha  = alpha->next;
	}
}


void printAll(List* list)
{
	Alphabet* alpha = list->head;

	while(alpha != NULL)
	{
		printf("nowAlp: %c\n", alpha->al);

		String* string = alpha->head;

		while(string)
		{

			printf("%s %d\n", string->word, string->id);
			string= string->next;
		}

		alpha= alpha->next;
		printf("\n");
	}
}

int main()
{

	List* list = create_List();

	for (int i=0; i<26; i++) {
		push_Alphabet(list,'a'+i);
	}
	for (int i=0; i<26; i++) {
		push_Alphabet(list, 'A'+i);
	}
	push_Alphabet(list, '.');

	//init is over

	//get input and token word .. using strtok? ... hmmmmm no 
	char input[MX_BUF], word[MX_WSIZE];
	fgets(input, MX_BUF, stdin);

	int len = strlen(input);
	if (input[len-1] == '\n') // if human input .. carriage return exist
	{
		input[--len]=0;
	}

	int id=0, word_len=0, chk=0;

	for (int i=0; i<=len; i++){

		if (input[i] == ' ' || input[i] == '\0' )
		{
			if(chk)  //chk if we get word
			{ 
				word[word_len++]='\0';  // insert null byte
				push_String_toList(list, word, id); 
				id++; // id up up ~
				chk=0;
				word_len=0; 
			}
		}
		else  // if we have character 
		{
			word[word_len++]=input[i];  // store it 
			chk=1; 
		}
	}

	printAll(list);
	char query[MX_WSIZE];

	while(scanf("%s", query)){
		if (query[0] == '0')
		{
			return 0;
		}
		if (strcmp(query, "sub") == 0)
		{
			char f[MX_WSIZE], t[MX_WSIZE];
			scanf("%s %s", f, t);
			Sub(list, f, t);

		}
		else if (strcmp(query, "sch") == 0)
		{
			scanf("%s", word);
		  Sch(list, word);
		}
		else if (strcmp(query, "del") == 0)
		{
			scanf("%s", word);
			Del(list, word);
		}
	}
}
