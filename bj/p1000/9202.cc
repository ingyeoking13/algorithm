#include <iostream>
#include <string.h>

using namespace std;
struct Trie
{
  Trie* al[26];
  bool word;
  bool hit;
  Trie() { word = false; for (int i=0; i<26; i++) al[i] =0; hit=0;}
};
Trie* root;

char boggle[4][5]; // input 
bool v[4][4];

int score_table[10] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int Score;
char ansWord[9];
int mxLen;
char tempWord[9];
int hit;

void go (int x, int y , int depth, Trie* &cur)
{
  if ( depth == 9) return;

  tempWord[depth-1] = boggle[x][y];
  tempWord[depth] = 0;

  if (cur->word) // does exist in Trie
  {
    if ( !cur->hit )  // check if word duplicate in same test_case
    {
      cur->hit=true;
      Score += score_table[depth];
      hit++;

      int tmpLen = strlen(tempWord);

      if ( mxLen < tmpLen)
      {
        strcpy(ansWord, tempWord);
        mxLen = tmpLen;
      }
      else if ( mxLen == tmpLen )
      {
        if ( strcmp(ansWord, tempWord) >0) strcpy(ansWord, tempWord);
      }
    }
  }

  for (int i=-1; i<=1; i++)
  {
    for (int j=-1; j<=1; j++)
    {

      int nx = x +i, ny = y+j;
      if ( nx < 0 || ny <0 || nx >=4 || ny >= 4 ) continue;
      if( v[nx][ny] ) continue;

      Trie* next = cur->al[boggle[nx][ny]-'A'];
      if ( next )
      {
        v[nx][ny]=1;
        go(nx, ny, depth+1, next);
        v[nx][ny]=0;
      }
    }
  }
}

void init(Trie* cur)
{
  cur->hit=false;
  for (int i=0; i<26; i++)
  {
    if (cur->al[i]) init(cur->al[i]);
  }
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;

  char words[(int)3e5][9];
  for (int i=0; i<n; i++)
  {
    cin >> words[i];
  }

  /* Creating Trie */
  root = new Trie();
  for (int i=0; i<n; i++)
  {
    int len = strlen(words[i]);

    Trie* cur = root;
    for (int j=0; j<len; j++)
    {
      int idx = (words[i][j]-'A');

      if ( cur->al[idx] == 0 )
      {
        cur->al[idx] = new Trie();
      }
      cur= cur->al[idx];
    }
    cur->word = 1;
  }

  /* End of Creating */

  int T;
  cin >> T;
  for (int test_case=1; test_case<=T; test_case++)
  {
    init(root); // trie hit initializing

    memset(ansWord, 0, sizeof(ansWord));
    Score= hit = mxLen= 0;
    for (int i=0; i<4; i++)
    {
      cin >> boggle[i];
    }

    for (int i=0; i<4; i++)
    {
      for (int j=0; j<4; j++)
      {
        Trie* cur = root;
        Trie* next = cur->al[boggle[i][j]-'A'];

        if ( next ) 
        {
          v[i][j]=1;
          go(i,j,1, next);
          v[i][j]=0;
        }
      }
    }
    cout << Score << " " << ansWord << " " << hit << "\n";
  }
}
