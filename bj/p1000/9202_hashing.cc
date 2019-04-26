#include <iostream>
#include <string.h>

#define MAX_TABLE (int)6e5

using namespace std;
struct Hash
{
  int idx;
  Hash() { idx=-1; }
};
char words[(int)3e5][9];
Hash hashes[MAX_TABLE];

char boggle[4][5]; // input 
bool v[4][4];
bool wordChk[(int)3e5*9];

int score_table[10] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int Score;
char ansWord[9];
int mxLen;
char tempWord[9];
int hit;

unsigned long hashFunc(const char *str)
{
  unsigned long hash = 5381;
  int c;
  while (c = *str++) hash = (((hash << 5) + hash) + c) % MAX_TABLE; 
  return hash % MAX_TABLE;
}

void go (int x, int y , int depth)
{
  if ( depth == 9) return;

  tempWord[depth-1] = boggle[x][y];
  tempWord[depth] = 0;

  int idx = hashFunc(tempWord);
  while ( hashes[idx].idx !=  -1 )
  {
    int iidx = hashes[idx].idx;
    if ( strcmp (words[iidx], tempWord) == 0 )
    {
      if ( wordChk[iidx] ) break;
      wordChk[iidx]=true;
      Score+=score_table[depth];
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
    idx++;
    idx%=MAX_TABLE;
  }

  for (int i=-1; i<=1; i++)
  {
    for (int j=-1; j<=1; j++)
    {
      int nx = x +i, ny = y+j;
      if ( nx < 0 || ny <0 || nx >=4 || ny >= 4 ) continue;
      if( v[nx][ny] ) continue;

      v[nx][ny]=1;
      go(nx, ny, depth+1);
      v[nx][ny]=0;
    }
  }
}

int main()
{
  int n;
  cin >> n;

  for (int i=0; i<n; i++)
  {
    cin >> words[i];
  }

  /* HASHING */
  for (int i=0; i<n; i++)
  {
    int idx = hashFunc(words[i]);
    while ( hashes[idx].idx != -1 )
    {
      idx++;
      idx%=MAX_TABLE;
    }
    hashes[idx].idx = i;
  }

  /* End of Creating */

  int T;
  cin >> T;
  for (int test_case=1; test_case<=T; test_case++)
  {

    memset(wordChk, false, sizeof(wordChk));
    memset(ansWord, 0, sizeof(ansWord));
    Score= hit = mxLen= 0;
    for (int i=0; i<4; i++) cin >> boggle[i];
    for (int i=0; i<4; i++)
    {
      for (int j=0; j<4; j++)
      {
        v[i][j]=1;
        go(i,j,1);
        v[i][j]=0;
      }
    }
    cout << Score << " " << ansWord << " " << hit << "\n";
  }
}
