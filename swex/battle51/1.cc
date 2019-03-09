#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

  scanf("%d\n", &T);
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int n, m;
    scanf("%d%d",&n, &m);

    vector<int> v(21,0);

    for (int i=0; i<n; i++)
    {
      int score=0;
      for (int j=0; j<m; j++)
      {
        int in;
        scanf("%d", &in);
        score+=in;
      }
      v[score]++;
    }

    int people, solved;
    for (int i=0;i<=20; i++)
    {
      if ( v[i] > 0 )  solved = i, people = v[i];
    }
    printf("#%d %d %d\n", test_case, people, solved); 

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
