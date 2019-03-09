#include <stdio.h>
#include <vector>

using namespace std;

int a[1001];
int ans[20][20];
int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n*n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    a[tmp]++;
  }

  if (n%2 == 0)
  {
    vector<int> cand;
    for (int i=0; i<=1000; i++)
    {
      if ( a[i]%4 != 0) return !printf("NO\n");
      for (int j=0; j<a[i]/4; j++)
      {
        cand.push_back(i);
      }
    }

    int cnt=0;

    for (int i=0; i<n/2; i++)
    {
      for (int j=0; j<n/2; j++)
      {
        ans[i][j] = cand[cnt];
        ans[n-i-1][j] = cand[cnt];
        ans[i][n-1-j] = cand[cnt];
        ans[n-1-i][n-1-j] = cand[cnt++];
      }
    }
  }
  else if (n%2 == 1)
  {

    int four = 0,two=0,one=0;
    vector<int> four_cand, two_cand, one_cand;

    for (int i=1; i<=1000; i++)
    {
      if ( a[i]/4 > 0)
      {
        int kk = a[i]/4;
        four += kk;
        for (int j=0; j<kk; j++) four_cand.push_back(i);

        a[i] -= kk*4;

        if ( four > (n/2)*(n/2))
        {
          int diff = four - (n/2)*(n/2);
          for (int j=0; j<diff; j++) four_cand.pop_back();

          four = (n/2)*(n/2);
          a[i] += (diff*4);
        }
      }

      if ( a[i]/2 > 0) 
      {
        int kk = a[i]/2;

        two += kk;

        a[i] -= kk*2;
        for (int j=0; j<kk; j++) two_cand.push_back(i);
      }

      if ( a[i] >0 )
      {
        one += a[i]; 
        one_cand.push_back(i);
      }
    }

    if ( one != 1 ) return !printf("NO\n");
    if ( four < (n/2)*(n/2)) return !printf("NO\n");
    if ( two != (n/2)*2 ) return !printf("NO\n");

    for (int i=0; i<=n/2; i++)
    {
      for (int j=0; j<=n/2; j++)
      {
        if ( i==n/2 && j==n/2) ans[i][j] = one_cand[0];
        else if ( i==n/2 )
        {
          int num = two_cand.back();
          two_cand.pop_back();
          ans[i][j] = num;
          ans[i][n-1-j] = num;
        }
        else if ( j==n/2 )
        {
          int num = two_cand.back();
          two_cand.pop_back();
          ans[i][j] = num;
          ans[n-1-i][j] = num;
        }
        else
        {
          int num = four_cand.back();
          four_cand.pop_back();
          ans[i][j] = num;
          ans[n-i-1][j] = num;
          ans[i][n-1-j] = num;
          ans[n-1-i][n-1-j] = num;
        }
      }
    }
  }
  printf("YES\n");
  for (int i=0;i<n; i++)
  {
    for (int j=0; j<n; j++)
    {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
}
