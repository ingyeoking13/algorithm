//#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 100

using namespace std;
string str;
vector<string> words;
vector<int> d;
int w[50][50];
int pre[50];

int main()
{

  cin >> str;
  int n;
  cin >> n;

  for (int i=0; i<n; i++)
  {
    string word;
    cin >> word;
    words.push_back(word);
  }

  for (int i=0; i<str.size(); i++)
  {
    for (int j=0; j<words.size(); j++)
    {
      int len = words[j].size();
      if ( len + i >= str.size() ) w[i][j] = MAX;

      int cost =0;
      for (int k=0; k<words[j].size(); k++)
      {
        if ( str[i+k] != words[j][k] ) cost++;
      }
      w[i][j] = cost;
    }
  }

  d.resize(50, 1e5);

  d[0] = 0;
  priority_queue<pair<int, pair<int, int> > >  pq;
  vector<bool> used(n+1, false);

  pq.push({0,{0, 50}});
  while(!pq.empty())
  {
    auto now = pq.top();
    int dist = -now.first;
    int pos = now.second.first;
    int pre_word = now.second.second;
    cout << d[pos] << " " << pos << " " << pre_word << "\n";

    pq.pop();
    if ( dist > d[pos] ) continue;
    if ( pos >= str.size() ) continue;
    used[pre_word] = true;

    for (int i=0; i<words.size(); i++)
    {
      if ( used[i] ) continue;

      int next = pos+words[i].size();
      if ( d[pos] + w[pos][i] < d[next] )
      {
        d[next] = d[pos] + w[pos][i];
        pq.push({-d[next], {next, i}});
      }
    }
  }
  if ( d[str.size()-1] == 1e5) cout << "-1\n";
  else cout <<  d[str.size()-1] << "\n";
}
