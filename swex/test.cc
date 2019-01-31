#include <stdio.h>

int main(void)
{

  int a[26];
  char b[1000001];

  int j = 0;
  int check =0;
  int max = 0;


  for(int i = 0; i < 26; i ++){
    a[i] = 0;
  }

  scanf("%s" , b);

  for(int i = 0; b[i]!= '\0'; i++)
  {

    if(b[i] > 90)
    {
      b[i] = b[i] - 32;
    }

    a[b[i]-65] += 1; 


  }

  int temp = 0;

  while(temp < 26)
  {
    if(a[max] < a[temp])
    {
      max = temp;
      check = 0;
    }
    else if(a[max] == a[temp]){
      check = 1;

    }

    temp++;
  }

  if(check == 1)
  {
    printf("?\n");
  }

  else 
  {
    printf("%c\n", (char)(max + 65));
  }








}


