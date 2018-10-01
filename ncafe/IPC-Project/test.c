#include <stdio.h>

void clearKeyboard(void) {
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// getInt function definition goes here:
int getInt(void) {

 int value;
 char NL = 'x';
 while(NL != '\n') { 
  scanf("%d%c", &value, &NL);
  if(NL != '\n')

  {

   clearKeyboard();

   printf("*** INVALID INTEGER *** <Please enter an integer>: ");

  }

 } 

 return value;

}



// getIntInRange function definition goes here:

int getIntInRange(int a, int b) 

{

 int x = getInt(); 

 while(x<a || x>b)

 {

  printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", a, b);

  x = getInt();

 }

 return x;

}

int main(){
	getIntInRange(250, 500);

}
