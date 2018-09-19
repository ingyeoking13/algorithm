#include <stdio.h>

int a[(int)5e5];
int part(int l, int r)
{
    int i =l+1;
    for (int j=l+1; j<=r; j++) 
    {
        if (a[l] >= a[j])
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
        }
    }

    i--;
    int tmp = a[i];
    a[i] = a[l];
    a[l] = tmp;
    return i;
}

int solve(int l, int r, int k)
{
    int i=part(l, r);
    int ans=-1;
    if (i==k-1) return a[i];

    if (i>k-1) ans = solve(l, i-1, k);
    else ans = solve(i+1, r,k);

    return ans;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    printf("%d\n", solve(0, n-1, k));
}