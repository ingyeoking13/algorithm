#include <stdio.h>

int a[(int)1e6];

void heapify(int idx, int n)
{
  int mx = idx;

  int left = idx*2+1;
  int right = idx*2+2;

  if ( left < n && a[left] > a[mx] ) mx = left;
  if ( right <n && a[right] > a[mx] ) mx =right;

  if( mx != idx )
  {
    int tmp = a[idx];
    a[idx] = a[mx];
    a[mx] = tmp;
    heapify(mx, n);
  }
}

void sort(int n)
{

  for (int i=n/2; i>=0; i--) heapify( i, n);

  for (int i=n-1; i>0; i--)
  {
    int tmp = a[0];
    a[0] = a[i];
    a[i] = tmp;
    heapify(0, i);
  }
}


int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++) scanf("%d", &a[i]);

  sort(n);
  for (int i=0; i<n; i++)
  {
    printf("%d\n", a[i]);
  }

}
