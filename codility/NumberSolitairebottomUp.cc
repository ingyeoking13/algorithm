// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#define MIN -1000000001
int d[100000];
int max(int x, int y) { return x<y?y:x; }
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n=A.size();
    for (int i=0; i<n; i++) d[i] = MIN;
    
    d[0]=A[0];
    
    for (int i=1; i<n; i++){
        for (int j=1; j<=6; j++){
            if ( i-j>=0 ){
                d[i] = max(d[i], d[i-j]+A[i]);  
            }
        }
    }
    

    return d[n-1];
}
