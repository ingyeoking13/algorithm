#include <iostream>
#include <string>
using namespace std;

int main()
{
  while(true)
  {
    string str;
    cin >> str;

    if ( str == "start" )
    {
      int base = 0;
      int l =1, r=2;
      string ans;
      cout << "? 0 1" << endl;
      cin >> ans;
      if (ans[0] == 'x') 
      {
        cout << "! 1\n";
        continue;
      }

      while(true )
      {
        cout << "? " << l << " " << r << endl;


        cin >> ans;

        int aans;
        if ( ans[0] == 'x' ) 
        {
          base = l;
          l++;
          while(l<=r)
          {
            int mid = (l+r)/2;
            cout << "? " << base << " " << mid << endl;
            string ans;
            cin >> ans;
            if (ans[0] == 'x')
            {
              aans=mid;
              r= mid-1;
            }
            else l=mid+1;
          }
          cout << "! " << aans << endl;
          cout.flush();
          break;
        } else l*=2, r*=2; 
      }
    } 
    else break;
  }

}
