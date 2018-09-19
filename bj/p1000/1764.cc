#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a;
    vector<string> b;
    vector<string> ans;
    string tmp;
    while(n--) 
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    while(m--)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j=0;
    for (int i=0; i<a.size(); i++)
    {
        while (j < b.size()  && a[i].compare(b[j]) >0)
        {
            j++;
        }
        if (a[i].compare(b[j]) == 0 )
        {
            ans.push_back(a[i]);
        }
    }
    cout<< ans.size() << '\n';
    for (auto i : ans)
        cout << i<< '\n';

}