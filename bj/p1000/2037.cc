#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int a[26] =
{
    2, 2, 2, 3, 3, 3, 
    4, 4, 4, 5, 5, 5, 
    6, 6, 6, 7, 7, 7, 7, 
    8, 8, 8, 9, 9, 9, 9
};

int required[26] =
{
    1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3,
    1, 2, 3, 1, 2, 3, 4,
    1, 2, 3, 1, 2, 3, 4 
};

char input[ 1002 ];
int main()
{
    int p, w; 
    cin >> p >> w;
    getchar();
    fgets(input, 1002, stdin);  

    int len = strlen(input);
    if ( input[len-1] == '\n') len--;

    int before = -1;
    int ans = 0;

    for (int i =0; i<len; i++)
    {
        if ( input[i] == ' ')
        {
            int key = 1;
            ans += p;
            before = key;

            continue;
        }

        int al = input[i]-'A';  
        int key = a[ al ]; 

        // 같은 키일 때 
        if ( key == before )
        {
            ans += w;
        }
        ans += required[ al ]*p;
        before = key;
    }
    printf("%d\n", ans);
}