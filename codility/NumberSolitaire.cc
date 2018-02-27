// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#define MIN -1000000001
int d[100001], a[1000001];

int max(int a, int b) { return a<b?b:a; }
int dfs(int now){
    if ( now < 0 ) return MIN;
    if ( d[now] > MIN ) return d[now];
    
    int ret=MIN;
    for (int i=1; i<=6; i++) 
        ret=max(ret, dfs(now-i));

    d[now]=a[now]+ret;
    return d[now];
}


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n= A.size();
    for (int i=0; i<n; i++) a[i]=A[i];    
    for (int i=0; i<n; i++){  
        d[i] = MIN;  
    }
    d[0]= a[0];
    return dfs(n-1);
}
