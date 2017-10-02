#include <stdio.h>

int main(){

	int i, alot;
	char ch, word;
	int arr[26];

	//init
	alot=0;
	for (i=0; i<26;i++) arr[i]=0;

	while((ch=getchar())!=EOF)
	{	
		if (ch<'a')
			arr[ch-'A']++;
		else arr[ch-'a']++; 
	}
	
	for (i=0; i<26; i++){
		if (alot==arr[i]) { word=63; }
		else if (alot<arr[i]) { alot=arr[i]; word=i+65; }
	}

	printf("%c\n", word);

	return 0;
}
