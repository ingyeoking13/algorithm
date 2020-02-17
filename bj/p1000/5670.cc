#include <bits/stdc++.h>
using ll = long long;

using namespace std;
struct trie
{
    bool word = false;
    int child[26];
    int ccnt = 0;
    trie(){}; 
};

trie t[(int)1e6+1];
int gidx = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n)
    {
        for (int i=0; i<=1e6; i++)
        {
            t[i].ccnt =0;
            t[i].word = false;
            for (int j=0; j<26;j++)
                t[i].child[j] =0;
        }
        gidx = 0;

        vector<string> words;
        char s[81];
        for (int i=0; i<n; i++)
        {
            cin >> s;
            words.push_back(string(s));

            int len = strlen(s);
            int cur = 0;
            for (int j=0; j<len; j++)
            {
                int idx = s[j]-'a';
                if ( !t[cur].child[idx] )
                {
                    t[cur].child[idx] = ++gidx;
                    t[cur].ccnt++;
                }
                cur= t[cur].child[idx];
            }
            t[cur].word = true;
        }

        int total = 0;
        for (string word : words)
        {
            int cur = 0;
            for (int i=0; i<word.size(); i++)
            {
                if ( i>0 && 
                     t[cur].ccnt == 1 && 
                     t[cur].word == false ) total--;
                total++;

                int idx = word[i] -'a';
                int next = t[cur].child[idx];
                cur = next;
            }
        }
        cout << ((double)total/n) << "\n";
    }
}