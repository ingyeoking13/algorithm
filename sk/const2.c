#include <stdio.h>

char *strcp(char* dest, const char* src){
	return dest=(char *)src;
}

int main(){
	char *name="abcdefg";
	char *name2="";

	name2=strcp(name2, name);
	printf("%s\n", name2);
}
