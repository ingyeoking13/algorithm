#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int x[201][201];
int dp[205][205];
int dest[501], up[501], down[501];

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);

   int t;
   cin >> t;
   while (t--)
   {
      memset(x, 0, sizeof x);
      int n, k, i, j, p;
      cin >> n >> k;
      for (i = 0; i < n; i++)
         cin >> dest[i] >> down[i] >> up[i];

      for (i = 1; i <= 200; i++)
         for (j = i; j <= 200; j++)
            for (p = 0; p < n; p++)
               if (dest[p] >= i && dest[p] <= j)
                  x[i][j] += min(up[p] * (dest[p] - i), down[p] * (j - dest[p]));

      for (i = 1; i <= 200; i++)
      {
         dp[i][1] = x[1][i];
         for (j = 2; j <= min(i, k); j++)
         {
            dp[i][j] = (int)1e9;
            for (p = 1; p < i; p++)
               dp[i][j] = min(dp[i][j], dp[p][j - 1] + x[p][i]);
         }
      }

      int ans = (int)1e9;
      for (i = k; i <= 200; i++)
      {
         int sum = 0;
         for (j = 0; j < n; j++)
            if (dest[j] >= i)
               sum += up[j] * (dest[j] - i);
         ans = min(ans, dp[i][k] + sum);
      }
      cout << ans << '\n';
   }
}
