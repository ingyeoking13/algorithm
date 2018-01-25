#include <bits/stdc++.h>

int main(){
	long long n; scanf("%lld", &n);

	int chk=0;

	if (n%7 == 0)			 chk=0;
	else if (n%7 == 1) chk=1;
	else if (n%7 == 2) chk=0;
	else if (n%7 == 3) chk=1;
	else if (n%7 == 4) chk=1;
	else if (n%7 == 5) chk=1;
	else if (n%7 == 6) chk=1;

	printf(chk?"SK\n":"CY\n");
}
