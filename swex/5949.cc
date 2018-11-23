#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  for (int tt=1; tt<=T; tt++)
  {
    char f[(int)1e5+2];
    char t[(int)1e5+2];
    scanf("%s%s", f, t);

    int flen = strlen(f);
    int tlen = strlen(t);

    if (flen!= tlen )
    {
      printf("#%d %d\n", tt, -1);
      continue;
    }

    int fa[(int)1e5];
    int falen=0;

    for (int i=0; i<flen; i++)
    {
      if (f[i] == 'a') fa[falen++]=i;
    }

    int ta[(int)1e5];
    int talen=0;

    for (int i=0; i<tlen; i++)
    {
      if (t[i] == 'a') ta[talen++]=i;
    }

    if (falen != talen)
    {
      printf("#%d %d\n", tt, -1);
      continue;
    }

    long long ans=0;

    for (int i=0; i<falen; i++)
    {
      int tmp = fa[i] - ta[i];
      if ( tmp <0 ) tmp = -tmp;

      ans+=(long long)tmp;
    }

    printf("#%d %lld\n", tt, ans);
  }

}
