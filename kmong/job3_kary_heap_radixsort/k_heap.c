// making k_ary heap
#include <stdio.h>

int SZ=0;
typedef struct {int num, idx; }pos;
pos min(pos a, pos b){ // return min pos structure for usability
	if (a.num >= b.num) return b;
	return a;
};
void swap(int* a, int* b){ int tmp = *a; *a=*b, *b=tmp; }

void heapify(int* a, int now, int len, int k){

	pos mn = {a[now], now}; // make sure node "now" is min node

	for (int i=now*k; i<len &&i<now*k+5; i++){
		pos tmp ={a[i],i};
		mn = min(tmp, mn);
	}

	if (mn.idx != now){ //if node "now" is not min node then we 
		swap(&a[mn.idx], &a[now]); //swap it with min node
		heapify(a, mn.idx, len, k); // and then go to sub-problemw which is sub-tree
	}
}

void heapsort(int* a, int k){

	for (int i=(SZ-1)/k; i>=0; i--){ //build heap, (SZ-1)/k is the lowest-depth node that have child.
		heapify(a, i, SZ, k);
	}
	
	for (int i=SZ-1; i>=0; i--){
		for (int j=0; j<SZ; j++) printf("%d ", a[j]);
		printf("\n");
		swap(&a[0],&a[i]); //deheap----
		heapify(a, 0, i, k); // and then we do make sure heapify tree with array size "i"
	}
}

int main(){
//	freopen("in.in", "r", stdin);
	int a[100001];
	int k; scanf("%d", &k);
	while(~scanf("%d", &a[SZ++])); //little trick
	SZ--;

	heapsort(a, k);
}
