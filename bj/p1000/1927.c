#include <stdio.h>

int a[100001], len;
void swap(int x, int y){ int tmp = a[x]; a[x]=a[y]; a[y]= tmp;}
void heapify(int now, int len){
    int minimum = now;
    int l = now<<1, r = (now<<1)+1;

    if (l <= len && a[minimum] > a[l]) minimum = l;
    if (r <= len && a[minimum] > a[r]) minimum = r;

    if (minimum != now){
        swap(minimum, now);
        heapify(minimum, len);
    }
}

int deheap(int len){
    int ret = a[1];
    a[1]=a[len];
    heapify(1, len-1);
    return ret;
}

int main(){
    int n; scanf("%d", &n);
    while(n--){
        int tmp; scanf("%d", &tmp);
        if (tmp){
            a[++len]=tmp;
            int now = len;
            while(now>>1 && a[now] < a[now>>1]){
                swap(now, now/2);
                now>>=1;
            }
        }
        else {
            if (len){ printf("%d\n", deheap(len)); len--;}
            else printf("0\n");
        }
    }
}
