#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ans;
vector<int> zero;
vector<int> rep;
char a[(int)5e3+1];
char b[(int)5e3+1];
int main()
{
  int n;
  scanf("%d", &n);

  scanf("%s", a);
  scanf("%s", b);

  int acnt = 0, bcnt=0;
  int zerocnt = 0;
  int stat = 1;

  for (int i=0; i<n; i++)
  {
    if ( a[i] == '0' && b[i] == '0')
    {
      if ( stat == 1 ) zero.push_back(i+1);
      stat = 3-stat;
      zerocnt ++;
      continue;
    }

    if ( a[i] == '1' && b[i] == '1' ) rep.push_back(i+1);
    else if ( a[i] == '1' ) ans.push_back(i+1);
    else bcnt++;
  }


  if (  zero.size()*2 != zerocnt )  return !printf("-1\n");

  while ( ans.size() < bcnt ) 
  {
    ans.push_back( rep.back() );
    rep.pop_back();
  }

  while ( bcnt < ans.size() )
  {
    rep.pop_back();
    bcnt++;
  }
  if ( rep.size() % 2 == 1 ) return !printf("-1\n");

  for (int i=0; i<zero.size(); i++ ) printf("%d ", zero[i]);
  for ( int i=0; i<ans.size(); i++)  printf("%d ", ans[i]);
  for ( int i=0; i<rep.size()/2; i++)  printf("%d ", rep[i]);
  printf("\n");


}
