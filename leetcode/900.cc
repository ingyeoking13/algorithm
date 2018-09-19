class RLEIterator {
public:
  vector<pair<int, int> > a;

  RLEIterator(vector<int> A) {
    int prev =0;
    for (int i=0; i<A.size(); i++)
    {
      if (i%2==0)
      {
        if (A[i] ==0) continue;
        a.push_back({A[i],A[i+1]});
        prev = A[i];
        i++;
      }
    }
  }
  
  int next(int n) {

    for (int i=0; i< a.size(); i++)
    {
      if ( n>a[i].first) n-=a[i].first;
      else
      {

        int ret = a[i].second;
        a[i].first-=n;
        if (a[i].first <=0) a.erase(a.begin()+i);
        for (int j=i-1; j>= 0; j--)
        {
           a.erase(a.begin()+j);
        }
        return ret;
      }
    }
    a.clear();
    return -1;
  }
};

