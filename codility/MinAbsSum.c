#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count[101], dp[2000001];
int main() 
{ 

		int N, A[20000];
		scanf("%d", &N);
		for (int i=0; i<N; i++) scanf("%d", &A[i]);
    int sum = 0;
    
    for (int i = 0; i < N; i++){
        A[i] = abs(A[i]);
        sum += A[i];
    }
        
    for (int i = 0; i < N; i++) count[A[i]]++;
    
    memset(dp, -1, sizeof(dp));
    
    dp[0] = 0;
    for (int i = 1; i <= 100; i++){
        if (count[i] <= 0) continue;    
        
				for (int j = 0; j <= sum; j++){
            if (dp[j] >= 0)    dp[j] = count[i];    
            else if (j-i >= 0 && dp[j - i] > 0){
                dp[j] = dp[j - i] - 1;    
            }
        }
    }
    
    int result = sum;
    for (int i = 0; i * 2 <= sum; i++){
        if (dp[i] >= 0){
            result = sum-2*i < result ? sum-2*i : result; 
        }
    }
		for (int i= 0; i<=2; i++) printf("%d ", dp[i]);
		printf("\n");
		printf("%d %d\n", sum,result);
    return result;
}
