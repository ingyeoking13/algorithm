class Solution {
public:
  int d[501][501];

  bool go(int cnt, int l, int r, int A, int B, int sz, vector<int>& piles)
  {
    if (d[l][r]>=0) return d[l][r];

    if ( cnt == sz)
    {
      if ( A>B) return 1;
      return 0;
    }

    if (d[l][r] = go(cnt+1, l+1, r, A+piles[l], B, sz, piles))
    {
      return d[l][r];
    }

    if (d[l][r] = go(cnt+1, l, r+1, A, B+piles[r], sz, piles))
    {
      return d[l][r];
    }
    return d[l][r];
  }

  bool stoneGame(vector<int>& piles) {
    memset(d, -1, sizeof(d));
    int ret = go(0, 0, piles.size()-1, 0, 0, piles.size(), piles);
    return ret;
  }
};
