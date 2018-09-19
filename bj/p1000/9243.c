#include <stdio.h>
#include <string.h>

char a[1003], b[1003];
int main(){
  int n; scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  n%=2;
  int len = strlen(a);
  if (n){
    for (int i=0; i<len; i++){
      if ( a[i] != b[i]);
      else return !printf("Deletion failed\n");
    }
  }
  else {
    for (int i=0; i<len; i++){
      if ( a[i] == b[i] );
      else return !printf("Deletion failed\n");
    }
  }
  printf("Deletion succeeded\n");

}
