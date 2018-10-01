#include <stdio.h>
#include <deque>

using namespace std;
deque<int> merge(deque<int> v1, deque<int> v2){
	deque<int> ret;

	while ( (!v1.empty()) && (!v2.empty()) ){
		if ( v1.front() > v2.front() ) ret.push_back(v2.front()), v2.pop_front();
		else 										 	 		 ret.push_back(v1.front()), v1.pop_front();
	}
	while ( !v1.empty() ) ret.push_back(v1.front()), v1.pop_front();
	while ( !v2.empty() ) ret.push_back(v2.front()), v2.pop_front();

	for (int i=0; i<ret.size(); i++) printf("%d ", ret[i]);
	printf("\n");
	return ret;
}

deque<int> divide(deque<int> v){

	int n = v.size();
	for (int i=0; i<n; i++) printf("%d ", v[i]);
	printf("\n");

	if (n>1){
		deque<int> v1, v2;
		for (int i=0; i<n/2; i++) 	v1.push_back(v[i]);
		v1=divide(v1);
		for (int i=n/2; i<n; i++) 	v2.push_back(v[i]);
		v2=divide(v2);

		return merge(v1, v2);
	}
	else return v;
}

int main(){
	int a[] = {9, 7, 5, 4, 3, 2, 1, 0, 13, 25, -13, -44, -10}; //13
	deque<int> d(a, a+13);
	for (int i=0; i<13; i++) printf("%d ", d[i]);
	printf("\n===========\n");

	d= divide(d);
	for (int i=0; i<13; i++) printf("%d ", d[i]);
	printf("\n");
}
