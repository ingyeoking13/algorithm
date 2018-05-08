#include <stdio.h>
class Solution {
  public:
    int consecutiveNumbersSum(int N) {
      long long tail=0, head=1;
      long long subsum=1;
      int ans=0;

      while(head <= N ){

        if ( subsum > N)  {subsum -= tail; tail++; }
        else if ( subsum == N) {ans++; subsum-= tail; tail++, head++; subsum+=head;}
        else {head++; subsum+=head;}

      }
      return ans;
    }
};

int main(){
	Solution a;
	printf("%d\n", a.consecutiveNumbersSum(15));
}
