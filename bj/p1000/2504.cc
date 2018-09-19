#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

char s[35];
int main()
{
    scanf("%s", s);
    int len = strlen(s);
    stack<int> myS;
    for (int i=0; i<len; i++)
    {
        if (s[i] == '(' || s[i] == '[') myS.push(s[i]);
        else if (s[i] == ']' || s[i] == ')')
        {
            int now=0;

            while(!myS.empty() && myS.top() != '(' && myS.top() != '[') {
                now += myS.top();
                myS.pop();
            }
            if (myS.empty()) return !printf("0\n");
            if (s[i] == ']' && myS.top()== '[')
            {
                if (now>0) now*=3;
                else now=3;
                myS.pop();
                myS.push(now);
            }
            else if (s[i] == ')' && myS.top() =='(')
            {
                if (now>0) now*=2;
                else now=2;
                myS.pop();
                myS.push(now);
            }
            else {
                return !printf("0\n");
            }
        }
    }
    int ans =0;
    while(!myS.empty())
    {
        if (myS.top() == '(' || myS.top() == '[' ) return !printf("0\n");
        ans += myS.top();
        myS.pop();
    }
    printf("%d\n", ans);
}