#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char a[101];
    scanf("%s", a);
    int n_len = strlen(a);

    while(m--)
    {
        char tmp[1001];
        scanf("%s", tmp);
        int i=0, j=0;
        int tmp_len = strlen(tmp);
        while(i<n_len && j< tmp_len)
        {
            if ( a[i] == tmp[j]) i++, j++;
            else j++;
        }

        if ( i== n_len) printf("true\n");
        else printf("false\n");
    }
}