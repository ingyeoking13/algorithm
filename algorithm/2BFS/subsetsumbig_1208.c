#include <stdio.h>
#include <stdlib.h>
int size, obj, input[40];
int arr1[1<<20], arr2[1<<20];
int arri;

int mycmp(const void* a, const void* b){
return *(int *)a - *(int *)b;
}

void bfs1(int sum,int inpi){
if (inpi<size/2){
int nsum = sum+input[inpi];
bfs1(nsum,inpi+1);
bfs1(sum, inpi+1);
}
else arr1[arri++]=sum;
}

void bfs2(int sum,int inpi){
if (inpi<size){
int nsum = sum+input[inpi];
bfs2(nsum,inpi+1);
bfs2(sum, inpi+1);
}
else arr2[arri++]=sum;
}

int main(){
scanf("%d %d", &size, &obj);

for (int i=0; i<size; i++)
scanf("%d", &input[i]);

arri=0; bfs1(0, 0);
arri=0; bfs2(0, size/2);

int n= 1<<size/2;
int m= 1<<size-size/2;
arr1[n-1]=0;
arr2[m-1]=0;
qsort(arr1, n, sizeof(int), mycmp);
qsort(arr2, m, sizeof(int), mycmp);
int l=0, r=m-1;
long long ans=0;
while(r>=0 && l<n){
if ((arr1[l]+arr2[r])>obj){ r--; }
else if ((arr1[l]+arr2[r])<obj) {l++;}
else{
int peg=r-1;
long long lenr=1;
while(peg >=0 && arr2[peg--]==arr2[r]) lenr++;
peg=l+1;
long long lenl=1;
while(peg <n &&arr1[peg++]==arr1[l]) lenl++;
ans += lenl*lenr;
r-=lenr;
l+=lenl;
}
}

if (!obj) ans--;
printf("%lld\n", ans);
return 0;
}

