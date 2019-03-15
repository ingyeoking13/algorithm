#include <stdio.h>

char s[(int)1e5+1];
int alp[26];
int main()
{
  int n, k;scanf("%d %d", &n, &k);
  scanf("%s", s);

  for (int i=0; i<n; i++)
  {
    alp[s[i]-'A']++;
  }

  int min=1e5+1;
  for (int i=0; i<k; i++) if (alp[i]<min) min =alp[i];
  printf("%d\n", min*k);

}
