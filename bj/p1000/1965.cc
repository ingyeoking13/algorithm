#include <stdio.h>

int a[1000], d[1000];
int main(){
    int n; scanf("%d", &n);
    for (int i=0; i<n;i++) scanf("%d", &a[i]);

    for (int i=0; i<n; i++){
        d[i]=1;
        for (int j=0; j<i; j++){
            if (a[i] > a[j] && d[j]+1 > d[i]) d[i] = d[j]+1;
        }
    }

    int ans=0;
    for (int i=0; i<n; i++) if (ans<d[i]) ans=d[i];
    printf("%d\n",ans);

}
