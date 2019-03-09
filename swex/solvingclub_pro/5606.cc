#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct Pos
{
  int x, y;
  Pos(int x, int y): x(x), y(y) {};
};

int ret(char c)
{
  if ( c == 'S') return 1;
  else if ( c== 'N') return 2;
  else if ( c== 'W') return 3;
  else if ( c=='E') return 6;
}

bool Opposite(char c, char c2)
{
  int a = ret(c), b = ret(c2);
  if ( a < b) { a^=b; b^=a; a^=b; };
  return b*2 == a;
}

int main(int argc, char** argv)
{
	int test_case;
	int T; 
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        char s[(int)1e3+2], s2[(int)1e3+2];
        cin >> s+1 >> s2+1;

        bool v[(int)1e3+1][(int)1e3+1];
        memset(v, 0, sizeof(v));

        bool ans =false;
        queue<Pos> q;
        q.push(Pos(0, 0));
        v[0][0]=1;

        while(!q.empty())
        {
          Pos now = q.front();
          q.pop();

          int i = now.x;
          int j = now.y;

          if ( i== n && j == n)
          {
            ans=true;
            break;
          }

          if ( i+1 <=n && j+1<=n && s[i+1] == s2[j+1] ) 
          {
            if ( v[i+1][j+1] ) continue;
            v[i+1][j+1]=1;
            q.push(Pos(i+1, j+1));
            continue;
          }

          if ( j+1<=n && Opposite( s[i], s2[j+1] ) ) 
          {
            if ( !v[i-1][j+1] )
            {
              v[i-1][j+1]=1;
              q.push(Pos(i-1, j+1));
            }
          }
          else if ( j+1<=n && !v[i][j+1] )
          {
            v[i][j+1]=1;
            q.push(Pos(i, j+1));
          }

          if ( i+1<=n && Opposite( s[i+1], s2[j] ) ) 
          {
            if ( !v[i+1][j-1])
            {
              v[i+1][j-1]=1;
              q.push(Pos(i+1, j-1));
            }
          }
          else if ( i+1<=n && !v[i+1][j] )
          {
            v[i+1][j]=1;
            q.push(Pos(i+1, j));
          }
        }
        
        cout << "#" << test_case << " ";
        if ( v[n][n] ) cout << "YES\n";
        else cout <<"NO\n";
	}
	return 0;
}
