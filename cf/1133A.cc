#include <stdio.h>

int main()
{
  int h1, m1, h2, m2;

  scanf("%d:%d", &h1, &m1);
  scanf("%d:%d", &h2, &m2);
  int start = h1*60 + m1;
  int ends = h2*60 + m2;

  int mid = (start+ends)/2;

  int h3 = mid/60;
  int m3 = mid%60;

  char h[3], m[3];
  h[0] = '0'+h3/10;
  h[1] = '0'+h3%10;
  h[2] =0;
  m[0] = '0'+m3/10;
  m[1] = '0'+ m3%10;
  m[2] = 0;

  printf("%s:%s\n", h, m);

}
