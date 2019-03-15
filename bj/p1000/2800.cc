#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

char s[(int)2e3+5];
char chk[(int)2e3+5];
int len;
pair<int, int> pos[10];
set<string> ans;

bool del[10];

void go( int cur, int& total_id)
{
  if ( cur > total_id ) 
  {
    int cnt=0;
    for (int i=0; i<=total_id; i++)
    {
      if ( del[i] == 0 ) continue;
      chk[pos[i].first] = chk[pos[i].second] = 1;
      cnt++;
    }

    if (cnt == 0) return;

    string str;
    for (int i=0; i<len; i++)
    {
      if (chk[i]) continue;
      str += s[i];
    }
    ans.insert(str);
    memset(chk, 0, sizeof(chk));

    return;
  }

  go( cur+1, total_id);
  del[cur]=1;
  go( cur+1, total_id);
  del[cur]=0;

}

int main() 
{
  scanf("%s", s);
  len = strlen(s);

  stack<int> st;
  int id =-1;

  for (int i=0; i<len; i++)
  {
    if ( s[i] == '(' )
    {
      id++;
      st.push(id);
      pos[id].first = i;
    }
    else if ( s[i] == ')' )
    {
      int pairId = st.top();
      st.pop();
      pos[pairId].second = i;
    }
  }

  go(0, id);
  for (auto s: ans) printf("%s\n", s.c_str());
}
