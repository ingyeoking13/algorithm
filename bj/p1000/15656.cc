#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;
vector<string> a;
set<string> sex;
vector<int> seq;

void go(int cur, int total)
{

  if (cur > total)
  {
    string number;

    for (int i=0; i<seq.size(); i++)
    {
      number += a[seq[i]]; 
      number += " ";
    }
    cout <<  number << "\n";

    return;
  }

  for (int i=0; i<a.size(); i++)
  {

    seq.push_back(i);
    go( cur+1, total);
    seq.pop_back();

  }
}

bool myfunc(string x, string y)
{
  return stoi(x) < stoi(y);
}

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i=0; i<n; i++)
  {
    string tmp;
    cin >> tmp;

    if (sex.find(tmp) == sex.end())
    {
      a.push_back(tmp);
      sex.insert(tmp);
    }
  }
  sort(a.begin(), a.end(), myfunc);
  go(1, m);
}
