/*
  https://www.acmicpc.net/problem/1786
*/
#include <stdio.h>
#include <string.h>

#define MAXLEN (int)1e6

using namespace std;

struct KMP
{
  int pi[MAXLEN];
  char pattern[MAXLEN+3];
  char ori[MAXLEN+3];

  int ansLen;
  int ans[MAXLEN];

  KMP() { ansLen = 0; } 
  void build_pi()
  {
    int begin = 1, matched=0;
    int len = strlen(pattern);

    while( begin+matched <len )
    {
      if ( pattern[begin+matched] == pattern[matched])
      {
        pi[ begin+matched ] = matched+1;
        matched++;
      }
      else
      {
        if (matched == 0) begin++;
        else
        {
          begin += matched - pi[matched-1];
          matched = pi[matched-1];
        }
      }
    }
  }

  int* return_ans() { return ans; }

  void search()
  {
    build_pi();

    int begin=0, matched=0;

    int len =strlen(ori);
    int patlen = strlen(pattern);

    while( begin + matched < len )
    {
      if ( matched < patlen && ori[begin+matched] == pattern[matched] )
      {
        matched++;
        if ( matched == patlen) ans[ansLen++] = begin;
      }
      else
      {
        if (matched == 0) begin++;
        else
        {
          begin += matched - pi[matched -1];
          matched = pi[matched-1];
        }
      }
    }
  }
};

KMP myKmp;

int main()
{

  fgets(myKmp.ori, MAXLEN+3, stdin); 
  fgets(myKmp.pattern, MAXLEN+3, stdin);

  int len =strlen(myKmp.ori);
  if ( myKmp.ori[len-1] == '\n' ) myKmp.ori[len-1]=0;
  len = strlen(myKmp.pattern);
  if (myKmp.pattern[len-1] == '\n' ) myKmp.pattern[len-1] =0;

  myKmp.search();

  printf("%d\n", myKmp.ansLen);
  int* ans = myKmp.return_ans();
  for (int i=0; i<myKmp.ansLen; i++)
  {
    printf("%d ", ans[i]+1);
  }
  printf("\n");
}
