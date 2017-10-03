#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int slice, a, b;
}Person;

Person p[100001], Pa[100001], Pb[100001];

int mycmp(const void* a, const void* b){
	const Person* sa = (const Person*)a;
	const Person* sb = (const Person*)b;
	return (sa->a-sa->b)-(sb->a-sb->b);
}

int main(){
	int n, s;
	scanf("%d %d", &n, &s);
	long long piza=0, pizb=0, ans=0; 
	int numa=0, numb=0;

	for (int i=0; i<n; i++){
		scanf("%d %d %d", &p[i].slice, &p[i].a, &p[i].b);
		int tmp=p[i].a-p[i].b;

		if (tmp>0) {
			ans+=(double)p[i].slice*p[i].a;
			piza+=p[i].slice;
			Pa[numa++]=p[i];
		}
		else {
			ans+=(double)p[i].slice*p[i].b;
			pizb+=p[i].slice;
			Pb[numb++]=p[i];
		}
	}

	qsort(Pa, numa, sizeof(Person), mycmp);
	qsort(Pb, numb, sizeof(Person), mycmp);

	if (piza%s ==0 && pizb%s==0) printf("%lld\n", ans);
	else if ((piza%s+pizb%s>s) || piza%s==0 || pizb%s==0) 
		printf("%lld\n", ans);
	else {
		long long ansa=ans, ansb=ans;
	  int i=0; 
		piza%=s; pizb%=s;
		while(piza--){
			ansa-=Pa[i].a;
			ansa+=Pa[i].b;
			Pa[i].slice--;
			if (!Pa[i].slice) i++;
		}
		i=numb-1;
		while(pizb--){
			ansb-=Pb[i].b;
			ansb+=Pb[i].a;
			Pb[i].slice--;
			if (!Pb[i].slice) i--;
		}
		printf("%lld\n", ansa>ansb?ansa:ansb);
	}
}
