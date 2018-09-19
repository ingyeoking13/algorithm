class Solution {
public:
  int d[10][11];

  int atMostNGivenDigitSet(vector<string>& D, int N) {
    for (int i=0; i<D.size(); i++) d[D[i]-'0'][0] =1;

    for (int len=1; len<=10; len++)
    {
      for (int i=0; i<D.size(); i++)
      {
        int now =(D[i]-'0');
        d[now][len]+= d[now][len-1];
      }
    }

      
  }
};
