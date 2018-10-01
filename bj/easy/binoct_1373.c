#include <stdio.h>

char bin[1000001];
char oct[333334];
int main(){

int i;
scanf("%s", bin);
for(i=0;i<1000001;i++) if(bin[i]=='\0') break;
int len=i;
int j=0;

for(i=len-1;i>=0;i-=3){

if( bin[i-2] && bin[i-1] && bin[i])
oct[j++]= 4*(bin[i-2]-'0')+2*(bin[i-1]-'0')+bin[i];
else if (bin[i-1] && bin[i])
oct[j++] = 2*(bin[i-1]-'0')+bin[i];
else 
oct[j++] = bin[i];
}


for(i=j-1; i>=0; i--)
printf("%c", oct[i]);
printf("\n");

return 0;
}
