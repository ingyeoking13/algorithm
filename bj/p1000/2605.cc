#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a;
    int tmp;
    scanf("%d", &tmp);
    a.push_back(1);
    for (int i=2; i<=n; i++)
    {
        scanf("%d", &tmp);
        a.insert(a.begin() +a.size()-tmp, i);
    }
    for (auto i: a)
        printf("%d ", i);
    printf("\n");
}
