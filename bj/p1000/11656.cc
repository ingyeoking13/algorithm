#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> v;
    string tmp;
    cin >> tmp;

    for (int i=0; i<tmp.length(); i++)
    {
        string ss = tmp.substr(i);
        v.push_back(ss);
    }
    sort(v.begin(), v.end());
    for (auto s: v) cout << s << '\n';
}