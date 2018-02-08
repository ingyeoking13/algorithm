#include <stdio.h>

int a[21];
void heapify(int size, int n){
    int max = n;
    if ( n*2 <= size && a[max] < a[n<<1])  max=n<<1;
    if ( n*2+1 <= size && a[max] < a[(n<<1)+1]) max = (n<<1)+1;
    if ( max != n){
        a[n]^=a[max], a[max]^=a[n], a[n]^=a[max];
        heapify(size, max);
    }
}

void heapsort(int size){
    for (int i=size/2; i>=1; i-- ) heapify(size,i); //build heap

    for (int i=size; i>=2; i--){
        a[i]^=a[1], a[1]^=a[i], a[i]^=a[1];
        size--;
        heapify(size, 1);
    }
}

int main(){
    for (int i=1; i<=20; i++) a[i]= 20-i;
    for (int i=1; i<=20; i++) printf("%d ", a[i]);
    printf("\n");

    heapsort(20);

    for (int i=1; i<=20; i++) printf("%d ", a[i]);
    printf("\n");
}
