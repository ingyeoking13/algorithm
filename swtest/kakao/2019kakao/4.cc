#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Trie 
{
    int child[26];
    bool end;
    Trie() 
    {
        end = false;
        for (int i=0; i<26; i++)
            child [ i ] =0;
    }
};

int idx = 1, bidx = 1;
Trie trie[(int)1e6+1];
Trie btrie[(int)1e6+1];

int go_back(int cur, int rem)
{
    int ret = 0;
    if (rem == 0)
    {
        return btrie[cur].end;
    }

    for (int i =0; i<26; i++)
    {
        int iidx = btrie[cur].child[i];
        if ( iidx == 0) continue;

        ret += go_back( iidx ,rem-1);
    }
    return ret;
}

int go(int cur, int rem)
{
    int ret = 0;
    if( rem == 0)
    {
        return trie[cur].end;
    }
    for (int i =0; i<26; i++)
    {
        int iidx = trie[cur].child[i];
        if ( iidx == 0) continue;

        ret += go( iidx ,rem-1);
    }
    return ret;
}


vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // build 
    for (int i=0; i<words.size(); i++)
    {
        string str = words[i];

        int cur = 0;
        for (int j=0; j<str.size(); j++)
        {
            char c = str[j];
            int iidx =  c - 'a';
            if ( trie[cur].child[ iidx ]  == 0) trie[cur].child[ iidx ] = idx++;
            cur = trie[cur].child[iidx];
        }
        trie[cur].end = true;

        reverse(str.begin(), str.end());

        cur = 0;
        for (int j=0; j<str.size(); j++)
        {
            char c = str[j];
            int iidx =  c - 'a';
            if ( btrie[cur].child[ iidx ]  == 0) btrie[cur].child[ iidx ] = bidx++;
            cur = btrie[cur].child[iidx];
        }
        btrie[cur].end = true;
    }
    //query

    int qsz = queries.size();
    for (int i =0; i<qsz; i++)
    {
        string &str = queries[i];
        int damn = 0;
        
        if (str.back() == '?')
        {
            int cur = 0;
            for (int j =0 ;j<str.size(); j++)
            {
                char c = str[j];
                if ( c == '?')
                {
                    int len = str.size();
                    damn = go( cur, len -j );

                    break;
                }
                else 
                {
                    int iidx = c-'a';
                    if ( trie[cur].child[ iidx ] == 0)
                    {
                        break;
                    }
                    cur = trie[cur].child[ iidx ];
                }
            }


        }
        else if ( str[0] == '?')
        {
            int cur = 0;
          //  reverse(str.begin(), str.end());
            for (int j =str.size()-1 ;j>=0; j--)
            {
                char c = str[j];
                if ( c == '?')
                {
                    int len = str.size();
                    damn = go_back( cur, j+1 );
                    break;
                }
                else 
                {
                    int iidx = c-'a';
                    if ( btrie[cur].child[ iidx ] == 0)
                    {
                        break;
                    }
                    cur = btrie[cur].child[ iidx ];
                }
            }

        }
        else 
        {
            int cur = 0;
            for (int j= 0; j<str.size(); j++)
            {
                char c = str[j];
                int iidx = c- 'a';
                if ( trie[cur].child[ iidx ] == 0) 
                {
                    break;
                }
                cur = trie[cur].child[iidx];
            }
            damn= trie[cur].end;
        }
        answer.push_back(damn);
    }

    return answer;
}