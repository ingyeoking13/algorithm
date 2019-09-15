#include <iostream>
#include <string>

using namespace std;
int n;
char s[(int)1e5+1], a[5][(int)2e4+1];

char num[10][5][4] = 
{
    {
        "###",
        "#.#",
        "#.#",
        "#.#",
        "###"
    },
     {
        "#",
        "#",
        "#",
        "#",
        "#"
    },
    {
        "###",
        "..#",
        "###",
        "#..",
        "###"
    },
    {
        "###",
        "..#",
        "###",
        "..#",
        "###"
    },
    {
        "#.#",
        "#.#",
        "###",
        "..#",
        "..#"
    },
    {
        "###",
        "#..",
        "###",
        "..#",
        "###"
    },

    {
        "###",
        "#..",
        "###",
        "#.#",
        "###"
    },

    {
        "###",
        "..#",
        "..#",
        "..#",
        "..#"
    },
    {
        "###",
        "#.#",
        "###",
        "#.#",
        "###"
    },
    {
        "###",
        "#.#",
        "###",
        "..#",
        "###"
    }
};

int prior[9] = { 8, 9, 0, 2, 6, 4, 3, 5, 7};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    int m = n/5;

    int cnt = 0;

    int j =0;
    for (int i=0; i<n; i++)
    {
        a[j][i%m] = s[i];
        cnt ++;
        if ( cnt == m) cnt=0, j++;
    }

    int ans = 0;
    for (int i=0; i<m; i++)
    {
        if ( a[0][i] == '#')
        {
            int find = -1;
            for (int j=0; j<10; j++)
            {
                if ( j == 1) continue;
                int kk =j;
                
                bool matched = true;
                for (int k=0; k<3; k++)
                {
                    for (int l=0; l<5; l++)
                    {
                        if ( num[kk][l][k] == a[l][i+k]);
                        else matched = false;
                    }
                }
                if ( matched ) 
                {
                    find = kk;
                    break;
                }

            }

            if ( find < 0 && 
                a[0][i] == a[1][i] && a[1][i] == a[2][i] &&
                a[2][i] == a[3][i] && a[3][i] == a[4][i] &&
                a[4][i] == '#') find =1;

            if ( find > 1 || find == 0) i+=3;
            else if ( find == 1) i++;
            else continue;

            cout << find;
        }
    }
}