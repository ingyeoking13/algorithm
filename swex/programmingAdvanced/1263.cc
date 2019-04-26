#include <iostream>

using namespace std;

struct ppair
{
  int dist, node;
  ppair() {} ;
  ppair(int a, int b ) : dist(a), node(b) {};
};

void sswap(ppair* a, ppair* b)
{
  ppair tmp = *a;
  *a = *b;
  *b = tmp;
}

struct priority_queue
{
  ppair array[(int)1e3];
  int len;
  priority_queue() :len(0) {};

  bool empty() { return len==0; }
  void push(ppair a)
  {
    sswap(&array[0], &array[len]);
    array[0] = a;
    len++;
    heapify(0, len);
  }

  void heapify(int idx, int len)
  {
    ppair mx = array[idx];
    int mxidx = idx;

    int left = idx*2 +1, right = idx*2 +2;
    if ( left < len &&  mx.dist < array[left].dist) mxidx = left;
    mx = array[mxidx];
    if ( right < len && mx.dist < array[right].dist ) mxidx = right;

    if ( mxidx != idx)
    {
      sswap(&array[mxidx], &array[idx]);
      heapify(mxidx, len);
    }
  }

  void buildheap() { for (int i=len/2; i>=0; i--) heapify(i, len); }

  ppair top()
  {
    if ( len == 0 ) { cout << "ERROR\n"; return array[0]; }
    return array[0];
  }

  void pop()
  {
    sswap(&array[0], &array[len-1]);
    len--;
    heapify(0, len);
  }

};

int main()
{
  int T;
  cin >> T;
  int tt=0;
  int edge[1000][1000];
  int len[1000];
  int d[1000][1000];

  while(++tt<=T)
  {
    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
      len[i] = 0;
      for (int j=0; j<n; j++)
      {
        int tmp;
        cin >> tmp;
        if ( tmp )
        {
          edge[i][len[i]] = j;
          len[i]++;
        }
      }
    }

    priority_queue pq;
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++) d[i][j] = 0x7f7f7f7f;
      d[i][i] =0;
      pq.push(ppair(d[i][i], i));

      while ( ! pq.empty() )
      {
        ppair cur = pq.top(); 
        int now = cur.node;
        int dist = -cur.dist;
        pq.pop();

        if ( d[i][now] < dist ) continue;
        for (int j=0; j<len[now]; j++)
        {
          int nxt = edge[now][j];
          int nxtdist = dist +1;
          if ( nxtdist < d[i][nxt] ) 
          {
            d[i][nxt] = nxtdist;
            pq.push(ppair(-nxtdist, nxt));
          }
        }
      }
    }

    int ans =2e9;
    for (int i=0; i<n; i++)
    {
      int tmp=0;
      for (int j=0; j<n; j++)
      {
        tmp += d[i][j];
      }
      if ( tmp < ans ) ans = tmp;
    }

    cout << "#" << tt << " " << ans << "\n";

  }
}
