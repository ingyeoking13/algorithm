#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student{ 
    string name;
    int k, e, m;
    Student(string s, int a, int b, int c)
    : name(s), k(a), e(b), m(c) {}
};

bool mycmp(Student& a, Student& b)
{
    if (a.k== b.k && a.e == b.e && a.m == b.m)
    {
        return a.name.compare(b.name)<0;
    }
    else if (a.k == b.k && a.e == b.e)
    {
        return a.m > b.m;
    }
    else if (a.k == b.k)
    {
        return a.e < b.e;
    }
    else return a.k >b.k;
}
vector<Student> vs;
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        string tmp;
        int a, b, c;
        cin >> tmp ;
        cin >> a >> b >> c;
        Student tmp_s= Student(tmp, a, b, c);
        vs.push_back(tmp_s);
    }

    sort(vs.begin(), vs.end(), mycmp);
    for (auto i : vs) cout << i.name << '\n';
}