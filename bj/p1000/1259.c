#include <stdio.h>
#include <string.h>

int main()
{
  while(1)
  {
    char input[6];
    scanf("%s", input);

    if (input[0] =='0' ) break;

    int len= strlen(input);
    int chk=1;
    for (int i=0; i<len/2; i++)
    {
      if ( input[i] != input[len-1-i] )
      {
        printf("no\n");
        chk=0;
        break;
      }
    }
    if (chk) printf("yes\n");
  }
}
