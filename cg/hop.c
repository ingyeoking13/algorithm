#include <stdio.h>

int Answer;

int main(void)
{
int T, test_case;
setbuf(stdout, NULL);
int arr[2000001];
int i, j, num, jump, temp;
scanf("%d", &T);
for(test_case = 0; test_case < T; test_case++)
{
//initializing
Answer=0;
temp=-1;

//input 
scanf("%d", &num);
for (i=1;i<=num;i++) scanf("%d", &arr[i]);
scanf("%d", &jump);
arr[i]=0;

for (i=0,j=1;arr[i+j];){
	if(i==temp) {Answer=-1; break; }
  if(jump<arr[i+j]-arr[i])
	{ Answer++; temp=i; i+=j-1; j=1; }
	else j++;	
}

printf("Case #%d\n", test_case+1);
if (Answer<0) printf("%d\n", Answer);
else printf("%d\n", Answer+1);

}

return 0;
}
