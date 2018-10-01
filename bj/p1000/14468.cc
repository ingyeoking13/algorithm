#include <stdio.h>
#include <stack>

using namespace std;

char ch[26];
char s[53];
int main()
{
    scanf("%s", s);
    stack<char> st;
    st.push(s[0]);
    ch[s[0]-'A']=1;
    int ans=0;

    for (int i=1; i<52; i++)
    {
        if (ch[s[i]-'A'])
        {
            ch[s[i]-'A']=0;
            stack<char> tmp_st;
            char tmp_ch = st.top();
            int cnt=0;
            while((tmp_ch = st.top())) 
            {
                st.pop();
                if (tmp_ch == s[i]) break;
                cnt++;
                tmp_st.push(tmp_ch);
            }

            while(!tmp_st.empty())
            {
                char tt =tmp_st.top();
                tmp_st.pop();
                st.push(tt);
            }
            ans += cnt;
        }
        else ch[s[i]-'A']=1, st.push(s[i]);
    }
    printf("%d\n", ans);
}