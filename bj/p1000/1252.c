#include <stdio.h>
#include <string.h>

char s1[81], s2[81];
char s3[160];
void go(int now)
{
  if (now <0) return;
  printf("%c", s3[now]);
  go(now-1);
}

int main()
{
  scanf("%s %s", s1, s2);

  int len1= strlen(s1), len2= strlen(s2);

  int i = len1-1, j = len2-1;
  int len3=0;

  int next=0;
  while( i >=0 && j>=0 )
  {
   int tmp = (s1[i]-'0' + s2[j]-'0')+next;
   next = tmp/2;
   tmp = tmp%2;
   s3[len3++] = tmp+'0';
   i--, j--;
  }
  while (i>=0 )
  {
   int tmp = (s1[i]-'0')+next;
   next = tmp/2;
   tmp = tmp%2;
   s3[len3++] = tmp+'0';
   i--;
  }
  while (j>=0)
  {
   int tmp = (s2[j]-'0')+next;
   next = tmp/2;
   tmp = tmp%2;
   s3[len3++] = tmp+'0';
   j--;
  }
  if ( next ) s3[len3++] = '1';

  int start=len3-1;
  while (s3[start] == '0' && start>0) start--;
  go(start);
  printf("\n");
}
