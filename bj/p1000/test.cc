#include <iostream>
#include <algorithm>
using namespace std;
bool arr[1000001];
int n, tmp;
int main() {
		cin >> n;
   for (int i = 0; i < n; i++) {
			cin >> tmp;
      arr[tmp] = true;
   }

   for (int i = 1; i <= 1000; i++) {
      if (arr[n]) 
         cout << i << endl;
   }

   return 0;
}
