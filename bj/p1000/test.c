#include <stdio.h>
#include <stdlib.h>

int mycmp(const void* a, const void* b) { return *(int *)a - *(int *)b; }
int a[10001];
int main(){
int n; scanf("%d", &n);
for (int i=0; i<n; i++) scanf("%d", &a[i]);
int obj; scanf("%d", &obj);

qsort(a, n, sizeof(int), mycmp);

int l=0, tmp=0, max=n-1;
while(1){
int r= max, mean=obj/n;
while(l<r){
int m=(l+r)/2;
if (a[m]>mean) r=m;
else l=m+1;
}
for (int i=tmp; i<l; i++) obj-=a[i];
n-=(l-tmp);
if (tmp==l) break;
else tmp=l;
}
printf("%d\n", obj/n);
}

