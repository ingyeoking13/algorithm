/*
   TRIE 
   https://www.acmicpc.net/problem/5446
*/
#include <iostream>
#include <string.h>
#define ChildSize 63

using namespace std;


struct TrieNode
{
  int child[ChildSize];
  bool word;
  bool noterase;

  TrieNode()
  {
    for (int i=0; i<ChildSize; i++) child[i] = -1;
    word = false;
    noterase = false;
  };

  void init()
  {
    for (int i=0; i<ChildSize; i++) child[i] = -1;
    word = false;
    noterase = false;
  };
};

int ret(char c)
{
  if ('a' <= c && c <= 'z' ) return c-'a';
  if ('A' <= c && c<= 'Z' ) return c-'A'+26;
  if ('0' <= c && c <= '9' ) return c-'0'+52;
  return 62;
}

TrieNode trie[2000*20];
int idx;

int go (int cur )
{
  if ( trie[cur].noterase )
  {
    int ret =0;
    if (trie[cur].word ) ret++;

    for (int i=0; i<ChildSize; i++)
    {
      if ( trie[cur].child[i] == -1 ) continue;
      ret += go( trie[cur].child[i]);
    }
    return ret;
  }
  else return 1;
}

int main()
{
  int T;
  cin >> T;
  while ( T-- )
  {

    for (int i=0; i<2000*20; i++) trie[i].init();
    idx = 0;
    int n;
    cin >> n;

    while (n--)
    {
      char input[21];
      cin >> input;

      int len = strlen(input);
      int cur = 0;
      for (int i=0; i<len; i++)
      {
        int r = ret(input[i]);
        if ( trie[cur].child[r] == -1 ) trie[cur].child[r] = ++idx;
        cur = trie[cur].child[r];
      }
      trie[cur].word=true;
    }

    cin >> n;
    while (n-- )
    {

      char input[21];
      cin >> input;

      int len = strlen(input);
      int cur = 0;
      trie[cur].noterase=true;

      for (int i=0; i<len; i++)
      {
        int r = ret(input[i]);
        if ( trie[cur].child[r] == -1 ) trie[cur].child[r] = ++idx;
        cur = trie[cur].child[r];
        trie[cur].noterase=true;
      }
    }
    int ans = go(0);
    cout << ans <<"\n";
  }
}
