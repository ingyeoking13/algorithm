#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> &A, vector<int> &B, int M, int X, int Y) {

  int now = 0;
  int allManSize = A.size();

  set<int> IWannaGo; // log n 
  int ans = 0;

  while( now < allManSize )
  {
    int curPossibleWeight = Y;
    int curPossiblePerson = X;

    for (int i=now; i<allManSize; i++)
    {
      if (curPossiblePerson ==0 ) break; 
      if (curPossibleWeight - A[i] <0 ) break;

      curPossibleWeight -= A[i];
      curPossiblePerson--;

      if ( IWannaGo.find(B[i]) == IWannaGo.end() ) 
      {
        IWannaGo.insert(B[i]);
      };
    }
    ans += IWannaGo.size();
    IWannaGo.clear();
  }
}
