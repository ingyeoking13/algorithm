#include<stdio.h>

#include<stdlib.h>



int main(void)

{

int random[10]={0};

int i ,max ;



for( i=0; i<100; i++)

{
int ran=rand()%10;
random[ran]++;

printf("random[%d] = %d \n", ran , random[ran]);

}

max = 0;

for( i=0; i<=9;i++)

{

if(random[i]>max)

max = i;

}

printf("%d\n",max);

return 0;

}


